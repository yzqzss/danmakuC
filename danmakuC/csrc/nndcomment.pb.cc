// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: nndcomment.proto

#include "nndcomment.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

PROTOBUF_CONSTEXPR NNDComment::NNDComment(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.user_id_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.mail_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.content_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.fork_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.thread_)*/int64_t{0}
  , /*decltype(_impl_.no_)*/0
  , /*decltype(_impl_.vpos_)*/0
  , /*decltype(_impl_.date_)*/int64_t{0}
  , /*decltype(_impl_.date_usec_)*/0
  , /*decltype(_impl_.anonymity_)*/false
  , /*decltype(_impl_.premium_)*/false
  , /*decltype(_impl_.leaf_)*/0
  , /*decltype(_impl_.score_)*/0
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct NNDCommentDefaultTypeInternal {
  PROTOBUF_CONSTEXPR NNDCommentDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~NNDCommentDefaultTypeInternal() {}
  union {
    NNDComment _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 NNDCommentDefaultTypeInternal _NNDComment_default_instance_;
static ::_pb::Metadata file_level_metadata_nndcomment_2eproto[1];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_nndcomment_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_nndcomment_2eproto = nullptr;

const uint32_t TableStruct_nndcomment_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::NNDComment, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::NNDComment, _impl_.thread_),
  PROTOBUF_FIELD_OFFSET(::NNDComment, _impl_.no_),
  PROTOBUF_FIELD_OFFSET(::NNDComment, _impl_.vpos_),
  PROTOBUF_FIELD_OFFSET(::NNDComment, _impl_.date_),
  PROTOBUF_FIELD_OFFSET(::NNDComment, _impl_.date_usec_),
  PROTOBUF_FIELD_OFFSET(::NNDComment, _impl_.anonymity_),
  PROTOBUF_FIELD_OFFSET(::NNDComment, _impl_.user_id_),
  PROTOBUF_FIELD_OFFSET(::NNDComment, _impl_.mail_),
  PROTOBUF_FIELD_OFFSET(::NNDComment, _impl_.leaf_),
  PROTOBUF_FIELD_OFFSET(::NNDComment, _impl_.premium_),
  PROTOBUF_FIELD_OFFSET(::NNDComment, _impl_.score_),
  PROTOBUF_FIELD_OFFSET(::NNDComment, _impl_.content_),
  PROTOBUF_FIELD_OFFSET(::NNDComment, _impl_.fork_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::NNDComment)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::_NNDComment_default_instance_._instance,
};

const char descriptor_table_protodef_nndcomment_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\020nndcomment.proto\"\326\001\n\nNNDComment\022\016\n\006thr"
  "ead\030\001 \001(\003\022\n\n\002no\030\002 \001(\005\022\014\n\004vpos\030\003 \001(\005\022\014\n\004d"
  "ate\030\004 \001(\003\022\021\n\tdate_usec\030\005 \001(\005\022\021\n\tanonymit"
  "y\030\006 \001(\010\022\017\n\007user_id\030\007 \001(\t\022\014\n\004mail\030\010 \001(\t\022\014"
  "\n\004leaf\030\t \001(\005\022\017\n\007premium\030\n \001(\010\022\r\n\005score\030\013"
  " \001(\005\022\017\n\007content\030\014 \001(\t\022\014\n\004fork\030\017 \001(\tb\006pro"
  "to3"
  ;
static ::_pbi::once_flag descriptor_table_nndcomment_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_nndcomment_2eproto = {
    false, false, 243, descriptor_table_protodef_nndcomment_2eproto,
    "nndcomment.proto",
    &descriptor_table_nndcomment_2eproto_once, nullptr, 0, 1,
    schemas, file_default_instances, TableStruct_nndcomment_2eproto::offsets,
    file_level_metadata_nndcomment_2eproto, file_level_enum_descriptors_nndcomment_2eproto,
    file_level_service_descriptors_nndcomment_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_nndcomment_2eproto_getter() {
  return &descriptor_table_nndcomment_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_nndcomment_2eproto(&descriptor_table_nndcomment_2eproto);

// ===================================================================

class NNDComment::_Internal {
 public:
};

NNDComment::NNDComment(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:NNDComment)
}
NNDComment::NNDComment(const NNDComment& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  NNDComment* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.user_id_){}
    , decltype(_impl_.mail_){}
    , decltype(_impl_.content_){}
    , decltype(_impl_.fork_){}
    , decltype(_impl_.thread_){}
    , decltype(_impl_.no_){}
    , decltype(_impl_.vpos_){}
    , decltype(_impl_.date_){}
    , decltype(_impl_.date_usec_){}
    , decltype(_impl_.anonymity_){}
    , decltype(_impl_.premium_){}
    , decltype(_impl_.leaf_){}
    , decltype(_impl_.score_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.user_id_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.user_id_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_user_id().empty()) {
    _this->_impl_.user_id_.Set(from._internal_user_id(), 
      _this->GetArenaForAllocation());
  }
  _impl_.mail_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.mail_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_mail().empty()) {
    _this->_impl_.mail_.Set(from._internal_mail(), 
      _this->GetArenaForAllocation());
  }
  _impl_.content_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.content_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_content().empty()) {
    _this->_impl_.content_.Set(from._internal_content(), 
      _this->GetArenaForAllocation());
  }
  _impl_.fork_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.fork_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_fork().empty()) {
    _this->_impl_.fork_.Set(from._internal_fork(), 
      _this->GetArenaForAllocation());
  }
  ::memcpy(&_impl_.thread_, &from._impl_.thread_,
    static_cast<size_t>(reinterpret_cast<char*>(&_impl_.score_) -
    reinterpret_cast<char*>(&_impl_.thread_)) + sizeof(_impl_.score_));
  // @@protoc_insertion_point(copy_constructor:NNDComment)
}

