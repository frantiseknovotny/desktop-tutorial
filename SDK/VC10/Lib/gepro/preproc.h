#ifndef   ___GEPRO_PREPROC_H
#define   ___GEPRO_PREPROC_H
// uzitecna makra pro preprocesor
#define _DEFINE_QUOTE(str) #str
// generování stringu z identitkátoru
#define DEFINE_QUOTE(str) _DEFINE_QUOTE(str)
// generování textu ze souboru a øádku 
#define PREPROC_LINE_QUOTE(str) __FILE__"(" DEFINE_QUOTE(__LINE__)") : " str

/**
   sestaveni verze z jednotlivych component.

   @param major  hlavní verze
   @param minor  vedlejší verze
   @param rev    revize.
   @param subrev subrevize.
*/
#define GEPRO_MAKE_VERSION(major,minor,rev,subrev) ((major<<24)|(minor<<16)|(rev<<8)|(subrev))

// sestaveni verze wxWidgets
#if defined(wxMAJOR_VERSION) && defined(wxMINOR_VERSION) && defined(wxRELEASE_NUMBER) && defined(wxSUBRELEASE_NUMBER)
  #define SDK_WXWIDGETS_VERSION GEPRO_MAKE_VERSION(wxMAJOR_VERSION,wxMINOR_VERSION,wxRELEASE_NUMBER,wxSUBRELEASE_NUMBER)
#else
  #define SDK_WXWIDGETS_VERSION 0
#endif
#define PP_ERROR(msg) PREPROC_LINE_QUOTE("[ERROR] " msg)
#if DEBUG_PREPROC > 1
#define PP_WARN(msg) PREPROC_LINE_QUOTE("[WARN] " msg)
#else
#define PP_WARN(msg) 
#endif
#if DEBUG_PREPROC > 2
#define PP_INFO(msg) PREPROC_LINE_QUOTE("[INFO] " msg)
#else
#define PP_INFO(msg) 
#endif
#if DEBUG_PREPROC > 3
#define PP_DEBUG(msg) PREPROC_LINE_QUOTE("[DEBUG] " msg)
#else
#define PP_DEBUG(msg) 
#endif
#if DEBUG_PREPROC > 5
#define PP_TRACE(msg) PREPROC_LINE_QUOTE("[TRACE] " msg)
#else
#define PP_TRACE(msg) 
#endif
#endif
