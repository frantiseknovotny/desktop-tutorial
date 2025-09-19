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
/** Funkce pr�ci s environmentem procesu. */
namespace environment {
/** Vyzvedne hodnotu syst�mov� prom�nn�

  @param          name    n�zev prom�nn�
  @param [in,out] buf     v�stupn� buffer
  @param          bufsize velikost v�stupn�ho bufferu

  @returns po�et byt� ve v�stupn�m buffer
   - 0  prom�nn� neexistuje
   - pokud je >= bufsize, vrac� jak velk� buffer je pot�eba, buffer je neplatn�
*/
inline size_t get(const char* name, char* buf, DWORD bufsize) { return GetEnvironmentVariableA(name, buf, bufsize); }
/** Vyzvedne d�lku hodnoty syst�mov� prom�nn�.

  @param          name    n�zev prom�nn�

  @returns d�lka hodnoty
    - 0 neexistuje
*/
inline size_t len(const char* name) {
  char buf[1];
  size_t r = GetEnvironmentVariableA(name, buf, 0);
  if (!r) return 0;
  return r - 1;
}
/** Zjist� zda syst�mov� prom�nn� existuje.

  @param          name    n�zev prom�nn�

  @returns true/false
*/
inline bool exists(const char* name) { return len(name) > 0; }
/** Vyzvedne hodnotu syst�mov� prom�nn�

  @param          name    n�zev prom�nn�
  @param [in,out] buf     v�stupn� buffer
  @param          bufsize velikost v�stupn�ho bufferu

  @returns po�et byt� ve v�stupn�m buffer
   - 0  prom�nn� neexistuje
   - pokud je >= bufsize, vrac� jak velk� buffer je pot�eba, buffer je neplatn�
*/
inline size_t get(const wchar_t* name, wchar_t* buf, DWORD bufsize) { return GetEnvironmentVariableW(name, buf, bufsize); }
/** Vyzvedne d�lku hodnoty syst�mov� prom�nn�.

  @param          name    n�zev prom�nn�

  @returns d�lka hodnoty
    - 0 neexistuje
*/
inline size_t len(const wchar_t* name) {
  wchar_t buf[1];
  size_t r = GetEnvironmentVariableW(name, buf, 0);
  if (!r) return 0;
  return r - 1;
}
/** Zjist� zda syst�mov� prom�nn� existuje.

  @param          name    n�zev prom�nn�

  @returns true/false
*/
inline bool exists(const wchar_t* name) { return len(name) > 0; }
/** Vyzvedne n�zvy v�ech syst�mov�ch prom�nn�ch do containeru A.

  @typeparam typ containeru - mus� implementovat metodu void bool append(const wchar_t* buf,size_t len), kter� ulo�� p�edan� nazev prom�nn� p�:
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
/** Nastav� hodnotu syst�mov� prom�nn�.

  @param  name n�zev prom�nn�
  @param  buf  hodnota propm�nn�

  @returns true/false
*/
inline bool set(const char* name, const char* buf) { return SetEnvironmentVariableA(name, buf)!=0; }
inline bool set(const wchar_t* name, const wchar_t* buf) { return SetEnvironmentVariableW(name, buf)!=0; }
/** Vyzvedne hodnotu syst�mov� prom�nn� do stringu - mus� podporovat operator =(const S::value_type* ptr);

  @typeparam S typ stringu
  @param          name n�zev prom�nn�
  @param [out] res  v�sledn� hodnota promm�nn�

  @returns po�et byt� ve v�stupn�m stringu
   - 0  prom�nn� neexistuje
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
/** P�ipoj� hodnotu na konec/za��tek syst�mov� prom�nn� - jako set(x,get(x) + a), nebo set(x,a+get(x)) pro prepend.
   U�ite�n� nap�. pro modifikaci PATH v procesu.

  @param  name    n�zev prom�nn�.
  @param  a       p�idan� hodnota
  @param  _append append/prepend

  @returns nov� d�lka prom�nn�.
*/
inline size_t append(const char* name, const char* a, bool _append = true) {
  char buf[GEPRO_ENVIRON_BUFSIZE];
  size_t alen = strlen(a);
  size_t r = get(name, buf, sizeof(buf));
  size_t nlen = r + alen;
  if (r >= sizeof(buf)) --nlen;  // v tomto p��pad� vr�tilo r po�adovanou d�lku a m� nav�c zero term
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
/** P�ipoj� hodnotu na za��tek syst�mov� prom�nn� - set(x,a+get(x)).
   U�ite�n� nap�. pro modifikaci PATH v procesu.

  @param  name    n�zev prom�nn�.
  @param  a       p�idan� hodnota

  @returns nov� d�lka prom�nn�.
*/
inline size_t prepend(const char* name, const char* a) { return append(name, a, false); }
};  // namespace environ
};  // namespace gepro
};  // namespace cz

#endif