inline void NNDComment::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.user_id_){}
    , decltype(_impl_.mail_){}
    , decltype(_impl_.content_){}
    , decltype(_impl_.fork_){}
    , decltype(_impl_.thread_){int64_t{0}}
    , decltype(_impl_.no_){0}
    , decltype(_impl_.vpos_){0}
    , decltype(_impl_.date_){int64_t{0}}
    , decltype(_impl_.date_usec_){0}
    , decltype(_impl_.anonymity_){false}
    , decltype(_impl_.premium_){false}
    , decltype(_impl_.leaf_){0}
    , decltype(_impl_.score_){0}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.user_id_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.user_id_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.mail_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.mail_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.content_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.content_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.fork_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.fork_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

NNDComment::~NNDComment() {
  // @@protoc_insertion_point(destructor:NNDComment)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void NNDComment::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.user_id_.Destroy();
  _impl_.mail_.Destroy();
  _impl_.content_.Destroy();
  _impl_.fork_.Destroy();
}

void NNDComment::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void NNDComment::Clear() {
// @@protoc_insertion_point(message_clear_start:NNDComment)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.user_id_.ClearToEmpty();
  _impl_.mail_.ClearToEmpty();
  _impl_.content_.ClearToEmpty();
  _impl_.fork_.ClearToEmpty();
  ::memset(&_impl_.thread_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&_impl_.score_) -
      reinterpret_cast<char*>(&_impl_.thread_)) + sizeof(_impl_.score_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* NNDComment::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int64 thread = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          _impl_.thread_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int32 no = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          _impl_.no_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int32 vpos = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 24)) {
          _impl_.vpos_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int64 date = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 32)) {
          _impl_.date_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int32 date_usec = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 40)) {
          _impl_.date_usec_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // bool anonymity = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 48)) {
          _impl_.anonymity_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string user_id = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 58)) {
          auto str = _internal_mutable_user_id();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "NNDComment.user_id"));
        } else
          goto handle_unusual;
        continue;
      // string mail = 8;
      case 8:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 66)) {
          auto str = _internal_mutable_mail();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "NNDComment.mail"));
        } else
          goto handle_unusual;
        continue;
      // int32 leaf = 9;
      case 9:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 72)) {
          _impl_.leaf_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // bool premium = 10;
      case 10:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 80)) {
          _impl_.premium_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int32 score = 11;
      case 11:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 88)) {
          _impl_.score_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string content = 12;
      case 12:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 98)) {
          auto str = _internal_mutable_content();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "NNDComment.content"));
        } else
          goto handle_unusual;
        continue;
      // string fork = 15;
      case 15:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 122)) {
          auto str = _internal_mutable_fork();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "NNDComment.fork"));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* NNDComment::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:NNDComment)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // int64 thread = 1;
  if (this->_internal_thread() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt64ToArray(1, this->_internal_thread(), target);
  }

  // int32 no = 2;
  if (this->_internal_no() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(2, this->_internal_no(), target);
  }

  // int32 vpos = 3;
  if (this->_internal_vpos() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(3, this->_internal_vpos(), target);
  }

  // int64 date = 4;
  if (this->_internal_date() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt64ToArray(4, this->_internal_date(), target);
  }

  // int32 date_usec = 5;
  if (this->_internal_date_usec() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(5, this->_internal_date_usec(), target);
  }

  // bool anonymity = 6;
  if (this->_internal_anonymity() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteBoolToArray(6, this->_internal_anonymity(), target);
  }

  // string user_id = 7;
  if (!this->_internal_user_id().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_user_id().data(), static_cast<int>(this->_internal_user_id().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "NNDComment.user_id");
    target = stream->WriteStringMaybeAliased(
        7, this->_internal_user_id(), target);
  }

  // string mail = 8;
  if (!this->_internal_mail().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_mail().data(), static_cast<int>(this->_internal_mail().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "NNDComment.mail");
    target = stream->WriteStringMaybeAliased(
        8, this->_internal_mail(), target);
  }

  // int32 leaf = 9;
  if (this->_internal_leaf() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(9, this->_internal_leaf(), target);
  }

  // bool premium = 10;
  if (this->_internal_premium() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteBoolToArray(10, this->_internal_premium(), target);
  }

  // int32 score = 11;
  if (this->_internal_score() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(11, this->_internal_score(), target);
  }

  // string content = 12;
  if (!this->_internal_content().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_content().data(), static_cast<int>(this->_internal_content().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "NNDComment.content");
    target = stream->WriteStringMaybeAliased(
        12, this->_internal_content(), target);
  }

  // string fork = 15;
  if (!this->_internal_fork().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_fork().data(), static_cast<int>(this->_internal_fork().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "NNDComment.fork");
    target = stream->WriteStringMaybeAliased(
        15, this->_internal_fork(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:NNDComment)
  return target;
}

size_t NNDComment::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:NNDComment)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string user_id = 7;
  if (!this->_internal_user_id().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_user_id());
  }

  // string mail = 8;
  if (!this->_internal_mail().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_mail());
  }

  // string content = 12;
  if (!this->_internal_content().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_content());
  }

  // string fork = 15;
  if (!this->_internal_fork().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_fork());
  }

  // int64 thread = 1;
  if (this->_internal_thread() != 0) {
    total_size += ::_pbi::WireFormatLite::Int64SizePlusOne(this->_internal_thread());
  }

  // int32 no = 2;
  if (this->_internal_no() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_no());
  }

  // int32 vpos = 3;
  if (this->_internal_vpos() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_vpos());
  }

  // int64 date = 4;
  if (this->_internal_date() != 0) {
    total_size += ::_pbi::WireFormatLite::Int64SizePlusOne(this->_internal_date());
  }

  // int32 date_usec = 5;
  if (this->_internal_date_usec() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_date_usec());
  }

  // bool anonymity = 6;
  if (this->_internal_anonymity() != 0) {
    total_size += 1 + 1;
  }

  // bool premium = 10;
  if (this->_internal_premium() != 0) {
    total_size += 1 + 1;
  }

  // int32 leaf = 9;
  if (this->_internal_leaf() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_leaf());
  }

  // int32 score = 11;
  if (this->_internal_score() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_score());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData NNDComment::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    NNDComment::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*NNDComment::GetClassData() const { return &_class_data_; }


