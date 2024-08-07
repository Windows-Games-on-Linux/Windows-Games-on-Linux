#include "combaseapi.h"

#include <objidl.h>
#include <iostream>
#include <winerror.h>
#include <cstring>
#include <type_traits>

const GUID IID_IMarshal = { 0x00000003, 0x0000, 0x0000, { 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46 } };

HRESULT WINAPI CoCreateFreeThreadedMarshaler(LPUNKNOWN punkOuter, LPUNKNOWN* ppunkMarshal) {
  class : public IMarshal {
  protected:
    ULONG ref = 1;

  public:
    HRESULT WINAPI QueryInterface(REFIID riid, void** ppvObject) override {
      std::cout << "IMarshal.QueryInterface: Unimplemented IID" << std::endl;
      return E_NOINTERFACE;
    }

    ULONG WINAPI AddRef() override {
      return ++ref;
    }

    ULONG WINAPI Release() override {
      ref--;
      if (ref == 0) {
        delete this;
      }

      return ref;
    }

    HRESULT WINAPI GetUnmarshalClass(REFIID riid, void* pv, DWORD dwDestContext, void* pvDestContext, DWORD mshlflags, CLSID* pCid) override {
      std::cout << "IMarshal.GetUnmarshalClass: Not implemented" << std::endl;
      return E_NOTIMPL;
    }

    HRESULT WINAPI GetMarshalSizeMax(REFIID riid, void* pv, DWORD dwDestContext, void* pvDestContext, DWORD mshlflags, DWORD* pSize) override {
      std::cout << "IMarshal.GetMarshalSizeMax: Not implemented" << std::endl;
      return E_NOTIMPL;
    }

    HRESULT WINAPI MarshalInterface(IStream* pStm, REFIID riid, void* pv, DWORD dwDestContext, void* pvDestContext, DWORD mshlflags) override {
      std::cout << "IMarshal.MarshalInterface: Not implemented" << std::endl;
      return E_NOTIMPL;
    }

    HRESULT WINAPI UnmarshalInterface(IStream* pStm, REFIID riid, void** ppv) override {
      std::cout << "IMarshal.UnmarshalInterface: Not implemented" << std::endl;
      return E_NOTIMPL;
    }

    HRESULT WINAPI ReleaseMarshalData(IStream* pStm) override {
      std::cout << "IMarshal.ReleaseMarshalData: Not implemented" << std::endl;
      return E_NOTIMPL;
    }

    HRESULT WINAPI DisconnectObject(DWORD dwReserved) override {
      std::cout << "IMarshal.DisconnectObject: Not implemented" << std::endl;
      return E_NOTIMPL;
    }
  }* marshal = new std::remove_pointer<decltype(marshal)>::type();

  class : public IUnknown {
  private:
    ULONG ref = 1;
    IMarshal* marshal = marshal;

  public:
    HRESULT WINAPI QueryInterface(REFIID riid, void** ppvObject) override {
      if (memcmp(riid, &IID_IMarshal, sizeof(IID_IMarshal)) == 0) {
        *ppvObject = marshal;
      } else {
        std::cout << "IUnknown(CoCreateFreeThreadedMarshaler).QueryInterface: Unimplemented IID" << std::endl;
        return E_NOINTERFACE;
      }

      return S_OK;
    }

    ULONG WINAPI AddRef() override {
      return ++ref;
    }

    ULONG WINAPI Release() override {
      ref--;
      if (ref == 0) {
        delete this;
      }

      return ref;
    }
  }* marshaler = new std::remove_pointer<decltype(marshaler)>::type();

  *ppunkMarshal = marshaler;
  return S_OK;
}

