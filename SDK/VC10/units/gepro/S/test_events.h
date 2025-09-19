#ifndef __TEST_EVENTS_H
#define __TEST_EVENTS_H
#include "includes/_events.h"
/* vzor pro odvozeni dalsich testu - nemodifikovat */
#pragma warning(disable:4101)
class TestEvents : public CxxTest::TestSuite
{
  EventsXRegister r;
  class EventsR :public EventsX { 
  public:
  std::string name; 
  int i1; 
  virtual void Name() override { name = "Name"; } 
  virtual void Int(int _i1) override { i1 = _i1; } 
  };

public:
    void test_1() {
      EventsR e;
      r.Add(&e);
      r.CallName();
      r.CallInt(10);
      TS_ASSERT_TEXT(e.name.c_str(),"Name")
      TS_ASSERT_EQUALS(e.i1, 10)
    }
};
#pragma warning(default:4101)


#endif // __TEST_H
