#ifndef __SDK_GEPRO_SMARTBUFS_H
#define __SDK_GEPRO_SMARTBUFS_H
#if defined(DEBUG_PREPROC)
#pragma message(__FILE__ "(1) : debug included")
#endif
#ifndef __SDK_GEPRO_TCHARBUF_H
#include "tcharbuf.h"
#endif
#include <type_traits>
namespace cz {
namespace gepro {

/** @defgroup smartbufs Chytré buffery

   @{ 
   Cílem je návrh string bufferu tak aby se nechala optimalizovat rychlost práce se stringy.
   Tyto požadavky se vyskytují typicky v tìchto pøípadech
   - sèítání velkého množství krátkých stringù - narùstá neumìrnì poèet realokací
   - ve vìtšinì pøípadù staèí oèekávaná max. velikost, ale je nutné zajistit že obèas bude vìtší

*/

/** Pomocnná tøída pro formátování double, obsahuje buffer dostateènì velký pro 
    výstup double v jakémkoliv formátu. 
*/
template <class E>
class Double {
 public:
  typedef E char_type;
  typedef size_t size_type;
  Double(double _value) { size_ = cz::gepro::vtoa::simple::vtoa(buf_, sizeof(buf_) / sizeof(char_type), _value); }
  Double(double _value, int _dec) { size_ = _snprintf(buf_, sizeof(buf_), "%.*f", _dec, _value); }
  const char_type* begin() const { return buf_; }
  const char_type* c_str() const { return buf_; }
  size_type size() const { return size_; }

 private:
  char_type buf_[256];
  size_type size_;
};
/** Pomocnná tøída pro formátování int, obsahuje buffer dostateènì velký pro 
    výstup int v jakémkoliv formátu. 
*/
template <class E>
class Int {
 public:
  typedef E char_type;
  typedef size_t size_type;
  Int(int _value) { size_ = cz::gepro::vtoa::simple::vtoa(buf_, sizeof(buf_)/sizeof(char_type), _value); }
  const char_type* begin() const { return buf_; }
  const char_type* c_str() const { return buf_; }
  size_type size() const { return size_; }

 private:
  char_type buf_[128];
  size_type size_;
};
template <class E>
class LongInt {
 public:
  typedef E char_type;
  typedef size_t size_type;
  LongInt(__int64 _value) { size_ = cz::gepro::vtoa::simple::vtoa(buf_, sizeof(buf_) / sizeof(char_type), _value); }
  const char_type* begin() const { return buf_; }
  const char_type* c_str() const { return buf_; }
  size_type size() const { return size_; }

 private:
  char_type buf_[128];
  size_type size_;
};
/** Pomocnná tøída pro formátování int na HEX, obsahuje buffer dostateènì velký pro 
    výstup int v jakémkoliv formátu. 
*/
class Hex {
 public:
  typedef char char_type;
  typedef size_t size_type;
  Hex(__int64 _value) { size_ = _snprintf_s(buf_, sizeof(buf_), sizeof(buf_) / sizeof(char_type) - 1, "%016llx", _value); }
  Hex(unsigned __int64 _value) { size_ = _snprintf_s(buf_, sizeof(buf_), sizeof(buf_) / sizeof(char_type) - 1, "%016llx", _value); }
  Hex(int _value) { size_ = _snprintf_s(buf_, sizeof(buf_), sizeof(buf_) / sizeof(char_type) - 1, "%08x", _value); }
  Hex(unsigned int _value) { size_ = _snprintf_s(buf_, sizeof(buf_), sizeof(buf_) / sizeof(char_type) - 1, "%08x", _value); }
  Hex(long _value) { size_ = _snprintf_s(buf_, sizeof(buf_), sizeof(buf_) / sizeof(char_type) - 1, "%08x", _value); }
  Hex(unsigned long _value) { size_ = _snprintf_s(buf_, sizeof(buf_), sizeof(buf_) / sizeof(char_type) - 1, "%08x", _value); }
  Hex(short _value) { size_ = _snprintf_s(buf_, sizeof(buf_), sizeof(buf_) / sizeof(char_type) - 1, "%04x", _value); }
  Hex(unsigned short _value) { size_ = _snprintf_s(buf_, sizeof(buf_), sizeof(buf_) / sizeof(char_type) - 1, "%04x", _value); }
  Hex(char _value) { size_ = _snprintf_s(buf_, sizeof(buf_), sizeof(buf_) / sizeof(char_type) - 1, "%02x", _value); }
  Hex(unsigned char _value) { size_ = _snprintf_s(buf_, sizeof(buf_), sizeof(buf_) / sizeof(char_type) - 1, "%02x", _value); }
  const char_type* begin() const { return buf_; }
  const char_type* c_str() const { return buf_; }
  size_type size() const { return size_; }

