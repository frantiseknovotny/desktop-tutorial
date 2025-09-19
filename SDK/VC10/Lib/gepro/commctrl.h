#ifndef __SDK_GEPRO_COMMCTRL_H
#define __SDK_GEPRO_COMMCTRL_H
#if defined(DEBUG_PREPROC)
  #pragma message(__FILE__ "(1) : debug included")
#endif
#ifndef _INC_COMMCTRL
  #include <commctrl.h>
#endif

// subclass combobox

#define CB_GETCOMBOBOXINFO 0x0164
struct GCOMBOBOXINFO:public COMBOBOXINFO {
  GCOMBOBOXINFO() {cbSize=sizeof(*this);}
};

#endif
