#pragma once

#include <windef.h>

#define CALG_3DES                 0x00006603
#define CALG_3DES_112             0x00006609
#define CALG_AES                  0x00006611
#define CALG_AES_128              0x0000660E
#define CALG_AES_192              0x0000660F
#define CALG_AES_256              0x00006610
#define CALG_AGREEDKEY_ANY        0x0000AA03
#define CALG_CYLINK_MEK           0x0000660C
#define CALG_DES                  0x00006601
#define CALG_DESX                 0x00006604
#define CALG_DH_EPHEM             0x0000AA02
#define CALG_DH_SF                0x0000AA01
#define CALG_DSS_SIGN             0x00002200
#define CALG_ECDH                 0x0000AA05
#define CALG_ECDH_EPHEM           0x0000AE06
#define CALG_ECDSA                0x00002203
#define CALG_ECMQV                0x0000A001
#define CALG_HASH_REPLACE_OWF     0x0000800B
#define CALG_HUGHES_MD5           0x0000A003
#define CALG_HMAC                 0x00008009
#define CALG_KEA_KEYX             0x0000AA04
#define CALG_MAC                  0x00008005
#define CALG_MD2                  0x00008001
#define CALG_MD4                  0x00008002
#define CALG_MD5                  0x00008003
#define CALG_NO_SIGN              0x00002000
#define CALG_OID_INFO_CNG_ONLY    0xFFFFFFFF
#define CALG_OID_INFO_PARAMETERS  0xFFFFFFFE
#define CALG_PCT1_MASTER          0x00004C04
#define CALG_RC2                  0x00006602
#define CALG_RC4                  0x00006801
#define CALG_RC5                  0x0000660D
#define CALG_RSA_KEYX             0x0000A400
#define CALG_RSA_SIGN             0x00002400
#define CALG_SCHANNEL_ENC_KEY     0x00004C07
#define CALG_SCHANNEL_MAC_KEY     0x00004C03
#define CALG_SCHANNEL_MASTER_HASH 0x00004C02
#define CALG_SEAL                 0x00006802
#define CALG_SHA                  0x00008004
#define CALG_SHA1                 0x00008004
#define CALG_SHA_256              0x8000800C
#define CALG_SHA_384              0x0000800D
#define CALG_SHA_512              0x0000800E
#define CALG_SKIPJACK             0x0000660A
#define CALG_SSL2_MASTER          0x00004C05
#define CALG_SSL3_MASTER          0x00004C01
#define CALG_SSL3_SHAMD5          0x00008008
#define CALG_TEK                  0x0000660B
#define CALG_TLS1_MASTER          0x00004C06
#define CALG_TLS1PRF              0x0000800A

#define PROV_RSA_FULL     0x00000001
#define PROV_RSA_AES      0x00000018
#define PROV_RSA_SIG      0x00000002
#define PROV_RSA_SCHANNEL 0x0000000C
#define PROV_DSS          0x00000003
#define PROV_DSS_DH       0x0000000D
#define PROV_DH_SCHANNEL  0x00000012
#define PROV_FORTEZZA     0x00000004
#define PROV_MS_EXCHANGE  0x00000005
#define PROV_SSL          0x00000006

#define CRYPT_VERIFYCONTEXT              0xF0000000
#define CRYPT_NEWKEYSET                  0x00000008
#define CRYPT_MACHINE_KEYSET             0x00000020
#define CRYPT_DELETEKEYSET               0x00000010
#define CRYPT_SILENT                     0x00000040
#define CRYPT_DEFAULT_CONTAINER_OPTIONAL 0x00000080

typedef ULONG_PTR    HCRYPTHASH;
typedef ULONG_PTR    HCRYPTKEY;
typedef ULONG_PTR    HCRYPTPROV;
typedef unsigned int ALG_ID;

extern "C" {
  BOOL WINAPI CryptAcquireContextW(HCRYPTPROV* phProv, LPCWSTR szContainer, LPCWSTR szProvider, DWORD dwProvType, DWORD dwFlags);
};

