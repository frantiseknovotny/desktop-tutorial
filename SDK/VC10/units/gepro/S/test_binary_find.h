#ifndef __TEST_BINARY_FIND_H
#define __TEST_BINARY_FIND_H

#include <vector>

using namespace cz::gepro;

class myclass {
public:
  myclass(const std::string _s,int _i) : s(_s),i(_i) {;}
  std::string s;
  int i;
};

bool my_compare(const myclass& a, const myclass& b) {
  return a.i<b.i;
}

bool compare_string(const std::string& a, const std::string& b) {
  return _strcmpi(a.c_str(),b.c_str())<0 ? true:false;
}



/** Test binary_find.
*/
class Test_binary_find : public CxxTest::TestSuite
{
public:
    void test_binary_find_cmp() {
      std::vector<myclass> cont;
      cont.push_back(myclass("ahoj",2));
      cont.push_back(myclass("nazdar",3));
      cont.push_back(myclass("nazdar",6));
      cont.push_back(myclass("kuk",7));
      cont.push_back(myclass("buk",8));
      cont.push_back(myclass("smrk",9));
      cont.push_back(myclass("luk",31));
      cont.push_back(myclass("puk",32));
      cont.push_back(myclass("suk",33));
      cont.push_back(myclass("drn",33));
      cont.push_back(myclass("trn",35));


      std::vector<myclass>::iterator it;
      std::vector<myclass>::iterator found;

      it=binary_find(cont.begin(),cont.end(),myclass("bota",9),my_compare,found);

      TS_ASSERT(it==cont.end()); //nasel se tak se vraci end a nalezeny je ve found
      TS_ASSERT_TEXT(found->s.c_str(),"smrk");
      TS_ASSERT(found->i==9);

      it=binary_find(cont.begin(),cont.end(),myclass("hrnec",18),my_compare,found);

      TS_ASSERT(found==cont.end()); //nenasel se tak se vraci ten pred nejz se ma vlozit
      TS_ASSERT_TEXT(it->s.c_str(),"luk"); //a ve found je end
      TS_ASSERT(it->i==31);

      it=binary_find(cont.begin(),cont.end(),myclass("kudla",98),my_compare,found);

      TS_ASSERT(it==cont.end());
      TS_ASSERT(found==cont.end());

      cont.insert(it,myclass("kudla",98));
      it=binary_find(cont.begin(),cont.end(),myclass("kudla",98),my_compare,found);
      TS_ASSERT(it==cont.end());
      TS_ASSERT_TEXT(found->s.c_str(),"kudla");
      TS_ASSERT(found->i==98);
    }

    void test_binary_find() {
      std::vector<int> cont;
      cont.push_back(2);
      cont.push_back(3);
      cont.push_back(6);
      cont.push_back(7);
      cont.push_back(8);
      cont.push_back(9);
      cont.push_back(31);
      cont.push_back(32);
      cont.push_back(33);
      cont.push_back(33);
      cont.push_back(35);


      std::vector<int>::iterator it;
      std::vector<int>::iterator found;

      it=binary_find(cont.begin(),cont.end(),9,found);

      TS_ASSERT(it==cont.end()); //nasel se tak se vraci end a nalezeny je ve found
      TS_ASSERT(*found==9);

      it=binary_find(cont.begin(),cont.end(),18,found);

      TS_ASSERT(found==cont.end()); //nenasel se tak se vraci ten pred nejz se ma vlozit
      TS_ASSERT(*it==31);

      it=binary_find(cont.begin(),cont.end(),98,found);

      TS_ASSERT(it==cont.end());
      TS_ASSERT(found==cont.end());

      cont.insert(it,98);
      it=binary_find(cont.begin(),cont.end(),98,found);
      TS_ASSERT(it==cont.end());
      TS_ASSERT(*found==98);
    }

    /** Test binary_find_string,
    testuje vyhledani stringu s porovnanim _strcmpi
    */
    void test_binary_find_string() {
      std::vector<std::string> strings;
      strings.push_back("akat");
      strings.push_back("buk");
      strings.push_back("cedr");

      std::vector<std::string>::iterator it;
      std::vector<std::string>::iterator found;

      it=binary_find(strings.begin(),strings.end(),"buk",compare_string,found);

      TS_ASSERT(it==strings.end()); //nasel se tak, se vraci end a nalezeny je ve found
      TS_ASSERT_TEXT(found->c_str(),"buk");


      it=binary_find(strings.begin(),strings.end(),"babyka",compare_string,found);

      TS_ASSERT(found==strings.end()); //nenasel se, tak se vraci 'buk' protoze babyka patri pred nej  a ve found je end 
      TS_ASSERT_TEXT(it->c_str(),"buk");

    }


};
#endif