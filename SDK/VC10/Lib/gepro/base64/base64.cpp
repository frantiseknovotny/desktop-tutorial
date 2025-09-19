//static int GetCode(char p) {
int GetCode(char p) {         //pouziva se v misysu v ciselnik.cpp, tak nemuze byt static
    switch(p) {
    case 'A':return 0;
    case 'B':return 1;
    case 'C':return 2;
    case 'D':return 3;
    case 'E':return 4;
    case 'F':return 5;
    case 'G':return 6;
    case 'H':return 7;
    case 'I':return 8;
    case 'J':return 9;
    case 'K':return 10;
    case 'L':return 11;
    case 'M':return 12;
    case 'N':return 13;
    case 'O':return 14;
    case 'P':return 15;
    case 'Q':return 16;
    case 'R':return 17;
    case 'S':return 18;
    case 'T':return 19;
    case 'U':return 20;
    case 'V':return 21;
    case 'W':return 22;
    case 'X':return 23;
    case 'Y':return 24;
    case 'Z':return 25;
    case 'a':return 26;
    case 'b':return 27;
    case 'c':return 28;
    case 'd':return 29;
    case 'e':return 30;
    case 'f':return 31;
    case 'g':return 32;
    case 'h':return 33;
    case 'i':return 34;
    case 'j':return 35;
    case 'k':return 36;
    case 'l':return 37;
    case 'm':return 38;
    case 'n':return 39;
    case 'o':return 40;
    case 'p':return 41;
    case 'q':return 42;
    case 'r':return 43;
    case 's':return 44;
    case 't':return 45;
    case 'u':return 46;
    case 'v':return 47;
    case 'w':return 48;
    case 'x':return 49;
    case 'y':return 50;
    case 'z':return 51;
    case '0':return 52;
    case '1':return 53;
    case '2':return 54;
    case '3':return 55;
    case '4':return 56;
    case '5':return 57;
    case '6':return 58;
    case '7':return 59;
    case '8':return 60;
    case '9':return 61;
    case '+':return 62;
    case '/':return 63;
    default:return 0x80000000; 
    }
}

#include "base64.h"

int DecodeBase64BitStream(char* data, int bytes) {
    char* bptr=data;
    char* ptr=data;
    int len=0;
    int contflag=1;
    while (contflag) {
          int i=GetCode(*ptr++);
          if (i<0) {i=0;contflag=0;}
          int code=i;
          if (contflag) {
             i=GetCode(*ptr++);
             if (i<0) {i=0;contflag=0;}
          }
          code<<=6;
          code|=i;
          if (contflag) {
             i=GetCode(*ptr++);
             if (i<0) {i=0;contflag=0;}
          }
          code<<=6;
          code|=i;
          if (contflag) {
             i=GetCode(*ptr++);
             if (i<0) {i=0;contflag=0;}
          }
          code<<=6;
          code|=i;
          int i1=(code&0xFF0000)>>16;
          int i2=(code&0xFF00)>>8;
          int i3=(code&0xFF);
          if (contflag||i3) {
             *bptr++=i1;
             *bptr++=i2;
             *bptr++=i3;
             len+=24;
          } else if (i2) {
             *bptr++=i1;
             *bptr++=i2;
             len+=16;
          } else if (i1) {
             *bptr++=i1;
             len+=8;
          } 
   }
   if (bytes) {
      return len>>3;   
   } else {
      int j=*--bptr;
      while (len) {
            if (j&1) break;
            len--;
            if (!(len&7)) j=*--bptr;
            else j>>=1;
      }
   }
   return len;
}

std::string EncodeBase64BitStream(char* data, int len) {
    static char table[] = {
	    'A','B','C','D','E','F','G','H','I','J','K','L','M',
	    'N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
	    'a','b','c','d','e','f','g','h','i','j','k','l','m',
	    'n','o','p','q','r','s','t','u','v','w','x','y','z',
	    '0','1','2','3','4','5','6','7','8','9','+','/'
        };
       if (len<=0) {len=1;data="";}
       std::string result(((len+23)/24)*4,0);
       char* res=(char*)result.c_str();
       int pad=0;
       while (len>0) {
             long bits=((long)(unsigned char)data[0])<<16;
             if (len>8) {
                bits|=((long)(unsigned char)data[1])<<8;
                if (len>16) bits|=((unsigned char)data[2]); 
                else pad=1;
             } else pad=2;
             *res++=table[(bits&0xFC0000)>>18];  
             *res++=table[(bits&0x3F000)>>12];  
             if (pad==2) {*res++='=';*res++='=';break;}
             else *res++=table[(bits&0xFC0)>>6];  
             if (pad==1) {*res++='=';break;}
             else *res++=table[(bits&0x3F)];  
             data+=3;
             len-=24;          
       }
       *res='\0';
       return result;
}
