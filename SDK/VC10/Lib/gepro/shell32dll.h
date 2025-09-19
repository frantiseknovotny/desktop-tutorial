#ifndef DYNAMICLIBRARYNAME
#ifndef __SDK_SHELL32DLL_H
#define __SDK_SHELL32DLL_H
#define DYNAMICLIBRARYNAME shell32dll
#define DEFINCLUDE "shell32dll.h"
#include <gepro/concept/def_dynalib.h>
extern shell32dll shell32lib;
#endif
#else
//       libname,rettype,cname,params ....
PROCADR2("Shell_GetImageLists",int,Shell_GetImageLists,HIMAGELIST*,phiml,HIMAGELIST*,phimlSmall)
PROCADR1((const char*)660,int,FileIconInit,BOOL,restorecache)
PROCADR5("SHGetFolderPathA",HRESULT,SHGetFolderPathA,HWND,hWnd,int,csidl,HANDLE,hToken,DWORD,flags,char*,path)
PROCADR5("SHGetFolderPathW",HRESULT,SHGetFolderPathW,HWND,hWnd,int,csidl,HANDLE,hToken,DWORD,flags,wchar_t*,path)
#endif
