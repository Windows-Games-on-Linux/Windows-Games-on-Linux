#pragma once

#include <windef.h>
#include "mmsystem.h"

#define TIMERR_BASE    96
#define TIMERR_NOCANDO (TIMERR_BASE + 1)

extern "C" {
  MMRESULT WINAPI timeGetDevCaps(LPTIMECAPS ptc, UINT cbtc);
  DWORD WINAPI timeGetTime();
  MMRESULT WINAPI timeBeginPeriod(UINT uPeriod);
};

