#include "sysinfoapi.h"

#include <sys/time.h>
#include <cstdint>

void __attribute__((stdcall)) GetSystemTimeAsFileTime(LPFILETIME lpSystemTimeAsFileTime) {
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
