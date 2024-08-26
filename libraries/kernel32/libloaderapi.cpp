#include "libloaderapi.h"

#include <string>
#include <iostream>
#include <dlfcn.h>
#include "processenv.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

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

    if (library.rfind(".dll") == library.length() - 4) {
      libraryPath += library.substr(0, library.length() - 4) + ".so";
    } else {
      libraryPath += library;

      if (library.find('.') == -1) {
        //Currently for simplicity implementations of Windows libraries are loaded from native .so files
        libraryPath += ".so";
      }
    }

    for (auto& c : libraryPath) {
      if (c == '\\') {
        c = '/';
      }
    }

    return libraryPath;
  }
};

HMODULE WINAPI LoadLibraryExW(LPCWSTR lpLibFileName, HANDLE hFile, DWORD dwFlags) {
  //TODO: Take the safe search mode into consideration

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

FARPROC WINAPI GetProcAddress(HMODULE hModule, LPCSTR lpProcName) {
  return (FARPROC)dlsym(hModule, lpProcName);
}

DWORD WINAPI GetModuleFileNameW(HMODULE hModule, LPWSTR lpFilename, DWORD nSize) {
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

HMODULE WINAPI GetModuleHandleW(LPCWSTR lpModuleName) {
  if (lpModuleName == nullptr) {
    //Linux doesn't support executable handles
    //Let's just assume the value 5 to be our executable's handle
    return (HMODULE)5;
  }

  //Otherwise, get a handle to an already loaded shared library
  std::string libFileName = LPCWSTR_to_string(lpModuleName);
  std::string libraryPath = getLibraryPath(libFileName);
  return dlopen(libraryPath.c_str(), RTLD_LAZY | RTLD_NOLOAD);
}

HMODULE WINAPI GetModuleHandleA(LPCSTR lpModuleName) {
  if (lpModuleName == nullptr) {
    //Linux doesn't support executable handles
    //Let's just assume the value 5 to be our executable's handle
    return (HMODULE)5;
  }

  //Otherwise, get a handle to an already loaded shared library
  std::string libraryPath = getLibraryPath(lpModuleName);
  return dlopen(libraryPath.c_str(), RTLD_LAZY | RTLD_NOLOAD);
}

HRSRC WINAPI FindResourceExW(HMODULE hModule, LPCWSTR lpType, LPCWSTR lpName, WORD wLanguage) {
  if (hModule != (HMODULE)5) {
    std::cout << "FindResourceExW: Support for modules other than the current one is not implemented" << std::endl;
    return nullptr;
  }

  if ((uintptr_t)lpType >= 0x10000) {
    std::cout << "FindResourceExW: Support for named types is not implemented" << std::endl;
    return nullptr;
  }

  if ((uintptr_t)lpName >= 0x10000) {
    std::cout << "FindResourceExW: Support for named resources is not implemented" << std::endl;
    return nullptr;
  }

  if ((uintptr_t)wLanguage >= 0x10000) {
    std::cout << "FindResourceExW: Support for named languages is not implemented" << std::endl;
    return nullptr;
  }

  //Currently for simplicity of implementation, the .rsrc section is located using a shared memory object
  //identified by the process ID
  std::string shm_path = "/windows-games-on-linux-";
  shm_path += std::to_string(getpid());
  shm_path += "-resources";

  int shm_fd = shm_open(shm_path.c_str(), O_RDWR, 0600);
  if (shm_fd == -1) {
    return nullptr;
  }

  //This object contains two fields:
  // - imageBase: The image base address; required to locate the actual data of a requested resource since it's pointed to by an RVA
  // - rsrc: The address of the .rsrc section
  size_t shm_size = 2 * sizeof(uintptr_t);
  uintptr_t* shm_data = (uintptr_t*)mmap(nullptr, shm_size, PROT_READ, MAP_SHARED, shm_fd, 0);
  if (!shm_data) {
    close(shm_fd);
    return nullptr;
  }

  uintptr_t imageBase = shm_data[0];
  uintptr_t rsrc = shm_data[1];

  munmap(shm_data, shm_size);
  close(shm_fd);



  //First, we need to scan the root directory for an lpType entry that will point to a directory of resources of the given type
  PIMAGE_RESOURCE_DIRECTORY typeDirectory = (PIMAGE_RESOURCE_DIRECTORY)rsrc;

  PIMAGE_RESOURCE_DIRECTORY_ENTRY typeIdEntries = (PIMAGE_RESOURCE_DIRECTORY_ENTRY)((uint8_t*)typeDirectory + sizeof(IMAGE_RESOURCE_DIRECTORY) + typeDirectory->NumberOfNamedEntries * sizeof(IMAGE_RESOURCE_DIRECTORY_ENTRY));

  PIMAGE_RESOURCE_DIRECTORY resourceDirectory = nullptr;

  for (int i = 0; i < typeDirectory->NumberOfIdEntries; i++) {
    auto& entry = typeIdEntries[i];
    if (entry.DUMMYUNIONNAME.Id == (WORD)((uintptr_t)lpType)) {
      resourceDirectory = (PIMAGE_RESOURCE_DIRECTORY)(rsrc + (entry.DUMMYUNIONNAME2.OffsetToData & 0x7FFFFFFF));
      break;
    }
  }

  if (!resourceDirectory) {
    return nullptr;
  }



  //Now, we can the found subdirectory for an lpName entry that will point to a directory of languages for the given resource
  PIMAGE_RESOURCE_DIRECTORY_ENTRY resourceIdEntries = (PIMAGE_RESOURCE_DIRECTORY_ENTRY)((uint8_t*)resourceDirectory + sizeof(IMAGE_RESOURCE_DIRECTORY) + resourceDirectory->NumberOfNamedEntries * sizeof(IMAGE_RESOURCE_DIRECTORY_ENTRY));

  PIMAGE_RESOURCE_DIRECTORY languageDirectory = nullptr;

  for (int i = 0; i < resourceDirectory->NumberOfIdEntries; i++) {
    auto& entry = resourceIdEntries[i];
    if (entry.DUMMYUNIONNAME.Id == (WORD)((uintptr_t)lpName)) {
      languageDirectory = (PIMAGE_RESOURCE_DIRECTORY)(rsrc + (entry.DUMMYUNIONNAME2.OffsetToData & 0x7FFFFFFF));
      break;
    }
  }

  if (!languageDirectory) {
    return nullptr;
  }



  //And now, finally we scan the found resource's language subdirectory to find the actual resource requested
  PIMAGE_RESOURCE_DIRECTORY_ENTRY languageIdEntries = (PIMAGE_RESOURCE_DIRECTORY_ENTRY)((uint8_t*)languageDirectory + sizeof(IMAGE_RESOURCE_DIRECTORY) + languageDirectory->NumberOfNamedEntries * sizeof(IMAGE_RESOURCE_DIRECTORY_ENTRY));

  for (int i = 0; i < languageDirectory->NumberOfIdEntries; i++) {
    if (languageIdEntries[i].DUMMYUNIONNAME.Id == (WORD)((uintptr_t)wLanguage)) {
      return &languageIdEntries[i];
    }
  }

  return nullptr;
}

