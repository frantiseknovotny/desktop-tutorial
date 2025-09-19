#include "log4cxx.h"
#include "log4c.h"
static LoggerPtr logger=NULL;

extern "C" {
  void log_init(const char* props,const char* lname) {
    if(lname) logger=Logger::getLogger(lname);
    else logger=Logger::getRootLogger();
    if(props) PropertyConfigurator::configure(props);
    else BasicConfigurator::configure();
  }
  void log_level(loglevel l) {
    if(logger) {
      switch(l) {
      case logERROR:
        logger->setLevel(::log4cxx::Level::getError());
        break;
      case logWARN:
        logger->setLevel(::log4cxx::Level::getWarn());
        break;
      case logINFO:
        logger->setLevel(::log4cxx::Level::getInfo());
        break;
      case logDEBUG:
        logger->setLevel(::log4cxx::Level::getDebug());
        break;
      case logTRACE:
        logger->setLevel(::log4cxx::Level::getTrace());
        break;
      }
    }
  }
  void log_error(const char* message,const char* file,unsigned line) {
        if (logger&&logger->isErrorEnabled()) {
           ::log4cxx::helpers::MessageBuffer oss_; 
           logger->forcedLog(::log4cxx::Level::getError(), oss_.str(oss_ << message), ::log4cxx::spi::LocationInfo(file,"",line));
        }
  }
  void log_warn(const char* message,const char* file,unsigned line) {
        if (logger&&logger->isWarnEnabled()) {
           ::log4cxx::helpers::MessageBuffer oss_; 
           logger->forcedLog(::log4cxx::Level::getWarn(), oss_.str(oss_ << message), ::log4cxx::spi::LocationInfo(file,"",line));
        }
  }
  void log_info(const char* message,const char* file,unsigned line) {
        if (logger&&logger->isInfoEnabled()) {
           ::log4cxx::helpers::MessageBuffer oss_; 
           logger->forcedLog(::log4cxx::Level::getInfo(), oss_.str(oss_ << message), ::log4cxx::spi::LocationInfo(file,"",line));
        }
  }
  void log_debug(const char* message,const char* file,unsigned line) {
        if (logger&&logger->isDebugEnabled()) {
           ::log4cxx::helpers::MessageBuffer oss_; 
           logger->forcedLog(::log4cxx::Level::getDebug(), oss_.str(oss_ << message), ::log4cxx::spi::LocationInfo(file,"",line));
        }
  }
  void log_trace(const char* message,const char* file,unsigned line){
        if (logger&&logger->isTraceEnabled()) {
           ::log4cxx::helpers::MessageBuffer oss_; 
           logger->forcedLog(::log4cxx::Level::getTrace(), oss_.str(oss_ << message), ::log4cxx::spi::LocationInfo(file,"",line));
        }
  }
}