#ifdef __SDK_GEPRO_STD2
#error "konflikt použití std.h a std2.h - lze použít pouze jeden z nich v celém projektu"
#endif
#ifndef __SDK_GEPRO_STD
#define __SDK_GEPRO_STD
#if defined(DEBUG_PREPROC)
#pragma message(__FILE__ "(1) : debug included")
#endif
/* rozsire STD pro GEPRO SDK */
#include <iostream>
#include <iomanip>
// pretizeni operatoru pro odvozenou tøídu z std::ostream
// x - název odvozené tøídy
#define STD_OSTREAM_OPERATORS(x)             \
  x& operator<<(ios_base& (*p)(ios_base&)) { \
    *(ostream*)this << p;                    \
    return *this;                            \
  }                                          \
  x& operator<<(ios& (*p)(ios&)) {           \
    *(ostream*)this << p;                    \
    return *this;                            \
  }                                          \
  x& operator<<(streambuf* p) {              \
    *(ostream*)this << p;                    \
    return *this;                            \
  }                                          \
  x& operator<<(ostream& (*p)(ostream&)) {   \
    *(ostream*)this << p;                    \
    return *this;                            \
  }                                          \
  x& operator<<(_Smanip<streamsize> p) {     \
    *(ostream*)this << p;                    \
    return *this;                            \
  }                                          \
  x& operator<<(_Fillobj<char> p) {          \
    *(ostream*)this << p;                    \
    return *this;                            \
  }                                          \
  x& operator<<(x& (*p)(x&)) {               \
    *(ostream*)this << p;                    \
    return *this;                            \
  }                                          \
  x& operator<<(const char* p) {             \
    *(ostream*)this << p;                    \
    return *this;                            \
  }                                          \
  x& operator<<(const unsigned char* p) {    \
    *(ostream*)this << p;                    \
    return *this;                            \
  }                                          \
  x& operator<<(const signed char* p) {      \
    *(ostream*)this << p;                    \
    return *this;                            \
  }                                          \
  x& operator<<(char p) {                    \
    *(ostream*)this << p;                    \
    return *this;                            \
  }                                          \
  x& operator<<(unsigned char p) {           \
    *(ostream*)this << p;                    \
    return *this;                            \
  }                                          \
  x& operator<<(signed char p) {             \
    *(ostream*)this << p;                    \
    return *this;                            \
  }                                          \
  x& operator<<(bool p) {                    \
    *(ostream*)this << p;                    \
    return *this;                            \
  }                                          \
  x& operator<<(short p) {                   \
    *(ostream*)this << p;                    \
    return *this;                            \
  }                                          \
  x& operator<<(unsigned short p) {          \
    *(ostream*)this << p;                    \
    return *this;                            \
  }                                          \
  x& operator<<(int p) {                     \
    *(ostream*)this << p;                    \
    return *this;                            \
  }                                          \
  x& operator<<(unsigned p) {                \
    *(ostream*)this << p;                    \
    return *this;                            \
  }                                          \
  x& operator<<(long p) {                    \
    *(ostream*)this << p;                    \
    return *this;                            \
  }                                          \
  x& operator<<(unsigned long p) {           \
    *(ostream*)this << p;                    \
    return *this;                            \
  }                                          \
  x& operator<<(long long p) {               \
    *(ostream*)this << p;                    \
    return *this;                            \
  }                                          \
  x& operator<<(unsigned long long p) {      \
    *(ostream*)this << p;                    \
    return *this;                            \
  }                                          \
  x& operator<<(void* p) {                   \
    *(ostream*)this << p;                    \
    return *this;                            \
  }                                          \
  x& operator<<(float p) {                   \
    *(ostream*)this << p;                    \
    return *this;                            \
  }                                          \
  x& operator<<(double p) {                  \
    *(ostream*)this << p;                    \
    return *this;                            \
  }                                          \
  x& operator<<(long double p) {             \
    *(ostream*)this << p;                    \
    return *this;                            \
  }