 private:
  char_type buf_[64];
  size_type size_;
};
#ifdef _STRING_
#define STDSTRING_DEFAULT_OPERATORS(Class)    \
  Class& operator<<(const std::string& val) { \
    if (val.empty()) return *this;            \
    Add(val.c_str(), val.length());           \
    return *this;                             \
  }
#else
#define STDSTRING_DEFAULT_OPERATORS(Class)
#endif
#define DEFAULT_OPERATORS(Class)                                               \
  STDSTRING_DEFAULT_OPERATORS(Class)                                           \
  Class& operator<<(int _value) {                                              \
    put(_value);                                                               \
    return *this;                                                              \
  }                                                                            \
  Class& operator<<(unsigned int _value) {                                     \
    put(_value);                                                               \
    return *this;                                                              \
  }                                                                            \
  Class& operator<<(long _value) {                                             \
    put(_value);                                                               \
    return *this;                                                              \
  }                                                                            \
  Class& operator<<(unsigned long _value) {                                    \
    put(_value);                                                               \
    return *this;                                                              \
  }                                                                            \
  Class& operator<<(__int64 _value) {                                          \
    put(_value);                                                               \
    return *this;                                                              \
  }                                                                            \
  Class& operator<<(unsigned __int64 _value) {                                 \
    put(_value);                                                               \
    return *this;                                                              \
  }                                                                            \
  Class& operator<<(double _value) {                                           \
    put(_value);                                                               \
    return *this;                                                              \
  }                                                                            \
  Class& operator<<(const typename Class::char_type* _value) {                 \
    put(_value);                                                               \
    return *this;                                                              \
  }                                                                            \
  Class& operator<<(const cz::gepro::tconstchar<typename Class::char_type>& _value) {                                            \
    Add(_value.c_str(), _value.size());                                                                                          \
    return *this;                                                                                                                \
  }                                                                                                                              \
  Class& operator<<(                                                                                                             \
      const cz::gepro::tconstchar<typename Class::char_type, cz::gepro::tstring_icompare<typename Class::char_type> >& _value) { \
    Add(_value.c_str(), _value.size());                                                                                          \
    return *this;                                                                                                                \
  }                                                                            \
  Class& operator<<(const Hex& _value) {                                       \
    Add(_value.begin(), _value.size());                                        \
    return *this;                                                              \
  }                                                                            \
  Class& operator<<(typename Class::char_type v) {                             \
    Add(v);                                                                    \
    return *this;                                                              \
  }                                                                            \
  bool operator==(const char_type* str) const { return compare(str) == 0; }    \
  Class& append_until_not(const char_type* s, size_type count, char_type ch) { \
    for (; count; --count) {                                                   \
      char_type c = *s++;                                                      \
      if (c == ch) break;                                                      \
      base_type::_append(c);                                                              \
    }                                                                          \
    return *this;                                                              \
  }                                                                            \
  Class& append_until_not(const char_type* s, char_type ch) {                  \
    for (;;) {                                                                 \
      char_type c = *s++;                                                      \
      if (!c || c == ch) break;                                                \
      base_type::_append(c);                                                              \
    }                                                                          \
    return *this;                                                              \
  }                                                                            \
  Class& append_until_not2(const char_type* s, char_type ch, char_type ch2) {  \
    for (;;) {                                                                 \
      char_type c = *s++;                                                      \
      if (!c || c == ch || c == ch2) break;                                    \
      base_type::_append(c);                                                              \
    }                                                                          \
    return *this;                                                              \
  }                                                                            \
  Class& append(const char_type* s, size_type count) {                         \
    base_type::_append(s, count);                                                         \
    return *this;                                                              \
  }                                                                            \
  template <typename S>                                                        \
  Class& append(const S& s) {                                                  \
    base_type::_append(s.data(), s.size());                                               \
    return *this;                                                              \
  }                                                                            \
  Class& assign(const char_type* s, size_type count) {                         \
    base_type::clear();                                                        \
    base_type::_append(s, count);                                                         \
    return *this;                                                              \
  }                                                                            \
  template <typename S>                                                        \
  Class& assign(const S& s) {                                                  \
    base_type::clear();                                                        \
    base_type::_append(s.data(), s.size());                                               \
    return *this;                                                              \
  }                                                                            \
  Class& assign(size_type count, char_type ch) {                               \
    base_type::clear();                                                        \
    base_type::_fill(ch, count);                                                          \
    return *this;                                                              \
  }

#define DEFAULT_TSTATBUF(Class)                                         \
  void cesky() { base_type::_cesky(); }                                 \
  void capitalize() { base_type::_capitalize(); }                       \
  void setcapacity(size_type l) { base_type::_setcapacity(l); }            \
  void lower() { base_type::_lower(); }                                 \
  void upper() { base_type::_upper(); }

/** Statický buffer vhodný jako náhrada ostream a char[]. Tento buffer nelze zvìtšit, zabazpeèuje
    pouze proti pøepsání alokované velikosti.
    Operátor << realizuje výstup typu stream pro všechny datové typy, podporované parametrem O.
    Pokud se požaduje generování výjimky v pøípadì, že buffer není dostateènì velký, je možné
    použít tøídu tstatbufe, která generuje výjimku small_buffer, pokud je buffer krátký.

    @param max   maximální velikost bufferu (buffer nelze zvìtšit)
    @param E     char typ (char,wchar_t)
    @param O     tøída relizující operátory << 

    \code
      typedef cz::gepro::tstatbuf<256> pathbuf;
      pathbuf buf;
      buf << "pocet=" << 10;
      TS_ASSERT_TEXT(buf.begin(),"pocet=10")  // buffer je dost velký
      cz::gepro::tstatbuf<4> buf2;
      buf2 << "pocet=" << 10;
      TS_ASSERT_TEXT(buf2.begin(),"poc")  // buffer je krátký na celý požadovaný výstup
    \endcode

    K dispozici jsou overloadované fce strcpy, strcat atd., aby se buffer nechal používat i bez zmìny
    kódu, pouhou náhradou deklarace promìnné.
    \code
      // char buf[4];
      cz::gepro::tstatbuf<4> buf;
      strcpy(buf,"abcd");
      TS_ASSERT_TEXT(buf.begin(),"abcd")
      strcpy(buf,"123456");
      TS_ASSERT_TEXT(buf.begin(),"1234")
    \endcode
*/
template <int max, class E = char, class O = simplevtox<E> >
class tstatbuf : public tcharbuf<E> {
 protected:
  E buf[max + 1];

