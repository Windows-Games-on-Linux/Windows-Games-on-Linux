#pragma once

#include "gdiplustypes.h"
#include <windef.h>

enum DebugEventLevel {
  DebugEventLevelFatal,
  DebugEventLevelWarning
};

typedef void (*DebugEventProc)(DebugEventLevel level, CHAR* message);
typedef Status (*NotificationHookProc)(ULONG_PTR* token);
typedef VOID (*NotificationUnhookProc)(ULONG_PTR token);

struct GdiplusStartupInput {
  UINT32 GdiplusVersion;
  DebugEventProc DebugEventCallback;
  BOOL SuppressBackgroundThread;
  BOOL SuppressExternalCodecs;

  GdiplusStartupInput(DebugEventProc debugEventCallback, BOOL suppressBackgroundThread, BOOL suppressExternalCodecs);
};

struct GdiplusStartupOutput {
  NotificationHookProc NotificationHook;
  NotificationUnhookProc NotificationUnhook;
};
