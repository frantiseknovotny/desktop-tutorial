#ifndef __TEST_VTOA_H
#define __TEST_VTOA_H

/* vzor pro odvozeni dalsich testu - nemodifikovat */
using namespace cz::gepro::vtoa::simple;

class vtoaTest : public CxxTest::TestSuite
{
public:
    void test_void_NULL() {
#ifdef _M_X64
      char buf[32];
      const void* v = NULL;
      size_t l = cz::gepro::vtoa::simple::vtoa(buf, sizeof(buf), v);
      TS_ASSERT_EQUALS(l, 16)
      TS_ASSERT_SAME_DATA(buf, "0000000000000000", 17)
#else
      char buf[16];
      const void* v = NULL;
      int l = cz::gepro::vtoa::simple::vtoa(buf, sizeof(buf), v);
      TS_ASSERT_EQUALS(l, 8)
      TS_ASSERT_SAME_DATA(buf, "00000000", 9)
#endif

    }
    void test_pchar_NULL_a() {
      char buf[16];
      const char* v=NULL;
      size_t l=cz::gepro::vtoa::simple::vtoa(buf,sizeof(buf),v);
      TS_ASSERT_EQUALS(l, (size_t)6)
      TS_ASSERT_SAME_DATA(buf,"[null]",7) 
    }
    void test_pchar_NULL() {
      char buf[4];
      const char* v=NULL;
      size_t l=cz::gepro::vtoa::simple::vtoa(buf,sizeof(buf),v);
      TS_ASSERT_EQUALS(l, (size_t)3)
      TS_ASSERT_SAME_DATA(buf,"[nu",4) 
    }
    void test_vtoa_int() {
      char buf[16];
      size_t l=cz::gepro::vtoa::simple::vtoa(buf,sizeof(buf),1);
      TS_ASSERT_EQUALS(l, (size_t)1)
      TS_ASSERT_SAME_DATA(buf,"1",2) 
    }
    void test_vtoa_max() {
      char buf[16];
      size_t l=cz::gepro::vtoa::simple::vtoa(buf,sizeof(buf),MAXINT);
      TS_ASSERT_EQUALS(l, (size_t)10)
      TS_ASSERT_SAME_DATA(buf,"2147483647",11) 
      l=cz::gepro::vtoa::simple::vtoa(buf,sizeof(buf),-MAXINT);
      TS_ASSERT_EQUALS(l, (size_t)11)
      TS_ASSERT_SAME_DATA(buf,"-2147483647",12) 
    }
    void test_vtoa_double_max() {
      char buf[80];
      size_t l=cz::gepro::vtoa::simple::vtoa(buf,sizeof(buf),DBL_MAX);
      TS_ASSERT_EQUALS(l, (size_t)21)
      TS_ASSERT_SAME_DATA(buf,"1.79769313486232e+308",22) 
    }
    void test_vtoa_double() {
      char buf[80];
      size_t l=cz::gepro::vtoa::simple::vtoa(buf,sizeof(buf),11.1,10);
      _DUMP(buf)
      TS_ASSERT_EQUALS(l, (size_t)4)
      TS_ASSERT_SAME_DATA(buf,"11.1",5) 
    }
    void test_vtoa_POINT_0() {
      char buf[32];
      POINT v={0,0};
      size_t l=cz::gepro::vtoa::simple::vtoa(buf,sizeof(buf),v);
      TS_ASSERT_EQUALS(l, (size_t)5)
      TS_ASSERT_SAME_DATA(buf,"{0,0}",6) 
    }
    void test_vtoa_RECT_0() {
      char buf[64];
      RECT v={0,0,0,0};
      size_t l=cz::gepro::vtoa::simple::vtoa(buf,sizeof(buf),v);
      TS_ASSERT_EQUALS(l, (size_t)9)
      TS_ASSERT_SAME_DATA(buf,"{0,0,0,0}",10) 
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
