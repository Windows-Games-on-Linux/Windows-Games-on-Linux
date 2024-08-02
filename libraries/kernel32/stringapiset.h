#pragma once

#include <windef.h>

#define MB_COMPOSITE         0x00000002
#define MB_ERR_INVALID_CHARS 0x00000008
#define MB_PRECOMPOSED       0x00000001
#define MB_USEGLYPHCHARS     0x00000004

#define CT_CTYPE1 0x00000001
#define CT_CTYPE2 0x00000002
#define CT_CTYPE3 0x00000004

#define C1_UPPER   0x0001
#define C1_LOWER   0x0002
#define C1_DIGIT   0x0004
#define C1_SPACE   0x0008
#define C1_PUNCT   0x0010
#define C1_CNTRL   0x0020
#define C1_BLANK   0x0040
#define C1_XDIGIT  0x0080
#define C1_ALPHA   0x0100
#define C1_DEFINED 0x0200

#define C2_LEFTTORIGHT      0x0001
#define C2_RIGHTTOLEFT      0x0002
#define C2_EUROPENUMBER     0x0003
#define C2_EUROPESEPARATOR  0x0004
#define C2_EUROPETERMINATOR 0x0005
#define C2_ARABICNUMBER     0x0006
#define C2_COMMONSEPARATOR  0x0007
#define C2_BLOCKSEPARATOR   0x0008
#define C2_SEGMENTSEPARATOR 0x0009
#define C2_WHITESPACE       0x000A
#define C2_OTHERNEUTRAL     0x000B
#define C2_NOTAPPLICABLE    0x0000

#define C3_NONSPACING    0x0001
#define C3_DIACRITIC     0x0002
#define C3_VOWELMARK     0x0004
#define C3_SYMBOL        0x0008
#define C3_KATAKANA      0x0010
#define C3_HIRAGANA      0x0020
#define C3_HALFWIDTH     0x0040
#define C3_FULLWIDTH     0x0080
#define C3_IDEOGRAPH     0x0100
#define C3_KASHIDA       0x0200
#define C3_LEXICAL       0x0400
#define C3_ALPHA         0x8000
#define C3_HIGHSURROGATE 0x0800
#define C3_LOWSURROGATE  0x1000
#define C3_NOTAPPLICABLE 0x0000

#define WC_COMPOSITECHECK    0x00000200
#define WC_DEFAULTCHAR       0x00000040
#define WC_DISCARDNS         0x00000010
#define WC_SEPCHARS          0x00000020
#define WC_ERR_INVALID_CHARS 0x00000080
#define WC_NO_BEST_FIT_CHARS 0x00000400

extern "C" {
  int WINAPI MultiByteToWideChar(UINT CodePage, DWORD dwFlags, LPCCH lpMultiByteStr, int cbMultiByte, LPWSTR lpWideCharStr, int cchWideChar);
  BOOL WINAPI GetStringTypeW(DWORD dwInfoType, LPCWCH lpSrcStr, int cchSrc, LPWORD lpCharType);
  int WINAPI WideCharToMultiByte(UINT CodePage, DWORD dwFlags, LPCWCH lpWideCharStr, int cchWideChar, LPSTR lpMultiByteStr, int cbMultiByte, LPCCH lpDefaultChar, LPBOOL lpUsedDefaultChar);
};

