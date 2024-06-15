#pragma once

#include <cstdint>
#include <sys/mman.h>

#define IMAGE_FILE_MACHINE_I386  0x014C
#define IMAGE_FILE_MACHINE_IA64  0x0200
#define IMAGE_FILE_MACHINE_AMD64 0x8664

#define IMAGE_FILE_RELOCS_STRIPPED         0x0001
#define IMAGE_FILE_EXECUTABLE_IMAGE        0x0002
#define IMAGE_FILE_LINE_NUMS_STRIPPED      0x0004
#define IMAGE_FILE_LOCAL_SYMS_STRIPPED     0x0008
#define IMAGE_FILE_AGGRESIVE_WS_TRIM       0x0010
#define IMAGE_FILE_LARGE_ADDRESS_AWARE     0x0020
#define IMAGE_FILE_BYTES_REVERSED_LO       0x0080
#define IMAGE_FILE_32BIT_MACHINE           0x0100
#define IMAGE_FILE_DEBUG_STRIPPED          0x0200
#define IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP 0x0400
#define IMAGE_FILE_NET_RUN_FROM_SWAP       0x0800
#define IMAGE_FILE_SYSTEM                  0x1000
#define IMAGE_FILE_DLL                     0x2000
#define IMAGE_FILE_UP_SYSTEM_ONLY          0x4000
#define IMAGE_FILE_BYTES_REVERSED_HI       0x8000

#define IMAGE_NT_OPTIONAL_HDR_MAGIC  0x10B
#define IMAGE_ROM_OPTIONAL_HDR_MAGIC 0x107

#define IMAGE_SUBSYSTEM_UNKNOWN                   0
#define IMAGE_SUBSYSTEM_NATIVE                    1
#define IMAGE_SUBSYSTEM_WINDOWS_GUI               2
#define IMAGE_SUBSYSTEM_WINDOWS_CUI               3
#define IMAGE_SUBSYSTEM_OS2_CUI                   5
#define IMAGE_SUBSYSTEM_POSIX_CUI                 7
#define IMAGE_SUBSYSTEM_WINDOWS_CE_GUI            9
#define IMAGE_SUBSYSTEM_EFI_APPLICATION          10
#define IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER  11
#define IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER       12
#define IMAGE_SUBSYSTEM_EFI_ROM                  13
#define IMAGE_SUBSYSTEM_XBOX                     14
#define IMAGE_SUBSYSTEM_WINDOWS_BOOT_APPLICATION 16

#define IMAGE_DLLCHARACTERISTICS_HIGH_ENTROPY_VA       0x0020
#define IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE          0x0040
#define IMAGE_DLLCHARACTERISTICS_FORCE_INTEGRITY       0x0080
#define IMAGE_DLLCHARACTERISTICS_NX_COMPAT             0x0100
#define IMAGE_DLLCHARACTERISTICS_NO_ISOLATION          0x0200
#define IMAGE_DLLCHARACTERISTICS_NO_SEH                0x0400
#define IMAGE_DLLCHARACTERISTICS_NO_BIND               0x0800
#define IMAGE_DLLCHARACTERISTICS_APPCONTAINER          0x1000
#define IMAGE_DLLCHARACTERISTICS_WDM_DRIVER            0x2000
#define IMAGE_DLLCHARACTERISTICS_GUARD_CF              0x4000
#define IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE 0x8000

#define IMAGE_DIRECTORY_ENTRY_ARCHITECTURE    7
#define IMAGE_DIRECTORY_ENTRY_BASERELOC       5
#define IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT   11
#define IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR 14
#define IMAGE_DIRECTORY_ENTRY_DEBUG           6
#define IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT   13
#define IMAGE_DIRECTORY_ENTRY_EXCEPTION       3
#define IMAGE_DIRECTORY_ENTRY_EXPORT          0
#define IMAGE_DIRECTORY_ENTRY_GLOBALPTR       8
#define IMAGE_DIRECTORY_ENTRY_IAT            12
#define IMAGE_DIRECTORY_ENTRY_IMPORT          1
#define IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG    10
#define IMAGE_DIRECTORY_ENTRY_RESOURCE        2
#define IMAGE_DIRECTORY_ENTRY_SECURITY        4
#define IMAGE_DIRECTORY_ENTRY_TLS             9

