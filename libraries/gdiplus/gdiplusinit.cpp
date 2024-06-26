#include "gdiplusinit.h"

GdiplusStartupInput::GdiplusStartupInput(DebugEventProc debugEventCallback, BOOL suppressBackgroundThread, BOOL suppressExternalCodecs) {
  this->GdiplusVersion = 1;
  this->DebugEventCallback = debugEventCallback;
  this->SuppressBackgroundThread = suppressBackgroundThread;
  this->SuppressExternalCodecs = suppressExternalCodecs;
}