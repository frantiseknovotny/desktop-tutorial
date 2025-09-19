#ifndef __SET_TEST_H
#define __SET_TEST_H
class request:public cz::gepro::set_key<request,int> {
  public:
    bool NotNull() const {return value?true:false;}
    request(const char* _url,int _v) {
      key=Key(_url);
      value=_v;
    }
};
typedef std::string _cstring;
class mystring:public _cstring {
  public:
    mystring() {}
    mystring(const char* s):_cstring(s) {}
    static int compare(const char* a,const char* b,size_t len) {
      int res=_strnicmp(a,b,len);
      if(res>0) return 1;
      if(res<0) return -1;
      return 0;
    }
    const char* begin() const {return c_str();}
};
class setTest : public CxxTest::TestSuite
{
public:

    void test_() {
      request key("/url/abc",1);
      int v=key.get();
      cz::gepro::constchars k=key.getKey();
      TS_ASSERT_EQUALS(v,1)
      TS_ASSERT_TEXT(k.begin(),"/url/abc")
    }
    void test_set() {
      cz::gepro::set_of_value<int> maps;
      cz::gepro::set_of_value<int>::set_iterator it;
      maps.add("/PspHrbit/",2);
      maps.add("/PspHrbit/files/",1);
      maps.add("/PspHrbit/help",4);
      maps.add("/PspHrbit/page",3);
      char buf[2048];
      maps.dump(buf,sizeof(buf));
      _DUMP(buf)
      int res=maps.find("/PspHrbit/files/abc.html");
      TS_ASSERT_EQUALS(res,1)
      it=maps.find_iterator("/PspHrbit/files/abc.html");
      TS_ASSERT_TEXT(it->getKey().begin(),"/PspHrbit/files/")
      TS_ASSERT_EQUALS(it->get(),1)
      res=maps.find("/PspHrbit/abc.html");
      TS_ASSERT_EQUALS(res,2)
      res=maps.find("/PspHrbit/help/abc.html");
      TS_ASSERT_EQUALS(res,4)
      res=maps.find("/PspHrbit/page?1,1,1");
      TS_ASSERT_EQUALS(res,3)
    }
    void test_seti() {
      cz::gepro::set_of_value<int,cz::gepro::constcharsi> maps;
      cz::gepro::set_of_value<int,cz::gepro::constcharsi>::set_iterator it;
      maps.add("/PspHrbit/",2);
      maps.add("/PspHrbit/files/",1);
      maps.add("/PspHrbit/help",4);
      maps.add("/PspHrbit/page",3);
      char buf[2048];
      maps.dump(buf,sizeof(buf));
      _DUMP(buf)
      int res=maps.find("/psphrbit/files/abc.html");
      TS_ASSERT_EQUALS(res,1)
      it=maps.find_iterator("/pspHrbit/files/abc.html");
      TS_ASSERT_TEXT(it->getKey().begin(),"/PspHrbit/files/")
      TS_ASSERT_EQUALS(it->get(),1)
      res=maps.find("/psphrbit/abc.html");
      TS_ASSERT_EQUALS(res,2)
      res=maps.find("/psphrbit/help/abc.html");
      TS_ASSERT_EQUALS(res,4)
      res=maps.find("/psphrbit/page?1,1,1");
      TS_ASSERT_EQUALS(res,3)
    }
    void test_setstd() {
      cz::gepro::set_of_value<int,mystring> maps;
      cz::gepro::set_of_value<int,mystring>::set_iterator it;
      maps.add("/PspHrbit/",2);
      maps.add("/PspHrbit/files",1);
      maps.add("/PspHrbit/help",4);
      maps.add("/PspHrbit/pagex",6);
      maps.add("/PspHrbit/page",3);
      maps.add("/PspHrbit/pagexy",7);
      maps.add("/fs~uploadvft",8);
      maps.add("/fs~upload",9);

      char buf[2048];
      maps.dump(buf,sizeof(buf));
      _DUMP(buf)
      int res=maps.find("/psphrbit/files/abc.html");
      TS_ASSERT_EQUALS(res,1)
      it=maps.find_iterator("/pspHrbit/files/abc.html");
      TS_ASSERT_TEXT(it->getKey().c_str(),"/PspHrbit/files")
      TS_ASSERT_EQUALS(it->get(),1)
      res=maps.find("/psphrbit/abc.html");
      TS_ASSERT_EQUALS(res,2)
      res=maps.find("/psphrbit/filesx");
      TS_ASSERT_EQUALS(res,1)
      res=maps.find("/psphrbit/help/abc.html");
      TS_ASSERT_EQUALS(res,4)
      res=maps.find("/psphrbit/page?1,1,1");
      TS_ASSERT_EQUALS(res,3)
      res=maps.find("/psphrbit/page");
      TS_ASSERT_EQUALS(res,3)
      res=maps.find("/psphrbit/pagexa");
      TS_ASSERT_EQUALS(res,6)
      res=maps.find("/psphrbit/pagexya");
      TS_ASSERT_EQUALS(res,7)
      res=maps.find("/fs~upload");
      TS_ASSERT_EQUALS(res,9)
      res=maps.find("/fs~uploadvft");
      TS_ASSERT_EQUALS(res,8)
    }
    void test_setstd2() {
      cz::gepro::set_of_value<int,mystring> maps;
      cz::gepro::set_of_value<int,mystring>::set_iterator it;
      maps.add("/fs~uploadvft",8);
      maps.add("/fs~upload",9);

      char buf[2048];
      maps.dump(buf,sizeof(buf));
      _DUMP(buf)
      int res=maps.find("/fs~upload");
      TS_ASSERT_EQUALS(res,9)
      res=maps.find("/fs~uploadvft");
      TS_ASSERT_EQUALS(res,8)
    }
    void test_setstd3() {
      cz::gepro::set_of_value<int,mystring> maps;
      cz::gepro::set_of_value<int,mystring>::set_iterator it;
      maps.add("/fs~uploadvft",8);
      maps.add("/fs~upload",9);
      maps.add("/fs~uploadv",7);

      char buf[2048];
      maps.dump(buf,sizeof(buf));
      _DUMP(buf)
      int res=maps.find("/fs~upload");
      TS_ASSERT_EQUALS(res,9)
      res=maps.find("/fs~uploadvft");
      TS_ASSERT_EQUALS(res,8)
    }
    void test_set0() {
      std::set<std::string> maps;
      maps.insert("beta");
      maps.insert("Alfa");
      maps.insert("delTA");
      maps.insert("GAMA");
      maps.insert("Delta1");
      std::set<std::string>::const_iterator it=maps.begin();
      TS_ASSERT_TEXT(it->c_str(),"Alfa")
      ++it;
      TS_ASSERT_TEXT(it->c_str(), "Delta1")
      ++it;
      TS_ASSERT_TEXT(it->c_str(), "GAMA")
      ++it;
      TS_ASSERT_TEXT(it->c_str(), "beta")
      ++it;
      TS_ASSERT_TEXT(it->c_str(), "delTA")
    }
    void test_iset() {
      std::iset<std::string> maps;
      maps.insert("beta");
      maps.insert("Alfa");
      maps.insert("delTA");
      maps.insert("GAMA");
      maps.insert("Delta1");
      std::iset<std::string>::const_iterator it = maps.begin();
      TS_ASSERT_TEXT(it->c_str(), "Alfa")
        ++it;
      TS_ASSERT_TEXT(it->c_str(), "beta")
        ++it;
      TS_ASSERT_TEXT(it->c_str(), "delTA")
        ++it;
      TS_ASSERT_TEXT(it->c_str(), "Delta1")
        ++it;
      TS_ASSERT_TEXT(it->c_str(), "GAMA")
    }
};


#endif // __TEST_H
