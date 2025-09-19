#ifndef   ___SDK_GEPRO_STRING_H
#define   ___SDK_GEPRO_STRING_H
#if defined(DEBUG_PREPROC)
  #pragma message(__FILE__ "(1) : debug included")
#endif
#if _MSC_VER > 1000
  #pragma once
#endif
#ifndef _INC_STRING
  #include <string.h>
#endif
/** C++ sjednoceni interface char a WCHAR. Funkce pro char jsou overloadovane pod stejným
    jménem pro WCHAR. 
*/
inline int strcmp(const wchar_t* a,const wchar_t* b) {return ::wcscmp(a,b);}
// !wcsicmp vraci r<0 r==0 r>0 pro kompatibilitu je nutno vracet -1,0,1
inline int stricmp(const wchar_t* a,const wchar_t* b) {
  int res=::_wcsicmp(a,b);
  if(res<0) return -1;
  if(res>0) return 1;
  return 0;
}
inline wchar_t* strchr(wchar_t* str,wchar_t c) {return ::wcschr(str,c);}
inline const wchar_t* strchr(const wchar_t* str,wchar_t c) {return ::wcschr(str,c);}
inline wchar_t* strrchr(wchar_t* str,wchar_t c) {return ::wcsrchr(str,c);}
inline const wchar_t* strrchr(const wchar_t* str,wchar_t c) {return ::wcsrchr(str,c);}
inline size_t strlen(const wchar_t* t) {return ::wcslen(t);}
inline double strtod(const wchar_t* v,wchar_t** r) {return ::wcstod(v,r);}
inline int strtol(const wchar_t* v,wchar_t** r,int b) {return ::wcstol(v,r,b);}
inline unsigned int strtoul(const wchar_t* v,wchar_t** r,int b) {return ::wcstoul(v,r,b);}
inline int _strnicmp(const wchar_t* str1,const wchar_t* str2,size_t len) {return ::_wcsnicmp(str1,str2,len);}
inline int g_atoi(const char *str) {return ::atoi(str);}
inline int g_atoi(const wchar_t *str) {return ::_wtoi(str);}
/*
inline int strncmp(const WCHAR* str1,const WCHAR* str2,size_t len) {return ::wcsncmp(str1,str2,len);}
inline int strnicmp(const WCHAR* str1,const WCHAR* str2,size_t len) {return ::_wcsnicmp(str1,str2,len);}
inline char* itoa(INT value,char* buf,int radix) {return ::_itoa(value,buf,radix);}
inline char* uitoa(UINT value,char* buf,int radix) {return ::_ultoa(value,buf,radix);}
inline char* ltoa(LONG value,char* buf,int radix) {return ::_ltoa(value,buf,radix);}
inline char* ultoa(ULONG value,char* buf,int radix) {return ::_ultoa(value,buf,radix);}
inline char* i64toa(INT64 value,char* buf,int radix) {return ::_i64toa(value,buf,radix);}
inline char* ui64toa(UINT64 value,char* buf,int radix) {return ::_ui64toa(value,buf,radix);}
inline wchar_t* itoa(int value,wchar_t* buf,int radix) {return ::_itow(value,buf,radix);}
inline wchar_t* _itoa(int value,wchar_t* buf,int radix) {return ::_itow(value,buf,radix);}
inline wchar_t* uitoa(UINT value,wchar_t* buf,int radix) {return ::_ultow(value,buf,radix);}
inline wchar_t* ltoa(LONG value,wchar_t* buf,int radix) {return ::_ltow(value,buf,radix);}
inline wchar_t* ultoa(ULONG value,wchar_t* buf,int radix) {return ::_ultow(value,buf,radix);}
inline wchar_t* i64toa(INT64 value,wchar_t* buf,int radix) {return ::_i64tow(value,buf,radix);}
inline wchar_t* ui64toa(UINT64 value,wchar_t* buf,int radix) {return ::_ui64tow(value,buf,radix);}
inline char* strcpy(char* _dst,unsigned char* _src) {return ::strcpy(_dst,(const char*)_src);}
inline int strlen(unsigned char* _src) {return ::strlen((const char*)_src);} 
#undef _CRT_SECURE_NO_WARNINGS
*/
#define SIZEARRAY(x) (sizeof(x)/sizeof(x[0]))
namespace sdk {
namespace gepro {

/** Kopíruje blok binárních hodnot. Použije memcpy - je to velmi rychle ale E mohou být pouze typy,
    které nevyžadují konstruktory - typicky POD a jejich struktury.

   <b>Pozor funkce nic nekontroluje, vše musí ošetøit volající funkce !</b>

  @typeparam E typ který se kopíruje
  @param [in,out] dest cílová adresa
  @param          src  zdrojová adresa
  @param          size poèet kopírovaných prvkù (ne bytù!).

  @returns dest
*/
template <class E>
E* memcpy(E* dest, const E* src, size_t size) {
  return (E*)::memcpy((void*)dest,(const void*)src,size*sizeof(E));
}
/** Pøesune blok binárních hodnot. Použije memmove - je to velmi rychle ale E mohou být pouze typy,
    které nevyžadují konstruktory - typicky POD a jejich struktury.

   <b>Pozor funkce nic nekontroluje, vše musí ošetøit volající funkce !</b>

  @typeparam E typ který se kopíruje
  @param [in,out] dest cílová adresa
  @param          src  zdrojová adresa
  @param          size poèet pøesouvaných prvkù (ne bytù!).

  @returns dest
*/
template <class E>
E* memmove(E* dest, const E* src, size_t size) {
  return (E*)::memmove((void*)dest,(const void*)src,size*sizeof(E));
}
/** Pøipojí prvky za dst, na konci vždy 0.

   <b>Pozor funkce nic nekontroluje, vše musí ošetøit volající funkce !</b>
  
  @typeparam E typ který se kopíruje.
  @param [in,out] dst    cílová adresa.
  @param          dstlen délka cílového bufferu
  @param          src    zdrojová adresa.
  @param          srclen poèet pøidaných prvkù (ne bytù!).
*/
template <class E>
inline void append(E* dst, size_t dstlen, const E* src, size_t srclen) {
  memcpy(dst+dstlen, src, srclen);
  dst[dstlen+srclen] ='\0';
}
/** Vloží prvky pøed dst, na konci vždy 0.

   <b>Pozor funkce nic nekontroluje, vše musí ošetøit volající funkce !</b>
  
  @typeparam E typ který se kopíruje.
  @param [in,out] dst    cílová adresa.
  @param          dstlen délka cílového bufferu
  @param          src    zdrojová adresa.
  @param          srclen poèet vložených prvkù (ne bytù!).
*/
template <class E>
void prepend(E* dst,size_t dstlen, const E* src, size_t srclen) {
  memmove(dst+srclen,dst,dstlen);
  memcpy(dst, src, srclen);
  dst[dstlen + srclen] = '\0';
}
/** Vloží prvky do dst na pozici at, na konci vždy 0.

   <b>Pozor funkce nic nekontroluje, vše musí ošetøit volající funkce !</b>
  
  @typeparam E typ který se kopíruje.
  @param [in,out] dst    cílová adresa.
  @param          dstlen délka cílového bufferu
  @param          at pozci vložení v dst
  @param          src    zdrojová adresa.
  @param          srclen poèet vložených prvkù (ne bytù!).
*/
template <class E>
void insert(E* dst, size_t dstlen, size_t at, const E* src, size_t srclen) {
  if (at == 0) prepend(dst, dstlen, src, srclen);
  else if (at == dstlen)
    append(dst, dstlen, src, srclen);
  else {
    memmove(dst + srclen+at, dst + at, dstlen - at);
    memcpy(dst + at, src, srclen);
    dst[dstlen + srclen] = '\0';
  }
}

};
};
namespace cz {
namespace gepro {
/** Porovnání stringù case sensitive

    @param E char type (char,wchar_t)
*/
template <class E> class tstring_compare {
    static int strncmp(const WCHAR* str1,const WCHAR* str2,size_t len) {return ::wcsncmp(str1,str2,len);}
    static int strncmp(const char* str1,const char* str2,size_t len) {return ::strncmp(str1,str2,len);}
  public:
    typedef E value_type;
    typedef const value_type* const_pointer;
    static int compare(const_pointer a,const_pointer b,size_t len) {
      int res=strncmp(a,b,len);
      if(res>0) return 1;
      if(res<0) return -1;
      return 0;
    }
};
/** Porovnání stringù case insensitive

    @param E char type (char,wchar_t)
*/
template <class E> class tstring_icompare {
  public:
    typedef E value_type;
    typedef const value_type* const_pointer;
    static int compare(const_pointer a,const_pointer b,size_t len) {
      int res=_strnicmp(a,b,len);
      if(res>0) return 1;
      if(res<0) return -1;
      return 0;
    }
};
/** Konstantní stringy - vhodné pro containery (set,map) kde klíèem je vždy konstantní
    øetìzec a je zbyteèné alokovat string. Pro STL containery poskytuje potøebné operátory.

    @param E char type (char,wchar_t)

    \code
      typedef std::map<cz::gepro::constchars,int> str2int;
      str2int m;
      m.insert(str2int::value_type(cz::gepro::constchars("alfa"),1));
      m.insert(str2int::value_type(cz::gepro::constchars("beta"),2));
      m.insert(str2int::value_type(cz::gepro::constchars("gama"),3));
      str2int::const_iterator i=m.find(cz::gepro::constchars("alfa"));
      TS_ASSERT_EQUALS(i->second,1)
      i=m.find(cz::gepro::constchars("gama"));
      TS_ASSERT_EQUALS(i->second,3)
      i=m.find(cz::gepro::constchars("beta"));
      TS_ASSERT_EQUALS(i->second,2)
      i=m.find(cz::gepro::constchars("delta"));
      TS_ASSERT_EQUALS(i,m.end())
    \endcode
*/
template <class E,class C=tstring_compare<E> > class tconstchar {
    const E* ptr_;
    size_t size_; 
	  static size_t minsize(size_t a,size_t b) {return (a<b)?a:b;}
  public:
    typedef E value_type;
    typedef E* pointer;
    typedef const E* const_pointer;
    typedef const_pointer const_iterator;
    static int compare(const_pointer a,const_pointer b,size_t len) {
      return C::compare(a,b,len);
    }
    const_iterator begin() const {return ptr_;}
    const_iterator end() const {return ptr_?ptr_+size_:nullptr;}
    size_t size() const {return size_;}
    size_t len() const {return size();}
    size_t length() const {return size();}
    const_pointer c_str() const {return ptr_;}
    bool empty() const {return ptr_?false:true;}
    tconstchar() {ptr_=NULL;size_=0;}
    tconstchar(const_pointer _ptr) {
      ptr_=_ptr;
      size_=0;
      if(_ptr) size_=strlen(_ptr);
    }
    tconstchar(const_pointer _ptr,size_t _size) {
      ptr_=_ptr;
      size_=_size;
    }
    void assign(const char* _ptr, size_t _size) {
      ptr_ = _ptr;
      size_ = _size;
    }
    void assign(const char* _ptr) {
      ptr_ = _ptr;
      size_ = 0;
      if (_ptr) size_ = strlen(_ptr);
    }
    void assign(const char* _ptr,const char* _end) {
      ptr_ = _ptr;
      size_ = 0;
      if (_ptr) size_ = _end - _ptr;
    }
    void operator=(const char* _ptr) { assign(_ptr); }
    bool operator==(const tconstchar& b) const {
      if(size()!=b.size()) return false;
      if(C::compare(begin(),b.begin(),size())) return false;
      return true;
    }
    bool operator<(const tconstchar& b) const {
      if(size()==0) {
        if(b.size()==0) return false;
        return true;
      }
      if(b.size()==0) return false;
      size_t l=minsize(size(),b.size());
      int res=C::compare(begin(),b.begin(),l);
      if(res<0) return true;
      if(res>0) return false;
      if(size()<b.size()) return true;
      return false;
    }
    bool operator <=(const tconstchar& b) const {
      if(size()==0) {
        return true;
      }
      if(b.size()==0) return false;
      size_t l=minsize(size(),b.size());
      int res=C::compare(begin(),b.begin(),l);
      if(res<0) return true;
      if(res>0) return false;
      if(size()<=b.size()) return true;
      return false;
    }
    bool operator >(const tconstchar& b) const {
      return !(*this<=b);
    }
    bool operator >=(const tconstchar& b) const {
      return !(*this<b);
    }
    bool operator !=(const tconstchar& b) const {
      return !(*this==b);
    }
    bool starts_with(const_pointer s, size_t l) const {
      if (l > size()) return false;
      int res = C::compare(begin(), s, l);
      return res == 0;
    }
    bool starts_with(const_pointer s) const { return starts_with(s, strlen(s)); }
    template <typename S>
    bool starts_with(const S& s) const {
      return starts_with(s.c_str(), s.length());
    }
    bool ends_with(const_pointer s, size_t l) const {
      if (l > size()) return false;
      int res = C::compare(begin() + size() - l, s, l);
      return res == 0;
    }
    bool ends_with(const_pointer s) const { return ends_with(s, strlen(s)); }
    template <typename S>
    bool ends_with(const S& s) const {
      return ends_with(s.c_str(), s.length());
    }
    void trim_to(value_type c) {
      if (ptr_) {
        const_pointer e = strchr(ptr_, c);
        if (e) {
          size_t l = e - ptr_;
          if (l < size_) size_ = l;
        }
      }
    }
    tconstchar substr(size_t start, size_t len = -1) const {
      if (start >= length()) return tconstchar();
      if (len == -1) len = length() - start;
      else if (len > start + length())
        len = length()-start;
      return tconstchar(ptr_ + start, len );
    }
};

typedef tconstchar<char> constchars;
typedef tconstchar<wchar_t> constwchars;
typedef tconstchar<char,tstring_icompare<char> > constcharsi;
typedef tconstchar<wchar_t,tstring_icompare<wchar_t> > constwcharsi;

typedef tstring_compare<char> string_compare;
typedef tstring_compare<wchar_t> wstring_compare;
typedef tstring_icompare<char> string_icompare;
typedef tstring_icompare<wchar_t> wstring_icompare;

/** Test na dir separator.
  @returns true/false
*/
inline bool is_dir_separator(int c) { return c == '/' || c == '\\'; }
/** Test zda string konèí na dir separator

  @typeparam E string char_type
  @param  str testovaý string

  @returns true/false
*/
template <typename E>
inline bool ends_dir_separator(const E* str) {
  str += strlen(str) - 1;
  return is_dir_separator(*str);
}
};
};  // namespace cz
namespace std {
template <typename S>
bool starts_with(const S& s) {
  return s.starts_with();
}
inline bool starts_with(const char* s,const char* x) {
  cz::gepro::constchars q(s);
  return q.starts_with(x);
}
}  // namespace std
#endif
  