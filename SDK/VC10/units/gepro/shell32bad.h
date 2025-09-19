#ifndef DYNAMICLIBRARYNAME
#ifndef __LIB_SHELL32BAD_H
#define __LIB_SHELL32BAD_H
#define DYNAMICLIBRARYNAME shell32bad
#define DEFINCLUDE "shell32bad.h"
#define DYNALIB_ERRORS_PRINT
#include <gepro/concept/def_dynalib.h>
#endif
#else
//       libname,rettype,cname,params ....
PROCADR2("Shell_GetImageLists",int,Shell_GetImageLists,HIMAGELIST*,phiml,HIMAGELIST*,phimlSmall)
PROCADR2("XXShell_GetImageLists", int, XXShell_GetImageLists, HIMAGELIST*, phiml, HIMAGELIST*, phimlSmall)

#endif
