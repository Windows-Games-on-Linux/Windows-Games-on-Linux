#pragma once

#include <windef.h>
#include <cstdlib>

union SLIST_HEADER {
  union {
    struct {
      uint64_t Alignment;
      uint64_t Region;
    };
    struct {
      struct {
        uint64_t Depth : 16;
        uint64_t Sequence : 48;
      };
      struct {
        uint64_t Reserved : 4;
        uint64_t NextEntry : 60;
      };
    } HeaderX64;
  };
};

typedef SLIST_HEADER* PSLIST_HEADER;
