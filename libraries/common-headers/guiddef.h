#pragma once

struct GUID {
  unsigned int Data1;
  unsigned short Data2;
  unsigned short Data3;
  unsigned char Data4[8];
};

typedef GUID IID;
typedef GUID CLSID;

