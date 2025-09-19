#ifndef __SDK_GEPRO_DEFVERZE_H
#define __SDK_GEPRO_DEFVERZE_H
#if defined(DEBUG_PREPROC)
#pragma message(__FILE__ "(1) : debug included")
#endif
#include "preproc.h"
#include "copyright.h"

#define VERMAJORS VERMAJOR
#define VERMINORS VERMINOR
#define VERTEXTS  VERTEXT
#ifndef WKOKES_REVIZE 
  #define WKOKES_REVIZE 0
#endif
#undef HASPVERTXT
#undef VERTEXT
#if HASPVER==1200
  #define HASPVERTXT "SW hasp"
#elif HASPVER==12 || HASPVER==8 || HASPVER==7
  #define HASPVERTXT "HW hasp." DEFINE_QUOTE(HASPVER)
#else 
  #define HASPVERTXT ""
#endif
#define VERTEXT    DEFINE_QUOTE(VERMAJOR) "." DEFINE_QUOTE(VERMINOR) "." DEFINE_QUOTE(REVIZE)
#define GEPRO_PRODUCT_VERSION (VERMAJOR*100+VERMINOR)
#ifndef BUILD_TYPE
  #define _BUILD_TYPE ""
#else
  #define _BUILD_TYPE " " BUILD_TYPE
#endif
#ifndef FILE_NAME
  #define FILE_NAME PRODUCT_NAME
#endif
#ifndef FILE_EXT
  #define FILE_EXT ".DLL"
#endif
#ifndef SVNREVISIONS
  #define SVNREVISIONS "svn://???"
#endif
#ifndef REVIZEHI
  #define REVIZEHI 0
#endif
#ifndef REVIZELO
  #define REVIZELO REVIZE
#endif

#define WXWIDGETS_LICENCE_URL "http://www.wxwidgets.org/about/licence/"
#define APACHE_LICENCE_URL "http://www.apache.org/licenses/LICENSE-2.0"
#define BOOST_LICENCE_URL "http://www.boost.org/users/license.html"

#ifdef WXWIDGETS_LICENCE
  #ifndef PRODUCT_USE_LICENCES
    #define PRODUCT_USE_LICENCES WXWIDGETS_LICENCE_URL
  #endif   
#endif
#ifdef APACHE_LICENCE
  #ifndef PRODUCT_USE_LICENCES
    #define PRODUCT_USE_LICENCES APACHE_LICENCE_URL
  #endif   
#endif
#ifdef BOOST_LICENCE
  #ifndef PRODUCT_USE_LICENCES
    #define PRODUCT_USE_LICENCES BOOST_LICENCE_URL
  #endif   
#endif
#ifdef DEBUG_PREPROC
#pragma message(PREPROC_LINE_QUOTE("BUILD:" DEFINE_QUOTE(VERMAJOR) "." DEFINE_QUOTE(VERMINOR) "." DEFINE_QUOTE(REVIZE) " " BUILD_TYPE " " DEFINE_QUOTE(HASPVER)))
#endif
#endif
