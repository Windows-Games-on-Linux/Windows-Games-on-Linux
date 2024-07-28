#include "stringapiset.h"

#include <iostream>

int __attribute__((stdcall)) MultiByteToWideChar(UINT CodePage, DWORD dwFlags, LPCCH lpMultiByteStr, int cbMultiByte, LPWSTR lpWideCharStr, int cchWideChar) {
  if (dwFlags & MB_COMPOSITE) {
    std::cout << "MultiByteToWideChar: Unimplemented Flag: MB_COMPOSITE" << std::endl;
  }

  if (dwFlags & MB_ERR_INVALID_CHARS) {
    std::cout << "MultiByteToWideChar: Unimplemented Flag: MB_ERR_INVALID_CHARS" << std::endl;
  }

  if (dwFlags & MB_USEGLYPHCHARS) {
    std::cout << "MultiByteToWideChar: Unimplemented Flag: MB_USEGLYPHCHARS" << std::endl;
  }

  if (!(dwFlags & MB_PRECOMPOSED)) {
    std::cout << "MultiByteToWideChar: Decomposed characters are not implemented" << std::endl;
  }

  if (cbMultiByte == 0) {
    return 0;
  }

  if (CodePage == 1252) {
    //If cchWideChar = 0, calculate and return the required output buffer size
    if (cchWideChar == 0) {
      //If cbMultiByte != -1, it specifies the size of the input buffer
      if (cbMultiByte != -1) {
        return cbMultiByte;
      }

      //Otherwise, the size needs to be calculated, including the NULL character
      int size = 0;
      for (const char* c = lpMultiByteStr; ; c++) {
        size++;
        if (*c == 0) {
          break;
        }
      }

      return size;
    }

    //If cchWideChar != 0, perform the actual conversion

    //If cbMultiByte = -1, copy until the end of the output buffer or until the NULL character
    if (cbMultiByte == -1) {
      int j = 0;
      for (const char* c = lpMultiByteStr; ; c++) {
        lpWideCharStr[j++] = *c;
        if (*c == 0 || j == cchWideChar) {
          break;
        }
      }

      return j;
    }

    //Otherwise, copy as much as possible
    int size = std::min(cbMultiByte, cchWideChar);
    int j = 0;
    for (const char* c = lpMultiByteStr; ; c++) {
      lpWideCharStr[j++] = *c;
      if (j == size) {
        break;
      }
    }

    return size;
  }

  std::cout << "MultiByteToWideChar: Unimplemented Code Page Identifier: " << CodePage << std::endl;
  return 0;
}

