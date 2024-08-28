#pragma once

#include <pthread.h>

namespace {
  enum ObjectType {
    Mutex
  };

  struct ObjectInfo {
    ObjectType objectType;
  };

  struct MutexInfo : public ObjectInfo {
    const char* name;
    int shm_fd;
    int shm_size;
    pthread_mutex_t* mutex;

    MutexInfo(const char* name, int shm_fd, int shm_size, pthread_mutex_t* mutex) {
      this->objectType = ObjectType::Mutex;

      this->name = name;
      this->shm_fd = shm_fd;
      this->mutex = mutex;
    }
  };
};

