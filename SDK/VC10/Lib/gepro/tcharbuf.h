#ifndef __SDK_GEPRO_TCHARBUF_H
#define __SDK_GEPRO_TCHARBUF_H
#if defined(DEBUG_PREPROC)
#pragma message(__FILE__ "(1) : debug included")
#endif
#ifndef __SDK_GEPRO_EXCEPTIONS_H
#include "exceptions.h"
#endif
#ifndef ___SDK_GEPRO_STRING_H
#include "string.h"
#endif
#ifndef __SDK_GEPRO_VTOA_H
#include "vtoa.h"
#endif
#ifndef __SDK_GEPRO_VTOW_H
#include "vtow.h"
#endif

class tcharbufTest;
#define CONVERT_TABLE_WIN2CESKY                                                                                                      \
  "\0\1\2\3\4\5\6\7\x8\x9\xa\xb\xc\xd\xe\xf\x10\x11\x12\x13\x14\x15\x16\x17\x18\x19\x1a\x1b\x1c\x1d\x1e\x1f "                        \
  "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~\x7f          S STZZ          s " \
  "stzz   l A    S    Z�� l �   as L lzRAAAALCCCEEEEIIDDNNOOOO RUUUUYT raaaalccceeeeiidonnoooo ruuuuyt ";

namespace cz {
namespace gepro {
template <class E>
class simplevtox {
 public:
  template <class V>
  static size_t vtoa(E* buf, size_t bufsize, const V& value) {
    return cz::gepro::vtoa::simple::vtoa(buf, bufsize, value);
  }
};

#define _DEFAULT_OPERATORS(Class)                              \
  Class& operator<<(const typename Class::char_type* _value) { \
    if (_value) write(_value, strlen(_value));                 \
    return *this;                                              \
  }                                                            \
  Class& operator<<(int _value) {                              \
    put(_value);                                               \
    return *this;                                              \
  }                                                            \
  Class& operator<<(unsigned int _value) {                     \
    put(_value);                                               \
    return *this;                                              \
  }                                                            \
  Class& operator<<(long _value) {                             \
    put(_value);                                               \
    return *this;                                              \
  }                                                            \
  Class& operator<<(unsigned long _value) {                    \
    put(_value);                                               \
    return *this;                                              \
  }                                                            \
  Class& operator<<(__int64 _value) {                          \
    put(_value);                                               \
    return *this;                                              \
  }                                                            \
  Class& operator<<(unsigned __int64 _value) {                 \
    put(_value);                                               \
    return *this;                                              \
  }                                                            \
  Class& operator<<(double _value) {                           \
    put(_value);                                               \
    return *this;                                              \
  }

/** Pomocn� t��da pro realizaci edita�n�ch operac� nad bufferm, samotn� alokace je zaji�t�na
    odvozenou t��dou, p��m� pou�it� t�to t��dy se nep�edpokl�d�.

    @param E     char typ (char,wchar_t)
    @param esig  pokud je nastaven na 1, bude signalizov�m medostatek pam�ti v�jimkou small_buffer
*/
template <class E, int esig = 0, class O = simplevtox<E> >
class tcharbuf {
  friend class tcharbufTest;
  // noncopayable!!!
  tcharbuf(const tcharbuf&);
  tcharbuf& operator=(const tcharbuf&);

 public:
  typedef E char_type;
  typedef E* pointer;
  typedef const E* const_pointer;
  typedef const_pointer iterator;
  typedef size_t size_type;
  static size_type len(const char* s) { return strlen(s); }
  static size_type len(const wchar_t* s) { return wcslen(s); }

 private:
  pointer _beg;   // za��tek bufferu
  pointer _last;  // posledn� obsazen� pozice - velikost = _last-_beg
  pointer _end;   // konec buffer - kapacita = _end-_beg
#if TCHARBUF_VERSION >=2
  bool _over;      // signalizace p�ete�en� - pokud nechceme generovat exception
#endif
  void memset(char* dest, int src, size_type size) { ::memset((void*)dest, src, size); }
  void memset(wchar_t* dest, int src, size_type size) {
    for (; size; size--) *dest++ = (E)src;
  }
  // editacni primitivy
  // primitivy netestuj�c� limity !!!
  // p�ipojit znak na konec
  void __append(E c) {
    *_last++ = c;
    *_last = E(0);
  }
  // p�ipojit �et�zec na konec
  void __append(const_pointer str, size_type len) {
    sdk::gepro::memcpy(_last, str, len);
    _last += len;
    *_last = E(0);
  }
  // vyplnit znakem
  void __fill(E c, size_type len) {
    memset(_last, c, len);
    _last += len;
    *_last = E(0);
  }

