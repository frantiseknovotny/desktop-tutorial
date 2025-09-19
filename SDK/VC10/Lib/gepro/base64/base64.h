#ifndef __BASE64_H
#define __BASE64_H
#include <string>

std::string EncodeBase64BitStream(char* data, int len);
// bytes   1 - vraci pocet bytu
//         0 - vraci pocet bitu
int DecodeBase64BitStream(char* data, int bytes=0);
int GetCode(char p);
#endif