namespace std {
inline void memset0(char* buf, size_t count) { memset(buf, 0, count * sizeof(char)); }
inline void memset0(wchar_t* buf, size_t count) { memset(buf, 0, count * sizeof(wchar_t)); }

template <size_t max, class S, class Siface>
class tstreambuf : public std::streambuf {
  S buf_;
  char_type array_[max];
  bool over_;
  void initp() {
    this->setp(array_, array_ + max - 1);
    memset0(array_, max);
  }
  void initp(size_t offset) {
    this->setp(array_ + offset, array_ + max - 1);
    memset0(array_ + offset, max - offset);
  }

 public:
  typedef char char_type;
  typedef const char_type* const_pointer;
  tstreambuf() {
    initp();
    over_ = false;
  }
  virtual int overflow(int c) {
    buf_ += array_;
    over_ = true;
    initp();
    return sputc((char)c);
  }
  const char_type* sdata() { return array_; }
  void clear() {
    initp();
    over_ = false;
    Siface::clear(buf_);
  }
  const char_type* begin() {
    if (over_) {
      buf_ += array_;
      initp();
      return Siface::begin(buf_);
    }
    return array_;
  }
  size_t size() { return Siface::size(buf_) + (pptr() - pbase()); }
  S GetBuffer() {
    buf_ += array_;
    initp();
    return buf_;
  }
  S str() { return GetBuffer(); }
  /**
       Zkrácení na požadovanou délku - nahrazení posledních znakù stringem r.
    
       @param _max maximální délka
       @param r    koncový text (...)
    */
  void trimr(size_t _max, const_pointer r) {
    if (size() > _max) {
      size_t rl = cz::gepro::tcharbuf<char_type>::len(r);
      size_t l = Siface::size(buf_);
      size_t m = _max - rl;
      if (m < l) {
        // substring
        buf_ = buf_.substr(0, m);
      }
      if (m <= l) {
        initp();
        sputn(r, rl);
        return;
      }
      initp(m - l);
      sputn(r, rl);
    }
  }
  char_type last() const {
    if (pptr() == pbase()) return 0;
    return *(pptr() - 1);
  }
};
template <size_t max>
class tstatstreambuf : public std::streambuf {
  char_type array_[max];
  bool over_;
  void initp() {
    this->setp(array_, array_ + max - 1);
    memset0(array_, max);
  }
  void initp(size_t offset) {
    this->setp(array_ + offset, array_ + max - 1);
    memset0(array_ + offset, max - offset);
  }

 public:
  typedef char char_type;
  typedef const char_type* const_pointer;
  tstatstreambuf() {
    initp();
    over_ = false;
  }
  virtual int overflow(int) {
    over_ = true;
    return 0;
  }
  const char_type* sdata() const { return array_; }
  void clear() {
    initp();
    over_ = false;
  }
  const char_type* begin() const { return array_; }
  size_t size() const { return (pptr() - pbase()); }
  void to_lower() { _strlwr(array_); }
  void to_upper() { _strupr(array_); }
  /**
       Zkrácení na požadovanou délku - nahrazení posledních znakù stringem r.
    
       @param _max maximální délka
       @param r    koncový text (...)
    */
  void trimr(size_t _max, const_pointer r) {
    if (size() > _max) {
      size_t rl = cz::gepro::tcharbuf<char_type>::len(r);
      initp(_max - rl);
      sputn(r, rl);
    }
  }
  char_type last() const {
    if (pptr() == pbase()) return 0;
    return *(pptr() - 1);
  }
};
class statstreambuf : public std::streambuf {
  char_type* array_;
  size_t max_;
  bool over_;
  void initp() {
    this->setp(array_, array_ + max_ - 1);
    memset0(array_, max_);
  }
  void initp(size_t offset) {
    this->setp(array_ + offset, array_ + max_ - 1);
    memset0(array_ + offset, max_ - offset);
  }

