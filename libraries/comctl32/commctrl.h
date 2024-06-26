#pragma once

#include <windef.h>

struct INITCOMMONCONTROLSEX {
  DWORD dwSize;
  DWORD dwICC;
};

typedef INITCOMMONCONTROLSEX* LPINITCOMMONCONTROLSEX;

extern "C" {
  BOOL _TrackMouseEvent(LPTRACKMOUSEEVENT lpEventTrack);
}
