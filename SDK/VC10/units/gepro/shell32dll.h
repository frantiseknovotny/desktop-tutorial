#ifndef DYNAMICLIBRARYNAME
#ifndef __LIB_SHELL32DLL_H
#define __LIB_SHELL32DLL_H
#define DYNAMICLIBRARYNAME shell32dll
#define DEFINCLUDE "shell32dll.h"
#define DYNALIB_ERRORS_PRINT
#include <gepro/concept/def_dynalib.h>
#endif
#else
//       libname,rettype,cname,params ....
PROCADR2("Shell_GetImageLists",int,Shell_GetImageLists,HIMAGELIST*,phiml,HIMAGELIST*,phimlSmall)

#endif
