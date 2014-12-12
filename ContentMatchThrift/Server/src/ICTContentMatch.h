/**
 * Autogenerated by Thrift Compiler (0.8.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef ICTContentMatch_H
#define ICTContentMatch_H

#include <TProcessor.h>
#include "ict_content_match_server_types.h"

namespace ContentMatchService {

class ICTContentMatchIf {
 public:
  virtual ~ICTContentMatchIf() {}
  virtual void GetDiff(Batch_Result_Info& _return, const std::string& content_source, const std::string& content_target) = 0;
};

class ICTContentMatchIfFactory {
 public:
  typedef ICTContentMatchIf Handler;

  virtual ~ICTContentMatchIfFactory() {}

  virtual ICTContentMatchIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(ICTContentMatchIf* /* handler */) = 0;
};

class ICTContentMatchIfSingletonFactory : virtual public ICTContentMatchIfFactory {
 public:
  ICTContentMatchIfSingletonFactory(const boost::shared_ptr<ICTContentMatchIf>& iface) : iface_(iface) {}
  virtual ~ICTContentMatchIfSingletonFactory() {}

  virtual ICTContentMatchIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(ICTContentMatchIf* /* handler */) {}

 protected:
  boost::shared_ptr<ICTContentMatchIf> iface_;
};

class ICTContentMatchNull : virtual public ICTContentMatchIf {
 public:
  virtual ~ICTContentMatchNull() {}
  void GetDiff(Batch_Result_Info& /* _return */, const std::string& /* content_source */, const std::string& /* content_target */) {
    return;
  }
};

typedef struct _ICTContentMatch_GetDiff_args__isset {
  _ICTContentMatch_GetDiff_args__isset() : content_source(false), content_target(false) {}
  bool content_source;
  bool content_target;
} _ICTContentMatch_GetDiff_args__isset;

class ICTContentMatch_GetDiff_args {
 public:

  ICTContentMatch_GetDiff_args() : content_source(""), content_target("") {
  }

  virtual ~ICTContentMatch_GetDiff_args() throw() {}

  std::string content_source;
  std::string content_target;

  _ICTContentMatch_GetDiff_args__isset __isset;

  void __set_content_source(const std::string& val) {
    content_source = val;
  }

  void __set_content_target(const std::string& val) {
    content_target = val;
  }

  bool operator == (const ICTContentMatch_GetDiff_args & rhs) const
  {
    if (!(content_source == rhs.content_source))
      return false;
    if (!(content_target == rhs.content_target))
      return false;
    return true;
  }
  bool operator != (const ICTContentMatch_GetDiff_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ICTContentMatch_GetDiff_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ICTContentMatch_GetDiff_pargs {
 public:


  virtual ~ICTContentMatch_GetDiff_pargs() throw() {}

  const std::string* content_source;
  const std::string* content_target;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ICTContentMatch_GetDiff_result__isset {
  _ICTContentMatch_GetDiff_result__isset() : success(false) {}
  bool success;
} _ICTContentMatch_GetDiff_result__isset;

class ICTContentMatch_GetDiff_result {
 public:

  ICTContentMatch_GetDiff_result() {
  }

  virtual ~ICTContentMatch_GetDiff_result() throw() {}

  Batch_Result_Info success;

  _ICTContentMatch_GetDiff_result__isset __isset;

  void __set_success(const Batch_Result_Info& val) {
    success = val;
  }

  bool operator == (const ICTContentMatch_GetDiff_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const ICTContentMatch_GetDiff_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ICTContentMatch_GetDiff_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ICTContentMatch_GetDiff_presult__isset {
  _ICTContentMatch_GetDiff_presult__isset() : success(false) {}
  bool success;
} _ICTContentMatch_GetDiff_presult__isset;

class ICTContentMatch_GetDiff_presult {
 public:


  virtual ~ICTContentMatch_GetDiff_presult() throw() {}

  Batch_Result_Info* success;

  _ICTContentMatch_GetDiff_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class ICTContentMatchClient : virtual public ICTContentMatchIf {
 public:
  ICTContentMatchClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  ICTContentMatchClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    piprot_(iprot),
    poprot_(oprot) {
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void GetDiff(Batch_Result_Info& _return, const std::string& content_source, const std::string& content_target);
  void send_GetDiff(const std::string& content_source, const std::string& content_target);
  void recv_GetDiff(Batch_Result_Info& _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class ICTContentMatchProcessor : public ::apache::thrift::TProcessor {
 protected:
  boost::shared_ptr<ICTContentMatchIf> iface_;
  virtual bool process_fn(apache::thrift::protocol::TProtocol* iprot, apache::thrift::protocol::TProtocol* oprot, std::string& fname, int32_t seqid, void* callContext);
 private:
  std::map<std::string, void (ICTContentMatchProcessor::*)(int32_t, apache::thrift::protocol::TProtocol*, apache::thrift::protocol::TProtocol*, void*)> processMap_;
  void process_GetDiff(int32_t seqid, apache::thrift::protocol::TProtocol* iprot, apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  ICTContentMatchProcessor(boost::shared_ptr<ICTContentMatchIf> iface) :
    iface_(iface) {
    processMap_["GetDiff"] = &ICTContentMatchProcessor::process_GetDiff;
  }

  virtual bool process(boost::shared_ptr<apache::thrift::protocol::TProtocol> piprot, boost::shared_ptr<apache::thrift::protocol::TProtocol> poprot, void* callContext);
  virtual ~ICTContentMatchProcessor() {}
};

class ICTContentMatchProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  ICTContentMatchProcessorFactory(const ::boost::shared_ptr< ICTContentMatchIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< ICTContentMatchIfFactory > handlerFactory_;
};

class ICTContentMatchMultiface : virtual public ICTContentMatchIf {
 public:
  ICTContentMatchMultiface(std::vector<boost::shared_ptr<ICTContentMatchIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~ICTContentMatchMultiface() {}
 protected:
  std::vector<boost::shared_ptr<ICTContentMatchIf> > ifaces_;
  ICTContentMatchMultiface() {}
  void add(boost::shared_ptr<ICTContentMatchIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void GetDiff(Batch_Result_Info& _return, const std::string& content_source, const std::string& content_target) {
    size_t sz = ifaces_.size();
    for (size_t i = 0; i < sz; ++i) {
      if (i == sz - 1) {
        ifaces_[i]->GetDiff(_return, content_source, content_target);
        return;
      } else {
        ifaces_[i]->GetDiff(_return, content_source, content_target);
      }
    }
  }

};

} // namespace

#endif

