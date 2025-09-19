#ifndef __SDK_GEPRO_SMARTBUF_H
#define __SDK_GEPRO_SMARTBUF_H
#if defined(DEBUG_PREPROC)
  #pragma message(__FILE__ "(1) : debug included")
#endif

namespace cz {
namespace gepro {

// ************************************************************************** //
// **************                   smartbuf                   ************** //
// ************************************************************************** //

/**	\brief	The smartbuf struct
  primitivni ale sikovna strukturka
  priklad pouziti

    ...

    char buffer[1024];
    int bufsize=sizeof(buffer);
    smartbuf buf(buffer);

    //funkce DejNeco da neco do buf pokud se to nevejde vrati 0 a vyplni bufsize potrebnou velikosti
    int res=DejNeco(buf,bufsize);
    if (res==0) {
      buf=malloc(bufsize);
      if (!buf) {
        ...
      }
    }

    ...

    if (...)
      return 0;  //pripadne free dela destruktor smartbuf :-)

    ...

    if (...)
      return 0;  //pripadne free dela destruktor smartbuf :-)

    return 1;
  }

*/
struct smartbuf {
    char* buf;
    char* _buf;
    smartbuf(char* orig) {_buf=buf=orig;}
    ~smartbuf() {_Heaptest(buf);if(buf&&(buf!=_buf))free(buf);}
    operator char*() {return buf;}
};
}; //gepro
}; //cz

#endif