#define IMAGE_SCN_TYPE_NO_PAD            0x00000008
#define IMAGE_SCN_CNT_CODE               0x00000020
#define IMAGE_SCN_CNT_INITIALIZED_DATA   0x00000040
#define IMAGE_SCN_CNT_UNINITIALIZED_DATA 0x00000080
#define IMAGE_SCN_LNK_OTHER              0x00000100
#define IMAGE_SCN_LNK_INFO               0x00000200
#define IMAGE_SCN_LNK_REMOVE             0x00000800
#define IMAGE_SCN_LNK_COMDAT             0x00001000
#define IMAGE_SCN_NO_DEFER_SPEC_EXC      0x00004000
#define IMAGE_SCN_GPREL                  0x00008000
#define IMAGE_SCN_MEM_PURGEABLE          0x00020000
#define IMAGE_SCN_MEM_LOCKED             0x00040000
#define IMAGE_SCN_MEM_PRELOAD            0x00080000
#define IMAGE_SCN_ALIGN_1BYTES           0x00100000
#define IMAGE_SCN_ALIGN_2BYTES           0x00200000
#define IMAGE_SCN_ALIGN_4BYTES           0x00300000
#define IMAGE_SCN_ALIGN_8BYTES           0x00400000
#define IMAGE_SCN_ALIGN_16BYTES          0x00500000
#define IMAGE_SCN_ALIGN_32BYTES          0x00600000
#define IMAGE_SCN_ALIGN_64BYTES          0x00700000
#define IMAGE_SCN_ALIGN_128BYTES         0x00800000
#define IMAGE_SCN_ALIGN_256BYTES         0x00900000
#define IMAGE_SCN_ALIGN_512BYTES         0x00A00000
#define IMAGE_SCN_ALIGN_1024BYTES        0x00B00000
#define IMAGE_SCN_ALIGN_2048BYTES        0x00C00000
#define IMAGE_SCN_ALIGN_4096BYTES        0x00D00000
#define IMAGE_SCN_ALIGN_8192BYTES        0x00E00000
#define IMAGE_SCN_LNK_NRELOC_OVFL        0x01000000
#define IMAGE_SCN_MEM_DISCARDABLE        0x02000000
#define IMAGE_SCN_MEM_NOT_CACHED         0x04000000
#define IMAGE_SCN_MEM_NOT_PAGED          0x08000000
#define IMAGE_SCN_MEM_SHARED             0x10000000
#define IMAGE_SCN_MEM_EXECUTE            0x20000000
#define IMAGE_SCN_MEM_READ               0x40000000
#define IMAGE_SCN_MEM_WRITE              0x80000000

#pragma pack(push, 1)
struct IMAGE_DOS_HEADER {
  uint16_t e_magic;
  uint16_t e_cblp;
  uint16_t e_cp;
  uint16_t e_crlc;
  uint16_t e_cparhdr;
  uint16_t e_minalloc;
  uint16_t e_maxalloc;
  uint16_t e_ss;
  uint16_t e_sp;
  uint16_t e_csum;
  uint16_t e_ip;
  uint16_t e_cs;
  uint16_t e_lfarlc;
  uint16_t e_ovno;
  uint16_t e_res[4];
  uint16_t e_oemid;
  uint16_t e_oeminfo;
  uint16_t e_res2[10];
  uint32_t e_lfanew;

  bool isValid() {
    return this->e_magic == 0x5A4D; //"MZ"
  }
};

struct IMAGE_FILE_HEADER {
  uint16_t Machine;
  uint16_t NumberOfSections;
  uint32_t TimeDateStamp;
  uint32_t PointerToSymbolTable;
  uint32_t NumberOfSymbols;
  uint16_t SizeOfOptionalHeader;
  uint16_t Characteristics;
};

struct IMAGE_DATA_DIRECTORY {
  uint32_t VirtualAddress;
  uint32_t Size;
};

struct IMAGE_OPTIONAL_HEADER {
  uint16_t Magic;
  uint8_t MajorLinkerVersion;
  uint8_t MinorLinkerVersion;
  uint32_t SizeOfCode;
  uint32_t SizeOfInitializedData;
  uint32_t SizeOfUninitializedData;
  uint32_t AddressOfEntryPoint;
  uint32_t BaseOfCode;
  uint32_t BaseOfData;
  uint32_t ImageBase;
  uint32_t SectionAlignment;
  uint32_t FileAlignment;
  uint16_t MajorOperatingSystemVersion;
  uint16_t MinorOperatingSystemVersion;
  uint16_t MajorImageVersion;
  uint16_t MinorImageVersion;
  uint16_t MajorSubsystemVersion;
  uint16_t MinorSubsystemVersion;
  uint32_t Win32VersionValue;
  uint32_t SizeOfImage;
  uint32_t SizeOfHeaders;
  uint32_t CheckSum;
  uint16_t Subsystem;
  uint16_t DllCharacteristics;
  uint32_t SizeOfStackReserve;
  uint32_t SizeOfStackCommit;
  uint32_t SizeOfHeapReserve;
  uint32_t SizeOfHeapCommit;
  uint32_t LoaderFlags;
  uint32_t NumberOfRvaAndSizes;
  IMAGE_DATA_DIRECTORY DataDirectory[];

