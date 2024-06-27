#pragma once

#include <windef.h>

#define NIF_MESSAGE  0x00000001
#define NIF_ICON     0x00000002
#define NIF_TIP      0x00000004
#define NIF_STATE    0x00000008
#define NIF_INFO     0x00000010
#define NIF_GUID     0x00000020
#define NIF_REALTIME 0x00000040
#define NIF_SHOWTIP  0x00000080

#define NIS_HIDDEN     0x00000001
#define NIS_SHAREDICON 0x00000002

#define NIIF_NONE               0x00000000
#define NIIF_INFO               0x00000001
#define NIIF_WARNING            0x00000002
#define NIIF_ERROR              0x00000003
#define NIIF_USER               0x00000004
#define NIIF_NOSOUND            0x00000010
#define NIIF_LARGE_ICON         0x00000020
#define NIIF_RESPECT_QUIET_TIME 0x00000080
#define NIIF_ICON_MASK          0x0000000F

struct NOTIFYICONDATAW {
  DWORD cbSize;
  HWND hWnd;
  UINT uID;
  UINT uFlags;
  UINT uCallbackMessage;
  HICON hIcon;
  WCHAR szTip[128];
  DWORD dwState;
  DWORD dwStateMask;
  WCHAR szInfo[256];
  union {
    UINT uTimeout;
    UINT uVersion;
  } DUMMYUNIONNAME;
  WCHAR szInfoTitle[64];
  DWORD dwInfoFlags;
  GUID guidItem;
  HICON hBalloonIcon;
};

typedef NOTIFYICONDATAW* PNOTIFYICONDATAW;
