#ifndef __TEST_EXCEPTIONS2_H
#define __TEST_EXCEPTIONS2_H

/* vzor pro odvozeni dalsich testu - nemodifikovat */

class Test_EXCEPTIONS2 : public CxxTest::TestSuite
{
public:
    void test_() {
      try {
        cz::gepro::exceptionmsg e;
        e.msg << "exceptionmsg";
        throw e;
      } catch(std::exception& e) {
        _DUMP(e.what());
        TS_ASSERT_TEXT(e.what(),"exceptionmsg")
      }
      try {
        int a=10;
        THROW_MSG1("THROW_MSG1:",a)
      } catch(std::exception& e) {
        _DUMP(e.what());
      }
      try {
        int a=10;
        const char* b="b";
        THROW_MSG2("THROW_MSG2:",a,b)
      } catch(std::exception& e) {
        _DUMP(e.what());
      }
      try {
        int a=10;
        const char* b="b";
        double c=1.41;
        THROW_MSG3("THROW_MSG3:",a,b,c)
      } catch(std::exception& e) {
        _DUMP(e.what());
      }
      try {
        int a=10;
        const char* b="b";
        double c=1.41;
        POINT p={10,10};
        THROW_MSG4("THROW_MSG4:",a,b,c,p.x)
      } catch(std::exception& e) {
        _DUMP(e.what());
      }
      try {
        int a=10;
        const char* b="b";
        double c=1.41;
        POINT p={10,10};
        THROW_MSG5("THROW_MSG5:",a,b,c,p.x,p.y)
      } catch(std::exception& e) {
        _DUMP(e.what());
      }
    }
    void test_throw() {
      try {
        cz::gepro::exceptionmsg e;
//        throw e << "exceptionmsg";
      } catch(std::exception& e) {
        _DUMP(e.what());
        TS_ASSERT_TEXT(e.what(),"exceptionmsg")
      }
      try {
        cz::gepro::exceptionmsg e;
       // throw e << FILELINEMSG << "popis chyby:" << 10 << "," << 10.1;
      } catch(std::exception& e) {
        _DUMP(e.what());
      }
      
    }
};


#endif // __TEST_H