 public:
  typedef E char_type;
  typedef typename std::make_unsigned<char_type>::type uchar_type;
  typedef tcharbuf<char_type> base_type;
  typedef typename base_type::size_type size_type;
  tstatbuf() : tcharbuf<E>(buf, sizeof(buf) / sizeof(buf[0])) { *buf = '\0'; }
  tstatbuf(const tstatbuf& src) : tcharbuf<E>(buf, sizeof(buf) / sizeof(buf[0])) {
    *buf = '\0';
    base_type::_append(src.begin(), src.size());
  }
  tstatbuf(const char_type* src) : tcharbuf<E>(buf, sizeof(buf) / sizeof(buf[0])) {
    *buf = '\0';
    base_type::_append(src, strlen(src));
  }
  tstatbuf& operator=(const tstatbuf& src) {
    base_type::clear();
    base_type::_append(src.begin(), src.size());
    return *this;
  }
  void Add(const char_type* str, size_type len) { base_type::_append(str, len); }
  void Add(char_type str) { base_type::_append(str); }
  void Add(char_type c, size_type n) {
    for (; n; n--) Add(c);
  }
  template <class V>
  tstatbuf& put(V v) {
    size_type l = O::vtoa(buf + base_type::size(), base_type::space(), v);
    base_type::seekr(l);
    return *this;
  }
  DEFAULT_OPERATORS(tstatbuf);
  DEFAULT_TSTATBUF(tstatbuf);

