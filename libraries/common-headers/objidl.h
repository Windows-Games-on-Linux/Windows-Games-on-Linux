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

class IStream : public ISequentialStream {
  virtual HRESULT WINAPI Seek(LARGE_INTEGER dlibMove, DWORD dwOrigin, ULARGE_INTEGER* plibNewPosition) = 0;
  virtual HRESULT WINAPI SetSize(ULARGE_INTEGER libNewSize) = 0;
  virtual HRESULT WINAPI Commit(DWORD grfCommitFlags) = 0;
  virtual HRESULT WINAPI Revert() = 0;
  virtual HRESULT WINAPI CopyTo(IStream* pstm, ULARGE_INTEGER cb, ULARGE_INTEGER* pcbRead, ULARGE_INTEGER* pcbWritten) = 0;
  virtual HRESULT WINAPI Stat(STATSTG* pstatstg, DWORD grfStatFlag) = 0;
  virtual HRESULT WINAPI Clone(IStream** ppstm) = 0;
};

class IMarshal : public IUnknown {
  virtual HRESULT WINAPI GetUnmarshalClass(REFIID riid, void* pv, DWORD dwDestContext, void* pvDestContext, DWORD mshlflags, CLSID* pCid) = 0;
  virtual HRESULT WINAPI GetMarshalSizeMax(REFIID riid, void* pv, DWORD dwDestContext, void* pvDestContext, DWORD mshlflags, DWORD* pSize) = 0;
  virtual HRESULT WINAPI MarshalInterface(IStream* pStm, REFIID riid, void* pv, DWORD dwDestContext, void* pvDestContext, DWORD mshlflags) = 0;
  virtual HRESULT WINAPI UnmarshalInterface(IStream* pStm, REFIID riid, void** ppv) = 0;
  virtual HRESULT WINAPI ReleaseMarshalData(IStream* pStm) = 0;
  virtual HRESULT WINAPI DisconnectObject(DWORD dwReserved) = 0;
};

