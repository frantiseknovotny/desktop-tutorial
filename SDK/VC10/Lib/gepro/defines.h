#ifndef   ___SDK_GEPRO_DEFINES_H
#define   ___SDK_GEPRO_DEFINES_H
#if defined(DEBUG_PREPROC)
  #pragma message(__FILE__ "(1) : debug included")
#endif
#ifdef _MSC_VER
  #define MSVC
#endif

#ifdef  MSVC
  #define MAXPATH   _MAX_PATH
  #define MAXDIR    _MAX_DIR 
  #define MAXFILE   _MAX_FNAME
  #define MAXEXT    _MAX_EXT
  #define MAXDRIVE  _MAX_DRIVE

  #define MAXDOUBLE DBL_MAX
  #define MAXFLOAT  FLT_MAX
#ifndef MAXINT
  #define MAXINT    INT_MAX
#endif
#ifndef MAXLONG
  #define MAXLONG   LONG_MAX
#endif
#ifndef LONGLONG
  #define LONGLONG   long long
#endif

#endif

#endif
