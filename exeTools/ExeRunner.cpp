#include "ExeRunner.h"

#include <memory>
#include "ExeReader.h"
#include <sys/prctl.h>

#include <iostream>

typedef void (*EXE_ENTRY_POINT)();

__thread NT_TIB tib = {};

bool ExeRunner::runExe(int argc, char** argv) {
  if (argc < 1) {
    return false;
  }

  std::unique_ptr<Exe> exe(ExeReader::readExe(argv[0]));

  //FS needs to point to TLS (the TIB)
 	asm("mov %gs, %ax");
 	asm("mov %ax, %fs");

  std::cout << "Running..." << std::endl;
  EXE_ENTRY_POINT entryPoint = exe->getEntryPoint();
  entryPoint();

  std::cout << "IT ACTUALLY RETURNED" << std::endl;
  
  return true;
}
