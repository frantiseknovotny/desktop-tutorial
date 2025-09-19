#ifndef __SDK_GEPRO__VTOX_H
#define __SDK_GEPRO__VTOX_H
#if defined(DEBUG_PREPROC)
  #pragma message(__FILE__ "(1) : debug included")
#endif
namespace cz {
namespace gepro {
namespace vtoa {
namespace simple {
  /** Pøevody hodnoty na string - šablony využívají toho že funkce itoa atd. jsou 
      overloadované i pro wchar_t
  */
  template <class E>
  inline int vtoa(E* buf,unsigned bufsize,int value) {
    if(bufsize>=16) {
      _itoa(value,buf,10);
      return strlen(buf);
    }
    return 0; 
  }
  template <class E>
  inline int vtoa(E* buf,unsigned bufsize,unsigned int value) {
    if(bufsize>=16) {
      uitoa(value,buf,10);
      return strlen(buf);
    }
    return 0; 
  }
  template <class E>
  inline int vtoa(E* buf,unsigned bufsize,long value) {
    if(bufsize>=16) {
      gltoa(value,buf,10);
      return strlen(buf);
    }
    return 0; 
  }
  template <class E>
  inline int vtoa(E* buf,unsigned bufsize,unsigned long value) {
    if(bufsize>=16) {
      _ultoa(value,buf,10);
      return strlen(buf);
    }
    return 0; 
  }
  template <class E>
  inline int vtoa(E* buf,unsigned bufsize,__int64 value) {
    if(bufsize>=16) {
      i64toa(value,buf,10);
      return strlen(buf);
    }
    return 0; 
  }
  template <class E>
  inline int vtoa(E* buf,unsigned bufsize,unsigned __int64 value) {
    if(bufsize>=16) {
      ui64toa(value,buf,10);
      return strlen(buf);
    }
    return 0; 
  }
  template <class E>
  inline int vtoa(E* buf,unsigned bufsize,HWND value) {
    return vtoa(buf,bufsize,(const void*)value);
  }
  template <class E>
  inline int vtoa(E* buf,unsigned bufsize,HDC value) {
    return vtoa(buf,bufsize,(const void*)value);
  }
  template <class E>
  inline int vtoa(E* buf,unsigned bufsize,HPEN value) {
    return vtoa(buf,bufsize,(const void*)value);
  }
  template <class E>
  inline int vtoa(E* buf,unsigned bufsize,HANDLE value) {
    return vtoa(buf,bufsize,(const void*)value);
  }
}; //simple 
}; //vtoa
}; //gepro
}; //cz

#endif
