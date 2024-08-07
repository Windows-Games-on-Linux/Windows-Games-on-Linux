#pragma once

#include "windef.h"

typedef IID* REFIID;

class IUnknown {
  virtual ULONG WINAPI AddRef() = 0;
  virtual HRESULT WINAPI QueryInterface(REFIID riid, void** ppvObject) = 0;
  virtual ULONG WINAPI Release() = 0;
};

typedef IUnknown* LPUNKNOWN;

