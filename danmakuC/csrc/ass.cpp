#include <map>
#include <cmath>
#include <codecvt>
#include <regex>
#include <fstream>
#include <fmt/core.h>
#include <boost/algorithm/string.hpp>
#include <pybind11/pybind11.h>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include "nndcomment.pb.h"
#include "nndcomment.pb.cc"

using namespace std;

// https://w.atwiki.jp/nicoapi/pages/20.html
const std::map<string, int> NICONICO_COLOR_MAPPINGS = {
    // Regular user
    { "white", 0xffffff },
    { "red", 0xff0000 },
    { "pink", 0xff8080 },
    { "orange", 0xffcc00 },
    { "yellow", 0xffff00 },
    { "green", 0x00ff00 },
    { "cyan", 0x00ffff },
    { "blue", 0x0000ff },
    { "purple", 0xc000ff },
    { "black", 0x000000 },
    // Premium user
    { "niconicowhite", 0xcccc99 },
    { "white2", 0xcccc99 },
    { "truered", 0xcc0033 },
    { "red2", 0xcc0033 },
    { "passionorange", 0xff6600 },
    { "orange2", 0xff6600 },
    { "madyellow", 0x999900 },
    { "yellow2", 0x999900 },
    { "elementalgreen", 0x00cc66 },
    { "green2", 0x00cc66 },
    { "marineblue", 0x33ffcc },
    { "blue2", 0x33ffcc },
    { "nobleviolet", 0x6633cc },
    { "purple2", 0x6633cc },
};

std::tuple<int, int, float> process_mailstyle(string mail, float fontsize) {
	int pos = 0;
	int color = 0xffffff;
	float size = fontsize;
	if (mail.length() == 0) return std::make_tuple(pos, color, size);
    vector<string> parts;
    boost::split(parts, mail, boost::is_any_of(" "));
	for (string mailstyle : parts)
	{
		//cout << mailstyle;
		if (mailstyle == "ue")
		{
			pos = 1; //top middle
		}
		else if (mailstyle == "shita")
		{
			pos = 2; //bottom middle
		}
		else if (mailstyle == "naka")
		{
			pos = 0; //default flying text (right to left)
		}
		else if (mailstyle == "big")
		{
			size = fontsize * 1.44;
		}
		else if (mailstyle == "small")
		{
			size = fontsize * 0.64;
		}
		else if (NICONICO_COLOR_MAPPINGS.count(mailstyle))
		{
			color = NICONICO_COLOR_MAPPINGS.at(mailstyle);
		}
		else if (std::regex_match (mailstyle, std::regex ("#([a-fA-F0-9]{6})")))
		{
			std::smatch sm;
			std::regex e ("#([a-fA-F0-9]{6})");
			std::regex_match (mailstyle, sm, e);
			std::stringstream ss;
			ss << std::hex << sm[1];
			ss >> color;
		}
	}
	return std::make_tuple(pos, color, size);
}

class Comment {
public:
    float progress;
    int ctime;
    string content;
    float font_size;
    int mode;
    int color;
    // others
    float size;
    float part_size;
    float max_len;
    int row;

    Comment() = delete;

    Comment(float progress,
            int ctime,
            string content,
            float font_size,
            int mode,
            int color
    ) : progress(progress), ctime(ctime), content(content), font_size(font_size), mode(mode), color(color) {}
};

size_t utf8_len(const string& utf8) {
    return wstring_convert<codecvt_utf8<char32_t>, char32_t>{}.from_bytes(utf8).size();
}

int find_alternative_row(vector<vector<Comment*>>& rows, Comment& c, int height, int reserve_blank) {
    int res = 0;
    for (int row = 0; row < height - reserve_blank - ceil(c.part_size); ++row) {
        if (rows[c.mode][row] == nullptr)
            return row;
        else if (rows[c.mode][row]->progress < rows[c.mode][res]->progress)
            res = row;
    }
    return res;
}

void mark_comment_row(vector<vector<Comment*>>& rows, Comment& c, int row) {
    for (size_t i = row; i < row + ceil(c.part_size) && i < rows[0].size(); ++i)
        rows[c.mode][i] = &c;
}

void unmark_rows(vector<vector<Comment*>>& rows, int mode) {
    for (size_t i = 0; i < rows[mode].size(); ++i)
        rows[mode][i] = nullptr;
}

