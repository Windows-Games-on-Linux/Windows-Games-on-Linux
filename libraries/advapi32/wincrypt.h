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

typedef ULONG_PTR    HCRYPTHASH;
typedef ULONG_PTR    HCRYPTKEY;
typedef ULONG_PTR    HCRYPTPROV;
typedef unsigned int ALG_ID;
