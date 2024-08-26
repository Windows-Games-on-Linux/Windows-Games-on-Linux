#include "fileapi.h"

#include <sys/stat.h>
#include <cstdio>
#include <sys/stat.h>

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

DWORD WINAPI GetFileAttributesW(LPCWSTR lpFileName) {
  size_t length = 0;
  for (const char16_t* c = lpFileName; *c != 0; c++) {
    length++;
  }

  char* fileName = new char[length + 1];
  char* namePart = fileName;

  for (int i = 0; i < length; i++) {
    fileName[i] = (char)lpFileName[i];

    if (fileName[i] == '\\') {
      fileName[i] = '/';
    }

    if (fileName[i] == '/') {
      namePart = &fileName[i + 1];
    }
  }

  struct stat file_stat = {};
  if (stat(fileName, &file_stat) != 0) {
    delete[] fileName;
    return INVALID_FILE_ATTRIBUTES;
  }

  delete[] fileName;

  DWORD attributes = 0;

  //Let's assume that the file is read-only when write permissions are not enabled for anyone
  if ((file_stat.st_mode & S_IWUSR) == 0 && (file_stat.st_mode & S_IWGRP) == 0 && (file_stat.st_mode & S_IWOTH) == 0) {
    attributes |= FILE_ATTRIBUTE_READONLY;
  }

  //In Linux, the file is considered "hidden" when its name begins with a dot
  if (namePart[0] == '.') {
    attributes |= FILE_ATTRIBUTE_HIDDEN;
  }

  if (S_ISDIR(file_stat.st_mode)) {
    attributes |= FILE_ATTRIBUTE_DIRECTORY;
  }

  //TODO: More attributes

  return attributes;
}