void NNDComment::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<NNDComment*>(&to_msg);
  auto& from = static_cast<const NNDComment&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:NNDComment)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_user_id().empty()) {
    _this->_internal_set_user_id(from._internal_user_id());
  }
  if (!from._internal_mail().empty()) {
    _this->_internal_set_mail(from._internal_mail());
  }
  if (!from._internal_content().empty()) {
    _this->_internal_set_content(from._internal_content());
  }
  if (!from._internal_fork().empty()) {
    _this->_internal_set_fork(from._internal_fork());
  }
  if (from._internal_thread() != 0) {
    _this->_internal_set_thread(from._internal_thread());
  }
  if (from._internal_no() != 0) {
    _this->_internal_set_no(from._internal_no());
  }
  if (from._internal_vpos() != 0) {
    _this->_internal_set_vpos(from._internal_vpos());
  }
  if (from._internal_date() != 0) {
    _this->_internal_set_date(from._internal_date());
  }
  if (from._internal_date_usec() != 0) {
    _this->_internal_set_date_usec(from._internal_date_usec());
  }
  if (from._internal_anonymity() != 0) {
    _this->_internal_set_anonymity(from._internal_anonymity());
  }
  if (from._internal_premium() != 0) {
    _this->_internal_set_premium(from._internal_premium());
  }
  if (from._internal_leaf() != 0) {
    _this->_internal_set_leaf(from._internal_leaf());
  }
  if (from._internal_score() != 0) {
    _this->_internal_set_score(from._internal_score());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void NNDComment::CopyFrom(const NNDComment& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:NNDComment)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool NNDComment::IsInitialized() const {
  return true;
}

void NNDComment::InternalSwap(NNDComment* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.user_id_, lhs_arena,
      &other->_impl_.user_id_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.mail_, lhs_arena,
      &other->_impl_.mail_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.content_, lhs_arena,
      &other->_impl_.content_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.fork_, lhs_arena,
      &other->_impl_.fork_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(NNDComment, _impl_.score_)
      + sizeof(NNDComment::_impl_.score_)
      - PROTOBUF_FIELD_OFFSET(NNDComment, _impl_.thread_)>(
          reinterpret_cast<char*>(&_impl_.thread_),
          reinterpret_cast<char*>(&other->_impl_.thread_));
}

::PROTOBUF_NAMESPACE_ID::Metadata NNDComment::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_nndcomment_2eproto_getter, &descriptor_table_nndcomment_2eproto_once,
      file_level_metadata_nndcomment_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::NNDComment*
Arena::CreateMaybeMessage< ::NNDComment >(Arena* arena) {
  return Arena::CreateMessageInternal< ::NNDComment >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
