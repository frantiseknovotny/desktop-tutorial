#ifndef __TEST_VIEWTYPES_H
#define __TEST_VIEWTYPES_H

      class mypairs {
        public:
          struct pair {
            const char* name;
            const char* value;
            pair() {name=value=NULL;}
            pair(const char* _name,const char* _value) {name=_name;value=_value;}
          };
        private: 
          std::vector<pair> ps;
          cz::gepro::vtoa::simple::buffer<2048> b;
        public:
          template <class V> void add(const char* name,V value) {
            pair x(name,b.end());
            b << value;
            b.Add("\0",1);
            ps.push_back(x);
          }
          pair operator[](unsigned i) {
            pair p;
            if(i>=ps.size()) return p;
            return ps.at(i);
          }
      };

class viewtypesTest : public CxxTest::TestSuite
{
public:
    void test_vtoa_DEVMODE() {
      DEVMODE dm;
      memset(&dm,0,sizeof(dm));
      dm.dmSpecVersion=1;
      dm.dmSize=sizeof(dm);
      cz::gepro::vtoa::simple::buffer2<256> b;
      b << dm;
      size_t l=b.size();
      _DUMP(b.begin())
      TS_ASSERT_EQUALS(l, (size_t)254)
      if(sizeof(dm)==156) {
        TS_ASSERT_SAME_DATA("{dmDeviceName=,dmSpecVersion=1,dmDriverVersion=0,dmSize=156,dmDriverExtra=0,dmFields=0,dmOrientation=0,dmPaperSize=0,dmPaperLength=0,dmPaperWidth=0,dmPosition={0,0},dmScale=0,dmCopies=0,dmDefaultSource=0,dmPrintQuality=0,dmColor=0,dmDuplex=0,dmYResolutio",b.begin(),b.size()+1)
      } else {
        TS_ASSERT_SAME_DATA("{dmDeviceName=,dmSpecVersion=1,dmDriverVersion=0,dmSize=220,dmDriverExtra=0,dmFields=0,dmOrientation=0,dmPaperSize=0,dmPaperLength=0,dmPaperWidth=0,dmPosition={0,0},dmScale=0,dmCopies=0,dmDefaultSource=0,dmPrintQuality=0,dmColor=0,dmDuplex=0,dmYResolutio",b.begin(),b.size()+1)
     }
    }
    void test_vtoa_PRINTER_INFO_2() {
      PRINTER_INFO_2 dm;
      memset(&dm,0,sizeof(dm));
      cz::gepro::vtoa::simple::buffer2<256> b;
      b << dm;
      size_t l=b.size();
      TS_ASSERT_EQUALS(l, (size_t)254)
    }
    void test_vtoa_DEVMODE_to_inifile() {
      DEVMODE dm;
      memset(&dm,0,sizeof(dm));
      dm.dmSpecVersion=1;
      dm.dmSize=sizeof(dm);
      cz::gepro::vtoa::inifile::buffer2<256> b;
      b << dm;
      size_t l=b.size();
      _DUMP(b.begin())
      TS_ASSERT_EQUALS(l, (size_t)254)
      if(sizeof(dm)==156) {
        TS_ASSERT_SAME_DATA("dmDeviceName=\ndmSpecVersion=1\ndmDriverVersion=0\ndmSize=156\ndmDriverExtra=0\ndmFields=0\ndmOrientation=0\ndmPaperSize=0\ndmPaperLength=0\ndmPaperWidth=0\ndmPosition={0,0}\ndmScale=0\ndmCopies=0\ndmDefaultSource=0\ndmPrintQuality=0\ndmColor=0\ndmDuplex=0\ndmYResolution",b.begin(),b.size()+1)
      } else {
        TS_ASSERT_SAME_DATA("dmDeviceName=\ndmSpecVersion=1\ndmDriverVersion=0\ndmSize=220\ndmDriverExtra=0\ndmFields=0\ndmOrientation=0\ndmPaperSize=0\ndmPaperLength=0\ndmPaperWidth=0\ndmPosition={0,0}\ndmScale=0\ndmCopies=0\ndmDefaultSource=0\ndmPrintQuality=0\ndmColor=0\ndmDuplex=0\ndmYResolution",b.begin(),b.size()+1)
      }
    }
    void test_vtoa_PRINTER_INFO_2_to_inifile() {
      PRINTER_INFO_2 dm;
      memset(&dm,0,sizeof(dm));
      cz::gepro::vtoa::inifile::buffer2<256> b;
      b << dm;
      size_t l=b.size();
      TS_ASSERT_EQUALS(l, (size_t)254)
    }
    void test_vtoa_PRINTER_INFO_2_to_pair() {
      mypairs p;
      p.add("A",1);
      p.add("B",2.1);
      #undef _OITEM
      #define _OITEM(v,t,i) p.add(#i,v.i);
      DEVMODE dm;
      memset(&dm,0,sizeof(dm));
      dm.dmSpecVersion=1;
      dm.dmSize=sizeof(dm);
      _O_DEVMODE(dm)
      p.add("C","TEST");
      mypairs::pair r=p[0];
      TS_ASSERT_SAME_DATA(r.name,"A",2)
      TS_ASSERT_SAME_DATA(r.value,"1",2)
      r=p[1];
      TS_ASSERT_SAME_DATA(r.name,"B",2)
      TS_ASSERT_SAME_DATA(r.value,"2.1",4)
      r=p[2];
      TS_ASSERT_SAME_DATA(r.name,"dmDeviceName",13)
      TS_ASSERT_SAME_DATA(r.value,"",1)
      r=p[3];
      TS_ASSERT_SAME_DATA(r.name,"dmSpecVersion",14)
      TS_ASSERT_SAME_DATA(r.value,"1",2)
    }
};


#endif // __TEST_H
