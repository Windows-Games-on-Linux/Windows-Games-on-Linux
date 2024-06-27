#pragma once

#include "intsafe.h"
#include "basetsd.h"
#include "minwinbase.h"
#include "guiddef.h"

#define WINAPI
#define CALLBACK
#define CONST const

#define APIENTRY WINAPI

typedef unsigned short WORD;
typedef int            BOOL;
typedef unsigned char  BYTE;
typedef DWORD          COLORREF;
typedef float          FLOAT;
typedef int            HFILE;
typedef int            INT;
typedef LONG_PTR       LPARAM;
typedef DWORD*         LPCOLORREF;
typedef CONST void*    LPCVOID;
typedef DWORD*         LPDWORD;
typedef int*           LPINT;
typedef long*          LPLONG;
typedef void*          LPVOID;
typedef WORD*          LPWORD;
typedef LONG_PTR       LRESULT;
typedef DWORD*         PDWORD;
typedef int*           PINT;
typedef unsigned char  UCHAR;
typedef unsigned int   UINT;
typedef unsigned long  ULONG;
typedef unsigned short USHORT;
typedef UINT_PTR       WPARAM;

typedef WORD    ATOM;
typedef BOOL*   LPBOOL;
typedef BYTE*   LPBYTE;
typedef BOOL*   PBOOL;
typedef BYTE*   PBYTE;
typedef FLOAT*  PFLOAT;
typedef UCHAR*  PUCHAR;
typedef UINT*   PUINT;
typedef ULONG*  PULONG;
typedef USHORT* PUSHORT;
typedef WORD*   PWORD;

#include "winnt.h"

typedef HANDLE     HACCEL;
typedef HANDLE     HBITMAP;
typedef HANDLE     HBRUSH;
typedef HANDLE     HCOLORSPACE;
typedef HANDLE     HICON;
typedef HANDLE     HDC;
typedef HANDLE     HDESK;
typedef HANDLE     HENHMETAFILE;
typedef HANDLE     HFONT;
typedef HANDLE     HGDIOBJ;
typedef HANDLE     HGLOBAL;
typedef HANDLE     HHOOK;
typedef HANDLE     HINSTANCE;
typedef HANDLE     HKEY;
typedef HANDLE     HKL;
typedef HANDLE     HLOCAL;
typedef HANDLE     HMENU;
typedef HANDLE     HMETAFILE;
typedef HANDLE     HMONITOR;
typedef HANDLE     HPALETTE;
typedef HANDLE     HPEN;
typedef HANDLE     HRGN;
typedef HANDLE     HRSRC;
typedef HANDLE     HWINSTA;
typedef HANDLE     HWND;
typedef HANDLE*    LPHANDLE;
typedef ULONGLONG* PULONGLONG;

typedef HICON     HCURSOR;
typedef HINSTANCE HMODULE;
typedef HKEY*     PHKEY;

struct RECT {
  LONG left;
  LONG top;
  LONG right;
  LONG bottom;
};

struct POINT {
  LONG x;
  LONG y;
};

typedef RECT* PRECT;
typedef RECT* NPRECT;
typedef RECT* LPRECT;

typedef POINT* PPOINT;
typedef POINT* NPPOINT;
typedef POINT* LPPOINT;
