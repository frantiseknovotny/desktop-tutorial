#pragma warning(disable:4097 4786)
#define _CRT_SECURE_NO_WARNINGS
#include <gepro/windows.h>
#include <limits.h>
#include <float.h>
#include <cxxtest/geproSuite.h>
#include <cxxtest/stdAsserts.h>
#include <boost/algorithm/string/predicate.hpp>
#define TCHARBUF_VERSION 2
#include <gepro/hexa.h>
#include <gepro/vector>
#include <gepro/set>
#include <gepro/map>
#include <gepro/math.h>
#include <gepro/string.h>
#include <gepro/singleton.h>
#include <gepro/point.h>
#include <gepro/g2d.h>
#include <sql.h>
#include <gepro/types.h>
#include <gepro/defines.h>
#include <gepro/vtox.h>

#include <gepro/smartbufs2.h>
#include <gepro/smartarrays.h>
#include <gepro/exceptions2.h>
#include <gepro/string_algorithm.h>
#include <gepro/binary_find.h>
#include <gepro/disk.h>
#include <gepro/std2.h>
#include <gepro/variant.h>
#include <gepro/idataimpl.h>
#include <gepro/_stdformat.h>
#include <gepro/mtimer.h>
#include <gepro/mtimer2.h>

//#include <geprolib.h>


// CxxTest definitions and headers
<CxxTest preamble>

#define WRITE_DUMP
bool enable_dump=true;
#define _DUMP(x) if(enable_dump) std::cout << "\n" << x << "\n";
#define DUMP(x) if(enable_dump) std::cout << "\n" << x.str() << "\n";

int main( int argc, char *argv[] ) {
  if(argc==2&&!_stricmp(argv[1],"/xmlprinter")) {
    enable_dump=false;
    argv[1]=NULL;argc=1;
    CxxTest::GuiTuiRunner<CxxTest::Win32Gui, CxxTest::XmlPrinter>  tmp;
   return CxxTest::Main<CxxTest::GuiTuiRunner<CxxTest::Win32Gui, CxxTest::XmlPrinter> >( tmp, argc, argv );
  }
  CxxTest::GuiTuiRunner<CxxTest::Win32Gui, CxxTest::ParenPrinter>  tmp;
  return CxxTest::Main<CxxTest::GuiTuiRunner<CxxTest::Win32Gui, CxxTest::ParenPrinter> >( tmp, argc, argv );
}

//using namespace sdk::gepro;

<CxxTest world>