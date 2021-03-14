// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: PointObjectFormat.proto

#include "PointObjectFormat.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)
class PointObjectFormatDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<PointObjectFormat>
      _instance;
} _PointObjectFormat_default_instance_;
namespace protobuf_PointObjectFormat_2eproto {
void InitDefaultsPointObjectFormatImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  protobuf_BaseType_2eproto::InitDefaultsPoint();
  protobuf_BaseType_2eproto::InitDefaultsColor();
  ::PointObjectFormat::_default_name_.DefaultConstruct();
  *::PointObjectFormat::_default_name_.get_mutable() = ::std::string("Feature Point", 13);
  ::google::protobuf::internal::OnShutdownDestroyString(
      ::PointObjectFormat::_default_name_.get_mutable());
  {
    void* ptr = &::_PointObjectFormat_default_instance_;
    new (ptr) ::PointObjectFormat();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::PointObjectFormat::InitAsDefaultInstance();
}

void InitDefaultsPointObjectFormat() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsPointObjectFormatImpl);
}

::google::protobuf::Metadata file_level_metadata[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::PointObjectFormat, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::PointObjectFormat, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::PointObjectFormat, type_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::PointObjectFormat, name_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::PointObjectFormat, id_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::PointObjectFormat, pos_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::PointObjectFormat, color_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::PointObjectFormat, size_),
  3,
  0,
  1,
  ~0u,
  ~0u,
  2,
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 11, sizeof(::PointObjectFormat)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::_PointObjectFormat_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "PointObjectFormat.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\027PointObjectFormat.proto\032\016BaseType.prot"
      "o\"\255\001\n\021PointObjectFormat\0225\n\004type\030\001 \002(\0162\017."
      "TP_OBJECT_TYPE:\026TP_OBJECT_TYPE_D_POINT\022\033"
      "\n\004name\030\003 \002(\t:\rFeature Point\022\n\n\002id\030\004 \002(\005\022"
      "\023\n\003pos\030\006 \003(\0132\006.Point\022\025\n\005color\030\007 \003(\0132\006.Co"
      "lor\022\014\n\004size\030\010 \002(\005"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 217);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "PointObjectFormat.proto", &protobuf_RegisterTypes);
  ::protobuf_BaseType_2eproto::AddDescriptors();
}

void AddDescriptors() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_PointObjectFormat_2eproto

// ===================================================================

void PointObjectFormat::InitAsDefaultInstance() {
}
::google::protobuf::internal::ExplicitlyConstructed< ::std::string> PointObjectFormat::_default_name_;
void PointObjectFormat::clear_pos() {
  pos_.Clear();
}
void PointObjectFormat::clear_color() {
  color_.Clear();
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int PointObjectFormat::kTypeFieldNumber;
const int PointObjectFormat::kNameFieldNumber;
const int PointObjectFormat::kIdFieldNumber;
const int PointObjectFormat::kPosFieldNumber;
const int PointObjectFormat::kColorFieldNumber;
const int PointObjectFormat::kSizeFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

PointObjectFormat::PointObjectFormat()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_PointObjectFormat_2eproto::InitDefaultsPointObjectFormat();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:PointObjectFormat)
}
PointObjectFormat::PointObjectFormat(const PointObjectFormat& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      _cached_size_(0),
      pos_(from.pos_),
      color_(from.color_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  name_.UnsafeSetDefault(&::PointObjectFormat::_default_name_.get());
  if (from.has_name()) {
    name_.AssignWithDefault(&::PointObjectFormat::_default_name_.get(), from.name_);
  }
  ::memcpy(&id_, &from.id_,
    static_cast<size_t>(reinterpret_cast<char*>(&type_) -
    reinterpret_cast<char*>(&id_)) + sizeof(type_));
  // @@protoc_insertion_point(copy_constructor:PointObjectFormat)
}

void PointObjectFormat::SharedCtor() {
  _cached_size_ = 0;
  name_.UnsafeSetDefault(&::PointObjectFormat::_default_name_.get());
  ::memset(&id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&size_) -
      reinterpret_cast<char*>(&id_)) + sizeof(size_));
  type_ = 13;
}

PointObjectFormat::~PointObjectFormat() {
  // @@protoc_insertion_point(destructor:PointObjectFormat)
  SharedDtor();
}

void PointObjectFormat::SharedDtor() {
  name_.DestroyNoArena(&::PointObjectFormat::_default_name_.get());
}

void PointObjectFormat::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* PointObjectFormat::descriptor() {
  ::protobuf_PointObjectFormat_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_PointObjectFormat_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const PointObjectFormat& PointObjectFormat::default_instance() {
  ::protobuf_PointObjectFormat_2eproto::InitDefaultsPointObjectFormat();
  return *internal_default_instance();
}

PointObjectFormat* PointObjectFormat::New(::google::protobuf::Arena* arena) const {
  PointObjectFormat* n = new PointObjectFormat;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void PointObjectFormat::Clear() {
// @@protoc_insertion_point(message_clear_start:PointObjectFormat)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  pos_.Clear();
  color_.Clear();
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    GOOGLE_DCHECK(!name_.IsDefault(&::PointObjectFormat::_default_name_.get()));
    (*name_.UnsafeRawStringPointer())->assign(*&::PointObjectFormat::_default_name_.get());
  }
  if (cached_has_bits & 14u) {
    ::memset(&id_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&size_) -
        reinterpret_cast<char*>(&id_)) + sizeof(size_));
    type_ = 13;
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool PointObjectFormat::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:PointObjectFormat)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .TP_OBJECT_TYPE type = 1 [default = TP_OBJECT_TYPE_D_POINT];
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::TP_OBJECT_TYPE_IsValid(value)) {
            set_type(static_cast< ::TP_OBJECT_TYPE >(value));
          } else {
            mutable_unknown_fields()->AddVarint(
                1, static_cast< ::google::protobuf::uint64>(value));
          }
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required string name = 3 [default = "Feature Point"];
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(26u /* 26 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->name().data(), static_cast<int>(this->name().length()),
            ::google::protobuf::internal::WireFormat::PARSE,
            "PointObjectFormat.name");
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required int32 id = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(32u /* 32 & 0xFF */)) {
          set_has_id();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &id_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated .Point pos = 6;
      case 6: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(50u /* 50 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(input, add_pos()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated .Color color = 7;
      case 7: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(58u /* 58 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(input, add_color()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required int32 size = 8;
      case 8: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(64u /* 64 & 0xFF */)) {
          set_has_size();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &size_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:PointObjectFormat)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:PointObjectFormat)
  return false;
