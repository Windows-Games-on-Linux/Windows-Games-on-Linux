#include "timezoneapi.h"

#include <iostream>

BOOL WINAPI SystemTimeToFileTime(const SYSTEMTIME* lpSystemTime, LPFILETIME lpFileTime) {
  struct tm tm_info = {};

  tm_info.tm_year = lpSystemTime->wYear - 1900;
  tm_info.tm_mon = lpSystemTime->wMonth - 1;
  tm_info.tm_wday = lpSystemTime->wDayOfWeek;
  tm_info.tm_mday = lpSystemTime->wDay;
  tm_info.tm_hour = lpSystemTime->wHour;
  tm_info.tm_min = lpSystemTime->wMinute;
  tm_info.tm_sec = lpSystemTime->wSecond;

  time_t time = mktime(&tm_info);

  //On Windows, the FILETIME structure holds the amount of time since January 1st, 1601.
  //On Linux however we get the amount of time since January 1st, 1970.
  //Below is the difference between these two time points in seconds.
  const uint64_t EPOCH_DIFFERENCE = 11644473600ULL;

  uint64_t filetime = EPOCH_DIFFERENCE + time;

  //FILETIME represents time in 100-nanosecond intervals
  filetime *= 10000000ULL;

  lpFileTime->dwLowDateTime = (filetime & 0x00000000FFFFFFFFULL);
  lpFileTime->dwHighDateTime = ((filetime & 0xFFFFFFFF00000000ULL) >> 32);

  return 1;
}

