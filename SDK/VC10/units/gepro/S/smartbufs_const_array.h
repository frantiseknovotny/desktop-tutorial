#ifndef __TEST_SMARTBUFS_CONST_ARRAY_H
#define __TEST_SMARTBUFS_CONST_ARRAY_H

 
class smartbufsTest_const_array : public CxxTest::TestSuite
{
public:
    void test_void_int() {
      typedef cz::gepro::const_T_array<int> const_int_array;
      int buf[]={1,2,3,4,5,6,7,8,9};
      const_int_array a(buf,sizeof(buf)/sizeof(buf[0]));
      TS_ASSERT_EQUALS(a.size(),(size_t)9)
      TS_ASSERT_EQUALS(*a.begin(),1)
      TS_ASSERT_EQUALS(*(a.begin()+2), 3)
      const_int_array::const_iterator p=a.find(6);
      TS_ASSERT_EQUALS(p,buf+5)
    }
    void test_void_char() {
      typedef cz::gepro::const_T_array<cz::gepro::constchars> const_chars_array;
      cz::gepro::constchars buf[]={"1","2","3","4","5","6","7","8","9"};
      const_chars_array a(buf,sizeof(buf)/sizeof(buf[0]));
      TS_ASSERT_EQUALS(a.size(), (size_t)9)
      TS_ASSERT_EQUALS(*a.begin(),cz::gepro::constchars("1"))
      TS_ASSERT_EQUALS(*(a.begin()+2),cz::gepro::constchars("3"))
      const_chars_array::const_iterator p=a.find("6");
      TS_ASSERT_EQUALS(p,buf+5)
      const_chars_array::const_iterator p2=a[5];
      TS_ASSERT_EQUALS(p2,buf+5)
    }
};


#endif // __TEST_H
