#include <gepro/preproc.h>
/* Vzor pro generov�n� interface pro dynamicky linkovane knihovny. 
   Generuje se t��da, kter� obsahuje 
     - funk�n� pointery na funkce v DLL knihovn�
     - metody pro vol�n� funk�n�ch pointer� 
     - metodu GetProc realizuj�c� napln�n� pointer� funkcemi z DLL pomoc� GetProcAddress
     - metodu Verify ov��uj�c� napln�n� v�ech funk�n�ch pointer�
     - metodu Init a ReInit zaji��uj�c� zaveden� knihovny, vol�n� GetProc a Verify 

   Pokud Init nebo ReInit vr�t� false - nesm� se ��dn� metody volat - nen� zaji�t�no �e funk�n� pointery jsou platn� !
  
   Stejn� interface m��e b�t inicializov�n r�zn�mi knihovnami - opakovan� pomoc� ReInit
     !! nen� to singleton i kdy� n�kdy byl vhodn� !!

   Parametrizace vzoru:
   DYNAMICLIBRARYNAME         povinn� - jm�no t��dy realizuj�c� dznamick� p�ipojen� a vol�n� funk�n�ch pointer�
   DEFINCLUDE_CONCEPT_MACRO   nepovinn� - soubor obsahujc�c� definici maker PROCADRn
   DYNAMICLIBRARYNAME_BASE    nepovinn� - base class - d��ve odvozen� t��da (skl�d�n� slo�it�j��ch interface)
*/
#ifndef DEFINCLUDE_CONCEPT_MACRO
#define DEFINCLUDE_CONCEPT_MACRO <gepro/concept/def_dynalib_macro.h>
#endif
#if DEBUG_PREPROC > 1
#pragma message(PREPROC_LINE_QUOTE("DYNAMICLIBRARYNAME: ") DEFINE_QUOTE(DYNAMICLIBRARYNAME))
#endif
#ifdef DYNAMICLIBRARYNAME_BASE
class DYNAMICLIBRARYNAME : public DYNAMICLIBRARYNAME_BASE {
#else
class DYNAMICLIBRARYNAME {
#endif
  const char* library;
  HMODULE module;
  bool ok;
  DWORD lasterror;
#if DEBUG_PREPROC > 2
#pragma message("   DEF_FUNC_TYPEDEF: typedef r (__stdcall* fce##n)(t1 p1);")
#endif
#define DEF_FUNC_TYPEDEF
#include DEFINCLUDE_CONCEPT_MACRO
#include DEFINCLUDE

#if DEBUG_PREPROC > 2
#pragma message("   DEF_FUNC_VARIABLE: fce##n call##n;")
#endif
#define DEF_FUNC_VARIABLE
#include DEFINCLUDE_CONCEPT_MACRO
#include DEFINCLUDE
 public:
  void Free() {
    if (module) {
      FreeLibrary(module);
      module = NULL;
    }
  }
  bool _ReInit(const char* _library) {
    Free();
    module = LoadLibraryA(_library);
    if (!module) {
      lasterror = GetLastError();
      return false;
    }
    return true;
  }
  const char* Name() const { return library; }
  HMODULE Module() const { return module; }
  DYNAMICLIBRARYNAME() {
    ok = false;
    module = NULL;
    library = NULL;
    lasterror = 0;
  }
  ~DYNAMICLIBRARYNAME() { Free(); }
  bool Ok() const { return ok; }
  DWORD Error() const { return lasterror; }
  #ifdef DYNALIB_ERRORS_PRINT
  DWORD Error(char* buf, DWORD size) {
    return FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM, NULL, lasterror, MAKELANGID(LANG_NEUTRAL, SUBLANG_UI_CUSTOM_DEFAULT), buf, size,
                          NULL);
  }
  DWORD Error(wchar_t* buf, DWORD size) {
    return FormatMessageW(FORMAT_MESSAGE_FROM_SYSTEM, NULL, lasterror, MAKELANGID(LANG_NEUTRAL, SUBLANG_UI_CUSTOM_DEFAULT), buf, size,
                          NULL);
  }
  #endif
  bool Verify() {
    ok = true;
#if DEBUG_PREPROC > 2
#pragma message("   DEF_FUNC_VERIFY: if(!call##n) ok=false;")
#endif
#define DEF_FUNC_VERIFY
#include DEFINCLUDE_CONCEPT_MACRO
#include DEFINCLUDE
    return ok;
  }
#ifdef DYNALIB_ERRORS_PRINT
  template <typename O>
  void Verify(O& o) {
#if DEBUG_PREPROC > 2
#pragma message("   DEF_FUNC_VERIFY_MSG: if(!call##n) o << cn << '\n';")
#endif
#define DEF_FUNC_VERIFY_MSG
#include DEFINCLUDE_CONCEPT_MACRO
#include DEFINCLUDE
  }
#endif
  void GetProc() {
#if DEBUG_PREPROC > 2
#pragma message("   DEF_FUNC_GETPROCADDRESS: call##n=(fce##n)GetProcAddress(module,#n);")
#endif
#define DEF_FUNC_GETPROCADDRESS
#include DEFINCLUDE_CONCEPT_MACRO
#include DEFINCLUDE
  }
  bool ReInit(const char* _library) {
    if (!_ReInit(_library)) return false;
    library = _library;
    GetProc();
    ok = Verify();
#ifdef DYNAMICLIBRARYNAME_BASE
    if (ok) { ok = DYNAMICLIBRARYNAME_BASE::GetProc(module); }
#endif
    return ok;
  }
  bool Init(const char* _library) {
    if (!module) ReInit(_library);
    return ok;
  }
  bool ReInit(const char* _library, int flags) {
    Free();
    module = LoadLibraryExA(_library, NULL, flags);
    if (!module) return false;
    library = _library;
    GetProc();
    ok = Verify();
#ifdef DYNAMICLIBRARYNAME_BASE
    if (ok) { ok = DYNAMICLIBRARYNAME_BASE::GetProc(module); }
#endif
    return ok;
  }
  bool Init(const char* _library, int flags) {
    if (!module) ReInit(_library, flags);
    return ok;
  }
#if DEBUG_PREPROC > 2
#pragma message("   DEF_FUNC_CALL: r cn(t1 p1) {return call##n(p1);}")
#endif
#define DEF_FUNC_CALL
#include DEFINCLUDE_CONCEPT_MACRO
#include DEFINCLUDE

#if DEBUG_PREPROC > 2
#pragma message("   DEF_FUNC_VERIFY_DECL: fce##cn GetAddr##cn() {return call##cn=(fce##cn)GetProcAddress(module,n);}")
#endif
#define DEF_FUNC_VERIFY_DECL
#include DEFINCLUDE_CONCEPT_MACRO
#include DEFINCLUDE
};
#undef DYNAMICLIBRARYNAME
#undef DEFINCLUDE_CONCEPT_MACRO
#undef DEFINCLUDE
#undef PROC_STDCALL
#undef DYNALIB_ERRORS_PRINT