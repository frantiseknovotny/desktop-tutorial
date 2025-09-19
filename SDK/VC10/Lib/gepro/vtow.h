#ifndef __SDK_GEPRO_VTOW_H
#define __SDK_GEPRO_VTOW_H
#if defined(DEBUG_PREPROC)
#pragma message(__FILE__ "(1) : debug included")
#endif
namespace cz {
namespace gepro {
namespace vtoa {
namespace simple {
#if _MSC_VER >= 1600
inline size_t vtoa(wchar_t* buf, size_t bufsize, int value) {
  if (bufsize >= 16) {
    _ltow_s(value, buf, bufsize, 10);
    return wcslen(buf);
  }
  return 0;
}
inline size_t vtoa(wchar_t* buf, size_t bufsize, unsigned int value) {
  if (bufsize >= 16) {
    _ultow_s(value, buf, bufsize, 10);
    return wcslen(buf);
  }
  return 0;
}
inline size_t vtoa(wchar_t* buf, size_t bufsize, long value) {
  if (bufsize >= 16) {
    _ltow_s(value, buf, bufsize, 10);
    return wcslen(buf);
  }
  return 0;
}
inline size_t vtoa(wchar_t* buf, size_t bufsize, unsigned long value) {
  if (bufsize >= 16) {
    _ultow_s(value, buf, bufsize, 10);
    return wcslen(buf);
  }
  return 0;
}
inline size_t vtoa(wchar_t* buf, size_t bufsize, __int64 value) {
  if (bufsize >= 16) {
    _i64tow_s(value, buf, bufsize, 10);
    return wcslen(buf);
  }
  return 0;
}
inline size_t vtoa(wchar_t* buf, size_t bufsize, unsigned __int64 value) {
  if (bufsize >= 16) {
    _ui64tow_s(value, buf, bufsize, 10);
    return wcslen(buf);
  }
  return 0;
}
inline size_t vtoa(wchar_t* buf, size_t bufsize, const void* value) {
  if (bufsize >= 16) { return _snwprintf_s(buf, bufsize, bufsize, L"%p", value); }
  return 0;
}
inline size_t vtoa(wchar_t* buf, size_t bufsize, HWND value) { return vtoa(buf, bufsize, (const void*)value); }
inline size_t vtoa(wchar_t* buf, size_t bufsize, HDC value) { return vtoa(buf, bufsize, (const void*)value); }
inline size_t vtoa(wchar_t* buf, size_t bufsize, HPEN value) { return vtoa(buf, bufsize, (const void*)value); }
inline size_t vtoa(wchar_t* buf, size_t bufsize, HANDLE value) { return vtoa(buf, bufsize, (const void*)value); }
inline size_t vtoa(wchar_t* buf, size_t bufsize, const wchar_t* value) {
  if (!value) value = L"[null]";
  size_t l = wcslen(value);
  if (l >= bufsize - 1) l = bufsize - 1;
  sdk::gepro::memcpy(buf, value, l);
  buf[l] = 0;
  return l;
}
inline size_t vtoa(wchar_t* buf, size_t bufsize, double value) {
  char tmp[80];
  size_t l = vtoa(tmp, sizeof(tmp), value);
  size_t lw = MultiByteToWideChar(CP_ACP, 0, tmp, (int)l, buf, (int)bufsize);
  if (lw >= bufsize) lw = bufsize - 1;
  buf[lw] = 0;
  return lw;
}
inline size_t vtoa(wchar_t* buf, size_t bufsize, POINT& value) {
  if (bufsize >= 32) { return _snwprintf_s(buf, bufsize, bufsize - 1, L"{%d,%d}", value.x, value.y); }
  return 0;
}
inline size_t vtoa(wchar_t* buf, size_t bufsize, POINTL& value) {
  if (bufsize >= 32) { return _snwprintf_s(buf, bufsize, bufsize - 1, L"{%d,%d}", value.x, value.y); }
  return 0;
}
inline size_t vtoa(wchar_t* buf, size_t bufsize, RECT& value) {
  if (bufsize >= 64) { return _snwprintf_s(buf, bufsize, bufsize - 1, L"{%d,%d-%d,%d}", value.left, value.top, value.right, value.bottom); }
  return 0;
}
#else
inline int vtoa(wchar_t* buf, unsigned bufsize, const wchar_t* value) {
  if (!value) value = L"[null]";
  unsigned l = strlen(value);
  if (l >= bufsize - 1) l = bufsize - 1;
  sdk::gepro::memcpy(buf, value, l);
  buf[l] = 0;
  return l;
}
inline int vtoa(wchar_t* buf, unsigned bufsize, const void* value) {
  if (bufsize >= 16) { return _snwprintf(buf, bufsize, L"%p", value); }
  return 0;
}
inline int vtoa(wchar_t* buf, unsigned bufsize, double value) {
  char tmp[80];
  unsigned l = vtoa(tmp, sizeof(tmp), value);
  unsigned lw = MultiByteToWideChar(CP_ACP, 0, tmp, l, buf, bufsize);
  if (lw >= bufsize) lw = bufsize - 1;
  buf[lw] = 0;
  return lw;
}
inline int vtoa(wchar_t* buf, unsigned bufsize, POINT& value) {
  if (bufsize >= 32) { return _snwprintf(buf, bufsize, L"{%d,%d}", value.x, value.y); }
  return 0;
}
inline int vtoa(wchar_t* buf, unsigned bufsize, POINTL& value) {
  if (bufsize >= 32) { return _snwprintf(buf, bufsize, L"{%d,%d}", value.x, value.y); }
  return 0;
}
inline int vtoa(wchar_t* buf, unsigned bufsize, RECT& value) {
  if (bufsize >= 64) { return _snwprintf(buf, bufsize, L"{%d,%d-%d,%d}", value.left, value.top, value.right, value.bottom); }
  return 0;
}
#endif
};  // namespace simple
};  // namespace vtoa
};  // namespace gepro
};  // namespace cz

#endif
