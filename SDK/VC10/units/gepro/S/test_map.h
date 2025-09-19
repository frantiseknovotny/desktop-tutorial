#ifndef __TEST_MAP_H
#define __TEST_MAP_H

/* vzor pro odvozeni dalsich testu - nemodifikovat */

class TestTEST_MAP : public CxxTest::TestSuite
{
public:
    void test_() {
      std::imap<std::string,int> maps;
      maps.insert(std::imap<std::string, int>::value_type("alfa",1));
      maps.insert(std::imap<std::string, int>::value_type("beta",2));
      maps.insert(std::imap<std::string, int>::value_type("gama", 3));
      std::imap<std::string, int>::const_iterator it=maps.find("ALFA");
      TS_ASSERT_EQUALS(it->second,1)
      it = maps.find("Beta");
      TS_ASSERT_EQUALS(it->second, 2)
        it = maps.find("gaMA");
      TS_ASSERT_EQUALS(it->second, 3)
    }
};


#endif // __TEST_H
