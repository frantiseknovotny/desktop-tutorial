#if defined(DEBUG_PREPROC)
  #pragma message(__FILE__ "(1) : debug included")
#endif
// zobrazeni obsahu struktur - definici _OITEM(v,t,i) lze modifikovat vystup na miste vlozeni
// v .. konkretni promenna, ktera se ma vypsat
// t .. typ polozky
// i .. nazev polozky

#ifndef _OITEM
  #define _OITEM(v,t,i) << #i"=" << v.i << "\n"
#endif

// PRINTER_INFO_2 - vsechny polozky
#define _O_PRINTER_INFO_2(v)\
_OITEM(v,LPTSTR,pServerName)\
_OITEM(v,LPTSTR,pPrinterName)\
_OITEM(v,LPTSTR,pShareName)\
_OITEM(v,LPTSTR,pPortName)\
_OITEM(v,LPTSTR,pDriverName)\
_OITEM(v,LPTSTR,pComment)\
_OITEM(v,LPTSTR,pLocation)\
_OITEM(v,LPDEVMODE,pDevMode)\
_OITEM(v,LPTSTR,pSepFile)\
_OITEM(v,LPTSTR,pPrintProcessor)\
_OITEM(v,LPTSTR,pDatatype)\
_OITEM(v,LPTSTR,pParameters)\
_OITEM(v,PSECURITY_DESCRIPTOR,pSecurityDescriptor)\
_OITEM(v,DWORD,Attributes)\
_OITEM(v,DWORD,Priority)\
_OITEM(v,DWORD,DefaultPriority)\
_OITEM(v,DWORD,StartTime)\
_OITEM(v,DWORD,UntilTime)\
_OITEM(v,DWORD,Status)\
_OITEM(v,DWORD,cJobs)\
_OITEM(v,DWORD,AveragePPM)

// DEVMODE - vsechny polozky
#define _O_DEVMODE(v)\
_OITEM(v,BCHAR,dmDeviceName)\
_OITEM(v,WORD,dmSpecVersion)\
_OITEM(v,WORD,dmDriverVersion)\
_OITEM(v,WORD,dmSize)\
_OITEM(v,WORD,dmDriverExtra)\
_OITEM(v,DWORD,dmFields)\
_OITEM(v,short,dmOrientation)\
_OITEM(v,short,dmPaperSize)\
_OITEM(v,short,dmPaperLength)\
_OITEM(v,short,dmPaperWidth)\
_OITEM(v,POINTL,dmPosition)\
_OITEM(v,short,dmScale)\
_OITEM(v,short,dmCopies)\
_OITEM(v,short,dmDefaultSource)\
_OITEM(v,short,dmPrintQuality)\
_OITEM(v,short,dmColor)\
_OITEM(v,short,dmDuplex)\
_OITEM(v,short,dmYResolution)\
_OITEM(v,short,dmTTOption)\
_OITEM(v,short,dmCollate)\
_OITEM(v,BCHAR,dmFormName)\
_OITEM(v,WORD,dmLogPixels)\
_OITEM(v,DWORD,dmBitsPerPel)\
_OITEM(v,DWORD,dmPelsWidth)\
_OITEM(v,DWORD,dmPelsHeight)\
_OITEM(v,DWORD,dmDisplayFlags)\
_OITEM(v,DWORD,dmDisplayFrequency)\
_OITEM(v,DWORD,dmICMMethod)\
_OITEM(v,DWORD,dmICMIntent)\
_OITEM(v,DWORD,dmMediaType)\
_OITEM(v,DWORD,dmDitherType)\
_OITEM(v,DWORD,dmReserved1)\
_OITEM(v,DWORD,dmReserved2)\
_OITEM(v,DWORD,dmPanningWidth)\
_OITEM(v,DWORD,dmPanningHeight)
