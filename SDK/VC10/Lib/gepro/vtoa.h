#ifndef __SDK_GEPRO_VTOA_H
#define __SDK_GEPRO_VTOA_H
#if defined(DEBUG_PREPROC)
#pragma message(__FILE__ "(1) : debug included")
#endif
#include<gepro/string.h>
namespace cz {
namespace gepro {
namespace vtoa {
namespace simple {
#if _MSC_VER >= 1600
// jednoduche konverze hodnota -> string
inline size_t vtoa(char* buf, size_t bufsize, int value) {
  if (bufsize >= 16) {
    _itoa_s(value, buf, bufsize, 10);
    return strlen(buf);
  }
  return 0;
}
inline size_t vtoa(char* buf, size_t bufsize, unsigned int value) {
  if (bufsize >= 16) {
    _ultoa_s(value, buf, bufsize, 10);
    return strlen(buf);
  }
  return 0;
}
inline size_t vtoa(char* buf, size_t bufsize, long value) {
  if (bufsize >= 16) {
    _ltoa_s(value, buf, bufsize, 10);
    return strlen(buf);
  }
  return 0;
}
inline size_t vtoa(char* buf, size_t bufsize, unsigned long value) {
  if (bufsize >= 16) {
    _ultoa_s(value, buf, bufsize, 10);
    return strlen(buf);
  }
  return 0;
}
inline size_t vtoa(char* buf, size_t bufsize, __int64 value) {
  if (bufsize >= 16) {
    _i64toa_s(value, buf, bufsize, 10);
    return strlen(buf);
  }
  return 0;
}
inline size_t vtoa(char* buf, size_t bufsize, unsigned __int64 value) {
  if (bufsize >= 16) {
    _ui64toa_s(value, buf, bufsize, 10);
    return strlen(buf);
  }
  return 0;
}
inline size_t vtoa(char* buf, size_t bufsize, const void* value) {
  if (bufsize >= 16) { return _snprintf_s(buf, bufsize, bufsize - 1, "%p", value); }
  return 0;
}
inline size_t vtoa(char* buf, size_t bufsize, HWND value) { return vtoa(buf, bufsize, (const void*)value); }
inline size_t vtoa(char* buf, size_t bufsize, HDC value) { return vtoa(buf, bufsize, (const void*)value); }
inline size_t vtoa(char* buf, size_t bufsize, HPEN value) { return vtoa(buf, bufsize, (const void*)value); }
inline size_t vtoa(char* buf, size_t bufsize, HANDLE value) { return vtoa(buf, bufsize, (const void*)value); }

inline size_t vtoa(char* buf, size_t bufsize, const char* value) {
  if (bufsize < 2) return 0;
  if (!value) value = "[null]";
  size_t l = strlen(value);
  if (l >= bufsize - 1) l = bufsize - 1;
  sdk::gepro::memcpy(buf, value, l);
  buf[l] = '\0';
  return l;
}
inline size_t vtoa(char* buf, size_t bufsize, const char* value, size_t lvalue) {
  if (bufsize < 2) return 0;
  if (!value) value = "[null]";
  size_t l = lvalue;
  if (l >= bufsize - 1) l = bufsize - 1;
  sdk::gepro::memcpy(buf, value, l);
  buf[l] = '\0';
  return l;
}
inline size_t vtoa(char* buf, size_t bufsize, const unsigned char* value) { return vtoa(buf, bufsize, (const char*)value); }
inline size_t vtoa(char* buf, size_t bufsize, const wchar_t* value) {
  if (bufsize < 2) return 0;
  if (!value) value = L"[null]";
  size_t l = wcslen(value);
  if (l >= bufsize) l = bufsize - 1;
  WideCharToMultiByte(CP_ACP, 0, value, (int)l, buf, (int)bufsize - 1, NULL, NULL);
  buf[l] = 0;
  return l;
}
inline size_t vtoa(char* buf, size_t bufsize, double value) {
  if (bufsize >= 80) {
    _gcvt_s(buf, bufsize, value, 15);
    return strlen(buf);
  }
  return 0;
}
inline size_t vtoa(char* buf, size_t bufsize, double value, int dec) {
  if (bufsize >= 80) {
    _gcvt_s(buf, bufsize, value, dec);
    return strlen(buf);
  }
  return 0;
}
inline size_t vtoa(char* buf, size_t bufsize, float value) { return vtoa(buf, bufsize, (double)value); }

inline size_t vtoa(char* buf, size_t bufsize, POINT& value) {
  if (bufsize >= 32) { return _snprintf_s(buf, bufsize, bufsize - 1, "{%d,%d}", value.x, value.y); }
  return 0;
}
inline size_t vtoa(char* buf, size_t bufsize, POINTL& value) {
  if (bufsize >= 32) { return _snprintf_s(buf, bufsize, bufsize - 1, "{%d,%d}", value.x, value.y); }
  return 0;
}
inline size_t vtoa(char* buf, size_t bufsize, RECT& value) {
  if (bufsize >= 64) { return _snprintf_s(buf, bufsize, bufsize - 1, "{%d,%d,%d,%d}", value.left, value.top, value.right, value.bottom); }
  return 0;
}
#else
// jednoduche konverze hodnota -> string
inline int vtoa(char* buf, unsigned bufsize, const char* value) {
  if (!value) value = "[null]";
  unsigned l = strlen(value);
  if (l >= bufsize - 1) l = bufsize - 1;
  sdk::gepro::memcpy(buf, value, l);
  buf[l] = '\0';
  return l;
}
inline int vtoa(char* buf, unsigned bufsize, const unsigned char* value) { return vtoa(buf, bufsize, (const char*)value); }
inline int vtoa(char* buf, unsigned bufsize, const void* value) {
  if (bufsize >= 16) { return _snprintf(buf, bufsize, "%p", value); }
  return 0;
}
inline int vtoa(char* buf, unsigned bufsize, double value) {
  if (bufsize >= 80) {
    _gcvt(value, 15, buf);
    return strlen(buf);
  }
  return 0;
}
inline int vtoa(char* buf, unsigned bufsize, double value, int dec) {
  if (bufsize >= 80) {
    _gcvt(value, dec, buf);
    return strlen(buf);
  }
  return 0;
}
inline int vtoa(char* buf, unsigned bufsize, float value) { return vtoa(buf, bufsize, (double)value); }

inline int vtoa(char* buf, unsigned bufsize, POINT& value) {
  if (bufsize >= 32) { return _snprintf(buf, bufsize, "{%d,%d}", value.x, value.y); }
  return 0;
}
inline int vtoa(char* buf, unsigned bufsize, POINTL& value) {
  if (bufsize >= 32) { return _snprintf(buf, bufsize, "{%d,%d}", value.x, value.y); }
  return 0;
}
inline int vtoa(char* buf, unsigned bufsize, RECT& value) {
  if (bufsize >= 64) { return _snprintf(buf, bufsize, "{%d,%d-%d,%d}", value.left, value.top, value.right, value.bottom); }
  return 0;
}
#endif
};  // namespace simple
};  // namespace vtoa
};  // namespace gepro
};  // namespace cz

#endif
