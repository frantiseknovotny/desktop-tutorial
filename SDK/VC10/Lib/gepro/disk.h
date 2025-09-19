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
/** Testuje existenci souboru. (portov�no z kokes\s\_gfce.h)
 
  @param f   absolutn� cesta k souboru 
  
  @return bool  true/false
*/
inline bool FileExists(const char* f)  {
  return (_access(f,0)==0)?true:false;
}

/** Vr�t� ukazatel na jm�no souboru.
 
  @param f  jm�no souboru
  
  @return const char*  jm�no souboru
*/
inline const char* FileName(const char* f)
{
  const char* x=strrchr(f,'\\');
  if(x) return ++x;
  x=strrchr(f,'/');
  if(x) return ++x;
  return f;
}
/** Vr�t� ukazatel na p��ponu souboru - bez te�ky. Pokud se te�ka nenajde vr�t� NULL.
 
  @param f  jm�no souboru
  
  @return const char*  p��pona souboru
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