  bool isValid() {
    return this->Magic == IMAGE_NT_OPTIONAL_HDR_MAGIC;
  }
};

struct IMAGE_NT_HEADERS {
  uint32_t Signature;
  IMAGE_FILE_HEADER FileHeader;
  IMAGE_OPTIONAL_HEADER OptionalHeader;

  bool isValid() {
    return this->Signature == 0x00004550; //"PE\0\0"
  }
};

struct IMAGE_SECTION_HEADER {
  char Name[8];
  union {
    uint32_t PhysicalAddress;
    uint32_t VirtualSize;
  } Misc;
  uint32_t VirtualAddress;
  uint32_t SizeOfRawData;
  uint32_t PointerToRawData;
  uint32_t PointerToRelocations;
  uint32_t PointerToLinenumbers;
  uint16_t NumberOfRelocations;
  uint16_t NumberOfLinenumbers;
  uint32_t Characteristics;
};

struct IMAGE_IMPORT_DESCRIPTOR {
  union {
    uint32_t Characteristics;
    uint32_t OriginalFirstThunk;
  } DUMMYUNIONNAME;
  uint32_t TimeDateStamp;
  uint32_t ForwarderChain;
  uint32_t Name;
  uint32_t FirstThunk;
};

struct IMAGE_THUNK_DATA {
  union {
    uint32_t Function;
    uint32_t Ordinal;
    uint32_t AddressOfData;
    uint32_t ForwarderStringl;
  } u1;
};

struct IMAGE_IMPORT_BY_NAME {
  uint16_t Hint;
  char Name[];
};

struct NT_TIB {
	uint32_t ExceptionList;
	uint32_t StackBase;
	uint32_t StackLimit;
	union {
		uint32_t FiberData;
		uint32_t Version;
	};
	uint32_t ArbitraryUserPointer;
	uint32_t Self;
};
#pragma pack(pop)

#include <iostream>
#include <vector>

typedef void (*EXE_ENTRY_POINT)();

class Exe {
public:
  class Section {
  private:
    Exe& exe;
    uint32_t virtualAddress;
    uint32_t virtualSize;

    uint8_t* data;

  public:
    Section(Exe& exe, uint32_t virtualAddress, uint32_t virtualSize) : exe(exe), virtualAddress(virtualAddress), virtualSize(virtualSize) {
      this->data = (uint8_t*)mmap((void*)(this->exe.imageBase + virtualAddress), virtualSize, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
      if (this->data) {
        std::cout << "Section created successfully" << std::endl;

        if (this->data == (void*)(this->exe.imageBase + virtualAddress)) {
          std::cout << "Allocated perfectly" << std::endl;
        } else {
          std::cout << "Addresses are off" << std::endl;
        }
      } else {
        std::cout << "Section allocation failed :(" << std::endl;
      }
    };

    ~Section() {
      this->discard();
    }

    void discard() {
      std::cout << "Discarded" << std::endl;
      if (this->data) {
        munmap(this->data, this->virtualSize);
        this->data = nullptr;
      }
    }

    void protect(uint32_t protectionFlags) {
      if (!this->data) {
        return;
      }

      int protection = PROT_WRITE;

      if (protectionFlags & IMAGE_SCN_MEM_EXECUTE) {
        protection |= PROT_EXEC;
      }

      if (protectionFlags & IMAGE_SCN_MEM_READ) {
        protection |= PROT_READ;
      }

      if (protectionFlags & IMAGE_SCN_MEM_WRITE) {
        protection |= PROT_WRITE;
      }

      if (mprotect(this->data, this->virtualSize, protection) == 0) {
        std::cout << "Protection successful" << std::endl;

        if (protection & PROT_EXEC) {
          std::cout << std::hex << (uint32_t)(this->data) << " - " << (uint32_t)(this->data + this->virtualSize) << " is now executable" << std::endl;
        }
      } else {
        std::cout << "Protection failed" << std::endl;
      }
    }

    void* getRawPointer() {
      return data;
    }
  };

  std::vector<Section*> sections;

  const uint32_t imageBase;
  const uint32_t sizeOfImage;

  uint32_t addressOfEntryPoint;

  Exe(uint32_t imageBase, uint32_t sizeOfImage) : imageBase(imageBase), sizeOfImage(sizeOfImage) {
  }

  ~Exe() {
    for (auto& section : sections) {
      delete section;
    }
  }

  Section& createSection(uint32_t virtualAddress, uint32_t virtualSize) {
    Section* section = new Section(*this, virtualAddress, virtualSize);
    this->sections.push_back(section);

    return *section;
  }

  EXE_ENTRY_POINT getEntryPoint() {
    return (EXE_ENTRY_POINT)(this->imageBase + this->addressOfEntryPoint);
  }
};