int test_free_row(vector<vector<Comment*>>& rows, Comment& c, int row, int width, int height,
                  int reserve_blank, float duration_marquee, float duration_still) {
    int res = 0;
    int row_max = height - reserve_blank;
    Comment* target_row = nullptr;
    if (c.mode == 1 || c.mode == 2) {
        while (row < row_max && res < c.part_size) {
            if (target_row != rows[c.mode][row]) {
                target_row = rows[c.mode][row];
                if (target_row != nullptr && target_row->progress + duration_still > c.progress)
                    break;
            }
            row++;
            res++;
        }
    } else {
        int div = c.max_len + width;
        float threshold_time;
        if (div != 0)
            threshold_time = c.progress - duration_marquee * (1 - width / float(div));
        else
            threshold_time = c.progress - duration_marquee;
        while (row < row_max && res < c.part_size) {
            if (target_row != rows[c.mode][row]) {
                target_row = rows[c.mode][row];
                if (target_row != nullptr) {
                    div = target_row->max_len + width;
                    if (div != 0 && (target_row->progress > threshold_time ||
                                     target_row->progress + target_row->max_len * duration_marquee / div > c.progress))
                        break;
                }
            }
            row++;
            res++;
        }
    }
    return res;
}

vector<float> get_zoom_factor(vector<int>& source_size, vector<int>& target_size) {
    float source_aspect = float(source_size[0]) / source_size[1];
    float target_aspect = float(target_size[0]) / target_size[1];
    if (target_aspect < source_aspect) {  // narrower
        if (source_size[0] == 0 || source_aspect == 0) return {1, 0, 0};
        float scale_factor = float(target_size[0]) / source_size[0];
        return {scale_factor, 0, (target_size[1] - target_size[0] / source_aspect) / 2};
    } else if (target_aspect > source_aspect) {  // wider
        if (source_size[1] == 0) return {1, 0, 0};
        float scale_factor = target_size[1] / source_size[1];
        return {scale_factor, (target_size[0] - target_size[1] * source_aspect) / 2, 0};
    } else {
        if (source_size[0] == 0) return {1, 0, 0};
        return {float(target_size[0]) / source_size[0], 0, 0};
    }
}

// https://aegi.vmoe.info/docs/3.0/ASS_Tags/#index1h2
string ass_escape(string s) {
    const string ZERO_WIDTH_SPACE = "​"; // U+200B

    // prevent "\" from causing line breaks/escaping anything ("\\" won't work)
    string s2 = boost::replace_all_copy(s, R"(\)", R"(\)" + ZERO_WIDTH_SPACE);

    // escape "}" and "{" (override block chars) with backslash
    s2 = std::regex_replace(s2, std::regex (R"(([}{]))"), R"(\$1)");

    // preserve intended spacing at start and end of lines
    boost::replace_all(s2, "\n", ZERO_WIDTH_SPACE + R"(\N)" + ZERO_WIDTH_SPACE);
    return ZERO_WIDTH_SPACE + s2 + ZERO_WIDTH_SPACE;
}

int clip_byte(float x) {
    if (x > 255) return 255;
    else if (x < 0) return 0;
    else return round(x);
}

string convert_color(int RGB, int width = 1280, int height = 576) {
    if (RGB == 0x000000)
        return "000000";
    else if (RGB == 0xFFFFFF)
        return "FFFFFF";
    int R = (RGB >> 16) & 0xFF;
    int G = (RGB >> 8) & 0xFF;
    int B = RGB & 0xFF;
    if (width < 1280 and height < 576)
        return fmt::format("{:02X}{:02X}{:02X}", B, G, R);
    else
        return fmt::format("{:02X}{:02X}{:02X}",
                           clip_byte(R * 0.00956384088080656 + G * 0.03217254540203729 + B * 0.95826361371715607),
                           clip_byte(R * -0.10493933142075390 + G * 1.17231478191855154 + B * -0.06737545049779757),
                           clip_byte(R * 0.91348912373987645 + G * 0.07858536372532510 + B * 0.00792551253479842)
        );
}

string convert_progress(float progress) {
    float timestamp = round(progress * 100.0);
    auto [hour, x1] = div(timestamp, 360000);
    auto [minute, x2] = div(x1, 6000);
    auto [second, centsecond] = div(x2, 100);
    return fmt::format("{}:{:02d}:{:02d}.{:02d}", hour, minute, second, centsecond);
}

int convert_type2(int row, int height, int reserve_blank) {
    return height - reserve_blank - row;
}

class Ass {
public:
    int width;
    int height;
    int reserve_blank;
    string font_face;
    float font_size;
    float alpha;
    float duration_marquee;
    float duration_still;
    string filter;
    bool reduced;
    // others
    vector<Comment> comments;
    vector<int> bili_player_size;
    vector<float> zoom_factor;
    string head;
    string body = "";
    bool need_clear = false;