  // STL iface
  tstatbuf& write(const char_type* str, size_type len) {
    Add(str, len);
    return *this;
  }
  tstatbuf& put(char_type c) {
    Add(c);
    return *this;
  }
};

/** Statický buffer jako tstatbuf, ale pokud není místo generuje výjimku small_buffer.

    @param max   maximální velikost bufferu (buffer nelze zvìtšit)
    @param E     char typ (char,wchar_t)
    @param O     tøída relizující operátory << 
*/
template <int max, class E = char, class O = simplevtox<E> >
class tstatbufe : public tcharbuf<E, 1> {
  E buf[max + 1];

 public:
  typedef E char_type;
  typedef tcharbuf<char_type, 1> base_type;
  typedef typename base_type::size_type size_type;
  tstatbufe() : tcharbuf<E, 1>(buf, sizeof(buf) / sizeof(buf[0])) { *buf = '\0'; }
  tstatbufe(const tstatbufe& src) : tcharbuf<E, 1>(buf, sizeof(buf) / sizeof(buf[0])) {
    *buf = '\0';
    base_type::_append(src.begin(), src.size());
  }
  tstatbufe(const char_type* src) : tcharbuf<E, 1>(buf, sizeof(buf) / sizeof(buf[0])) {
    *buf = '\0';
    base_type::_append(src, strlen(src));
  }
  tstatbufe& operator=(const tstatbufe& src) {
    base_type::clear();
    base_type::_append(src.begin(), src.size());
    return *this;
  }
  void Add(const char* str, size_type len) { base_type::_append(str, len); }
  void Add(char_type str) { base_type::_append(str); }
  void Add(char_type c, size_type n) {
    for (; n; n--) Add(c);
  }
  template <class V>
  tstatbufe& put(V v) {
    size_type l = O::vtoa(buf + base_type::size(), base_type::space(), v);
    base_type::seekr(l);
    return *this;
  }
  DEFAULT_OPERATORS(tstatbufe);
  DEFAULT_TSTATBUF(tstatbufe);
  // STL iface
  tstatbufe& write(const char_type* str, size_type len) {
    Add(str, len);
    return *this;
  }
  tstatbufe& put(char_type c) {
    Add(c);
    return *this;
  }
};
/** Pomocná tøída - dummy STL string interface
*/
template <class S, class E>
class STLifacestring {
 public:
  typedef E char_type;
  typedef size_t size_type;
  static void clear(S& s) { s = S(); }
  static size_type size(S& s) { return s.size(); }
  static const char_type* begin(S& s) { return s.c_str(); }
};
/** Pomocná tøída - pøevod CString interface na STL string interface
*/
template <class S, class E>
class STLCString {
 public:
  typedef E char_type;
  typedef size_t size_type;
  static void clear(S& s) { s.Empty(); }
  static size_type size(S& s) { return s.GetLength(); }
  static const char_type* begin(S& s) { return (const char_type*)s; }
};
/** Pomocná tøída - pøevod cz::gepro::String interface na STL string interface
*/
template <class S, class E>
class Stringface {
 public:
  typedef E char_type;
  typedef size_t size_type;
  static void clear(S& s) { s.clear(); }
  static size_type size(S& s) { return s.len(); }
  static const char_type* begin(S& s) { return s.begin(); }
};
/** Dynamický buffer vhodný jako náhrada ostream a char[]. Pokud délka vkládaných dat
    nepøesáhne  velikost max, používá se staticky alokovaný buffer, pokud jsou data delší,
    pøiète se statický buffer ke stringu, vynuluje se a opìt slouží pro naèítání.
    Jakýkoliv pøístup k internímu bufferu zajistí, aby se data podle potøeby seèetla
    a vrátil se správný pointer na aktuální øetìzec.

    Významì ušetøí alokace pøi sèítání stringù, vyladìní lze provést nastavením 
    velikosti statického bufferu - max. Pro snadnìjší manipulaci je možno použít výstupních operatorù <<, 
    postupnì je doplòován interface pro std::basic_ostream a std::basic_string.


    \code
      typedef cz::gepro::tstringbuf<std::string,4> strbuf;
      strbuf buf;
      buf+="1234";
      TS_ASSERT_EQUALS(buf.size(),4)
      buf << "567890";
      TS_ASSERT_EQUALS(buf.size(),10)
      TS_ASSERT_TEXT(buf.begin(),"1234567890")
    \endcode

    K dispozici jsou overloadované funkce strcpy, strcat atd., aby se buffer nechal používat i bez zmìny
    kódu, pouhou náhradou deklarace promìnné.
    \code
      // char buf[256];
      // nahrazením se ziská 'neomezený' buffer s poèáteèní velikostí 4
      typedef cz::gepro::tstringbuf<std::string,4> strbuf;
      strbuf buf;
      strcpy(buf,"12345678");
      TS_ASSERT_EQUALS(buf.size(),8)
      strcat(buf,"90");
      TS_ASSERT_EQUALS(buf.size(),10)
      TS_ASSERT_TEXT(buf.begin(),"1234567890")
    \endcode

    @param S     string sloužící pro ukládání vìtších dat než je max, lze použít libovolný string
                 podporující operátor += a STL interface. Pokud se použije jiný string napø
                 (CString) pak je nutno nastavit odpovídající transformaèní Siface 
                 (pro CString je to STLCString).
                 \code
                  typedef cz::gepro::tstringbuf<CString,64,char,STLCstring<CString,char> > mmydynabuf;
                 \endcode
    @param max   maximální velikost bufferu (buffer nelze zvìtšit)
    @param E     char typ (char,wchar_t)
    @param Siface   tøída pøevádìjící non STL interface na požadovaný STL
*/
template <class S, unsigned max, class E = char, class Siface = STLifacestring<S, E> >
class tstringbuf : public tcharbuf<E> {
 public:
  typedef E char_type;
  typedef tcharbuf<char_type> base_type;
  typedef typename base_type::size_type size_type;
  typedef S string;
  typedef Double<char_type> double_buf;
  typedef Int<char_type> int_buf;
  typedef LongInt<char_type> long_buf;
  typedef typename base_type::const_pointer const_pointer;
  tstringbuf() : tcharbuf<char_type>(buf, max) {}
  tstringbuf(const tstringbuf& src) : tcharbuf<char_type>(buf, max) {
    buffer = src.buffer;
    base_type::_append(src.tcharbuf<char_type>::begin(), src.tcharbuf<char_type>::size());
  }
  tstringbuf(const char_type* src) : tcharbuf<char_type>(buf, max) {
    *buf = '\0';
    base_type::_append(src, strlen(src));
  }
  tstringbuf& operator=(const tstringbuf& src) {
    clear();
    buffer = src.buffer;
    base_type::_append(src.tcharbuf<char_type>::begin(), src.tcharbuf<char_type>::size());
    return *this;
  }
  size_type size() { return Siface::size(buffer) + tsize(); }
  const char_type* begin() {
    if (Siface::size(buffer) == 0) return tbegin();
    if (tsize() > 0) join();
    return Siface::begin(buffer);
  }
  const_pointer c_str() { return begin(); }
  tstringbuf& append_if_not(char_type ch) {
    if (base_type::last() != ch) Add(ch);
    return *this;
  }
  void Add(const char_type* str, size_type len) {
    size_type l = base_type::_append(str, len);
    for (; l < len;) {
      join();
      str += l;
      len -= l;
      l = base_type::_append(str, len);
    }
  }
  void Add(char_type str) {
    size_type l = base_type::_append(str);
    if (!l) {
      join();
      base_type::_append(str);
    }
  }
  void Add(char_type c, size_type n) {
    for (; n; n--) Add(c);
  }
  void operator+=(const char_type* str) { Add(str, strlen(str)); }
  string GetBuffer() {
    join();
    return buffer;
  }
  const char_type* data() {
    if (Siface::size(buffer) > 0) {
      if (size() > 0) join();
      return buffer.c_str();
    }
    return buf;
  }
  void clear() {
    tclear();
    Siface::clear(buffer);
  }
  bool compare(const char_type* str) { return strcmp(str, data()) == 0; }
  bool icompare(const char_type* str) { return _stricmp(str, data()) == 0; }
  // STL ostream iface
  tstringbuf& operator<<(const char_type val) {
    Add(val);
    return *this;
  }
  tstringbuf& operator<<(const char_type* val) {
    if (!val || !*val) return *this;
    Add(val, strlen(val));
    return *this;
  }
  tstringbuf& operator<<(int _val) {
    int_buf d(_val);
    Add(d.begin(), d.size());
    return *this;
  }
  tstringbuf& operator<<(unsigned _val) {
    int_buf d(_val);
    Add(d.begin(), d.size());
    return *this;
  }
  tstringbuf& operator<<(long _val) {
    int_buf d(_val);
    Add(d.begin(), d.size());
    return *this;
  }
  tstringbuf& operator<<(unsigned long _val) {
    int_buf d((unsigned)_val);
    Add(d.begin(), d.size());
    return *this;
  }
  tstringbuf& operator<<(double _val) {
    double_buf d(_val);
    Add(d.begin(), d.size());
    return *this;
  }
  tstringbuf& operator<<(long long _val) {
    long_buf d(_val);
    Add(d.begin(), d.size());
    return *this;
  }
  tstringbuf& operator<<(unsigned long long _val) {
    long_buf d(_val);
    Add(d.begin(), d.size());
    return *this;
  }
  tstringbuf& operator<<(const cz::gepro::tconstchar<typename tstringbuf::char_type>& _value) {
    Add(_value.c_str(), _value.size());
    return *this;
  }
  tstringbuf& operator<<(
      const cz::gepro::tconstchar<typename tstringbuf::char_type, cz::gepro::tstring_icompare<typename tstringbuf::char_type> >& _value) {
    Add(_value.c_str(), _value.size());
    return *this;
  }
#ifdef _STRING_
  tstringbuf& operator<<(const std::string& val) {
    if (val.empty()) return *this;
    Add(val.c_str(), val.length());
    return *this;
  }
#endif
  // STL iface
  tstringbuf& write(const char_type* str, size_type len) {
    Add(str, len);
    return *this;
  }
  tstringbuf& put(char_type c) {
    Add(c);
    return *this;
  }
  string str() { return GetBuffer(); }
  /**
       Zkrácení na požadovanou délku - nahrazení posledních znakù stringem r.
    
       @param _max maximální délka
       @param r    koncový text (...)
    */
  void trimr(size_type _max, const_pointer r) {
    if (size() > _max) {
      size_type rl = base_type::len(r);
      size_type l = Siface::size(buffer);
      size_type m = _max - rl;
      if (m < l) {
        // substring
        buffer = buffer.substr(0, m);
      }
      if (m <= l) {
        tclear();
        base_type::_append(r, rl);
        return;
      }
      base_type::trimr(_max - l, r);
    }
  }
  void cesky() {
    tcharbuf<char_type> tmp((char*)buffer.c_str(), buffer.size(), buffer.size());
    tmp._cesky();
    base_type::_cesky();
  }

