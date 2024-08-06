#include "errhandlingapi.h"

#include <csignal>

__thread DWORD lastError = 0;
LPTOP_LEVEL_EXCEPTION_FILTER unhandledExceptionFilter = nullptr;

DWORD WINAPI GetLastError() {
  return lastError;
}

void WINAPI SetLastError(DWORD dwErrorCode) {
  lastError = dwErrorCode;
}

void signalHandler(int signal, siginfo_t* info, void* context) {
  if (unhandledExceptionFilter) {
    EXCEPTION_RECORD exceptionRecord = {};

    exceptionRecord.ExceptionFlags = 0;
    exceptionRecord.NumberParameters = 0;

    if (signal == SIGABRT) {
      exceptionRecord.ExceptionCode = EXCEPTION_NONCONTINUABLE_EXCEPTION;
    } else if (signal == SIGBUS) {
      if (info->si_code == BUS_ADRALN) {
        exceptionRecord.ExceptionCode = EXCEPTION_DATATYPE_MISALIGNMENT;
      } else if (info->si_code == BUS_ADRERR) {
        exceptionRecord.ExceptionCode = EXCEPTION_ACCESS_VIOLATION;

        exceptionRecord.NumberParameters = 2;
        exceptionRecord.ExceptionInformation[0] = 0; //There's no easy way to figure out if it was a write or a read
        exceptionRecord.ExceptionInformation[1] = (ULONG_PTR)info->si_addr;
      }
    } else if (signal == SIGFPE) {
      if (info->si_code == FPE_INTDIV) {
        exceptionRecord.ExceptionCode = EXCEPTION_INT_DIVIDE_BY_ZERO;
      } else if (info->si_code == FPE_INTOVF) {
        exceptionRecord.ExceptionCode = EXCEPTION_INT_OVERFLOW;
      } else if (info->si_code == FPE_FLTDIV) {
        exceptionRecord.ExceptionCode = EXCEPTION_FLT_DIVIDE_BY_ZERO;
      } else if (info->si_code == FPE_FLTOVF) {
        exceptionRecord.ExceptionCode = EXCEPTION_FLT_OVERFLOW;
      } else if (info->si_code == FPE_FLTUND) {
        exceptionRecord.ExceptionCode = EXCEPTION_FLT_UNDERFLOW;
      } else if (info->si_code == FPE_FLTRES) {
        exceptionRecord.ExceptionCode = EXCEPTION_FLT_INEXACT_RESULT;
      } else if (info->si_code == FPE_FLTINV) {
        exceptionRecord.ExceptionCode = EXCEPTION_FLT_INVALID_OPERATION;
      }
    } else if (signal == SIGILL) {
      exceptionRecord.ExceptionCode = EXCEPTION_ILLEGAL_INSTRUCTION;
    } else if (signal == SIGSEGV) {
      exceptionRecord.ExceptionCode = EXCEPTION_ACCESS_VIOLATION;
    } else if (signal == SIGSTKFLT) {
      exceptionRecord.ExceptionCode = EXCEPTION_STACK_OVERFLOW;
    } else if (signal == SIGTRAP) {
      if (info->si_code == TRAP_BRKPT) {
        exceptionRecord.ExceptionCode = EXCEPTION_BREAKPOINT;
      } else if (info->si_code == TRAP_TRACE) {
        exceptionRecord.ExceptionCode = EXCEPTION_SINGLE_STEP;
      }
    }

    exceptionRecord.ExceptionRecord = nullptr;
    exceptionRecord.ExceptionAddress = 0;

    CONTEXT contextRecord = {};
    ucontext_t* ucontext = (ucontext_t*)context;

    #if defined(__x86_64__)
      contextRecord.ContextFlags = CONTEXT_AMD64;
      contextRecord.MxCsr = ucontext->uc_mcontext.fpregs->mxcsr;
      contextRecord.EFlags = ucontext->uc_mcontext.gregs[REG_EFL];
      //TODO: Debug registers
      contextRecord.Rax = ucontext->uc_mcontext.gregs[REG_RAX];
      contextRecord.Rcx = ucontext->uc_mcontext.gregs[REG_RCX];
      contextRecord.Rdx = ucontext->uc_mcontext.gregs[REG_RDX];
      contextRecord.Rbx = ucontext->uc_mcontext.gregs[REG_RBX];
      contextRecord.Rsp = ucontext->uc_mcontext.gregs[REG_RSP];
      contextRecord.Rbp = ucontext->uc_mcontext.gregs[REG_RBP];
      contextRecord.Rsi = ucontext->uc_mcontext.gregs[REG_RSI];
      contextRecord.Rdi = ucontext->uc_mcontext.gregs[REG_RDI];
      contextRecord.R8 = ucontext->uc_mcontext.gregs[REG_R8];
      contextRecord.R9 = ucontext->uc_mcontext.gregs[REG_R9];
      contextRecord.R10 = ucontext->uc_mcontext.gregs[REG_R10];
      contextRecord.R11 = ucontext->uc_mcontext.gregs[REG_R11];
      contextRecord.R12 = ucontext->uc_mcontext.gregs[REG_R12];
      contextRecord.R13 = ucontext->uc_mcontext.gregs[REG_R13];
      contextRecord.R14 = ucontext->uc_mcontext.gregs[REG_R14];
      contextRecord.R15 = ucontext->uc_mcontext.gregs[REG_R15];
      contextRecord.Rip = ucontext->uc_mcontext.gregs[REG_RIP];
      //TODO: The remaining fields
    #elif defined (__i386)
      //TODO: P1Home, P2Home, P3Home, P4Home, P5Home, P6Home
      contextRecord.ContextFlags = CONTEXT_i386;
      //TODO: MxCsr
      contextRecord.SegCs = ucontext->uc_mcontext.gregs[REG_CS];
      contextRecord.SegDs = ucontext->uc_mcontext.gregs[REG_DS];
      contextRecord.SegEs = ucontext->uc_mcontext.gregs[REG_ES];
      contextRecord.SegFs = ucontext->uc_mcontext.gregs[REG_FS];
      contextRecord.SegGs = ucontext->uc_mcontext.gregs[REG_GS];
      contextRecord.SegSs = ucontext->uc_mcontext.gregs[REG_SS];
      contextRecord.EFlags = ucontext->uc_mcontext.gregs[REG_EFL];
      //TODO: Debug registers
      contextRecord.Rax = ucontext->uc_mcontext.gregs[REG_EAX];
      contextRecord.Rcx = ucontext->uc_mcontext.gregs[REG_ECX];
      contextRecord.Rdx = ucontext->uc_mcontext.gregs[REG_EDX];
      contextRecord.Rbx = ucontext->uc_mcontext.gregs[REG_EBX];
      contextRecord.Rsp = ucontext->uc_mcontext.gregs[REG_ESP];
      contextRecord.Rbp = ucontext->uc_mcontext.gregs[REG_EBP];
      contextRecord.Rsi = ucontext->uc_mcontext.gregs[REG_ESI];
      contextRecord.Rdi = ucontext->uc_mcontext.gregs[REG_EDI];
      contextRecord.Rip = ucontext->uc_mcontext.gregs[REG_EIP];
      //TODO: The remaining fields
    #else
      #error "Unsupported architecture"
    #endif

    EXCEPTION_POINTERS exceptionPointers = {};
    exceptionPointers.ExceptionRecord = &exceptionRecord;
    exceptionPointers.ContextRecord = &contextRecord;

    unhandledExceptionFilter(&exceptionPointers);
  }
}

LPTOP_LEVEL_EXCEPTION_FILTER WINAPI SetUnhandledExceptionFilter(LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter) {
  LPTOP_LEVEL_EXCEPTION_FILTER previous = unhandledExceptionFilter;
  unhandledExceptionFilter = lpTopLevelExceptionFilter;

  struct sigaction sa = {};

  if (lpTopLevelExceptionFilter) {
    sa.sa_sigaction = signalHandler;
    sa.sa_flags = SA_SIGINFO;
  } else {
    sa.sa_handler = SIG_DFL;
    sa.sa_flags = 0;
  }

  sigemptyset(&sa.sa_mask);

  sigaction(SIGABRT, &sa, nullptr);
  sigaction(SIGBUS, &sa, nullptr);
  sigaction(SIGFPE, &sa, nullptr);
  sigaction(SIGILL, &sa, nullptr);
  sigaction(SIGSEGV, &sa, nullptr);
  sigaction(SIGSTKFLT, &sa, nullptr);
  sigaction(SIGTRAP, &sa, nullptr);

  return previous;
}

