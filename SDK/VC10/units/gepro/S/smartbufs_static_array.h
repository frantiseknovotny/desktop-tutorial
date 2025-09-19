#ifndef __TEST_SMARTBUFS_STATIC_ARRAY_H
#define __TEST_SMARTBUFS_STATIC_ARRAY_H

 
class smartbufsTest_static_array : public CxxTest::TestSuite
{
public:
    void test_void_int() {
      typedef cz::gepro::static_T_array<5,int,1> static_int_array;
      //int buf[]={1,2,3,4,5,6,7,8,9};
      static_int_array a;
      TS_ASSERT_EQUALS(a.size(),(size_t)5)
      TS_ASSERT_EQUALS(a[0],0)
      TS_ASSERT_EQUALS(a[4],0)
      try {
        a[5]=5;
        TS_ASSERT_EQUALS(a[5],0)
      } catch(std::exception& e) {
        _DUMP(e.what());
      }
      a[0]=1;
      a[4]=4;
      TS_ASSERT_EQUALS(a[0],1)
      TS_ASSERT_EQUALS(a[4],4)
    }
};


#endif // __TEST_H
