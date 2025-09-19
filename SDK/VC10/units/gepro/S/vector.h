#ifndef __VECTOR_TEST_H
#define __VECTOR_TEST_H

class vectorTest : public CxxTest::TestSuite
{
public:
    void test_0() {
      cz::gepro::unique_vector<int> a;
      a.push_back(1);
      a.push_back(2);
      a.push_back(1);
      a.push_back(2);
      a.push_back(1);
      TS_ASSERT_EQUALS(a.size(),(size_t)2)
      TS_ASSERT_EQUALS(a[0],1)
      TS_ASSERT_EQUALS(a[1],2)
    }
    void test_1() {
      cz::gepro::unique_vector<int,1> a;
      std::string ex;
      a.push_back(1);
      a.push_back(2);
      try {
        a.push_back(1);
      }catch(std::exception& e) {
        ex=e.what();
      }
      TS_ASSERT_EQUALS(a.size(), (size_t)2)
      TS_ASSERT_EQUALS(a[0],1)
      TS_ASSERT_EQUALS(a[1],2)
      TS_ASSERT_TEXT(ex.c_str(),"non unique item")
    }
    void test_plus() {
      cz::gepro::unique_vector<int> a;
      a.push_back(1);
      a.push_back(2);
      cz::gepro::unique_vector<int> b;
      b.push_back(1);
      b.push_back(2);
      b.push_back(3);
      a+=b;
      TS_ASSERT_EQUALS(a.size(), (size_t)3)
      TS_ASSERT_EQUALS(a[0],1)
      TS_ASSERT_EQUALS(a[1],2)
      TS_ASSERT_EQUALS(a[2],3)
    }
};


#endif // __TEST_H
