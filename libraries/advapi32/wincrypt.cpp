#include "wincrypt.h"

#include <iostream>

namespace {
  struct CryptProvider {
  };

  struct RsaFullProvider : public CryptProvider {
  };

  RsaFullProvider defaultRsaFullProvider = {};

  struct CryptContext {
    CryptProvider* provider;
  };
};

BOOL WINAPI CryptAcquireContextW(HCRYPTPROV* phProv, LPCWSTR szContainer, LPCWSTR szProvider, DWORD dwProvType, DWORD dwFlags) {
  if (dwFlags & CRYPT_NEWKEYSET) {
    std::cout << "CryptAcquireContextW: Unimplemented flag: CRYPT_NEWKEYSET" << std::endl;
  }

  if (dwFlags & CRYPT_MACHINE_KEYSET) {
    std::cout << "CryptAcquireContextW: Unimplemented flag: CRYPT_MACHINE_KEYSET" << std::endl;
  }

  if (dwFlags & CRYPT_DELETEKEYSET) {
    std::cout << "CryptAcquireContextW: Unimplemented flag: CRYPT_DELETEKEYSET" << std::endl;
  }

  if (dwFlags & CRYPT_DEFAULT_CONTAINER_OPTIONAL) {
    std::cout << "CryptAcquireContextW: Unimplemented flag: CRYPT_DEFAULT_CONTAINER_OPTIONAL" << std::endl;
  }

  if (dwProvType == PROV_RSA_FULL) {
    if (szProvider != nullptr) {
      std::cout << "CryptAcquireContextW: Non-default providers are not supported" << std::endl;
      return 0;
    }

    if (szContainer != nullptr) {
      std::cout << "CryptAcquireContextW: Non-default containers are not supported" << std::endl;
      return 0;
    }

    if (!(dwFlags & CRYPT_VERIFYCONTEXT)) {
      std::cout << "CryptAcquireContextW: Contexts with key storage access are not implemented" << std::endl;
    }

    if (!(dwFlags & CRYPT_SILENT)) {
      std::cout << "CryptAcquireContextW: Non-silent contexts are not supported" << std::endl;
    }

    CryptContext* cryptContext = new CryptContext();
    cryptContext->provider = &defaultRsaFullProvider;

    *phProv = (HCRYPTPROV)cryptContext;
    return 1;
  } else if (dwProvType == PROV_RSA_AES) {
    std::cout << "CryptAcquireContextW: Unimplemented provider type: PROV_RSA_AES" << std::endl;
    return 0;
  } else if (dwProvType == PROV_RSA_SIG) {
    std::cout << "CryptAcquireContextW: Unimplemented provider type: PROV_RSA_SIG" << std::endl;
    return 0;
  } else if (dwProvType == PROV_RSA_SCHANNEL) {
    std::cout << "CryptAcquireContextW: Unimplemented provider type: PROV_RSA_SCHANNEL" << std::endl;
    return 0;
  } else if (dwProvType == PROV_DSS) {
    std::cout << "CryptAcquireContextW: Unimplemented provider type: PROV_DSS" << std::endl;
    return 0;
  } else if (dwProvType == PROV_DSS_DH) {
    std::cout << "CryptAcquireContextW: Unimplemented provider type: PROV_DSS_DH" << std::endl;
    return 0;
  } else if (dwProvType == PROV_DH_SCHANNEL) {
    std::cout << "CryptAcquireContextW: Unimplemented provider type: PROV_DH_SCHANNEL" << std::endl;
    return 0;
  } else if (dwProvType == PROV_FORTEZZA) {
    std::cout << "CryptAcquireContextW: Unimplemented provider type: PROV_FORTEZZA" << std::endl;
    return 0;
  } else if (dwProvType == PROV_MS_EXCHANGE) {
    std::cout << "CryptAcquireContextW: Unimplemented provider type: PROV_MS_EXCHANGE" << std::endl;
    return 0;
  } else if (dwProvType == PROV_SSL) {
    std::cout << "CryptAcquireContextW: Unimplemented provider type: PROV_SSL" << std::endl;
    return 0;
  }

  return 0;
}

