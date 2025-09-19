#ifndef __TEST_STRING_ALGORITHM_H
#define __TEST_STRING_ALGORITHM_H

using namespace cz::gepro;
/** Test funkci ze string_algorithm.h
*/
class string_algorithmTest : public CxxTest::TestSuite
{
public:

    void test_ifind_and_replace() {
      std::string s="aasxcpfPolygoN(345)---";
      std::string sample="polygon";
      std::string replace="MultiPolygon";
      bool r=ifind_and_replace(s,sample.c_str(),replace.c_str());
      TS_ASSERT_EQUALS(r,true);
      TS_ASSERT_EQUALS(s,"aasxcpfMultiPolygon(345)---");

      r=ifind_and_replace(s,"()","(hgh)");
      TS_ASSERT_EQUALS(r,false);
      TS_ASSERT_EQUALS(s,"aasxcpfMultiPolygon(345)---");


    }
};
#endif