#include "processthreadsapi.h"

#include <pthread.h>
#include <unistd.h>
#include <iostream>

DWORD WINAPI GetCurrentThreadId() {
  return pthread_self();
}

DWORD WINAPI GetCurrentProcessId() {
  return getpid();
}

BOOL WINAPI IsProcessorFeaturePresent(DWORD ProcessorFeature) {
  if (ProcessorFeature == PF_XMMI64_INSTRUCTIONS_AVAILABLE
   || ProcessorFeature == PF_FASTFAIL_AVAILABLE
  ) {
    //First, push all the registers that will be affected by CPUID
    //We have to restore them later
    #if defined(__x86_64__)
      asm ("push %rax");
      asm ("push %rbx");
      asm ("push %rcx");
      asm ("push %rdx");
    #elif defined(__i386)
      asm ("push %eax");
      asm ("push %ebx");
      asm ("push %ecx");
      asm ("push %edx");
    #else
      #error "Unsupported architecture"
    #endif

    BOOL available;

    //Query available processor features
    if (ProcessorFeature == PF_XMMI64_INSTRUCTIONS_AVAILABLE) {
      asm ("mov $1, %eax");
      asm ("cpuid");

      //Bit 26 of EDX determines whether SSE2 is available
      asm ("and $0x04000000, %edx");
      asm ("shr $26, %edx");
      asm volatile ("movl %%edx, %0" : "=r" (available));
    } else if (ProcessorFeature == PF_FASTFAIL_AVAILABLE) {
      asm ("mov $7, %eax");
      asm ("cpuid");

      //Bit 7 of EBX determines whether SMEP is available
      //Bit 20 determines whether SMAP is available
      asm ("and $0x00100080, %ebx");
      asm volatile ("movl %%ebx, %0" : "=r" (available));
      if ((available & 0x00100000) && (available & 0x00000080)) {
        available = 1;
      } else {
        available = 0;
      }
    }

    //Restore the registers we pushed previously
    #if defined(__x86_64__)
      asm ("pop %rdx");
      asm ("pop %rcx");
      asm ("pop %rbx");
      asm ("pop %rax");
    #elif defined(__i386)
      asm ("pop %edx");
      asm ("pop %ecx");
      asm ("pop %ebx");
      asm ("pop %eax");
    #else
      #error "Unsupported architecture"
    #endif

    return available;
  }

  std::cout << "IsProcessorFeaturePresent: Unimplemented ProcessorFeature: " << ProcessorFeature << std::endl;
  return 0;
}
