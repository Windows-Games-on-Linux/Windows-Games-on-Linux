#include "stringapiset.h"

#include <iostream>
#include <cwctype>

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
        lpWideCharStr[j++] = (unsigned char)*c;
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
      lpWideCharStr[j++] = (unsigned char)*c;
      if (j == size) {
        break;
      }
    }

    return size;
  }

  std::cout << "MultiByteToWideChar: Unimplemented Code Page Identifier: " << CodePage << std::endl;
  return 0;
}

BOOL __attribute__((stdcall)) GetStringTypeW(DWORD dwInfoType, LPCWCH lpSrcStr, int cchSrc, LPWORD lpCharType) {
  if (cchSrc == 0) {
    return 0;
  }

  if (dwInfoType == CT_CTYPE1) {
    int i = 0;
    for (const char16_t* c = lpSrcStr; ; c++) {
      lpCharType[i] = 0;

      bool typeFound = false;

      if (iswupper(*c)) {
        lpCharType[i] |= C1_UPPER;
        typeFound = true;
      }

      if (iswlower(*c)) {
        lpCharType[i] |= C1_LOWER;
        typeFound = true;
      }

      if (iswdigit(*c)) {
        lpCharType[i] |= C1_DIGIT;
        typeFound = true;
      }

      if (iswspace(*c)) {
        lpCharType[i] |= C1_SPACE;
        typeFound = true;
      }

      if (iswpunct(*c)) {
        lpCharType[i] |= C1_PUNCT;
        typeFound = true;
      }

      if (iswcntrl(*c)) {
        lpCharType[i] |= C1_CNTRL;
        typeFound = true;
      }

      if (iswblank(*c)) {
        lpCharType[i] |= C1_BLANK;
        typeFound = true;
      }

      if (iswxdigit(*c)) {
        lpCharType[i] |= C1_XDIGIT;
        typeFound = true;
      }

      if (iswalpha(*c)) {
        lpCharType[i] |= C1_ALPHA;
        typeFound = true;
      }

      if (!typeFound) {
        lpCharType[i] = C1_DEFINED;
      }

      i++;

      if (cchSrc < 0 && *c == 0) {
        break;
      }

      if (i == cchSrc) {
        break;
      }
    }

    return 1;
  }

  std::cout << "GetStringTypeW: Unimplemented Info Type: " << dwInfoType << std::endl;
  return 0;
}

