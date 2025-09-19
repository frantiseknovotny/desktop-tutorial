#ifndef __TEST_VTOW_H
#define __TEST_VTOW_H

/* vzor pro odvozeni dalsich testu - nemodifikovat */
using namespace cz::gepro::vtoa::simple;
#ifdef _M_X64
#else
#endif
class vtowTest : public CxxTest::TestSuite
{
public:
    void test_void_NULL() {
#ifdef _M_X64
      wchar_t buf[32];
      const void* v = NULL;
      size_t l = cz::gepro::vtoa::simple::vtoa(buf, SIZEARRAY(buf), v);
      TS_ASSERT_EQUALS(l, 16)
      TS_ASSERT_SAME_DATA(buf, L"0000000000000000", 34)
#else
      wchar_t buf[16];
      const void* v = NULL;
      int l = cz::gepro::vtoa::simple::vtoa(buf, SIZEARRAY(buf), v);
      TS_ASSERT_EQUALS(l, 8)
        TS_ASSERT_SAME_DATA(buf, L"00000000", 18)

#endif
    }
    void test_pchar_NULL_a() {
      wchar_t buf[16];
      const wchar_t* v = NULL;
      size_t l = cz::gepro::vtoa::simple::vtoa(buf, SIZEARRAY(buf), v);
      TS_ASSERT_EQUALS(l, (size_t)6)
      TS_ASSERT_SAME_DATA(buf, L"[null]", 14)
    }
    void test_pchar_NULL() {
      wchar_t buf[4];
      const wchar_t* v=NULL;
      size_t l=cz::gepro::vtoa::simple::vtoa(buf,SIZEARRAY(buf),v);
      TS_ASSERT_EQUALS(l, (size_t)3)
      TS_ASSERT_SAME_DATA(buf,L"[nu",8) 
    }
    void test_vtoa_int() {
      wchar_t buf[16];
      size_t l=cz::gepro::vtoa::simple::vtoa(buf,SIZEARRAY(buf),1);
      TS_ASSERT_EQUALS(l, (size_t)1)
      TS_ASSERT_SAME_DATA(buf,L"1",4) 
    }
    void test_vtoa_max() {
      wchar_t buf[16];
      size_t l=cz::gepro::vtoa::simple::vtoa(buf,SIZEARRAY(buf),MAXINT);
      TS_ASSERT_EQUALS(l, (size_t)10)
      TS_ASSERT_SAME_DATA(buf,L"2147483647",22) 
      l=cz::gepro::vtoa::simple::vtoa(buf,SIZEARRAY(buf),-MAXINT);
      TS_ASSERT_EQUALS(l, (size_t)11)
      TS_ASSERT_SAME_DATA(buf,L"-2147483647",24) 
    }
    void test_vtoa_double_max() {
      wchar_t buf[80];
      size_t l=cz::gepro::vtoa::simple::vtoa(buf,SIZEARRAY(buf),DBL_MAX);
      TS_ASSERT_EQUALS(l, (size_t)21)
      TS_ASSERT_SAME_DATA(buf,L"1.79769313486232e+308",44) 
    }
    void test_vtoa_POINT_0() {
      wchar_t buf[32];
      POINT v={0,0};
      size_t l=cz::gepro::vtoa::simple::vtoa(buf,SIZEARRAY(buf),v);
      TS_ASSERT_EQUALS(l, (size_t)5)
      TS_ASSERT_SAME_DATA(buf,L"{0,0}",12) 
    }
    void test_vtoa_RECT_0() {
      wchar_t buf[64];
      RECT v={0,0,0,0};
      size_t l=cz::gepro::vtoa::simple::vtoa(buf,SIZEARRAY(buf),v);
      TS_ASSERT_EQUALS(l, (size_t)9)
      TS_ASSERT_SAME_DATA(buf,L"{0,0-0,0}",20) 
    }
    void test_vtoa_buffer() {
      cz::gepro::vtoa::simple::buffer<256> b;
      b << DBL_MAX;
      TS_ASSERT_EQUALS(b.size(), (size_t)21)
      TS_ASSERT_SAME_DATA(b.begin(),"1.79769313486232e+308",22) 
      b << -MAXINT;
      TS_ASSERT_EQUALS(b.size(), (size_t)32)
      TS_ASSERT_SAME_DATA(b.begin(),"1.79769313486232e+308-2147483647",23) 
    }
    void test_vtoa_buffer_overflow() {
      cz::gepro::vtoa::simple::buffer<84> b;
      b << DBL_MAX;
      TS_ASSERT_EQUALS(b.size(), (size_t)21)
      TS_ASSERT_SAME_DATA(b.begin(),"1.79769313486232e+308",22) 
      b << DBL_MAX;
      TS_ASSERT_EQUALS(b.size(), (size_t)21)
      TS_ASSERT_SAME_DATA(b.begin(),"1.79769313486232e+308",22) 
    }
    void test_vtoa_buffer_overflow2() {
      cz::gepro::vtoa::simple::buffer<16> b;
      b << "1234567890";
      TS_ASSERT_EQUALS(b.size(), (size_t)10)
      TS_ASSERT_SAME_DATA(b.begin(),"1234567890",11) 
      b << "1234567890";
      TS_ASSERT_EQUALS(b.size(), (size_t)14)
      TS_ASSERT_SAME_DATA(b.begin(),"12345678901234",15) 
    }

    
};


#endif // __TEST_H
