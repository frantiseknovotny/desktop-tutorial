#ifndef __SDK_GEPRO_SMARTBUFS2_H
#define __SDK_GEPRO_SMARTBUFS2_H
#if defined(DEBUG_PREPROC)
  #pragma message(__FILE__ "(1) : debug included")
#endif
#include "smartbufs.h"

namespace cz {
namespace gepro {
/** Pomocn� t��da - dummy STL string interface
*/
template <class S, class E>
class STLifacestring2 {
 public:
  typedef E char_type;
  static void clear(S& s) { s = S(); }
  static size_t size(S& s) { return s.size(); }
  static const char_type* begin(S& s) { return s.c_str(); }
  static void append(S& s, const E* p, size_t l) { s.append(p, l); }
};
/** Pomocn� t��da - p�evod CString interface na STL string interface
*/
template <class S, class E>
class STLCString2 {
 public:
  typedef E char_type;
  static void clear(S& s) { s.Empty(); }
  static size_t size(S& s) { return s.GetLength(); }
  static const char_type* begin(S& s) { return (const char_type*)s; }
  static void append(S& s, const E* p, size_t l) { s += S(p, l); }
};
/** Pomocn� t��da - p�evod cz::gepro::String interface na STL string interface
*/
template <class S, class E>
class Stringface2 {
 public:
  typedef E char_type;
  static void clear(S& s) { s.clear(); }
  static size_t size(S& s) { return s.len(); }
  static const char_type* begin(S& s) { return s.begin(); }
  static void append(S& s, const E* p, size_t l) { s += S(p, l); }
};
/** Dynamick� buffer vhodn� jako n�hrada ostream a char[]. Pokud d�lka vkl�dan�ch dat
    nep�es�hne  velikost max, pou��v� se staticky alokovan� buffer, pokud jsou data del��,
    p�i�te se statick� buffer ke stringu, vynuluje se a op�t slou�� pro na��t�n�.
    Jak�koliv p��stup k intern�mu bufferu zajist�, aby se data podle pot�eby se�etla
    a vr�til se spr�vn� pointer na aktu�ln� �et�zec.

    V�znam� u�et�� alokace p�i s��t�n� string�, vylad�n� lze prov�st nastaven�m 
    velikosti statick�ho bufferu - max. Pro snadn�j�� manipulaci je mo�no pou��t v�stupn�ch operator� <<, 
    postupn� je dopl�ov�n interface pro std::basic_ostream a std::basic_string.


    \code
      typedef cz::gepro::tstringbuf<std::string,4> strbuf;
      strbuf buf;
      buf+="1234";
      TS_ASSERT_EQUALS(buf.size(),4)
      buf << "567890";
      TS_ASSERT_EQUALS(buf.size(),10)
      TS_ASSERT_TEXT(buf.begin(),"1234567890")
    \endcode

    K dispozici jsou overloadovan� funkce strcpy, strcat atd., aby se buffer nechal pou��vat i bez zm�ny
    k�du, pouhou n�hradou deklarace prom�nn�.
    \code
      // char buf[256];
      // nahrazen�m se zisk� 'neomezen�' buffer s po��te�n� velikost� 4
      typedef cz::gepro::tstringbuf<std::string,4> strbuf;
      strbuf buf;
      strcpy(buf,"12345678");
      TS_ASSERT_EQUALS(buf.size(),8)
      strcat(buf,"90");
      TS_ASSERT_EQUALS(buf.size(),10)
      TS_ASSERT_TEXT(buf.begin(),"1234567890")
    \endcode

    @param S     string slou��c� pro ukl�d�n� v�t��ch dat ne� je max, lze pou��t libovoln� string
                 podporuj�c� oper�tor += a STL interface. Pokud se pou�ije jin� string nap�
                 (CString) pak je nutno nastavit odpov�daj�c� transforma�n� Siface 
                 (pro CString je to STLCString).
                 \code
                  typedef cz::gepro::tstringbuf<CString,64,char,STLCstring<CString,char> > mmydynabuf;
                 \endcode
    @param max   maxim�ln� velikost bufferu (buffer nelze zv�t�it)
    @param E     char typ (char,wchar_t)
    @param Siface   t��da p�ev�d�j�c� non STL interface na po�adovan� STL
*/
template <class S, unsigned max, class E = char, class Siface = STLifacestring2<S, E> >
class tstringbuf2 : public tcharbuf<E> {
 public:
  typedef size_t size_type;
  typedef E char_type;
  typedef tcharbuf<char_type> base_type;
  typedef S string;
  typedef Double<char_type> double_buf;
  typedef Int<char_type> int_buf;
  typedef LongInt<char_type> long_buf;
  typedef typename base_type::const_pointer const_pointer;
  tstringbuf2() : tcharbuf<char_type>(buf, max) {}
  tstringbuf2(const tstringbuf2& src) : tcharbuf<char_type>(buf, max) {
    buffer = src.buffer;
    base_type::_append(src.tcharbuf<char_type>::begin(), src.tcharbuf<char_type>::size());
  }
  tstringbuf2(const char_type* src) : tcharbuf<char_type>(buf, max) {
    *buf = '\0';
    base_type::_append(src, strlen(src));
  }
  tstringbuf2& operator=(const tstringbuf2& src) {
    clear();
    buffer = src.buffer;
    base_type::_append(src.tcharbuf<char_type>::begin(), src.tcharbuf<char_type>::size());
    return *this;
  }
  size_t size() { return Siface::size(buffer) + tsize(); }
  const char_type* begin() {
    if (Siface::size(buffer) == 0) return tbegin();
    if (tsize() > 0) join();
    return Siface::begin(buffer);
  }
  const_pointer c_str() { return begin(); }
  tstringbuf2& append_if_not(char_type ch) {
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
  void Add(char_type c, size_t n) {
    for (; n; n--) Add(c);
  }
  size_type AddTokens(const char_type* str, size_t n, char_type token, char_type delim = '\0') {
    const char_type* end = str + n;
    size_type cnt = 0;
    const char_type* s = strchr(str, token);
    for (; str < end;) {
      if (!s) {
        const char_type* s2 = strchr(str, '\0');
        size_type l = s2 - str;
        if (l > 0) {
          ++cnt;
          Add(str, l);
          Add(delim);
          Add(delim);
        }
        return cnt;
      }
      size_type l = s - str;
      if (l) {
        ++cnt;
        Add(str, l);
        Add(delim);
      }
      str = s + 1;
      s = strchr(str, token);
    }
    return cnt;
  }
  void operator+=(const char_type* str) { Add(str, strlen(str)); }
  string GetBuffer() {
    join();
    return buffer;
  }
  const char_type* data() {
    if (Siface::size(buffer) > 0) {
      if (size() > 0) join();
      return buffer.begin();
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
  tstringbuf2& operator<<(const char_type val) {
    Add(val);
    return *this;
  }
  tstringbuf2& operator<<(const char_type* val) {
    if (!val || !*val) return *this;
    Add(val, strlen(val));
    return *this;
  }
  tstringbuf2& operator<<(int _val) {
    int_buf d(_val);
    Add(d.begin(), d.size());
    return *this;
  }
  tstringbuf2& operator<<(unsigned _val) {
    int_buf d(_val);
    Add(d.begin(), d.size());
    return *this;
  }
  tstringbuf2& operator<<(long _val) {
    int_buf d(_val);
    Add(d.begin(), d.size());
    return *this;
  }
  tstringbuf2& operator<<(unsigned long _val) {
    int_buf d((unsigned)_val);
    Add(d.begin(), d.size());
    return *this;
  }
  tstringbuf2& operator<<(long long _val) {
    long_buf d(_val);
    Add(d.begin(), d.size());
    return *this;
  }
  tstringbuf2& operator<<(unsigned long long _val) {
    long_buf d(_val);
    Add(d.begin(), d.size());
    return *this;
  }
  tstringbuf2& operator<<(double _val) {
    double_buf d(_val);
    Add(d.begin(), d.size());
    return *this;
  }
  tstringbuf2& operator<<(const cz::gepro::tconstchar<typename tstringbuf2::char_type>& _value) {
    Add(_value.c_str(), _value.size());
    return *this;
  }
  tstringbuf2& operator<<(
      const cz::gepro::tconstchar<typename tstringbuf2::char_type, cz::gepro::tstring_icompare<typename tstringbuf2::char_type> >& _value) {
    Add(_value.c_str(), _value.size());
    return *this;
  }

#ifdef _STRING_
  tstringbuf2& operator<<(const std::string& val) {
    if (val.empty()) return *this;
    Add(val.c_str(), val.length());
    return *this;
  }
#endif
  // STL iface
  tstringbuf2& write(const char_type* str, size_t len) {
    Add(str, len);
    return *this;
  }
  tstringbuf2& put(char_type c) {
    Add(c);
    return *this;
  }
  string str() { return GetBuffer(); }
  /**
       Zkr�cen� na po�adovanou d�lku - nahrazen� posledn�ch znak� stringem r.
    
       @param _max maxim�ln� d�lka
       @param r    koncov� text (...)
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
    Siface::append(buffer, tbegin(), tsize());
    tclear();
  }
};

template <typename S>
struct string_iface {
  typedef S string_type;
};
template <size_t V,typename S>
struct xstringbuf:tstringbuf<S,V,typename string_iface<S>::char_type,typename string_iface<S>::iface> {
  typedef S string_type;
  typedef tstringbuf<string_type, V, typename string_iface<string_type>::char_type, typename string_iface<string_type>::iface> base_type;
  S str() { return base_type::GetBuffer(); }
};

template <typename S>
struct string_iface2 {
  typedef S string_type;
};
template <size_t V, typename S>
struct xstringbuf2 : tstringbuf2<S, V, typename string_iface2<S>::char_type, typename string_iface2<S>::iface> {
  typedef S string_type;
  typedef tstringbuf2<string_type, V, typename string_iface2<string_type>::char_type, typename string_iface2<string_type>::iface> base_type;
  S str() { return base_type::GetBuffer(); }
};
};  // namespace gepro
};
#endif
