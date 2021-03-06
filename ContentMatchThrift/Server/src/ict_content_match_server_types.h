/**
 * Autogenerated by Thrift Compiler (0.8.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef ict_content_match_server_TYPES_H
#define ict_content_match_server_TYPES_H

#include <Thrift.h>
#include <TApplicationException.h>
#include <protocol/TProtocol.h>
#include <transport/TTransport.h>



namespace ContentMatchService {

typedef struct _Match_Result__isset {
  _Match_Result__isset() : type(false), source_start_offset(false), source_length(false), target_start_offset(false), target_length(false) {}
  bool type;
  bool source_start_offset;
  bool source_length;
  bool target_start_offset;
  bool target_length;
} _Match_Result__isset;

class Match_Result {
 public:

  static const char* ascii_fingerprint; // = "2EB010665070FC89CB24AB9DA34D5F9D";
  static const uint8_t binary_fingerprint[16]; // = {0x2E,0xB0,0x10,0x66,0x50,0x70,0xFC,0x89,0xCB,0x24,0xAB,0x9D,0xA3,0x4D,0x5F,0x9D};

  Match_Result() : type(0), source_start_offset(0), source_length(0), target_start_offset(0), target_length(0) {
  }

  virtual ~Match_Result() throw() {}

  int32_t type;
  int32_t source_start_offset;
  int32_t source_length;
  int32_t target_start_offset;
  int32_t target_length;

  _Match_Result__isset __isset;

  void __set_type(const int32_t val) {
    type = val;
  }

  void __set_source_start_offset(const int32_t val) {
    source_start_offset = val;
  }

  void __set_source_length(const int32_t val) {
    source_length = val;
  }

  void __set_target_start_offset(const int32_t val) {
    target_start_offset = val;
  }

  void __set_target_length(const int32_t val) {
    target_length = val;
  }

  bool operator == (const Match_Result & rhs) const
  {
    if (!(type == rhs.type))
      return false;
    if (!(source_start_offset == rhs.source_start_offset))
      return false;
    if (!(source_length == rhs.source_length))
      return false;
    if (!(target_start_offset == rhs.target_start_offset))
      return false;
    if (!(target_length == rhs.target_length))
      return false;
    return true;
  }
  bool operator != (const Match_Result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Match_Result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Batch_Result_Info__isset {
  _Batch_Result_Info__isset() : status(false), result_info_list(false) {}
  bool status;
  bool result_info_list;
} _Batch_Result_Info__isset;

class Batch_Result_Info {
 public:

  static const char* ascii_fingerprint; // = "DA8376474548CEFDC60819CB964E5633";
  static const uint8_t binary_fingerprint[16]; // = {0xDA,0x83,0x76,0x47,0x45,0x48,0xCE,0xFD,0xC6,0x08,0x19,0xCB,0x96,0x4E,0x56,0x33};

  Batch_Result_Info() : status(0) {
  }

  virtual ~Batch_Result_Info() throw() {}

  int32_t status;
  std::vector<Match_Result>  result_info_list;

  _Batch_Result_Info__isset __isset;

  void __set_status(const int32_t val) {
    status = val;
  }

  void __set_result_info_list(const std::vector<Match_Result> & val) {
    result_info_list = val;
  }

  bool operator == (const Batch_Result_Info & rhs) const
  {
    if (!(status == rhs.status))
      return false;
    if (!(result_info_list == rhs.result_info_list))
      return false;
    return true;
  }
  bool operator != (const Batch_Result_Info &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Batch_Result_Info & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

} // namespace

#endif

