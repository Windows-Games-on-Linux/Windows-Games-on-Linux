#pragma once

//This file will be included by windef.h after all necessary types are defined

struct FILETIME {
  DWORD dwLodDateTime;
  DWORD dwHighDateTime;
};

struct SYSTEMTIME {
  WORD wYear;
  WORD wMonth;
  WORD wDayOfWeek;
  WORD wDay;
  WORD wHour;
  WORD wMinute;
  WORD wSecond;
  WORD wMilliseconds;
};

typedef FILETIME* PFILETIME;
typedef FILETIME* LPFILETIME;

typedef SYSTEMTIME* PSYSTEMTIME;
typedef SYSTEMTIME* LPSYSTEMTIME;
