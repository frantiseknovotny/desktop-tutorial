#ifndef __WXBASE64_H
#define __WXBASE64_H
#include <string>

std::string EncodeBase64BitStream(char* data, int len);
// bytes   1 - vraci pocet bytu
//         0 - vraci pocet bitu
int DecodeBase64BitStream(char* data, int bytes=0);
//int GetCode(char p);
enum wxBase64DecodeMode
{
    // normal behaviour: stop at any invalid characters
    wxBase64DecodeMode_Strict,

    // skip whitespace characters
    wxBase64DecodeMode_SkipWS,

    // the most lenient behaviour: simply ignore all invalid characters
    wxBase64DecodeMode_Relaxed
};
size_t wxBase64Encode(char *dst, size_t dstLen, const void *src_, size_t srcLen);
size_t wxBase64Decode(void *dst_, size_t dstLen,
               const char *src, size_t srcLen,
               wxBase64DecodeMode mode,
               size_t *posErr);
inline size_t wxBase64EncodedSize(size_t len) { return 4*((len+2)/3); }
#endif