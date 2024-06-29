#pragma once

#include <windef.h>

#define CTRL_C_EVENT        0
#define CTRL_BREAK_EVENT    1
#define CTRL_CLOSE_EVENT    2
#define CTRL_LOGOFF_EVENT   5
#define CTRL_SHUTDOWN_EVENT 6

typedef BOOL (*PHANDLER_ROUTINE)(DWORD dwCtrlType);
