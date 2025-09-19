#ifdef __SDK_GEPRO_STD
#error "konflikt použití std.h a std2.h - lze použít pouze jeden z nich v celém projektu"
#endif
#ifndef __SDK_GEPRO_STD2
#define __SDK_GEPRO_STD2
#if defined(DEBUG_PREPROC)
#pragma message(__FILE__ "(1) : debug included")
#endif
#include "string.h"
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
  x& operator<<(basic_ios<typename x::char_type, char_traits<typename x::char_type> >& (*p)(      \
      basic_ios<typename x::char_type, char_traits<typename x::char_type> >&)) {           \
    *(ostream*)this << p;                    \
    return *this;                            \
  }                                          \
  x& operator<<(basic_streambuf<typename x::char_type, char_traits<typename x::char_type> >* p) {              \
    *(ostream*)this << p;                    \
    return *this;                            \
  }                                          \
  x& operator<<(basic_ostream<typename x::char_type, char_traits<typename x::char_type> >& (*p)( \
      basic_ostream<typename x::char_type, char_traits<typename x::char_type> >&)) {   \
    *(ostream*)this << p;                    \
    return *this;                            \
  }                                          \
  x& operator<<(_Smanip<streamsize> p) {     \
    *(ostream*)this << p;                    \
    return *this;                            \
  }                                          \
  x& operator<<(_Fillobj<typename x::char_type> p) {          \
    *(ostream*)this << p;                    \
    return *this;                            \
  }                                          \
  x& operator<<(x& (*p)(x&)) {               \
    *(ostream*)this << p;                    \
    return *this;                            \
  }                                          \
  x& operator<<(const typename x::char_type* p) {             \
    *(ostream*)this << p;                    \
    return *this;                            \
  }                                          \
  x& operator<<(typename x::char_type p) {                    \
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

template <size_t max, class S, class Siface,typename E=char>
class tstreambuf : public basic_streambuf<E, char_traits<E> > {
 public:
  typedef basic_streambuf<E, char_traits<E> > streambuf_type;
  typedef typename streambuf_type::char_type char_type;
  typedef typename streambuf_type::int_type int_type;
  typedef const char_type* const_pointer;

 private:
  typedef streambuf_type base_type;
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
  tstreambuf() {
    initp();
    over_ = false;
  }
  virtual int_type overflow(int_type c) {
    buf_ += array_;
    over_ = true;
    initp();
    return base_type::sputc((char)c);
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
  size_t size() { return Siface::size(buf_) + (base_type::pptr() - base_type::pbase()); }
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
        base_type::sputn(r, rl);
        return;
      }
      initp(m - l);
      base_type::sputn(r, rl);
    }
  }
  char_type last() const {
    if (base_type::pptr() == base_type::pbase()) return 0;
    return *(base_type::pptr() - 1);
  }
};
template <size_t max,typename E=char>
class tstatstreambuf : public basic_streambuf<E, char_traits<E> > {
 public:
  typedef E char_type;
  typedef const char_type* const_pointer;
  typedef basic_streambuf<E, char_traits<E> > streambuf_type;
 private:
  typedef streambuf_type base_type;
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
  const char_type* c_str() const { return array_; }
  size_t size() const { return (base_type::pptr() - base_type::pbase()); }
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
      base_type::sputn(r, rl);
    }
  }
  char_type last() const {
    if (base_type::pptr() == base_type::pbase()) return 0;
    return *(base_type::pptr() - 1);
  }
};
template <typename E=char>
class statstreambuf : public basic_streambuf<E, char_traits<E> > {
 public:
  typedef E char_type;
  typedef const char_type* const_pointer;
  typedef basic_streambuf < E, char_traits<E> >streambuf_type;
 private:
  typedef streambuf_type base_type;
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
  const char_type* c_str() const { return array_; }
  size_t size() const { return (base_type::pptr() - base_type::pbase()); }
  char_type last() const {
    if (base_type::pptr() == base_type::pbase()) return 0;
    return *(base_type::pptr() - 1);
  }
};
// rozsiruji trida ostream o zakladni typy Windows
template <typename E = char>
class ostreamex : public basic_ostream<E, char_traits<E> > {
 public:
  typedef E char_type;
  typedef basic_ostream<E, char_traits<E> > ostream;
  typedef basic_streambuf<E, char_traits<E> > streambuf;
  typedef ostreamex<E> streamex;
  typedef streamex base_type;
  ostreamex() : ostream() {}
  ostreamex(streambuf* s) : ostream(s) {}
  STD_OSTREAM_OPERATORS(ostreamex)
  streamex& operator<<(const POINT& p) {
    *this << p.x << char_type(',') << p.y;
    return *this;
  }
  streamex& operator<<(const cz::gepro::tconstchar<char_type>& p) {
    base_type::write(p.c_str(), p.size());
    return *this;
  }
  streamex& operator<<(const cz::gepro::tconstchar<char_type, cz::gepro::tstring_icompare<char_type> >& p) {
    base_type::write(p.c_str(), p.size());
    return *this;
  }
};
template <size_t max, class S, class Siface,typename E=char>
class tstringbuf : public ostreamex<E> {
  typedef ostreamex<E> ostream_type;
  typedef tstreambuf<max, S, Siface,E> streambuf_type;
  streambuf_type mem;

 public:
  typedef tstringbuf<max, S, Siface> self_type;
  typedef typename streambuf_type::char_type char_type;
  typedef typename streambuf_type::const_pointer const_pointer;
  tstringbuf() : ostream_type(&mem) {}
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
};

template <size_t max,typename E=char>
class tstatbuf : public ostreamex<E> {
  typedef tstatstreambuf<max,E> streambuf_type;
  streambuf_type mem;
 public:
  typedef tstatbuf<max> self_type;
  typedef ostreamex<E> ostreamex_type;
  typedef typename streambuf_type::char_type char_type;
  typedef typename streambuf_type::const_pointer const_pointer;
  tstatbuf() : ostreamex_type(&mem) {}
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
  void to_lower() { mem.to_lower(); }
  void to_upper() { mem.to_upper(); }
};
template <typename E=char>
class statbuf : public ostreamex<E> {
  typedef statstreambuf<E> streambuf_type;
  streambuf_type mem;

 public:
  typedef ostreamex<E> streamex_type;
  typedef statbuf self_type;
  typedef typename streambuf_type::char_type char_type;
  typedef typename streambuf_type::const_pointer const_pointer;
  statbuf(char_type* buf, size_t bufsize) : mem(buf, bufsize), streamex_type(&mem) {}
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
};
};  // namespace std

#endif
