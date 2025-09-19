#ifndef __TEST_DYNALIB_H
#define __TEST_DYNALIB_H

/* vzor pro odvozeni dalsich testu - nemodifikovat */

#include "../shell32dll.h"
#include "../shell32bad.h"

class TestDYNALIB : public CxxTest::TestSuite
{
public:
    void test_ok() {
      shell32dll shell;
      bool ok=shell.Init("shell32.dll");
      TS_ASSERT_EQUALS(ok,true)
    }
    void test_bad() {
      shell32dll shell;
      bool ok = shell.Init("xxxshell32.dll");
      TS_ASSERT_EQUALS(ok, false)
      TS_ASSERT_EQUALS(shell.Error(), (DWORD)126)
      char buf[1024];
      DWORD len=shell.Error(buf,sizeof(buf)-1);
      wchar_t wbuf[1024];
      DWORD wlen = shell.Error(wbuf, sizeof(wbuf)/2 - 1);
      UNUSED(len)
      UNUSED(wlen)
    }
    void test_func() {
      shell32bad shell;
      bool ok = shell.Init("shell32.dll");
      TS_ASSERT_EQUALS(ok, false)
      cz::gepro::tstatbuf<1024> o;
      shell.Verify(o);
      const char* s=o.c_str();
      UNUSED(s)
    }
};


#endif // __TEST_H
