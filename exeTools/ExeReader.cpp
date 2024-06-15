#include "ExeReader.h"

#include <fstream>
#include <iostream>
#include <memory>
#include <vector>
#include <dlfcn.h>

#define MAJOR_OPERATING_SYSTEM_VERSION 10
#define MINOR_OPERATING_SYSTEM_VERSION  0

//TODO: Move this to some utils
struct OSVersion {
  uint16_t major;
  uint16_t minor;

  OSVersion(uint16_t major, uint16_t minor) {
    this->major = major;
    this->minor = minor;
  }

  bool meetsRequirements(OSVersion& otherVersion) {
    if (this->major > otherVersion.major) {
      return false;
    } else if (this->major == otherVersion.major && this->minor > otherVersion.minor) {
      return false;
    }

    return true;
  }
};

namespace {
  bool tryRead(std::ifstream& exeFile, void* destination, size_t position, size_t size) {
    exeFile.seekg(0, std::ios::end);
    size_t exeSize = exeFile.tellg();
    if (exeSize < position + size) {
      std::cout << "exeSize: " << exeSize << std::endl;
      std::cout << "position + size: " << position + size << std::endl;

      return false;
    }

    exeFile.seekg(position, std::ios::beg);
    exeFile.read((char*)destination, size);
    return true;
  }

  std::string getLibraryName(const char* dllName) {
    std::string _dllName = std::string("./") + std::string(dllName);
    for (auto& c : _dllName) {
      c = std::tolower(c);
    }

    int extension = _dllName.find(".dll");
    _dllName.replace(extension, 4, ".so");

    return _dllName;
  }
};

void unimplementedCall() {
  std::cout << "TODO: Unimplemented call" << std::endl;
}

