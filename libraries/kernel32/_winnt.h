#pragma once

#include <windef.h>

extern "C" {
  VOID WINAPI RtlCaptureContext(PCONTEXT ContextRecord);
};

