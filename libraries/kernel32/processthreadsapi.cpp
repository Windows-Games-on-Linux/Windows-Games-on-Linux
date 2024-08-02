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
  if (ProcessorFeature == PF_XMMI64_INSTRUCTIONS_AVAILABLE) {
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

    //Query available processor features
    asm ("mov $1, %eax");
    asm ("cpuid");

    //Bit 26 of EDX determines whether SSE2 is available
    BOOL available;
    asm ("and $0x04000000, %edx");
    asm ("shr $26, %edx");
    asm volatile ("movl %%edx, %0" : "=r" (available));

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