Exe* ExeReader::readExe(const char* path) {
  std::ifstream exeFile(path, std::ios::binary);
  if (!exeFile.is_open()) {
    return nullptr;
  }

  IMAGE_DOS_HEADER msDosStub = {};
  if (tryRead(exeFile, &msDosStub, 0, sizeof(msDosStub))) {
    if (!msDosStub.isValid()) {
      return nullptr;
    }
  } else {
    return nullptr;
  }

  IMAGE_NT_HEADERS peHeaders;
  if (tryRead(exeFile, &peHeaders, msDosStub.e_lfanew, sizeof(peHeaders))) {
    if (!peHeaders.isValid()) {
      return nullptr;
    }
  } else {
    return nullptr;
  }

  std::vector<IMAGE_DATA_DIRECTORY> DataDirectory(peHeaders.OptionalHeader.NumberOfRvaAndSizes);
  if (!tryRead(exeFile, DataDirectory.data(), msDosStub.e_lfanew + sizeof(peHeaders), peHeaders.OptionalHeader.NumberOfRvaAndSizes * sizeof(IMAGE_DATA_DIRECTORY))) {
    std::cerr << "Failed to read data directories :(" << std::endl;
    return nullptr;
  }

  std::cout << "Hi: " << sizeof(peHeaders) << std::endl;
  std::cout << "Test:" << std::hex << msDosStub.e_lfanew + sizeof(peHeaders) << std::endl;

  std::cout << "MS-DOS stub and PE signature correct :)" << std::endl;

  //TODO: Add support for Intel Itanium and x64
  if (peHeaders.FileHeader.Machine != IMAGE_FILE_MACHINE_I386) {
    std::cerr << "Unsupported machine type" << std::endl;
    return nullptr;
  }

  std::cout << "NumberOfSections: " << peHeaders.FileHeader.NumberOfSections << std::endl;

  std::cout << "Machine type correct :)" << std::endl;

  auto& characteristics = peHeaders.FileHeader.Characteristics;

  if (!(characteristics & IMAGE_FILE_EXECUTABLE_IMAGE)) {
    std::cerr << "Not executable :(" << std::endl;
    return nullptr;
  }

  if (characteristics & IMAGE_FILE_LARGE_ADDRESS_AWARE) {
    //TODO: What exactly should this do?
  }

  if (!(characteristics & IMAGE_FILE_32BIT_MACHINE)) {
    std::cerr << "Not 32-bit :(" << std::endl;
    return nullptr;
  }

  std::cout << peHeaders.FileHeader.SizeOfOptionalHeader << std::endl;
  std::cout << sizeof(IMAGE_OPTIONAL_HEADER) << std::endl;

  if (peHeaders.FileHeader.SizeOfOptionalHeader >= sizeof(IMAGE_OPTIONAL_HEADER)) {
    std::cout << "Valid optional header :)" << std::endl;
  } else {
    std::cout << "Invalid optional header :(" << std::endl;
    return nullptr;
  }

  OSVersion requiredVersion(peHeaders.OptionalHeader.MajorOperatingSystemVersion, peHeaders.OptionalHeader.MinorOperatingSystemVersion);
  OSVersion currentVersion(MAJOR_OPERATING_SYSTEM_VERSION, MINOR_OPERATING_SYSTEM_VERSION);

  if (!requiredVersion.meetsRequirements(currentVersion)) {
    std::cerr << "OS too old :(" << std::endl;
    return nullptr;
  }

  std::vector<IMAGE_SECTION_HEADER> sectionHeaders(peHeaders.FileHeader.NumberOfSections);
  if (!tryRead(exeFile, sectionHeaders.data(), msDosStub.e_lfanew + sizeof(peHeaders) + peHeaders.OptionalHeader.NumberOfRvaAndSizes * sizeof(IMAGE_DATA_DIRECTORY), peHeaders.FileHeader.NumberOfSections * sizeof(IMAGE_SECTION_HEADER))) {
    std::cerr << "Failed to read section headers :(" << std::endl;
    return nullptr;
  }

  std::unique_ptr<Exe> exe(new Exe(peHeaders.OptionalHeader.ImageBase, peHeaders.OptionalHeader.SizeOfImage));
  exe->addressOfEntryPoint = peHeaders.OptionalHeader.AddressOfEntryPoint;

  IMAGE_IMPORT_DESCRIPTOR* imports = nullptr;

  if (peHeaders.OptionalHeader.NumberOfRvaAndSizes > IMAGE_DIRECTORY_ENTRY_IMPORT) {
    auto& importDirectory = DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];
    imports = (IMAGE_IMPORT_DESCRIPTOR*)(peHeaders.OptionalHeader.ImageBase + importDirectory.VirtualAddress);
  }

  std::cout << "Number: " << peHeaders.OptionalHeader.NumberOfRvaAndSizes << std::endl;

  std::vector<Exe::Section*> sectionsToProtect(peHeaders.FileHeader.NumberOfSections);


  for (int i = 0; i < peHeaders.FileHeader.NumberOfSections; i++) {
    auto& sectionHeader = sectionHeaders[i];

    std::cout << "Section: " << std::hex << sectionHeader.VirtualAddress << " - " << (sectionHeader.VirtualAddress + sectionHeader.Misc.VirtualSize) << std::endl;
    auto& section = exe->createSection(sectionHeader.VirtualAddress, sectionHeader.Misc.VirtualSize);
    sectionsToProtect[i] = &section;
    
    std::cout << "Section: " << sectionHeader.Name << std::endl;

    uint32_t protectionFlags = 0;

    auto& sc = sectionHeader.Characteristics;

    if (sc & IMAGE_SCN_MEM_EXECUTE) {
      protectionFlags |= IMAGE_SCN_MEM_EXECUTE;
    }

    if (sc & IMAGE_SCN_MEM_READ) {
      protectionFlags |= IMAGE_SCN_MEM_READ;
    }

    if (sc & IMAGE_SCN_MEM_WRITE) {
      protectionFlags |= IMAGE_SCN_MEM_WRITE;
    }

    //section.protect(protectionFlags);

    void* sectionData = section.getRawPointer();
    uint32_t* t = (uint32_t*)sectionData;
    std::cout << t[0] << std::endl;

    std::cout << "SizeOfRawData: " << sectionHeader.SizeOfRawData << std::endl;
    if (!tryRead(exeFile, sectionData, sectionHeader.PointerToRawData, sectionHeader.SizeOfRawData)) {
      std::cout << "Failed to read section data :(" << std::endl;
      return nullptr;
    } else {
      std::cout << "Read: " << std::hex << (uint32_t)(peHeaders.OptionalHeader.ImageBase + sectionHeader.VirtualAddress) << " - " << (uint32_t)(peHeaders.OptionalHeader.ImageBase + sectionHeader.VirtualAddress + sectionHeader.SizeOfRawData) << std::endl;
      std::cout << "Imports: " << (uint32_t)imports << std::endl;
    }



    /*if (sc & IMAGE_SCN_MEM_DISCARDABLE) {
      //TODO: Possibly remove it from the sections vector in the Exe object?
      //For now just call discard
      section.discard();
    }*/
  }

  for (auto currentImport = imports; currentImport->Name != 0; currentImport++) {
    IMAGE_THUNK_DATA* thunks = (IMAGE_THUNK_DATA*)(peHeaders.OptionalHeader.ImageBase + currentImport->DUMMYUNIONNAME.OriginalFirstThunk);
    const char* dllName = (const char*)(peHeaders.OptionalHeader.ImageBase + currentImport->Name);

    uint32_t* addresses = (uint32_t*)(peHeaders.OptionalHeader.ImageBase + currentImport->FirstThunk);
    std::cout << "Import address table: " << std::hex << (uint32_t)addresses << std::endl;

    std::string libraryName = getLibraryName(dllName);

    void* library = dlopen(libraryName.c_str(), RTLD_LAZY);
    if (library) {
      std::cout << std::endl;
      std::cout << "Successfully loaded: " << libraryName << std::endl;

      for (auto currentThunk = thunks; currentThunk->u1.Function != 0; currentThunk++) {
        if (!(currentThunk->u1.Function & 0x80000000)) {
          IMAGE_IMPORT_BY_NAME* importByName = (IMAGE_IMPORT_BY_NAME*)(peHeaders.OptionalHeader.ImageBase + currentThunk->u1.Function);
          //std::cout << "Import by name: " << importByName->Name << std::endl;

          if ((uint32_t)addresses == 0x73D28C) {
            std::cout << "WE'RE IMPORTING TO THIS ADDRESS THAT I WANT" << std::endl;
          }

          void* function = dlsym(library, importByName->Name);
          if (function) {
            *addresses = (uint32_t)function;
            std::cout << "Function: " << importByName->Name << std::endl;
          } else {
            *addresses = (uint32_t)unimplementedCall;
            std::cout << "Failed to import function: " << importByName->Name << std::endl;
          }
        } else {
          *addresses = (uint32_t)unimplementedCall;
          std::cout << "Another kind of import" << std::endl;
        }

        addresses++;
      }

      std::cout << std::endl << std::endl;
    } else {
      std::cout << "Failed to load library: " << libraryName << std::endl;

      //This is just to propagate the address table
      for (auto currentThunk = thunks; currentThunk->u1.Function != 0; currentThunk++) {
        if (!(currentThunk->u1.Function & 0x80000000)) {
          IMAGE_IMPORT_BY_NAME* importByName = (IMAGE_IMPORT_BY_NAME*)(peHeaders.OptionalHeader.ImageBase + currentThunk->u1.Function);
          std::cout << "Import by name (no library): " << importByName->Name << std::endl;

          if ((uint32_t)addresses == 0x73D28C) {
            std::cout << "WE'RE IMPORTING TO THIS ADDRESS THAT I WANT" << std::endl;
          }

          //void* function = dlsym(library, importByName->Name);
          //if (function) {
          //  *addresses = (uint32_t)function;
          //  std::cout << "Function: " << importByName->Name << std::endl;
          //} else {
            *addresses = (uint32_t)unimplementedCall;
          //  std::cout << "Failed to import function: " << importByName->Name << std::endl;

          //  void (*test)() = (void (*)())(*addresses);
          //  test();
          //}
        } else {
          *addresses = (uint32_t)unimplementedCall;
          std::cout << "Another kind of import" << std::endl;
        }

        addresses++;
      }
    }

    //TODO: Import the
  }

  //*((uint8_t*)0x6E922C) = 0xCC;
  //*((uint32_t*)(peHeaders.OptionalHeader.ImageBase + peHeaders.OptionalHeader.AddressOfEntryPoint + 1)) = (uint32_t)(unimplementedCall - (peHeaders.OptionalHeader.ImageBase + peHeaders.OptionalHeader.AddressOfEntryPoint + 5));
  
  //TODO: Test
  for (int i = 0; i < peHeaders.FileHeader.NumberOfSections; i++) {
    auto& sectionHeader = sectionHeaders[i];

    //std::cout << "Section: " << std::hex << sectionHeader.VirtualAddress << " - " << (sectionHeader.VirtualAddress + sectionHeader.Misc.VirtualSize) << std::endl;
    auto& section = sectionsToProtect[i];
    //auto& section = exe->createSection(sectionHeader.VirtualAddress, sectionHeader.Misc.VirtualSize);
    //sectionsToProtect[i] = &section;

    uint32_t protectionFlags = 0;

    auto& sc = sectionHeader.Characteristics;

    if (sc & IMAGE_SCN_MEM_EXECUTE) {
      protectionFlags |= IMAGE_SCN_MEM_EXECUTE;
    }

    if (sc & IMAGE_SCN_MEM_READ) {
      protectionFlags |= IMAGE_SCN_MEM_READ;
    }

    if (sc & IMAGE_SCN_MEM_WRITE) {
      protectionFlags |= IMAGE_SCN_MEM_WRITE;
    }

    section->protect(protectionFlags);

    /*void* sectionData = section.getRawPointer();
    uint32_t* t = (uint32_t*)sectionData;
    std::cout << t[0] << std::endl;

    std::cout << "SizeOfRawData: " << sectionHeader.SizeOfRawData << std::endl;
    if (!tryRead(exeFile, sectionData, sectionHeader.PointerToRawData, sectionHeader.SizeOfRawData)) {
      std::cout << "Failed to read section data :(" << std::endl;
      return nullptr;
    } else {
      std::cout << "Read: " << std::hex << (uint32_t)(peHeaders.OptionalHeader.ImageBase + sectionHeader.VirtualAddress) << " - " << (uint32_t)(peHeaders.OptionalHeader.ImageBase + sectionHeader.VirtualAddress + sectionHeader.SizeOfRawData) << std::endl;
      std::cout << "Imports: " << (uint32_t)imports << std::endl;
    }*/



    /*if (sc & IMAGE_SCN_MEM_DISCARDABLE) {
      //TODO: Possibly remove it from the sections vector in the Exe object?
      //For now just call discard
      section.discard();
    }*/
  }

  std::cout << "ImageBase: " << std::hex << peHeaders.OptionalHeader.ImageBase << std::endl;
  std::cout << "AddressOfEntryPoint: " << std::hex << peHeaders.OptionalHeader.AddressOfEntryPoint << std::endl;

  return exe.release();
}
