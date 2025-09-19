#ifndef __SDK_GEPRO_ENVIRON_H
#define __SDK_GEPRO_ENVIRON_H
#if defined(DEBUG_PREPROC)
#pragma message(__FILE__ "(1) : debug included")
#endif
#ifndef GEPRO_ENVIRON_BUFSIZE
#define GEPRO_ENVIRON_BUFSIZE 256
#endif
#ifndef ___SDK_GEPRO_STRING_H
#include <gepro/string.h>
#endif
namespace cz {
namespace gepro {
/** Funkce práci s environmentem procesu. */
namespace environment {
/** Vyzvedne hodnotu systémové promìnné

  @param          name    název promìnné
  @param [in,out] buf     výstupní buffer
  @param          bufsize velikost výstupního bufferu

  @returns poèet bytù ve výstupním buffer
   - 0  promìnná neexistuje
   - pokud je >= bufsize, vrací jak velký buffer je potøeba, buffer je neplatný
*/
inline size_t get(const char* name, char* buf, DWORD bufsize) { return GetEnvironmentVariableA(name, buf, bufsize); }
/** Vyzvedne délku hodnoty systémové promìnné.

  @param          name    název promìnné

  @returns délka hodnoty
    - 0 neexistuje
*/
inline size_t len(const char* name) {
  char buf[1];
  size_t r = GetEnvironmentVariableA(name, buf, 0);
  if (!r) return 0;
  return r - 1;
}
/** Zjistí zda systémová promìnná existuje.

  @param          name    název promìnné

  @returns true/false
*/
inline bool exists(const char* name) { return len(name) > 0; }
/** Vyzvedne hodnotu systémové promìnné

  @param          name    název promìnné
  @param [in,out] buf     výstupní buffer
  @param          bufsize velikost výstupního bufferu

  @returns poèet bytù ve výstupním buffer
   - 0  promìnná neexistuje
   - pokud je >= bufsize, vrací jak velký buffer je potøeba, buffer je neplatný
*/
inline size_t get(const wchar_t* name, wchar_t* buf, DWORD bufsize) { return GetEnvironmentVariableW(name, buf, bufsize); }
/** Vyzvedne délku hodnoty systémové promìnné.

  @param          name    název promìnné

  @returns délka hodnoty
    - 0 neexistuje
*/
inline size_t len(const wchar_t* name) {
  wchar_t buf[1];
  size_t r = GetEnvironmentVariableW(name, buf, 0);
  if (!r) return 0;
  return r - 1;
}
/** Zjistí zda systémová promìnná existuje.

  @param          name    název promìnné

  @returns true/false
*/
inline bool exists(const wchar_t* name) { return len(name) > 0; }
/** Vyzvedne názvy všech systémových promìnných do containeru A.

  @typeparam typ containeru - musí implementovat metodu void bool append(const wchar_t* buf,size_t len), která uloží pøedaný nazev promìnné pø:
    \code
    struct appender {
      std::vector<std::wstring> data;
      void append(const wchar_t* str, size_t len) { data.push_back(std::wstring(str,len)); }
    };
    \endcode

  @param [in,out] a instance containeru

  @seealso .
*/
template <typename A>
inline void names(A& a) {
  LPWCH b = GetEnvironmentStrings();
  LPWCH r = b;
  LPWCH n = r;
  r = strchr(n, '=');
  while (r) {
    size_t l = r - n;
    if (l) {
      if(!a.append(n, l)) break;
    }
    n = strchr(r + 1, 0);
    if (!n) break;
    ++n;
    if (!*n) break;
    r = strchr(n, '=');
  }
  FreeEnvironmentStrings(b);
}
/** Nastaví hodnotu systémové promìnné.

  @param  name název promìnné
  @param  buf  hodnota propmìnné

  @returns true/false
*/
inline bool set(const char* name, const char* buf) { return SetEnvironmentVariableA(name, buf)!=0; }
inline bool set(const wchar_t* name, const wchar_t* buf) { return SetEnvironmentVariableW(name, buf)!=0; }
/** Vyzvedne hodnotu systémové promìnné do stringu - musí podporovat operator =(const S::value_type* ptr);

  @typeparam S typ stringu
  @param          name název promìnné
  @param [out] res  výsledná hodnota prommìnné

  @returns poèet bytù ve výstupním stringu
   - 0  promìnná neexistuje
*/
template <typename S>
size_t get(const typename S::value_type* name, S& res) {
  typedef typename S::value_type char_type;
  char_type buf[GEPRO_ENVIRON_BUFSIZE];
  size_t r = get(name, buf, sizeof(buf));
  if (r <= sizeof(buf)) {
    res = buf;
    return r;
  }
  DWORD xr = (DWORD)r;
  char_type* b = (char_type*)alloca(xr);
  if (!b) throw "bad alloca";
  size_t r2 = get(name, b, xr);
  if (r2 <= r) res = b;
  return r2;
}
/** Pøipojí hodnotu na konec/zaèátek systémové promìnné - jako set(x,get(x) + a), nebo set(x,a+get(x)) pro prepend.
   Užiteèné napø. pro modifikaci PATH v procesu.

  @param  name    název promìnné.
  @param  a       pøidaná hodnota
  @param  _append append/prepend

  @returns nová délka promìnné.
*/
inline size_t append(const char* name, const char* a, bool _append = true) {
  char buf[GEPRO_ENVIRON_BUFSIZE];
  size_t alen = strlen(a);
  size_t r = get(name, buf, sizeof(buf));
  size_t nlen = r + alen;
  if (r >= sizeof(buf)) --nlen;  // v tomto pøípadì vrátilo r požadovanou délku a má navíc zero term
  if (nlen < sizeof(buf)) {
    if (_append) sdk::gepro::append(buf, r, a, alen);
    else
      sdk::gepro::prepend(buf, r, a, alen);
    set(name, buf);
    return nlen;
  }
  DWORD xlen = (DWORD)nlen;
  char* b = (char*)alloca(xlen + 2);
  if (!b) throw "bad alloca";
  size_t r2 = get(name, b, xlen + 1);
  if (r2 <= nlen) {
    if (_append) sdk::gepro::append(b, r2, a, alen);
    else
      sdk::gepro::prepend(b, r2, a, alen);
    set(name, b);
    return nlen;
  }
  return (size_t)-1;
}
/** Pøipojí hodnotu na zaèátek systémové promìnné - set(x,a+get(x)).
   Užiteèné napø. pro modifikaci PATH v procesu.

  @param  name    název promìnné.
  @param  a       pøidaná hodnota

  @returns nová délka promìnné.
*/
inline size_t prepend(const char* name, const char* a) { return append(name, a, false); }
};  // namespace environ
};  // namespace gepro
};  // namespace cz

#endif
