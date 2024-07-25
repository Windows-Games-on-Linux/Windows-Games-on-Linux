#pragma once

#include <windef.h>

#define PF_ARM_64BIT_LOADSTORE_ATOMIC            25
#define PF_ARM_DIVIDE_INSTRUCTION_AVAILABLE      24
#define PF_ARM_EXTERNAL_CACHE_AVAILABLE          26
#define PF_ARM_FMAC_INSTRUCTIONS_AVAILABLE       27
#define PF_ARM_VFP_32_REGISTERS_AVAILABLE        18
#define PF_3DNOW_INSTRUCTIONS_AVAILABLE           7
#define PF_CHANNELS_ENABLED                      16
#define PF_COMPARE_EXCHANGE_DOUBLE                2
#define PF_COMPARE_EXCHANGE128                   14
#define PF_COMPARE64_EXCHANGE128                 15
#define PF_FASTFAIL_AVAILABLE                    23
#define PF_FLOATING_POINT_EMULATED                1
#define PF_FLOATING_POINT_PRECISION_ERRATA        0
#define PF_MMX_INSTRUCTIONS_AVAILABLE             3
#define PF_NX_ENABLED                            12
#define PF_PAE_ENABLED                            9
#define PF_RDTSC_INSTRUCTION_AVAILABLE            8
#define PF_RDWRFSGSBASE_AVAILABLE                22
#define PF_SECOND_LEVEL_ADDRESS_TRANSLATION      20
#define PF_SSE3_INSTRUCTIONS_AVAILABLE           13
#define PF_SSSE3_INSTRUCTIONS_AVAILABLE          36
#define PF_SSE4_1_INSTRUCTIONS_AVAILABLE         37
#define PF_SSE4_2_INSTRUCTIONS_AVAILABLE         38
#define PF_AVX_INSTRUCTIONS_AVAILABLE            39
#define PF_AVX2_INSTRUCTIONS_AVAILABLE           40
#define PF_AVX512F_INSTRUCTIONS_AVAILABLE        41
#define PF_VIRT_FIRMWARE_ENABLED                 21
#define PF_XMMI_INSTRUCTIONS_AVAILABLE            6
#define PF_XMMI64_INSTRUCTIONS_AVAILABLE         10
#define PF_XSAVE_ENABLED                         17
#define PF_ARM_V8_INSTRUCTIONS_AVAILABLE         29
#define PF_ARM_V8_CRYPTO_INSTRUCTIONS_AVAILABLE  30
#define PF_ARM_V8_CRC32_INSTRUCTIONS_AVAILABLE   31
#define PF_ARM_V81_ATOMIC_INSTRUCTIONS_AVAILABLE 34
#define PF_ARM_V82_DP_INSTRUCTIONS_AVAILABLE     43
#define PF_ARM_V83_JSCVT_INSTRUCTIONS_AVAILABLE  44
#define PF_ARM_V83_LRCPC_INSTRUCTIONS_AVAILABLE  45

struct STARTUPINFOW {
  DWORD cb;
  LPWSTR lpReserved;
  LPWSTR lpDesktop;
  LPWSTR lpTitle;
  DWORD dwX;
  DWORD dwY;
  DWORD dwXSize;
  DWORD dwYSize;
  DWORD dwXCountChars;
  DWORD dwYCountChars;
  DWORD dwFillAttribute;
  DWORD dwFlags;
  WORD wShowWindow;
  WORD cbReserved2;
  LPBYTE lpReserved2;
  HANDLE hStdInput;
  HANDLE hStdOutput;
  HANDLE hStdError;
};

struct PROCESS_INFORMATION {
  HANDLE hProcess;
  HANDLE hThread;
  DWORD dwProcessId;
  DWORD dwThreadId;
};

typedef STARTUPINFOW* LPSTARTUPINFOW;

typedef PROCESS_INFORMATION* PPROCESS_INFORMATION;
typedef PROCESS_INFORMATION* LPPROCESS_INFORMATION;

extern "C" {
  DWORD __attribute__((stdcall)) GetCurrentThreadId();
  DWORD __attribute__((stdcall)) GetCurrentProcessId();
  BOOL __attribute__((stdcall)) IsProcessorFeaturePresent(DWORD ProcessorFeature);
};
