#include "debugapi.h"

BOOL WINAPI IsDebuggerPresent() {
  //TODO: Check whether a debugger is attached to the current process
  //For now just assume that it's not
  return 0;
}

