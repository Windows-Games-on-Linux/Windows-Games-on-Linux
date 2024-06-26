#pragma once

#include "gdiplustypes.h"
#include <windef.h>

enum DebugEventLevel {
  DebugEventLevelFatal,
  DebugEventLevelWarning
};

typedef void (*DebugEventProc)(DebugEventLevel level, CHAR* message);
typedef Status (*NotificationHookProc)(ULONG_PTR* token);
