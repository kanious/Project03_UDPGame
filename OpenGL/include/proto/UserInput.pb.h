// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: UserInput.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_UserInput_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_UserInput_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3018000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3018001 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_UserInput_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_UserInput_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_UserInput_2eproto;
class UserInput;
struct UserInputDefaultTypeInternal;
extern UserInputDefaultTypeInternal _UserInput_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::UserInput* Arena::CreateMaybeMessage<::UserInput>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class UserInput final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:UserInput) */ {
 public:
  inline UserInput() : UserInput(nullptr) {}
  ~UserInput() override;
  explicit constexpr UserInput(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  UserInput(const UserInput& from);
  UserInput(UserInput&& from) noexcept
    : UserInput() {
    *this = ::std::move(from);
  }

  inline UserInput& operator=(const UserInput& from) {
    CopyFrom(from);
    return *this;
  }
  inline UserInput& operator=(UserInput&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const UserInput& default_instance() {
    return *internal_default_instance();
  }
  static inline const UserInput* internal_default_instance() {
    return reinterpret_cast<const UserInput*>(
               &_UserInput_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(UserInput& a, UserInput& b) {
    a.Swap(&b);
  }
  inline void Swap(UserInput* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(UserInput* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline UserInput* New() const final {
    return new UserInput();
  }

  UserInput* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<UserInput>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const UserInput& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const UserInput& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(UserInput* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "UserInput";
  }
  protected:
  explicit UserInput(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kMessageIdFieldNumber = 1,
    kInputFieldNumber = 2,
    kTickNumberFieldNumber = 3,
  };
  // required int32 messageId = 1;
  bool has_messageid() const;
  private:
  bool _internal_has_messageid() const;
  public:
  void clear_messageid();
  ::PROTOBUF_NAMESPACE_ID::int32 messageid() const;
  void set_messageid(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_messageid() const;
  void _internal_set_messageid(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // required int32 input = 2;
  bool has_input() const;
  private:
  bool _internal_has_input() const;
  public:
  void clear_input();
  ::PROTOBUF_NAMESPACE_ID::int32 input() const;
  void set_input(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_input() const;
  void _internal_set_input(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // required int64 tick_number = 3;
  bool has_tick_number() const;
  private:
  bool _internal_has_tick_number() const;
  public:
  void clear_tick_number();
  ::PROTOBUF_NAMESPACE_ID::int64 tick_number() const;
  void set_tick_number(::PROTOBUF_NAMESPACE_ID::int64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int64 _internal_tick_number() const;
  void _internal_set_tick_number(::PROTOBUF_NAMESPACE_ID::int64 value);
  public:

  // @@protoc_insertion_point(class_scope:UserInput)
 private:
  class _Internal;

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::int32 messageid_;
  ::PROTOBUF_NAMESPACE_ID::int32 input_;
  ::PROTOBUF_NAMESPACE_ID::int64 tick_number_;
  friend struct ::TableStruct_UserInput_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// UserInput

// required int32 messageId = 1;
inline bool UserInput::_internal_has_messageid() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool UserInput::has_messageid() const {
  return _internal_has_messageid();
}
inline void UserInput::clear_messageid() {
  messageid_ = 0;
  _has_bits_[0] &= ~0x00000001u;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 UserInput::_internal_messageid() const {
  return messageid_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 UserInput::messageid() const {
  // @@protoc_insertion_point(field_get:UserInput.messageId)
  return _internal_messageid();
}
inline void UserInput::_internal_set_messageid(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _has_bits_[0] |= 0x00000001u;
  messageid_ = value;
}
inline void UserInput::set_messageid(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_messageid(value);
  // @@protoc_insertion_point(field_set:UserInput.messageId)
}

// required int32 input = 2;
inline bool UserInput::_internal_has_input() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool UserInput::has_input() const {
  return _internal_has_input();
}
inline void UserInput::clear_input() {
  input_ = 0;
  _has_bits_[0] &= ~0x00000002u;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 UserInput::_internal_input() const {
  return input_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 UserInput::input() const {
  // @@protoc_insertion_point(field_get:UserInput.input)
  return _internal_input();
}
inline void UserInput::_internal_set_input(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _has_bits_[0] |= 0x00000002u;
  input_ = value;
}
inline void UserInput::set_input(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_input(value);
  // @@protoc_insertion_point(field_set:UserInput.input)
}

// required int64 tick_number = 3;
inline bool UserInput::_internal_has_tick_number() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool UserInput::has_tick_number() const {
  return _internal_has_tick_number();
}
inline void UserInput::clear_tick_number() {
  tick_number_ = int64_t{0};
  _has_bits_[0] &= ~0x00000004u;
}
inline ::PROTOBUF_NAMESPACE_ID::int64 UserInput::_internal_tick_number() const {
  return tick_number_;
}
inline ::PROTOBUF_NAMESPACE_ID::int64 UserInput::tick_number() const {
  // @@protoc_insertion_point(field_get:UserInput.tick_number)
  return _internal_tick_number();
}
inline void UserInput::_internal_set_tick_number(::PROTOBUF_NAMESPACE_ID::int64 value) {
  _has_bits_[0] |= 0x00000004u;
  tick_number_ = value;
}
inline void UserInput::set_tick_number(::PROTOBUF_NAMESPACE_ID::int64 value) {
  _internal_set_tick_number(value);
  // @@protoc_insertion_point(field_set:UserInput.tick_number)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_UserInput_2eproto
