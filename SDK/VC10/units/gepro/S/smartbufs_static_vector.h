#ifndef __TEST_SMARTBUFS_STATIC_VECTOR_H
#define __TEST_SMARTBUFS_STATIC_VECTOR_H

 
class smartbufsTest_static_vector : public CxxTest::TestSuite
{
public:
    void test_void_int() {
      typedef cz::gepro::static_T_vector<5,int,1> static_int_vector;
      //int buf[]={1,2,3,4,5,6,7,8,9};
      static_int_vector a;
      TS_ASSERT_EQUALS(a.size(), (size_t)0)
      try {
        a[5]=5;
        TS_ASSERT_EQUALS(a[5],0)
      } catch(std::exception& e) {
        _DUMP(e.what());
      }
      a[0]=1;
      TS_ASSERT_EQUALS(a.size(), (size_t)1)
      TS_ASSERT_EQUALS(a[0],1)
    }
};


#endif // __TEST_H
