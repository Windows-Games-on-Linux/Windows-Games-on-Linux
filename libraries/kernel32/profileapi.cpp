#include "profileapi.h"

#include <time.h>

BOOL __attribute__((stdcall)) QueryPerformanceCounter(LARGE_INTEGER* lpPerformanceCount) {
  struct timespec time;
  clock_gettime(CLOCK_REALTIME, &time);

  lpPerformanceCount->QuadPart = (time.tv_sec * 1000000000ULL) + time.tv_nsec;

  return 1;
}
