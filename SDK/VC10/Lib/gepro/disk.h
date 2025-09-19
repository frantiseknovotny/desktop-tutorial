#ifndef __SDK_GEPRO_DISK_H
#define __SDK_GEPRO_DISK_H
#if defined(DEBUG_PREPROC)
  #pragma message(__FILE__ "(1) : debug included")
#endif
#ifndef _INC_IO
  #include   <io.h>
#endif

namespace cz {
namespace gepro {
// testuje existenci souboru
/** Testuje existenci souboru. (portováno z kokes\s\_gfce.h)
 
  @param f   absolutní cesta k souboru 
  
  @return bool  true/false
*/
inline bool FileExists(const char* f)  {
  return (_access(f,0)==0)?true:false;
}

/** Vrátí ukazatel na jméno souboru.
 
  @param f  jméno souboru
  
  @return const char*  jméno souboru
*/
inline const char* FileName(const char* f)
{
  const char* x=strrchr(f,'\\');
  if(x) return ++x;
  x=strrchr(f,'/');
  if(x) return ++x;
  return f;
}
/** Vrátí ukazatel na pøíponu souboru - bez teèky. Pokud se teèka nenajde vrátí NULL.
 
  @param f  jméno souboru
  
  @return const char*  pøípona souboru
*/
inline const char* FileExt(const char* f)
{
  const char* x=FileName(f);
  const char* ext=strrchr(x,'.');
  if(ext) {
    ext++;
    return ext;
  }
  return NULL;
}
inline char* FileExt(char* f) {return (char*)FileExt((const char*)f);}

inline void FileRemove(const char* f) 
{
  if(FileExists(f)) _unlink(f);
}
}; //gepro
}; //cz
#endif