#include "fibersapi.h"

#include <pthread.h>

DWORD WINAPI FlsAlloc(PFLS_CALLBACK_FUNCTION lpCallback) {
  pthread_key_t key;
  pthread_key_create(&key, lpCallback);

  return key;
}

PVOID WINAPI FlsGetValue(DWORD dwFlsIndex) {
  return pthread_getspecific(dwFlsIndex);
}