 private:
  char_type buf[max + 1];
  string buffer;
  const char_type* tbegin() const { return base_type::begin(); }
  size_type tsize() const { return base_type::size(); }
  void tclear() { base_type::clear(); }
  void join() {
    buffer += tbegin();
    tclear();
  }
};
/** 
  @}
*/

};  // namespace gepro
};  // namespace cz

/** 
    @defgroup smartbufs
    @{
    Pro pohodlný pøevod stávajícího kódu na smartbuffers, jsou overloadovány
    nìkteré C funkce pro práci s øetìzci.
*/
/** strcpz pro zápis do tstringbuf
    @param S     string sloužící pro ukládání vìtších dat než je max
    @param max   maximální velikost bufferu (buffer nelze zvìtšit)
    @param E     char typ (char,wchar_t)
    @param Siface   tøída pøevádìjící non STL interface na požadovaný STL
*/
template <class S, unsigned max, class E, class Siface>
const E* strcpy(cz::gepro::tstringbuf<S, max, E, Siface>& dest, const E* src) {
  dest.clear();
  if (src) dest.Add(src, strlen(src));
  return dest.begin();
}
/** strcat pro zápis do tstringbuf
    @param S     string sloužící pro ukládání vìtších dat než je max
    @param max   maximální velikost bufferu (buffer nelze zvìtšit)
    @param E     char typ (char,wchar_t)
    @param Siface   tøída pøevádìjící non STL interface na požadovaný STL
*/
template <class S, unsigned max, class E, class Siface>
const E* strcat(cz::gepro::tstringbuf<S, max, E, Siface>& dest, const E* src) {
  if (src) dest.Add(src, strlen(src));
  return dest.begin();
}

