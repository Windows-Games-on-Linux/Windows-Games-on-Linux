#pragma once

#include <windef.h>

#define LOCALE_NAME_INVARIANT      u""
#define LOCALE_NAME_SYSTEM_DEFAULT u"!x-sys-default-locale"
#define LOCALE_NAME_USER_DEFAULT   nullptr

#define LCMAP_BYTEREV             0x00000800
#define LCMAP_FULLWIDTH           0x00800000
#define LCMAP_HALFWIDTH           0x00400000
#define LCMAP_HIRAGANA            0x00100000
#define LCMAP_KATAKANA            0x00200000
#define LCMAP_LINGUISTIC_CASING   0x01000000
#define LCMAP_LOWERCASE           0x00000100
#define LCMAP_HASH                0x00040000
#define LCMAP_SIMPLIFIED_CHINESE  0x02000000
#define LCMAP_SORTHANDLE          0x20000000
#define LCMAP_SORTKEY             0x00000400
#define LCMAP_TITLECASE           0x00000300
#define LCMAP_TRADITIONAL_CHINESE 0x04000000
#define LCMAP_UPPERCASE           0x00000200

#define NORM_IGNORENONSPACE 0x00000002
#define NORM_IGNORESYMBOLS  0x00000004

#define LINGUISTIC_IGNORECASE      0x00000010
#define LINGUISTIC_IGNOREDIACRITIC 0x00000020
#define NORM_IGNORECASE            0x00000001
#define NORM_IGNOREKANATYPE        0x00010000
#define NORM_IGNOREWIDTH           0x00020000
#define NORM_LINGUISTIC_CASING     0x08000000
#define SORT_DIGITSASNUMBERS       0x00000008
#define SORT_STRINGSORT            0x00001000

struct NLSVERSIONINFO {
  DWORD dwNLSVersionInfoSize;
  DWORD dwNLSVersion;
  DWORD dwDefinedVersion;
};

typedef NLSVERSIONINFO* LPNLSVERSIONINFO;

extern "C" {
  int __attribute__((stdcall)) LCMapStringEx(LPCWSTR lpLocaleName, DWORD dwMapFlags, LPCWSTR lpSrcStr, int cchSrc, LPWSTR lpDestStr, int cchDest, LPNLSVERSIONINFO lpVersionInformation, LPVOID lpReserved, LPARAM sortHandle);
};

