#pragma once

#include <windef.h>

enum DebugEventLevel {
  DebugEventLevelFatal,
  DebugEventLevelWarning
};

typedef void (*DebugEventProc)(DebugEventLevel level, CHAR* message);