 protected:
  // posun aktualniho last o len znaku doprava
  size_type seekr(size_type len) {
    size_type _rspace = space();
    if (!_rspace) return 0;
    if (_rspace < len) len = _rspace;
    _last += len;
    *_last = E(0);
    return len;
  }

  /**
       Zkr�cen� na po�adovanou d�lku.
           
       @param len zadan� d�lka
    */
  void _trim(size_type len) {
    if (len >= size()) return;
    _last = _beg + len;
    *_last = E(0);
  }

 public:
  /** Konstruktor, pr�zdn� buffer 
     
      @param _ptr     za��atek bufferu
      @param max      celkov� velikost bufferu
    */
  tcharbuf(pointer _ptr, size_type max) {
    _beg = _last = _ptr;
    _end = _ptr + max - 1;
    *_last = E(0);
#if TCHARBUF_VERSION >= 2
    _over = false;
#endif
  }

  /**
       Konstruktor - lze zadat velikost bufferu a ji� vypln�n� data - len.
    
       @param  _ptr pointer na buffer
       @param  max  maxim�ln� velikost bufferu
       @param  len  obsazen� d�lka
    */
  tcharbuf(pointer _ptr, size_type max, size_type len) {
    _beg = _ptr;
    _last = _ptr + len;
    _end = _ptr + max - 1;
    *_last = E(0);
#if TCHARBUF_VERSION >= 2
    _over = false;
    if (len>=max) _over=true;
#endif
  }

  /** Smaz�n� bufferu
    */
  void clear() {
    _last = _beg;
    *_last = E(0);
#if TCHARBUF_VERSION >= 2
    _over = false;
#endif
  }
#if TCHARBUF_VERSION >= 2
  bool overflow() const { return _over; }
#endif
 protected:
  // ---------------------------------------------------------------------------------------
  // editacni fce - testuj�c� limty, sign�l p�ete�nen� lze odchytit jako vyj�mku, nebo logovat
  /** P�ipojen� �et�zce na konec bufferu
     
      @param str   vkl�dan� �et�zec
      @param len   d�lka vkl�dan�ho �et�zce

      @return      zapsan�ch znak�
    */
  size_type _append(const_pointer str, size_type len) {
    size_type _rspace = space();
    if (!_rspace) {
#if TCHARBUF_VERSION >= 2
      _over = true;
#endif
      if (esig) throw small_buffer();
      return 0;
    }
    if (_rspace < len) {
      __append(str, _rspace);
#if TCHARBUF_VERSION >= 2
      _over = true;
#endif
      if (esig) throw small_buffer();
      return _rspace;
    }
    __append(str, len);
    return len;
  }
  size_type _append(E c) {
    size_type _rspace = space();
    if (!_rspace) {
#if TCHARBUF_VERSION >= 2
      _over = true;
#endif
      if (esig) throw small_buffer();
      return 0;
    }
    __append(c);
    return 1;
  }
  size_type _fill(E c, size_type len) {
    size_type _rspace = space();
    if (!_rspace) {
#if TCHARBUF_VERSION >= 2
      _over = true;
#endif
      if (esig) throw small_buffer();
      return 0;
    }
    if (_rspace < len) {
      __fill(c, _rspace);
#if TCHARBUF_VERSION >= 2
      _over = true;
#endif
      if (esig) throw small_buffer();
      return _rspace;
    }
    __fill(c, len);
    return len;
  }

 public:
  // STL interface
  iterator begin() const { return (iterator)_beg; }
  iterator end() const { return (iterator)_last; }
  const_pointer c_str() const { return _beg; }
  /** Voln� prostor od _last do _end
    */
  size_type space() const { return _end - _last; }
  /** Obsazen� prostor od _beg do _last
    */
  size_type size() const { return _last - _beg; }
  bool empty() const { return size() == 0; }
  /** Celkov� kapacita bufferu
    */
  size_type capacity() const { return (_end - _beg); }
  char_type at(size_type i) const {
    if (_last == _beg) return 0;
    if (_beg + i >= _last) return 0;
    return *(_beg + i);
  }
  char_type first() const {
    if (_last == _beg) return 0;
    return *(_beg);
  }
  char_type last() const {
    if (_last == _beg) return 0;
    return *(_last - 1);
  }

