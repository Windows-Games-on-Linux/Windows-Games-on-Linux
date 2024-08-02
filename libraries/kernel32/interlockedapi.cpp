#include "interlockedapi.h"

void WINAPI InitializeSListHead(PSLIST_HEADER ListHead) {
  //For now, let's ignore the Region field

  ListHead->HeaderX64.Depth = 0;
  ListHead->HeaderX64.Sequence = 0;
  ListHead->HeaderX64.NextEntry = 0;
}

