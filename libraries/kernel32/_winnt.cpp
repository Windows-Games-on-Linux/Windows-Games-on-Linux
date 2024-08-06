#include "_winnt.h"

#include <ucontext.h>

VOID WINAPI RtlCaptureContext(PCONTEXT ContextRecord) {
  ucontext_t context;
  getcontext(&context);

  #if defined(__x86_64__)
    ContextRecord->ContextFlags = CONTEXT_AMD64;
    ContextRecord->MxCsr = context.uc_mcontext.fpregs->mxcsr;
    ContextRecord->EFlags = context.uc_mcontext.gregs[REG_EFL];
    //TODO: Debug registers
    ContextRecord->Rax = context.uc_mcontext.gregs[REG_RAX];
    ContextRecord->Rcx = context.uc_mcontext.gregs[REG_RCX];
    ContextRecord->Rdx = context.uc_mcontext.gregs[REG_RDX];
    ContextRecord->Rbx = context.uc_mcontext.gregs[REG_RBX];
    ContextRecord->Rsp = context.uc_mcontext.gregs[REG_RSP];
    ContextRecord->Rbp = context.uc_mcontext.gregs[REG_RBP];
    ContextRecord->Rsi = context.uc_mcontext.gregs[REG_RSI];
    ContextRecord->Rdi = context.uc_mcontext.gregs[REG_RDI];
    ContextRecord->R8 = context.uc_mcontext.gregs[REG_R8];
    ContextRecord->R9 = context.uc_mcontext.gregs[REG_R9];
    ContextRecord->R10 = context.uc_mcontext.gregs[REG_R10];
    ContextRecord->R11 = context.uc_mcontext.gregs[REG_R11];
    ContextRecord->R12 = context.uc_mcontext.gregs[REG_R12];
    ContextRecord->R13 = context.uc_mcontext.gregs[REG_R13];
    ContextRecord->R14 = context.uc_mcontext.gregs[REG_R14];
    ContextRecord->R15 = context.uc_mcontext.gregs[REG_R15];
    ContextRecord->Rip = context.uc_mcontext.gregs[REG_RIP];
    //TODO: The remaining fields
  #elif defined (__i386)
    //TODO: P1Home, P2Home, P3Home, P4Home, P5Home, P6Home
    ContextRecord->ContextFlags = CONTEXT_i386;
    //TODO: MxCsr
    ContextRecord->SegCs = context.uc_mcontext.gregs[REG_CS];
    ContextRecord->SegDs = context.uc_mcontext.gregs[REG_DS];
    ContextRecord->SegEs = context.uc_mcontext.gregs[REG_ES];
    ContextRecord->SegFs = context.uc_mcontext.gregs[REG_FS];
    ContextRecord->SegGs = context.uc_mcontext.gregs[REG_GS];
    ContextRecord->SegSs = context.uc_mcontext.gregs[REG_SS];
    ContextRecord->EFlags = context.uc_mcontext.gregs[REG_EFL];
    //TODO: Debug registers
    ContextRecord->Rax = context.uc_mcontext.gregs[REG_EAX];
    ContextRecord->Rcx = context.uc_mcontext.gregs[REG_ECX];
    ContextRecord->Rdx = context.uc_mcontext.gregs[REG_EDX];
    ContextRecord->Rbx = context.uc_mcontext.gregs[REG_EBX];
    ContextRecord->Rsp = context.uc_mcontext.gregs[REG_ESP];
    ContextRecord->Rbp = context.uc_mcontext.gregs[REG_EBP];
    ContextRecord->Rsi = context.uc_mcontext.gregs[REG_ESI];
    ContextRecord->Rdi = context.uc_mcontext.gregs[REG_EDI];
    ContextRecord->Rip = context.uc_mcontext.gregs[REG_EIP];
    //TODO: The remaining fields
  #else
    #error "Unsupported architecture"
  #endif
}

PRUNTIME_FUNCTION WINAPI RtlLookupFunctionEntry(DWORD64 ControlPc, PDWORD64 ImageBase, PUNWIND_HISTORY_TABLE HistoryTable) {
  //TODO: This function requires the function table
  //For now let's just assume that it doesn't exist
  return nullptr;
}

