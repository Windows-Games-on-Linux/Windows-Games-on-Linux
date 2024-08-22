#pragma once

#include <windef.h>

#define MMSYSERR_NOERROR 0
#define MMSYSERR_ERROR   1

typedef UINT MMRESULT;

struct TIMECAPS {
  UINT wPeriodMin;
  UINT wPeriodMax;
};

typedef TIMECAPS* PTIMECAPS;
typedef TIMECAPS* LPTIMECAPS;

