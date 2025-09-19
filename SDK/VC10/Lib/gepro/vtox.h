#ifndef __SDK_GEPRO_VTOX_H
#define __SDK_GEPRO_VTOX_H
#if defined(DEBUG_PREPROC)
#pragma message(__FILE__ "(1) : debug included")
#endif
#ifndef __SDK_GEPRO_VTOA_H
#include "vtoa.h"
#endif
#ifndef __SDK_GEPRO_VTOW_H
#include "vtow.h"
#endif
#ifndef __SDK_GEPRO_TCHARBUF_H
#include "tcharbuf.h"
#endif
namespace cz {
namespace gepro {
namespace vtoa {
namespace simple {
template <int max, class E = char>
class buffer : public cz::gepro::tcharbuf<E> {
  E buf[max];

 public:
  typedef public cz::gepro::tcharbuf<E> base_type;
  typedef size_t size_type;
  buffer() : tcharbuf<E>(buf, sizeof(buf) / sizeof(buf[0])) { *buf = '\0'; }
  void Add(const char* str, size_t len) { base_type::_append(str, len); }
  template <class V>
  buffer& operator<<(V v) {
    size_type l = vtoa(buf + base_type::size(), base_type::space(), v);
    base_type::seekr(l);
    return *this;
  }
};

#undef _OITEM
#define _OITEM(v, t, i) << #i "=" << v.i << ","
#include "viewtypes.h"
typedef buffer<1024> tmpbuffer;
inline size_t copy(tmpbuffer& b, char* buf, size_t bufsize) {
  size_t l = b.size();
  if (l >= bufsize) l = bufsize - 1;
  memcpy(buf, b.begin(), l);
  buf[l] = '\0';
  return l;
}
inline size_t vtoa(char* buf, size_t bufsize, const DEVMODE& v) {
  tmpbuffer b;
  b << "{" _O_DEVMODE(v) << "}";
  return copy(b, buf, bufsize);
}
inline size_t vtoa(char* buf, size_t bufsize, const PRINTER_INFO_2& v) {
  tmpbuffer b;
  b << "{" _O_PRINTER_INFO_2(v) << "}";
  return copy(b, buf, bufsize);
}

template <int max>
class buffer2 : public cz::gepro::tcharbuf<char> {
  char buf[max];

 public:
  buffer2() : tcharbuf<char>(buf, sizeof(buf) / sizeof(buf[0])) { *buf = '\0'; }
  template <class V>
  buffer2& operator<<(const V& v) {
    size_t l = vtoa(buf + size(), space(), v);
    seekr(l);
    return *this;
  }
};

};  // namespace simple

namespace inifile {
// vystup do tvaru klic=hodnota\n ...
#undef _OITEM
#define _OITEM(v, t, i) << #i "=" << v.i << "\n"
#include "viewtypes.h"
typedef cz::gepro::vtoa::simple::buffer<1024> tmpbuffer;
inline size_t inicopy(tmpbuffer& b, char* buf, size_t bufsize) {
  size_t l = b.size();
  if (l >= bufsize) l = bufsize - 1;
  memcpy(buf, b.begin(), l);
  buf[l] = '\0';
  return l;
}
inline size_t vtoa(char* buf, size_t bufsize, const DEVMODE& v) {
  tmpbuffer b;
  b _O_DEVMODE(v) << "\n";
  return inicopy(b, buf, bufsize);
}
inline size_t vtoa(char* buf, size_t bufsize, const PRINTER_INFO_2& v) {
  tmpbuffer b;
  b _O_PRINTER_INFO_2(v) << "\n";
  return inicopy(b, buf, bufsize);
}

template <int max>
class buffer2 : public cz::gepro::tcharbuf<char> {
  char buf[max];

 public:
  buffer2() : tcharbuf<char>(buf, sizeof(buf) / sizeof(buf[0])) { *buf = '\0'; }
  void Add(const char* str, size_t len) { append(str, len); }
  template <class V>
  buffer2& operator<<(const V& v) {
    size_type l = vtoa(buf + size(), space(), v);
    seekr(l);
    return *this;
  }
};
};  // namespace inifile

};  // namespace vtoa
};  // namespace gepro
};  // namespace cz

#endif
