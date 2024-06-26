#pragma once

#include <windef.h>

struct DISPLAY_DEVICEA {
  DWORD cb;
  CHAR DeviceName[32];
  CHAR DeviceString[128];
  DWORD StateFlags;
  CHAR DeviceID[128];
  CHAR DeviceKey[128];
};

typedef DISPLAY_DEVICEA* PDISPLAY_DEVICEA;
typedef DISPLAY_DEVICEA* LPDISPLAY_DEVICEA;