    Ass(int w, int h, int rb, const string& ff, float fs, float a, float dm, float ds, const string& flt, bool rd) :
            width(w), height(h), reserve_blank(rb), font_face(ff), font_size(fs), alpha(a), duration_marquee(dm),
            duration_still(ds), filter(flt), reduced(rd) {
        head = fmt::format("[Script Info]\n"
                           "; Script generated by danmakuC (based on Danmaku2ASS)\n"
                           "; https://github.com/HFrost0/danmakuC\n"
                           "Script Updated By: danmakuC (https://github.com/HFrost0/danmakuC)\n"
                           "ScriptType: v4.00+\n"
                           "PlayResX: {0}\n"
                           "PlayResY: {1}\n"
                           "Aspect Ratio: {0}:{1}\n"
                           "Collisions: Normal\n"
                           "WrapStyle: 2\n"
                           "ScaledBorderAndShadow: yes\n"
                           "YCbCr Matrix: TV.601\n"
                           "\n"
                           "[V4+ Styles]\n"
                           "Format: Name, Fontname, Fontsize, PrimaryColour, SecondaryColour, OutlineColour, BackColour, Bold, Italic, Underline, StrikeOut, ScaleX, ScaleY, Spacing, Angle, BorderStyle, Outline, Shadow, Alignment, MarginL, MarginR, MarginV, Encoding\n"
                           // todo stylid
                           "Style: danmakuC, {2}, {3:.0f}, &H{4:02X}FFFFFF, &H{4:02X}FFFFFF, &H{4:02X}000000, &H{4:02X}000000, 0, 0, 0, 0, 100, 100, 0.00, 0.00, 1, {5:.0f}, 0, 7, 0, 0, 0, 0\n"
                           "\n"
                           "[Events]\n"
                           "Format: Layer, Start, End, Style, Name, MarginL, MarginR, MarginV, Effect, Text\n",
                           width, height, font_face, font_size, int(round(1 - alpha)) * 255,
                           max(font_size / 25.0, 1.0));
        // bili_player_size = {512, 384}  // Bilibili player version 2010
        // bili_player_size = {540, 384}  // Bilibili player version 2012
        // bili_player_size = {672, 438}  // Bilibili player version 2014
        bili_player_size = {891, 589};    // Bilibili player version 2021 (flex)
        vector<int> target_size{width, height};
        zoom_factor = get_zoom_factor(bili_player_size, target_size);
    }

    bool add_comment(float progress, int ctime, const string& content, float fontsize, int mode, int color) {
        // need clear
        need_clear = true;
        // content regex filter
        if (filter != "" && regex_search(content, regex(filter)))
            return false;
        // calculate extra filed
        Comment comment = Comment(progress, ctime, content, fontsize, mode, color);
        if (comment.mode != 4) {
            comment.content = ass_escape(comment.content);
            comment.size = int(comment.font_size) * font_size / 25.0;
            vector<string> parts;
            boost::split(parts, comment.content, boost::is_any_of("\n"));
            comment.part_size = comment.size * parts.size();
            int max_len = 0;
            for (string& p: parts) {
                int part_len = utf8_len(p);
                if (part_len > max_len)
                    max_len = part_len;
            }
            comment.max_len = max_len * comment.size;
        } else
            // bilipos comment
            comment.size = comment.font_size, comment.part_size = 0, comment.max_len = 0;
        comments.push_back(comment);
        return true;
    }

    int add_comments_from_file_niconico(string filename) {
        bool compressed = false;
        {
            ifstream file(filename, ios_base::in | ios_base::binary);
            boost::iostreams::filtering_streambuf<boost::iostreams::input> in;
            in.push(file);
            unsigned char magic[2];
            in.sgetn((char *)magic, 2);
            file.close();
            if ((magic[0] << 8) + magic[1] == 0x1f8b)
                compressed = true;
        }
        ifstream file(filename, ios_base::in | ios_base::binary);
        boost::iostreams::filtering_streambuf<boost::iostreams::input> in;
        if (compressed)
            in.push(boost::iostreams::gzip_decompressor());
        in.push(file);
        unsigned char sizebuf[4];
        const int proto_bytes_size = 1<<20;
        char proto_bytes[proto_bytes_size];
        NNDComment proto_comment;
        int count = 0;
        while (true) {
            if (in.sgetn((char *)sizebuf, 4) == 0) break;
            uint32_t size = (sizebuf[0] << 24) | (sizebuf[1] << 16) | (sizebuf[2] << 8) | sizebuf[3];
            if (size > proto_bytes_size) {
                return -1;
            }
            in.sgetn(proto_bytes, size);
            if (!proto_comment.ParseFromArray(proto_bytes, size)) {
                return -1;
            }
            float progress = proto_comment.vpos() / 100.0f;
            int ctime = proto_comment.date();
            string content = proto_comment.content();
            string mail = proto_comment.mail();
            std::tuple<int, int, float> mailstyle = process_mailstyle(mail, font_size);
            int mode = std::get<0>(mailstyle);
            int color = std::get<1>(mailstyle);
            float fontsize = std::get<2>(mailstyle);
            add_comment(progress, ctime, content, fontsize, mode, color);
            count++;
        }
        return count;
    }

