#include "profileapi.h"

#include <time.h>

BOOL WINAPI QueryPerformanceCounter(LARGE_INTEGER* lpPerformanceCount) {
  struct timespec time;
  clock_gettime(CLOCK_REALTIME, &time);

  lpPerformanceCount->QuadPart = (time.tv_sec * 1000000000ULL) + time.tv_nsec;

  return 1;
}

BOOL WINAPI QueryPerformanceFrequency(LARGE_INTEGER* lpFrequency) {
  lpFrequency->QuadPart = 1000000000ULL;
  return 1;
}

