#include "timeapi.h"

#include <ctime>

MMRESULT WINAPI timeGetDevCaps(LPTIMECAPS ptc, UINT cbtc) {
  if (ptc == nullptr) {
    return TIMERR_NOCANDO;
  }

  if (cbtc < sizeof(TIMECAPS)) {
    return TIMERR_NOCANDO;
  }

  struct timespec res = {};
  if (clock_getres(CLOCK_REALTIME, &res) != 0) {
    return MMSYSERR_ERROR;
  }

  //The TIMECAPS structure holds the result in milliseconds
  ptc->wPeriodMin = (res.tv_sec * 1000) + (res.tv_nsec / 1000000);
  ptc->wPeriodMax = (res.tv_sec * 1000) + (res.tv_nsec / 1000000);

  if (ptc->wPeriodMin == 0) {
    ptc->wPeriodMin = 1;
  }

  if (ptc->wPeriodMax == 0) {
    ptc->wPeriodMax = 1;
  }

  return MMSYSERR_NOERROR;
}

DWORD WINAPI timeGetTime() {
  struct timespec ts = {};
  clock_gettime(CLOCK_MONOTONIC, &ts);

  return (ts.tv_sec * 1000) + (ts.tv_nsec / 1000000);
}

