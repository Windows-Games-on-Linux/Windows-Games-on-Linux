#pragma once

#include <windef.h>

struct TIME_ZONE_INFORMATION {
  LONG Bias;
  WCHAR StandardName[32];
  SYSTEMTIME StandardDate;
  LONG StandardBias;
  WCHAR DaylightName[32];
  SYSTEMTIME DaylightDate;
  LONG DaylightBias;
};

typedef TIME_ZONE_INFORMATION* PTIME_ZONE_INFORMATION;
typedef TIME_ZONE_INFORMATION* LPTIME_ZONE_INFORMATION;
