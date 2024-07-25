#include "fibersapi.h"

#include <pthread.h>

DWORD __attribute__((stdcall)) FlsAlloc(PFLS_CALLBACK_FUNCTION lpCallback) {
  pthread_key_t key;
  pthread_key_create(&key, lpCallback);

  return key;
}

PVOID __attribute__((stdcall)) FlsGetValue(DWORD dwFlsIndex) {
  return pthread_getspecific(dwFlsIndex);
}

