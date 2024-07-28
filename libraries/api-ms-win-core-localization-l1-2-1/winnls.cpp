#include "winnls.h"

#include <iostream>

int __attribute__((stdcall)) LCMapStringEx(LPCWSTR lpLocaleName, DWORD dwMapFlags, LPCWSTR lpSrcStr, int cchSrc, LPWSTR lpDestStr, int cchDest, LPNLSVERSIONINFO lpVersionInformation, LPVOID lpReserved, LPARAM sortHandle) {
  if (lpLocaleName != LOCALE_NAME_USER_DEFAULT) {
    std::cout << "LCMapStringEx: Unimplemented Locale Name" << std::endl;
  }

  if (dwMapFlags & LCMAP_BYTEREV) {
    std::cout << "LCMapStringEx: Unimplemented Map Flag: LCMAP_BYTEREV" << std::endl;
  }

  if (dwMapFlags & LCMAP_FULLWIDTH) {
    std::cout << "LCMapStringEx: Unimplemented Map Flag: LCMAP_FULLWIDTH" << std::endl;
  }

  if (dwMapFlags & LCMAP_HALFWIDTH) {
    std::cout << "LCMapStringEx: Unimplemented Map Flag: LCMAP_HALFWIDTH" << std::endl;
  }

  if (dwMapFlags & LCMAP_HIRAGANA) {
    std::cout << "LCMapStringEx: Unimplemented Map Flag: LCMAP_HIRAGANA" << std::endl;
  }

  if (dwMapFlags & LCMAP_KATAKANA) {
    std::cout << "LCMapStringEx: Unimplemented Map Flag: LCMAP_KATAKANA" << std::endl;
  }

  if (dwMapFlags & LCMAP_LINGUISTIC_CASING) {
    std::cout << "LCMapStringEx: Unimplemented Map Flag: LCMAP_LINGUISTIC_CASING" << std::endl;
  }

  if (dwMapFlags & LCMAP_HASH) {
    std::cout << "LCMapStringEx: Unimplemented Map Flag: LCMAP_HASH" << std::endl;
  }

  if (dwMapFlags & LCMAP_SIMPLIFIED_CHINESE) {
    std::cout << "LCMapStringEx: Unimplemented Map Flag: LCMAP_SIMPLIFIED_CHINESE" << std::endl;
  }

  if (dwMapFlags & LCMAP_SORTHANDLE) {
    std::cout << "LCMapStringEx: Unimplemented Map Flag: LCMAP_SORTHANDLE" << std::endl;
  }

  if (dwMapFlags & LCMAP_SORTKEY) {
    std::cout << "LCMapStringEx: Unimplemented Map Flag: LCMAP_SORTKEY" << std::endl;
  }

  if (dwMapFlags & LCMAP_TRADITIONAL_CHINESE) {
    std::cout << "LCMapStringEx: Unimplemented Map Flag: LCMAP_TRADITIONAL_CHINESE" << std::endl;
  }

  if (dwMapFlags & NORM_IGNORENONSPACE) {
    std::cout << "LCMapStringEx: Unimplemented Map Flag: NORM_IGNORENONSPACE" << std::endl;
  }

  if (dwMapFlags & NORM_IGNORESYMBOLS) {
    std::cout << "LCMapStringEx: Unimplemented Map Flag: NORM_IGNORESYMBOLS" << std::endl;
  }

  if (dwMapFlags & LINGUISTIC_IGNORECASE) {
    std::cout << "LCMapStringEx: Unimplemented Map Flag: LINGUISTIC_IGNORECASE" << std::endl;
  }

  if (dwMapFlags & LINGUISTIC_IGNOREDIACRITIC) {
    std::cout << "LCMapStringEx: Unimplemented Map Flag: LINGUISTIC_IGNOREDIACRITIC" << std::endl;
  }

  if (dwMapFlags & NORM_IGNORECASE) {
    std::cout << "LCMapStringEx: Unimplemented Map Flag: NORM_IGNORECASE" << std::endl;
  }

  if (dwMapFlags & NORM_IGNOREKANATYPE) {
    std::cout << "LCMapStringEx: Unimplemented Map Flag: NORM_IGNOREKANATYPE" << std::endl;
  }

  if (dwMapFlags & NORM_IGNOREWIDTH) {
    std::cout << "LCMapStringEx: Unimplemented Map Flag: NORM_IGNOREWIDTH" << std::endl;
  }

  if (dwMapFlags & NORM_LINGUISTIC_CASING) {
    std::cout << "LCMapStringEx: Unimplemented Map Flag: NORM_LINGUISTIC_CASING" << std::endl;
  }

  if (dwMapFlags & SORT_DIGITSASNUMBERS) {
    std::cout << "LCMapStringEx: Unimplemented Map Flag: SORT_DIGITSASNUMBERS" << std::endl;
  }

  if (dwMapFlags & SORT_STRINGSORT) {
    std::cout << "LCMapStringEx: Unimplemented Map Flag: SORT_STRINGSORT" << std::endl;
  }

  if (cchSrc == 0) {
    return 0;
  }

  //If cchDest = 0, calculate the required size of the output buffer
  if (cchDest == 0) {
    //If cchSrc already contains the string size, just return it
    if (cchSrc > 0) {
      return cchSrc;
    }

    //Otherwise, calculate the size including the NULL character
    int size = 0;
    for (const char16_t* c = lpSrcStr; ; c++) {
      size++;
      if (*c == 0) {
        break;
      }
    }

    return size;
  }

  //Otherwise, perform the actual mapping
  int size;
  bool nullCheck = false;
  if (cchSrc > 0) {
    size = std::min(cchSrc, cchDest);
    nullCheck = false;
  } else {
    size = cchDest;
    nullCheck = true;
  }

  int i = 0;

  bool newWord = true; //Used by LCMAP_TITLECASE to determine whether it's the first letter of a new word

  for (const char16_t* c = lpSrcStr; ; c++) {
    char16_t dc = *c;

    if (dwMapFlags & LCMAP_LOWERCASE) {
      dc = towlower(dc);
    }

    if (dwMapFlags & LCMAP_TITLECASE) {
      if (iswalpha(dc)) {
        if (newWord) {
          dc = towupper(dc);
          newWord = false;
        }
      } else {
        newWord = true;
      }
    }

    if (dwMapFlags & LCMAP_UPPERCASE) {
      dc = towupper(dc);
    }

    lpDestStr[i++] = dc;
    if (i == size) {
      break;
    }

    if (nullCheck && *c == 0) {
      break;
    }
  }

  //Return the amount of characters mapped
  return i;
}

