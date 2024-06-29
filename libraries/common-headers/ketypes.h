#pragma once

#include "windef.h"

struct M128A {
  ULONGLONG Low;
  LONGLONG High;
};

typedef M128A* PM128A;

struct XSAVE_FORMAT {
  USHORT ControlWord;
  USHORT StatusWord;
  UCHAR TagWord;
  UCHAR Reserved1;
  USHORT ErrorOpcode;
  ULONG ErrorOffset;
  USHORT ErrorSelector;
  USHORT Reserved2;
  ULONG DataOffset;
  USHORT DataSelector;
  USHORT Reserved3;
  ULONG MxCsr;
  ULONG MxCsr_Mask;
  M128A FloatRegisters[8];
  M128A XmmRegisters[8];
  UCHAR Reserved4[192];
  ULONG StackControl[7];
  ULONG Cr0NpxState;
};

typedef XSAVE_FORMAT* PXSAVE_FORMAT;
