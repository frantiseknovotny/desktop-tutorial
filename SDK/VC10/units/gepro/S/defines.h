#ifndef __TEST_DEFINES_H
#define __TEST_DEFINES_H

/* vzor pro odvozeni dalsich testu - nemodifikovat */
#pragma warning(disable:4101)
class TestDefines : public CxxTest::TestSuite
{
public:
    void test_1() {
      char path[MAXPATH];
      TS_ASSERT_EQUALS(sizeof(path),(size_t)_MAX_PATH)
      char dir[MAXDIR];
      TS_ASSERT_EQUALS(sizeof(dir), (size_t)_MAX_DIR)
      char file[MAXFILE];
      TS_ASSERT_EQUALS(sizeof(file), (size_t)_MAX_FNAME)
      char ext[MAXEXT];
      TS_ASSERT_EQUALS(sizeof(ext),(size_t)_MAX_EXT)
      char drive[MAXDRIVE];
      TS_ASSERT_EQUALS(sizeof(drive),(size_t)_MAX_DRIVE)
    }
};
#pragma warning(default:4101)


#endif // __TEST_H
