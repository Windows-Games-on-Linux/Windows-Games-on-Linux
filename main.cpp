#include <iostream>

const char* getFilenameFromPath(const char* path) {
  size_t filenameIndex = 0;

  size_t currentIndex = 0;
  for (; path[currentIndex] != '\0'; currentIndex++) {
    if (path[currentIndex] == '/') {
      filenameIndex = currentIndex + 1;
    }
  }

  return &path[filenameIndex];
}

int main(int argc, char** argv) {
  if (argc < 2) {
    const char* filename = getFilenameFromPath(argv[0]);
    std::cerr << "Usage: " << filename << " <exe_path> <arguments>" << std::endl;
    return 1;
  }

  //TODO: Run the EXE
  return 0;
}
