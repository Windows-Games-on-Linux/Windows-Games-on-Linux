#include "timeapi.h"

#include <ctime>
#include <iostream>
#include <signal.h>

namespace {
  struct TimerInfo {
    UINT uTimerID;
    LPTIMECALLBACK lpTimeProc;
    DWORD_PTR dwUser;
    UINT fuEvent;
  };

  void timer_handler(union sigval sv) {
    TimerInfo* timerInfo = (TimerInfo*)sv.sival_ptr;

    //For now, only TIME_CALLBACK_FUNCTION is supported
    timerInfo->lpTimeProc(timerInfo->uTimerID, 0, timerInfo->dwUser, 0, 0);

    if (!(timerInfo->fuEvent & TIME_PERIODIC)) {
      timer_delete((timer_t)timerInfo->uTimerID);
      delete timerInfo;

      return;
    }
  }
}

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

MMRESULT WINAPI timeBeginPeriod(UINT uPeriod) {
  //Nothing needs to be done here
  return MMSYSERR_NOERROR;
}

MMRESULT WINAPI timeSetEvent(UINT uDelay, UINT uResolution, LPTIMECALLBACK lpTimeProc, DWORD_PTR dwUser, UINT fuEvent) {
  timer_t timerId;
  TimerInfo* timerInfo = new TimerInfo();

  struct sigevent sev = {};
  sev.sigev_notify = SIGEV_THREAD;
  sev.sigev_value.sival_ptr = timerInfo;
  sev.sigev_notify_function = timer_handler;
  sev.sigev_notify_attributes = nullptr;
  if (timer_create(CLOCK_REALTIME, &sev, &timerId) == -1) {
    delete timerInfo;
    return MMSYSERR_ERROR;
  }

  timerInfo->uTimerID = (UINT)timerId;
  timerInfo->lpTimeProc = lpTimeProc;
  timerInfo->dwUser = dwUser;
  timerInfo->fuEvent = fuEvent;

  struct itimerspec its = {};
  its.it_value.tv_sec = uDelay / 1000;
  its.it_value.tv_nsec = (uDelay % 1000) * 1000000;

  if (fuEvent & TIME_PERIODIC) {
    its.it_interval.tv_sec = uDelay / 1000;
    its.it_interval.tv_nsec = (uDelay % 1000) * 1000000;
  }

  if (timer_settime(timerId, 0, &its, nullptr) == -1) {
    timer_delete(timerId);
    delete timerInfo;

    return MMSYSERR_ERROR;
  }

  if (fuEvent & TIME_CALLBACK_EVENT_SET) {
    std::cout << "timeSetEvent: Unimplemented Flag: TIME_CALLBACK_EVENT_SET" << std::endl;
  } else if (fuEvent & TIME_CALLBACK_EVENT_PULSE) {
    std::cout << "timeSetEvent: Unimplemented Flag: TIME_CALLBACK_EVENT_PULSE" << std::endl;
  } else if (fuEvent & TIME_KILL_SYNCHRONOUS) {
    std::cout << "timeSetEvent: Unimplemented Flag: TIME_KILL_SYNCHRONOUS" << std::endl;
  }

  return MMSYSERR_NOERROR;
}

