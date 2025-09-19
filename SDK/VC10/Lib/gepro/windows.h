#ifndef ___GEPRO_WINDOWS_H
#define ___GEPRO_WINDOWS_H
#if defined(DEBUG_PREPROC)
#pragma message(__FILE__ "(1) : debug included")
#endif

#if _MSC_VER > 1000
#pragma once
#endif

#ifndef _WINDOWS_
#pragma warning(disable : 4201 4786)  // nonstandard extension used : nameless struct/union
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0500
#endif
#ifdef _M_X64
#define _USE_MATH_DEFINES 1
#endif
#include <windows.h>
#include <malloc.h>
#include <stdio.h>
#include "defines.h"
#ifdef _M_X64
#undef min
#undef max
#endif
#endif

#endif
