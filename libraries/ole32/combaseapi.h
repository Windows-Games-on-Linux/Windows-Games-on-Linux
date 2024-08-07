#pragma once

#include <windef.h>
#include <unknwn.h>

extern "C" {
  HRESULT WINAPI CoCreateFreeThreadedMarshaler(LPUNKNOWN punkOuter, LPUNKNOWN* ppunkMarshal);
};

