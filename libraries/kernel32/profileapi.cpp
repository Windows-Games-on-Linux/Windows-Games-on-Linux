#include "profileapi.h"

#include <time.h>

BOOL __attribute__((stdcall)) QueryPerformanceCounter(LARGE_INTEGER* lpPerformanceCount) {
  struct timespec time;
  clock_gettime(CLOCK_REALTIME, &time);

  lpPerformanceCount->QuadPart = (time.tv_sec * 1000000000ULL) + time.tv_nsec;

  return 1;
}

BOOL __attribute__((stdcall)) QueryPerformanceFrequency(LARGE_INTEGER* lpFrequency) {
  lpFrequency->QuadPart = 1000000000ULL;
  return 1;
}

