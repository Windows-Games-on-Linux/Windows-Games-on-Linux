#pragma once

#include <windef.h>

typedef DWORD (*LPTHREAD_START_ROUTINE)(LPVOID);
typedef void (*PFIBER_START_ROUTINE)(LPVOID);

typedef PFIBER_START_ROUTINE LPFIBER_START_ROUTINE;