  /** Porovn�n� string� s ohledem na velikost p�smen

       @param str porovn�van� string
    
       @return 
         - >0 porovn�van� string je v�t�� ne� string v bufferu
         - <0 porovn�van� string je v�t�� ne� string v bufferu
         - 0 porovn�van� string je shodn� se stringem v bufferu
    */
  int compare(const char_type* str) const { return strcmp(str, _beg); }
  /** Porovn�n� string� bez ohledu na velikost p�smen

       @param str porovn�van� string
    
       @return 
         - >0 porovn�van� string je v�t�� ne� string v bufferu
         - <0 porovn�van� string je v�t�� ne� string v bufferu
         - 0 porovn�van� string je shodn� se stringem v bufferu
    */
  int icompare(const char* str) const { return _stricmp(str, _beg); }
  int icompare(const wchar_t* str) const { return _wcsicmp(str, _beg); }
  tcharbuf& put(char_type c) {
    _append(c);
    return *this;
  }
  template <class V>
  tcharbuf& put(V v) {
    size_type l = O::vtoa(_last, space(), v);
    seekr(l);
    return *this;
  }
  _DEFAULT_OPERATORS(tcharbuf);

  void write(const char_type* ptr, size_type len) { _append(ptr, len); }

 protected:
  void _replace(char_type f, char_type t) {
    pointer e = strchr(_beg, f);
    while (e) {
      *e = t;
      e = strchr(e + 1, f);
    }
  }
  void _replace(char_type f, char_type t, char_type term) {
    if (term) {
      pointer e = strchr(_beg, term);
      if (e) *e = '\0';
    }
    pointer e = strchr(_beg, f);
    while (e) {
      *e = t;
      e = strchr(e + 1, f);
    }
  }
  void _capitalize() {
    if (size()) {
      pointer e = _beg;
      *e = (char_type)::toupper(*e);
      while (e < _last) {
        e = strchr(e, ' ');
        if (!e) break;
        e++;
        for (; e < _last; e++) {
          if (*e != ' ') break;
        }
        if (e < _last) *e = (char_type)::toupper(*e);
        e++;
      }
    }
  }
  void _setcapacity(size_type l) {
    if (!l) {
      _end = _last = _beg;
      *_last = E(0);
      return;
    }
    if (l >= capacity()) return;
    _end = _beg + l;
    if (_end <= _last) {
      _last = _end - 1;
      *_last = E(0);
    }
  }
  static void repchars(char* r, size_type len, unsigned char* cnv) {
    for (; len; len--, r++) *r = cnv[*(unsigned char*)r];
  }
  static void toupper(char* str) { _strupr(str); }
  static void toupper(wchar_t* str) { _wcsupr(str); }
  static void tolower(char* str) { _strlwr(str); }
  static void tolower(wchar_t* str) { _wcslwr(str); }

 public:
  // stringove operace
  void _lower() { tolower(_beg); }
  void _upper() { toupper(_beg); }
  void _cesky() {
    static unsigned char cnv[] = CONVERT_TABLE_WIN2CESKY;
    repchars(_beg, size(), cnv);
  }

  /** P�ipojen� �et�zce na konec bufferu
     
      @param str   vkl�dan� �et�zec
      @param len   d�lka vkl�dan�ho �et�zce

      @return      reference na objekt
    */
  tcharbuf& append(const_pointer str, size_type len) {
    _append(str, len);
    return *this;
  }
  /** P�ipoj� znak na konec, pokud znak p�ipojen nen�
    
      @param  ch p�ipojovan� znak
    
      @return      reference na objekt
    */
  tcharbuf& append_if_not(char_type ch) {
    if (last() != ch) _append(ch);
    return *this;
  }
  /** Nahrad� znak f znakem t
    
      @param  f nahrazovan� znak
      @param  t n�hradn� znak
    */
  void replace(char_type f, char_type t) { _replace(f, t); }
  /** Nahrad� znak f znakem t, pokud je nalezen znak term, je nahrazen 0 a process je ukon�en
    
      @param  f    nahrazovan� znak.
      @param  t    n�hradn� znak.
      @param  term znak termin�tor
    */
  void replace(char_type f, char_type t, char_type term) { _replace(f, t, term); }
  /**
       Pokud je velikost bufferu v�t�� ne� po�adovan� d�lka _max, p�ipoj� na konec �et�zec r, tak aby celkov� d�lka byla najv�ce _max.
       Vhodn� pro nahrazen� dlouh�ch text� Abcde ...
    
       @param _max maxim�ln� d�lka
       @param r    koncov� text (...)
    */
  void trimr(size_type _max, const_pointer r) {
    if (size() > _max) {
      size_type l = len(r);
      _trim(_max - l);
      _append(r, l);
    }
  }
};
};  // namespace gepro
};  // namespace cz

#endif  // __GEPRO_TCHARBUF_H