    string to_string() {
        if (body == "" || need_clear) {
            write_comments();
        }
        return head + body;
    }

    void write_comments(std::ofstream *out_fp = nullptr) {
        /// 1. clear body first
        body = "";
        /// 2. sort before find row
        sort(comments.begin(), comments.end(), [](Comment& a, Comment& b) -> bool {
            if (a.progress != b.progress)
                return a.progress < b.progress;
            else
                return a.ctime < b.ctime;
        });
        /// 3. find row
        vector<vector<Comment*>> rows(4, vector<Comment*>(height - reserve_blank + 1, nullptr));
        for (size_t idx = 0; idx < comments.size(); ++idx) {
            Comment& c = comments[idx];
            if (c.mode != 4) {  // not a bilipos
                int row = 0;
                int row_max = height - reserve_blank - c.part_size;
                bool flag = true;
                while (row <= row_max) {
                    int free_row = test_free_row(rows, c, row,
                                                 width, height, reserve_blank, duration_marquee, duration_still);
                    if (free_row >= c.part_size) {
                        mark_comment_row(rows, c, row);
                        flag = false;
                        break;
                    } else
                        row += free_row || 1;
                }
                if (flag && !reduced) {
                    row = find_alternative_row(rows, c, height, reserve_blank);
                    if (row == 0)
                        unmark_rows(rows, c.mode);
                    mark_comment_row(rows, c, row);
                }
                c.row = row;
                write_comment(c, out_fp);
            } else
                write_bilipos_comment(c, out_fp);
        }
        need_clear = false;
    }

    void write_comment(Comment& c, std::ofstream *out_fp = nullptr) {
        vector<string> styles;
        float duration;
        switch (c.mode) {
            case 1: {
                styles.push_back(fmt::format("\\an8\\pos({}, {})",
                                             width / 2, c.row));
                duration = duration_still;
                break;
            }
            case 2: {
                styles.push_back(fmt::format("\\an2\\pos({}, {})",
                                             width / 2, convert_type2(c.row, height, reserve_blank)));
                duration = duration_still;
                break;
            }
            case 3: {
                styles.push_back(fmt::format("\\move({2}, {1}, {0}, {1})",
                                             width, c.row, -ceil(c.max_len)));
                duration = duration_marquee;
                break;
            }
            default: {
                styles.push_back(fmt::format("\\move({0}, {1}, {2}, {1})",
                                             width, c.row, -ceil(c.max_len)));
                duration = duration_marquee;
            }
        }
        float size = c.size - font_size;
        if (size <= -1 || size >= 1)
            styles.push_back(fmt::format("\\fs{:.0f}", c.size));
        if (c.color != 0xFFFFFF) {
            styles.push_back(fmt::format("\\c&H{}&", convert_color(c.color)));
            if (c.color == 0x000000)
                styles.push_back("\\3c&HFFFFFF&");
        }
        string line = fmt::format("Dialogue: 2,{0},{1},danmakuC,,0000,0000,0000,,{{{2}}}{3}\n",
                            convert_progress(c.progress),
                            convert_progress(c.progress + duration),
                            boost::algorithm::join(styles, ""),
                            c.content
        );
        if (out_fp == nullptr)
            body += line;
        else
            *out_fp << line;
    }

    void write_bilipos_comment(Comment& c, std::ofstream *out_fp = nullptr) {
        // todo
        return;
    }

    float get_position(float input_pos, bool is_height) {
        if (input_pos > 1)
            return zoom_factor[0] * input_pos + zoom_factor[is_height + 1];
        else
            return bili_player_size[is_height] * zoom_factor[0] * input_pos + zoom_factor[is_height + 1];
    }

    void write_to_file(string out_filename) {
        std::ofstream out_fp;
        out_fp.open(out_filename, std::ofstream::out);
        out_fp << head;
        write_comments(&out_fp);
        out_fp.close();
    }
};

namespace py = pybind11;

PYBIND11_MODULE(ass, m) {
    m.doc() = "pybind11 ass extension"; // optional module docstring
    py::class_<Ass>(m, "Ass")
            .def(py::init<int, int, int, const string&, float, float, float, float, string, bool>())
            .def("add_comment", &Ass::add_comment)
            .def("add_comments_from_file_niconico", &Ass::add_comments_from_file_niconico)
            .def("to_string", &Ass::to_string)
            .def("write_to_file", &Ass::write_to_file);
}
