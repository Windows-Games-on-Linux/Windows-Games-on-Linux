#pragma once

#include <windef.h>

extern "C" {
  VOID WINAPI RtlCaptureContext(PCONTEXT ContextRecord);
  PRUNTIME_FUNCTION WINAPI RtlLookupFunctionEntry(DWORD64 ControlPc, PDWORD64 ImageBase, PUNWIND_HISTORY_TABLE HistoryTable);
};