 public:
  typedef char char_type;
  typedef const char_type* const_pointer;
  statstreambuf(char_type* _array, size_t _max) : array_(_array), max_(_max) {
    initp();
    over_ = false;
  }
  virtual int overflow(int) {
    over_ = true;
    return 0;
  }
  const char_type* sdata() const { return array_; }
  void clear() {
    initp();
    over_ = false;
  }
  const char_type* begin() const { return array_; }
  size_t size() const { return (pptr() - pbase()); }
  char_type last() const {
    if (pptr() == pbase()) return 0;
    return *(pptr() - 1);
  }
};
// rozsiruji trida ostream o zakladni typy Windows
class ostreamex : public ostream {
 public:
  ostreamex(streambuf* s) : ostream(s) {}
  STD_OSTREAM_OPERATORS(ostreamex)
  ostreamex& operator<<(const POINT& p) {
    *this << p.x << "," << p.y;
    return *this;
  }
};
#define STD_OSTREAMEX_OPERATORS(o)          \
  STD_OSTREAM_OPERATORS(o)                  \
  o& operator<<(const POINT& p) {           \
    *(ostreamex*)this << p.x << ',' << p.y; \
    return *this;                           \
  }
template <size_t max, class S, class Siface>
class tstringbuf : public ostreamex {
  typedef tstreambuf<max, S, Siface> streambuf_type;
  streambuf_type mem;

 public:
  typedef tstringbuf<max, S, Siface> self_type;
  typedef typename streambuf_type::char_type char_type;
  typedef typename streambuf_type::const_pointer const_pointer;
  tstringbuf() : ostreamex(&mem) {}
  void clear() {
    mem.clear();
    ostream::clear();
  }
  const_pointer begin() { return mem.begin(); }
  const_pointer c_str() { return begin(); }
  size_t size() { return mem.size(); }
  S GetBuffer() { return mem.GetBuffer(); }
  S str() { return GetBuffer(); }
  self_type& append_if_not(char_type c) {
    if (mem.last() != c) mem.sputc(c);
    return *this;
  }
  void Add(const char_type* str, size_t len) { mem.sputn(str, len); }
  /**
       Zkrácení na požadovanou délku - nahrazení posledních znakù stringem r.
    
       @param _max maximální délka
       @param r    koncový text (...)
    */
  void trimr(size_t _max, const char* r) { mem.trimr(_max, r); }
  STD_OSTREAMEX_OPERATORS(self_type)
};

template <size_t max>
class tstatbuf : public ostreamex {
  typedef tstatstreambuf<max> streambuf_type;
  streambuf_type mem;

 public:
  typedef tstatbuf<max> self_type;
  typedef typename streambuf_type::char_type char_type;
  typedef typename streambuf_type::const_pointer const_pointer;
  tstatbuf() : ostreamex(&mem) {}
  void clear() {
    mem.clear();
    ostream::clear();
  }
  const_pointer begin() const { return mem.begin(); }
  const_pointer c_str() const { return begin(); }
  size_t size() const { return mem.size(); }
  self_type& append_if_not(char_type c) {
    if (mem.last() != c) mem.sputc(c);
    return *this;
  }
  void Add(const char_type* str, size_t len) { mem.sputn(str, len); }
  /**
       Zkrácení na požadovanou délku - nahrazení posledních znakù stringem r.
    
       @param _max maximální délka
       @param r    koncový text (...)
    */
  void trimr(size_t _max, const char* r) { mem.trimr(_max, r); }
  STD_OSTREAMEX_OPERATORS(self_type)
  void to_lower() { mem.to_lower(); }
  void to_upper() { mem.to_upper(); }
};
class statbuf : public ostreamex {
  typedef statstreambuf streambuf_type;
  streambuf_type mem;

 public:
  typedef statbuf self_type;
  typedef streambuf_type::char_type char_type;
  typedef streambuf_type::const_pointer const_pointer;
  statbuf(char* buf, size_t bufsize) : mem(buf, bufsize), ostreamex(&mem) {}
  void clear() {
    mem.clear();
    ostream::clear();
  }
  const_pointer begin() const { return mem.begin(); }
  const_pointer c_str() const { return begin(); }
  size_t size() const { return mem.size(); }
  self_type& append_if_not(char_type c) {
    if (mem.last() != c) mem.sputc(c);
    return *this;
  }
  void Add(const char_type* str, size_t len) { mem.sputn(str, len); }
  STD_OSTREAMEX_OPERATORS(self_type)
};
};  // namespace std

#endif
