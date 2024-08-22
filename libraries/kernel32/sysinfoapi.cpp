#include "sysinfoapi.h"

#include <sys/time.h>
#include <cstdint>

void WINAPI GetSystemTimeAsFileTime(LPFILETIME lpSystemTimeAsFileTime) {
  struct timeval time;
  gettimeofday(&time, nullptr);

  //On Windows, the FILETIME structure holds the amount of time since January 1st, 1601.
  //On Linux however we get the amount of time since January 1st, 1970.
  //Below is the difference between these two time points in seconds.
  const uint64_t EPOCH_DIFFERENCE = 11644473600ULL;

  uint64_t filetime = EPOCH_DIFFERENCE + time.tv_sec;

  //FILETIME represents time in 100-nanosecond intervals
  filetime *= 10000000ULL;

  filetime += time.tv_usec * 10ULL;

  lpSystemTimeAsFileTime->dwLowDateTime = (filetime & 0x00000000FFFFFFFFULL);
  lpSystemTimeAsFileTime->dwHighDateTime = ((filetime & 0xFFFFFFFF00000000ULL) >> 32);
}

void WINAPI GetSystemTime(LPSYSTEMTIME lpSystemTime) {
  time_t t = time(nullptr);
  struct tm* tm_info = localtime(&t);

  lpSystemTime->wYear = tm_info->tm_year + 1900;
  lpSystemTime->wMonth = tm_info->tm_mon + 1;
  lpSystemTime->wDayOfWeek = tm_info->tm_wday;
  lpSystemTime->wDay = tm_info->tm_mday;
  lpSystemTime->wHour = tm_info->tm_hour;
  lpSystemTime->wMinute = tm_info->tm_min;
  lpSystemTime->wSecond = tm_info->tm_sec;
  lpSystemTime->wMilliseconds = 0;

  //TODO: Add support for leap seconds
}