#undef DO_
}

void PointObjectFormat::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:PointObjectFormat)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required .TP_OBJECT_TYPE type = 1 [default = TP_OBJECT_TYPE_D_POINT];
  if (cached_has_bits & 0x00000008u) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->type(), output);
  }

  // required string name = 3 [default = "Feature Point"];
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->name().data(), static_cast<int>(this->name().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "PointObjectFormat.name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->name(), output);
  }

  // required int32 id = 4;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(4, this->id(), output);
  }

  // repeated .Point pos = 6;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->pos_size()); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      6, this->pos(static_cast<int>(i)), output);
  }

  // repeated .Color color = 7;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->color_size()); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      7, this->color(static_cast<int>(i)), output);
  }

  // required int32 size = 8;
  if (cached_has_bits & 0x00000004u) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(8, this->size(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:PointObjectFormat)
}

::google::protobuf::uint8* PointObjectFormat::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:PointObjectFormat)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required .TP_OBJECT_TYPE type = 1 [default = TP_OBJECT_TYPE_D_POINT];
  if (cached_has_bits & 0x00000008u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->type(), target);
  }

  // required string name = 3 [default = "Feature Point"];
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->name().data(), static_cast<int>(this->name().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "PointObjectFormat.name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->name(), target);
  }

  // required int32 id = 4;
  if (cached_has_bits & 0x00000002u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, this->id(), target);
  }

  // repeated .Point pos = 6;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->pos_size()); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        6, this->pos(static_cast<int>(i)), deterministic, target);
  }

  // repeated .Color color = 7;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->color_size()); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        7, this->color(static_cast<int>(i)), deterministic, target);
  }

  // required int32 size = 8;
  if (cached_has_bits & 0x00000004u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(8, this->size(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:PointObjectFormat)
  return target;
}

size_t PointObjectFormat::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:PointObjectFormat)
  size_t total_size = 0;

  if (has_name()) {
    // required string name = 3 [default = "Feature Point"];
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->name());
  }

  if (has_id()) {
    // required int32 id = 4;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->id());
  }

  if (has_size()) {
    // required int32 size = 8;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->size());
  }

  if (has_type()) {
    // required .TP_OBJECT_TYPE type = 1 [default = TP_OBJECT_TYPE_D_POINT];
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->type());
  }

  return total_size;
}
size_t PointObjectFormat::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:PointObjectFormat)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  if (((_has_bits_[0] & 0x0000000f) ^ 0x0000000f) == 0) {  // All required fields are present.
    // required string name = 3 [default = "Feature Point"];
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->name());

    // required int32 id = 4;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->id());

    // required int32 size = 8;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->size());

    // required .TP_OBJECT_TYPE type = 1 [default = TP_OBJECT_TYPE_D_POINT];
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->type());

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  // repeated .Point pos = 6;
  {
    unsigned int count = static_cast<unsigned int>(this->pos_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          this->pos(static_cast<int>(i)));
    }
  }

  // repeated .Color color = 7;
  {
    unsigned int count = static_cast<unsigned int>(this->color_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          this->color(static_cast<int>(i)));
    }
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void PointObjectFormat::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:PointObjectFormat)
  GOOGLE_DCHECK_NE(&from, this);
  const PointObjectFormat* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const PointObjectFormat>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:PointObjectFormat)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:PointObjectFormat)
    MergeFrom(*source);
  }
}

void PointObjectFormat::MergeFrom(const PointObjectFormat& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:PointObjectFormat)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  pos_.MergeFrom(from.pos_);
  color_.MergeFrom(from.color_);
  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 15u) {
    if (cached_has_bits & 0x00000001u) {
      set_has_name();
      name_.AssignWithDefault(&::PointObjectFormat::_default_name_.get(), from.name_);
    }
    if (cached_has_bits & 0x00000002u) {
      id_ = from.id_;
    }
    if (cached_has_bits & 0x00000004u) {
      size_ = from.size_;
    }
    if (cached_has_bits & 0x00000008u) {
      type_ = from.type_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void PointObjectFormat::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:PointObjectFormat)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void PointObjectFormat::CopyFrom(const PointObjectFormat& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:PointObjectFormat)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PointObjectFormat::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000000f) != 0x0000000f) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->pos())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->color())) return false;
  return true;
}

void PointObjectFormat::Swap(PointObjectFormat* other) {
  if (other == this) return;
  InternalSwap(other);
}
void PointObjectFormat::InternalSwap(PointObjectFormat* other) {
  using std::swap;
  pos_.InternalSwap(&other->pos_);
  color_.InternalSwap(&other->color_);
  name_.Swap(&other->name_);
  swap(id_, other->id_);
  swap(size_, other->size_);
  swap(type_, other->type_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata PointObjectFormat::GetMetadata() const {
  protobuf_PointObjectFormat_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_PointObjectFormat_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
