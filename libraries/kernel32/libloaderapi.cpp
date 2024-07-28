#include "libloaderapi.h"

#include <string>
#include <iostream>
#include <dlfcn.h>
#include "processenv.h"

#define DONT_RESOLVE_DLL_REFERENCES         0x00000001
#define LOAD_IGNORE_CODE_AUTHZ_LEVEL        0x00000010
#define LOAD_LIBRARY_AS_DATAFILE            0x00000002
#define LOAD_LIBRARY_AS_DATAFILE_EXCLUSIVE  0x00000040
#define LOAD_LIBRARY_AS_IMAGE_RESOURCE      0x00000020
#define LOAD_LIBRARY_SEARCH_APPLICATION_DIR 0x00000200
#define LOAD_LIBRARY_SEARCH_DEFAULT_DIRS    0x00001000
#define LOAD_LIBRARY_SEARCH_DLL_LOAD_DIR    0x00000100
#define LOAD_LIBRARY_SEARCH_SYSTEM32        0x00000800
#define LOAD_LIBRARY_SEARCH_USER_DIRS       0x00000400
#define LOAD_WITH_ALTERED_SEARCH_PATH       0x00000008
#define LOAD_LIBRARY_REQUIRE_SIGNED_TARGET  0x00000080
#define LOAD_LIBRARY_SAFE_CURRENT_DIRS      0x00002000

namespace {
  //Basic LPCWSTR to string conversion required by some functions
  std::string LPCWSTR_to_string(LPCWSTR lpcwstr) {
    size_t size = 0;

    char* sc = (char*)lpcwstr;
    while (*sc != '\0') {
      size++;
      sc += 2;
    }

    std::string _string(size, '\0');

    sc = (char*)lpcwstr;
    char* dc = (char*)_string.data();
    while (true) {
      *dc = *sc;

      if (*sc == '\0') {
        break;
      }

      sc += 2;
      dc++;
    }

    return _string;
  }

  //Convert Windows library path to Linux library path
  std::string getLibraryPath(std::string library) {
    std::string libraryPath;

    if (library.find('\\') == -1) {
    //For now let's just load the libraries from the working path
      libraryPath += "./";
    }

    libraryPath += library;

    if (library.find('.') == -1) {
      //Currently for simplicity implementations of Windows libraries are loaded from native .so files
      libraryPath += ".so";
    }

    for (auto& c : libraryPath) {
      if (c == '\\') {
        c = '/';
      }
    }

    return libraryPath;
  }
};

HMODULE __attribute__((stdcall)) LoadLibraryExW(LPCWSTR lpLibFileName, HANDLE hFile, DWORD dwFlags) {
  //TODO: Implement the LOAD_LIBRARY_SEARCH_SYSTEM32 flag
  //We need a directory that will emulate the system32 directory
  //For now let's just load the libraries from the working path

  if (dwFlags & DONT_RESOLVE_DLL_REFERENCES) {
    std::cout << "LoadLibraryExW: Unimplemented Flag: DONT_RESOLVE_DLL_REFERENCES" << std::endl;
  }

  if (dwFlags & LOAD_IGNORE_CODE_AUTHZ_LEVEL) {
    std::cout << "LoadLibraryExW: Unimplemented Flag: LOAD_IGNORE_CODE_AUTHZ_LEVEL" << std::endl;
  }

  if (dwFlags & LOAD_LIBRARY_AS_DATAFILE) {
    std::cout << "LoadLibraryExW: Unimplemented Flag: LOAD_LIBRARY_AS_DATAFILE" << std::endl;
  }

  if (dwFlags & LOAD_LIBRARY_AS_DATAFILE_EXCLUSIVE) {
    std::cout << "LoadLibraryExW: Unimplemented Flag: LOAD_LIBRARY_AS_DATAFILE_EXCLUSIVE" << std::endl;
  }

  if (dwFlags & LOAD_LIBRARY_AS_IMAGE_RESOURCE) {
    std::cout << "LoadLibraryExW: Unimplemented Flag: LOAD_LIBRARY_AS_IMAGE_RESOURCE" << std::endl;
  }

  if (dwFlags & LOAD_LIBRARY_SEARCH_APPLICATION_DIR) {
    std::cout << "LoadLibraryExW: Unimplemented Flag: LOAD_LIBRARY_SEARCH_APPLICATION_DIR" << std::endl;
  }

  if (dwFlags & LOAD_LIBRARY_SEARCH_DEFAULT_DIRS) {
    std::cout << "LoadLibraryExW: Unimplemented Flag: LOAD_LIBRARY_SEARCH_DEFAULT_DIRS" << std::endl;
  }

  if (dwFlags & LOAD_LIBRARY_SEARCH_DLL_LOAD_DIR) {
    std::cout << "LoadLibraryExW: Unimplemented Flag: LOAD_LIBRARY_SEARCH_DLL_LOAD_DIR" << std::endl;
  }

  if (dwFlags & LOAD_LIBRARY_SEARCH_USER_DIRS) {
    std::cout << "LoadLibraryExW: Unimplemented Flag: LOAD_LIBRARY_SEARCH_USER_DIRS" << std::endl;
  }

  if (dwFlags & LOAD_WITH_ALTERED_SEARCH_PATH) {
    std::cout << "LoadLibraryExW: Unimplemented Flag: LOAD_WITH_ALTERED_SEARCH_PATH" << std::endl;
  }

  if (dwFlags & LOAD_LIBRARY_REQUIRE_SIGNED_TARGET) {
    std::cout << "LoadLibraryExW: Unimplemented Flag: LOAD_LIBRARY_REQUIRE_SIGNED_TARGET" << std::endl;
  }

  if (dwFlags & LOAD_LIBRARY_SAFE_CURRENT_DIRS) {
    std::cout << "LoadLibraryExW: Unimplemented Flag: LOAD_LIBRARY_SAFE_CURRENT_DIRS" << std::endl;
  }

  //TODO: Implement loading Windows DLL files
  //Currently for simplicity this function loads implementations of Windows libraries from native .so files

  std::string libFileName = LPCWSTR_to_string(lpLibFileName);
  std::string libraryPath = getLibraryPath(libFileName);
  return dlopen(libraryPath.c_str(), RTLD_LAZY);
}

FARPROC __attribute__((stdcall)) GetProcAddress(HMODULE hModule, LPCSTR lpProcName) {
  return (FARPROC)dlsym(hModule, lpProcName);
}

DWORD __attribute__((stdcall)) GetModuleFileNameW(HMODULE hModule, LPWSTR lpFilename, DWORD nSize) {
  if (hModule) {
    std::cout << "GetModuleFileNameW: Modules other than the current process are not supported yet" << std::endl;
    return 0;
  }

  if (nSize == 0) {
    return 0;
  }

  LPWSTR commandLine = GetCommandLineW();

  //The first element in the command line is our executable's path and is terminated with a quote character
  //First, calculate the length of this path
  unsigned int size = 0;
  {
    const char16_t* c = &commandLine[1]; //Skip the beginning quote character
    while (true) {
      size++;
      if (size == nSize) {
        break;
      }

      if (*c == 0 || *c == u'"') {
        break;
      }

      c++;
    }
  }

  //Now, copy the path
  const char16_t* c = &commandLine[1];
  unsigned int i = 0;
  while (true) {
    if (i < size - 1) {
      lpFilename[i++] = *c;
    } else {
      lpFilename[i++] = 0;
    }

    if (i == size) {
      break;
    }

    if (*c == 0 || *c == u'"') {
      break;
    }

    c++;
  }

  //Return the length of the copied string (not including the NULL character)
  return size - 1;
}

