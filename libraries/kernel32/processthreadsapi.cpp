#include "processthreadsapi.h"

#include <pthread.h>
#include <unistd.h>
#include <iostream>

DWORD __attribute__((stdcall)) GetCurrentThreadId() {
  return pthread_self();
}

DWORD __attribute__((stdcall)) GetCurrentProcessId() {
  return getpid();
}

BOOL __attribute__((stdcall)) IsProcessorFeaturePresent(DWORD ProcessorFeature) {
  if (ProcessorFeature == PF_XMMI64_INSTRUCTIONS_AVAILABLE) {
    //First, push all the registers that will be affected by CPUID
    //We have to restore them later
    asm ("push %eax");
    asm ("push %ebx");
    asm ("push %ecx");
    asm ("push %edx");

    //Query available processor features
    asm ("mov $1, %eax");
    asm ("cpuid");

    //Bit 26 of EDX determines whether SSE2 is available
    BOOL available;
    asm ("and $0x04000000, %edx");
    asm ("shr $26, %edx");
    asm volatile ("movl %%edx, %0" : "=r" (available));

    //Restore the registers we pushed previously
    asm ("pop %edx");
    asm ("pop %ecx");
    asm ("pop %ebx");
    asm ("pop %eax");

    return available;
  }

  std::cout << "IsProcessorFeaturePresent: Unimplemented ProcessorFeature: " << ProcessorFeature << std::endl;
  return 0;
}
