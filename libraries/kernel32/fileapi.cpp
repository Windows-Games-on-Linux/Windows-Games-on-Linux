#include "fileapi.h"

#include <sys/stat.h>
#include <cstdio>

DWORD WINAPI GetFileType(HANDLE hFile) {
  int fd = -1;

  //For now, only the standard handles are supported

  //STD_INPUT_HANDLE
  if (hFile == (HANDLE)2) {
    fd = fileno(stdin);
  }

  //STD_OUTPUT_HANDLE
  if (hFile == (HANDLE)3) {
    fd = fileno(stdout);
  }

  //STD_ERROR_HANDLE
  if (hFile == (HANDLE)4) {
    fd = fileno(stderr);
  }

  if (fd == -1) {
    return FILE_TYPE_UNKNOWN;
  }

  struct stat fileInfo;
  fstat(fd, &fileInfo);

  if (S_ISCHR(fileInfo.st_mode)) {
    return FILE_TYPE_CHAR;
  }

  if (S_ISREG(fileInfo.st_mode)) {
    return FILE_TYPE_DISK;
  }

  if (S_ISFIFO(fileInfo.st_mode)) {
    return FILE_TYPE_PIPE;
  }

  //TODO: Implement support for FILE_TYPE_REMOTE

  return FILE_TYPE_UNKNOWN;
}

BOOL WINAPI AreFileApisANSI() {
  return 0;
}

