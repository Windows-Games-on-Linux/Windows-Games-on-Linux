#include "handleapi.h"

#include <iostream>
#include <unistd.h>
#include "objects.h"
#include <cstring>
#include <sys/mman.h>

BOOL WINAPI CloseHandle(HANDLE hObject) {
  ObjectInfo* objectInfo = (ObjectInfo*)hObject;

  if (objectInfo->objectType == ObjectType::Mutex) {
    MutexInfo* mutexInfo = (MutexInfo*)objectInfo;

    if (mutexInfo->name) {
      munmap(mutexInfo->mutex, sizeof(pthread_mutex_t));
      close(mutexInfo->shm_fd);

      std::string shm_path;

      if (memcmp(mutexInfo->name, "Global\\", 7) == 0) {
        shm_path = "/mutex-global-";
        shm_path += &mutexInfo->name[7];
      } else if (memcmp(mutexInfo->name, "Local\\", 6) == 0) {
        shm_path = "/mutex-local-";
        shm_path += &mutexInfo->name[6];
      } else {
        shm_path = mutexInfo->name;
      }

      if (shm_unlink(shm_path.c_str()) != 0) {
        return 0;
      }
    } else {
      delete (pthread_mutex_t*)mutexInfo->mutex;
    }

    return 1;
  } else {
    std::cout << "CloseHandle: Closing handles to objects other than mutexes is not implemented" << std::endl;
    return 0;
  }

  return 0;
}

