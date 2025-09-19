#include <gepro/preproc.h>
/* Vzor pro generování interface pro dynamicky linkovane knihovny. 
   Generuje se tøída, která obsahuje 
     - funkèní pointery na funkce v DLL knihovnì
     - metody pro volání funkèních pointerù 
     - metodu GetProc realizující naplnìní pointerù funkcemi z DLL pomocí GetProcAddress
     - metodu Verify ovìøující naplnìní všech funkèních pointerù
     - metodu Init a ReInit zajišující zavedení knihovny, volání GetProc a Verify 

   Pokud Init nebo ReInit vrátí false - nesmí se ádné metody volat - není zajištìno e funkèní pointery jsou platné !
  
   Stejnı interface mùe bıt inicializován rùznımi knihovnami - opakovanì pomocí ReInit
     !! není to singleton i kdy nìkdy byl vhodnı !!

   Parametrizace vzoru:
   DYNAMICLIBRARYNAME         povinnı - jméno tøídy realizující dznamické pøipojení a volání funkèních pointerù
   DEFINCLUDE_CONCEPT_MACRO   nepovinnı - soubor obsahujcící definici maker PROCADRn
   DYNAMICLIBRARYNAME_BASE    nepovinnı - base class - døíve odvozená tøída (skládání sloitìjších interface)
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