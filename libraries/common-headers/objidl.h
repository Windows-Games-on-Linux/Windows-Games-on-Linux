#pragma once

#include <windef.h>
#include "unknwn.h"

typedef WCHAR* LPOLESTR;

struct STATSTG {
  LPOLESTR pwcsName;
  DWORD type;
  ULARGE_INTEGER cbSize;
  FILETIME mtime;
  FILETIME ctime;
  FILETIME atime;
  DWORD grfMode;
  DWORD grfLocksSupported;
  CLSID clsid;
  DWORD grfStateBits;
  DWORD reserved;
};

class ISequentialStream : public IUnknown {
  virtual HRESULT WINAPI Read(void* pv, ULONG cb, ULONG* pcbRead) = 0;
  virtual HRESULT WINAPI Write(const void* pv, ULONG cb, ULONG* pcbWritten) = 0;
};

