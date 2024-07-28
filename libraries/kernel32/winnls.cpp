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

