#ifndef __TEST_HEXA_H
#define __TEST_HEXA_H


/** Test operatoru point.
*/
class Test_HEXA : public CxxTest::TestSuite
{
public:
	void test_hexa() {
		int a = cz::gepro::gethexa('A');
		TS_ASSERT_EQUALS(a, 10);
		int a1 = cz::gepro::gethexa('a');
		TS_ASSERT_EQUALS(a1, 10);
		int f = cz::gepro::gethexa('F');
		TS_ASSERT_EQUALS(f, 15);
		int f1 = cz::gepro::gethexa('f');
		TS_ASSERT_EQUALS(f1, 15);
		int g = cz::gepro::gethexa('G');
		TS_ASSERT_EQUALS(g, -1);
		int g1 = cz::gepro::gethexa('g');
		TS_ASSERT_EQUALS(g1, -1);
		int n = cz::gepro::gethexa('0');
		TS_ASSERT_EQUALS(n, 0);
		int n1 = cz::gepro::gethexa('1');
		TS_ASSERT_EQUALS(n1, 1);
		int n9 = cz::gepro::gethexa('9');
		TS_ASSERT_EQUALS(n9, 9);
	}
	void test_ishexa() {
		bool a = cz::gepro::ishexa('A');
		TS_ASSERT_EQUALS(a, true);
		bool b = cz::gepro::ishexa('G');
		TS_ASSERT_EQUALS(b, false);
		bool c = cz::gepro::ishexa('0');
		TS_ASSERT_EQUALS(c, true);		
		const char* p = "ABCDEFabcdef0123456789";
		bool d = cz::gepro::ishexa(p, p + strlen(p));
		TS_ASSERT_EQUALS(d, true); 
		const char* p2 = "ABCDEFabcdef0123456789g";
		bool e = cz::gepro::ishexa(p2, p2 + strlen(p2));
		TS_ASSERT_EQUALS(e, false);
	}
	void test_isuuid() {
		const char* p = "c91b5e63-f39f-4c54-857d-0a694e8f47fa";
		bool a = cz::gepro::isuuid(p, p + strlen(p));
		TS_ASSERT_EQUALS(a, true);
		const char* p2 = "c91b5e6-f39f-4c54-857d-0a694e8f47fa";
		bool b = cz::gepro::isuuid(p2, p2 + strlen(p2));
		TS_ASSERT_EQUALS(b, false);
		const char* p3 = "Ac91b5e63-f39f-4c54-857d-0a694e8f47fa";
		bool c = cz::gepro::isuuid(p3, p3 + strlen(p3));
		TS_ASSERT_EQUALS(c, false);
		const char* p4 = "G91b5e63-f39f-4c54-857d-0a694e8f47fa";
		bool d = cz::gepro::isuuid(p4, p4 + strlen(p4));
		TS_ASSERT_EQUALS(d, false);
	}
	void test_isuuidw() {
		const wchar_t* p = L"c91b5e63-f39f-4c54-857d-0a694e8f47fa";
		bool a = cz::gepro::isuuid(p, p + strlen(p));
		TS_ASSERT_EQUALS(a, true);
		const wchar_t* p2 = L"c91b5e6-f39f-4c54-857d-0a694e8f47fa";
		bool b = cz::gepro::isuuid(p2, p2 + strlen(p2));
		TS_ASSERT_EQUALS(b, false);
		const wchar_t* p3 = L"Ac91b5e63-f39f-4c54-857d-0a694e8f47fa";
		bool c = cz::gepro::isuuid(p3, p3 + strlen(p3));
		TS_ASSERT_EQUALS(c, false);
		const wchar_t* p4 = L"G91b5e63-f39f-4c54-857d-0a694e8f47fa";
		bool d = cz::gepro::isuuid(p4, p4 + strlen(p4));
		TS_ASSERT_EQUALS(d, false);
	}
};
#endif