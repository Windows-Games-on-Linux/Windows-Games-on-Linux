#include "winnls.h"

#include <cstring>
#include <iostream>

UINT __attribute__((stdcall)) GetACP() {
  char* locale = setlocale(LC_CTYPE, nullptr);

  if (strcmp(locale, "C") == 0) {
    return 1252;
  }

  std::cout << "GetACP: Unimplemented Code Page Identifier" << std::endl;
  return 0;
}

BOOL __attribute__((stdcall)) IsValidCodePage(UINT CodePage) {
  if (CodePage == 1252) {
    return 1;
  }

  //For now just assume that every other code page identifier is unimplemented
  std::cout << "IsValidCodePage: Unimplemented Code Page Identifier" << std::endl;
  return 0;
}

BOOL __attribute__((stdcall)) GetCPInfo(UINT CodePage, LPCPINFO lpCPInfo) {
  if (CodePage == 1252) {
    lpCPInfo->MaxCharSize = 1;
    lpCPInfo->DefaultChar[0] = '?';
    lpCPInfo->DefaultChar[1] = 0;
    memset(lpCPInfo->LeadByte, 0, sizeof(lpCPInfo->LeadByte));

    return 1;
  }

  std::cout << "GetCPInfo: Unimplemented Code Page Identifier: " << CodePage << std::endl;
  return 0;
}

