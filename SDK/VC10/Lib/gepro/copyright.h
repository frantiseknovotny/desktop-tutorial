#define CORPORATION_NAME  "GEPRO spol. s r.o."
#define CORPORATION_ADR   "Štefánikova 52,  Praha 5"
#define CORPORATION_TEL   "tel/fax  +420 257 089 811"
#define CORPORATION_HELPTEL   "+420 257 089 811"
#define CORPORATION_WWW   "http://www.gepro.cz"
#define CORPORATION_WWWNEWS   "https://www.gepro.cz/novinky/"
#define CORPORATION_MAIL  "misys@gepro.cz"
#define CORPORATION_HELPMAIL  "gepro@gepro.cz"
#define COPYRIGHT_TEXT    "Copyright ©"
#define COPYRIGHT_BEGIN   "1994"
#define COPYRIGHT_END     "2024"

#ifndef PRODUCT_BEGIN
  #define PRODUCT_BEGIN COPYRIGHT_BEGIN
#endif
#ifndef PRODUCT_NAME 
  #define PRODUCT_NAME "MISYS" 
#endif
#define COPYRIGHT    COPYRIGHT_TEXT " " PRODUCT_BEGIN "-" COPYRIGHT_END ", " CORPORATION_NAME 
#define JENKINS_URL "http://build3/jenkins/"
#define BUGZILLA_URL "http://bugzilla.gepro/bugzilla/"
#define WIKI_URL "http://wiki.gepro/mediawiki/"
