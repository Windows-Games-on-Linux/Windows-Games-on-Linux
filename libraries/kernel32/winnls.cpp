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

