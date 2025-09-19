#ifndef __LOG4WX_H
#define __LOG4WX_H
#if defined(DEBUG_PREPROC)
#pragma message(__FILE__ "(1) : debug included")
#endif
#ifndef LOGGER_COMPILE_LEVEL
#define LOGGER_COMPILE_LEVEL 2
#endif
#include <log4cxx2.h>

inline CharMessageBuffer& operator<<(CharMessageBuffer& oss,const wxString& p) {
  oss << (const char*)p;
  return oss;
}


#endif