/** strcpy pro zápis do tstatbuf. 
    @param max   maximální velikost bufferu (buffer nelze zvìtšit)
    @param E     char typ (char,wchar_t)
    @param O     tøída relizující operátory << 
*/
template <int max, class E>
const E* strcpy(cz::gepro::tstatbuf<max, E>& dest, const E* src) {
  dest.clear();
  if (src) dest.Add(src, strlen(src));
  return dest.begin();
}
/** strcat pro zápis do tstatbuf. 
    @param max   maximální velikost bufferu (buffer nelze zvìtšit)
    @param E     char typ (char,wchar_t)
    @param O     tøída relizující operátory << 
*/
template <int max, class E>
const E* strcat(cz::gepro::tstatbuf<max, E>& dest, const E* src) {
  if (src) dest.Add(src, strlen(src));
  return dest.begin();
}
/** strcpy pro zápis do tstatbufe. 
    @param max   maximální velikost bufferu (buffer nelze zvìtšit)
    @param E     char typ (char,wchar_t)
    @param O     tøída relizující operátory << 
*/
template <int max, class E>
const E* strcpy(cz::gepro::tstatbufe<max, E>& dest, const E* src) {
  dest.clear();
  if (src) dest.Add(src, strlen(src));
  return dest.begin();
}
/** strcat pro zápis do tstatbufe. 
    @param max   maximální velikost bufferu (buffer nelze zvìtšit)
    @param E     char typ (char,wchar_t)
    @param O     tøída relizující operátory << 
*/
template <int max, class E>
const E* strcat(cz::gepro::tstatbufe<max, E>& dest, const E* src) {
  if (src) dest.Add(src, strlen(src));
  return dest.begin();
}
/** 
  @}
*/
#endif  // __SDK_GEPRO_SMARTBUFS_H
