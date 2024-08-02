#include "processenv.h"

#include <cstdio>
#include <cstring>

//TODO: These need to be deallocated when the application exits
LPSTR commandLineA = nullptr;
LPWSTR commandLineW = nullptr;

HANDLE WINAPI GetStdHandle(DWORD nStdHandle) {
  //Let's assume the following handle values:
  // - STD_INPUT_HANDLE: 2
  // - STD_OUTPUT_HANDLE: 3
  // - STD_ERROR_HANDLE: 4

  if (nStdHandle == STD_INPUT_HANDLE) {
    return (HANDLE)2;
  }

  if (nStdHandle == STD_OUTPUT_HANDLE) {
    return (HANDLE)3;
  }

  if (nStdHandle == STD_ERROR_HANDLE) {
    return (HANDLE)4;
  }

  return nullptr;
}

LPSTR WINAPI GetCommandLineA() {
  //If the command line buffer is already available, simply return it
  if (commandLineA) {
    return commandLineA;
  }

  //If not, we need to make it
  //"/proc/self/cmdline" contains a list of arguments separated by NULL characters, like this
  //We need to convert it into a list of quoted arguments separated by space characters
  FILE* cmdline = fopen("/proc/self/cmdline", "r");

  //First, let's calculate the length of the output command line buffer
  size_t length = 0;
  {
    char buffer[1024];

    //Are we currently inside of an argument?
    bool insideArgument = true; //The very first character in the sequence is part of the first argument

    //We need to know which argument we're currently in
    //The first argument (argumentIndex = 0) needs to be skipped, because it's the path of the 'Windows Games on Linux' executable
    int argumentIndex = 0;

    while (fgets(buffer, 1024, cmdline)) {
      for (int i = 0; i < 1024; i++) {
        //Handle a NULL character
        if (buffer[i] == 0) {
          //If we're already outside of an argument (meaning that there was another NULL character before this one),
          //this means that it's the end of the sequence
          if (!insideArgument) {
            break;
          }

          //Quit the argument
          insideArgument = false;

          //Allocate a byte for a quote character that ends the argument
          //Note: First argument is skipped, see above
          if (argumentIndex > 0) {
            length++;
          }

          argumentIndex++;
          continue;
        }

        //Handle all the other characters
        //Note: First argument is skipped, see above
        if (argumentIndex > 0) {
          //If we're currently outside of an argument, that means that we're entering a new argument
          if (!insideArgument) {
            insideArgument = true;

            //If this is the first argument that will be put into the command line buffer,
            //simply allocate a byte for a quote character
            if (argumentIndex == 1) {
              length++;
            } else {
              //If it's any other argument, allocate 2 bytes: one for a separating space character, and one for the opening quote
              length += 2;
            }
          }

          length++;
        }
      }
    }
  }

  //Now, allocate a command line buffer and write to it using an algorithm similar to the above one
  commandLineA = new char[length + 1];

  //The current position in the command line buffer
  int j = 0;

  {
    fseek(cmdline, 0, SEEK_SET);
    char buffer[1024];

    //Are we currently inside of an argument?
    bool insideArgument = true; //The very first character in the sequence is part of the first argument

    //We need to know which argument we're currently in
    //The first argument (argumentIndex = 0) needs to be skipped, because it's the path of the 'Windows Games on Linux' executable
    int argumentIndex = 0;

    while (fgets(buffer, 1024, cmdline)) {
      for (int i = 0; i < 1024; i++) {
        //Handle a NULL character
        if (buffer[i] == 0) {
          //If we're already outside of an argument (meaning that there was another NULL character before this one),
          //this means that it's the end of the sequence
          if (!insideArgument) {
            break;
          }

          //Quit the argument
          insideArgument = false;

          //End the argument with a quote character
          //Note: First argument is skipped, see above
          if (argumentIndex > 0) {
            commandLineA[j++] = '"';
          }

          argumentIndex++;
          continue;
        }

        //Handle all the other characters
        //Note: First argument is skipped, see above
        if (argumentIndex > 0) {
          //If we're currently outside of an argument, that means that we're entering a new argument
          if (!insideArgument) {
            insideArgument = true;

            //If this is the first argument that will be put into the command line buffer,
            //simply start it with a quote character
            if (argumentIndex == 1) {
              commandLineA[j++] = '"';
            } else {
              //If it's any other argument, add a separating space character and start the argument with a quote character
              commandLineA[j++] = ' ';
              commandLineA[j++] = '"';
            }
          }

          commandLineA[j++] = buffer[i];
        }
      }
    }
  }

  //Finally, end the command line with a NULL character
  commandLineA[j++] = 0;

  fclose(cmdline);
  return commandLineA;
}

LPWSTR WINAPI GetCommandLineW() {
  //If the command line buffer is already available, simply return it
  if (commandLineW) {
    return commandLineW;
  }

  //If not, we need to make it
  //"/proc/self/cmdline" contains a list of arguments separated by NULL characters, like this
  //We need to convert it into a list of quoted arguments separated by space characters
  FILE* cmdline = fopen("/proc/self/cmdline", "r");

  //First, let's calculate the length of the output command line buffer
  size_t length = 0;
  {
    char buffer[1024];

    //Are we currently inside of an argument?
    bool insideArgument = true; //The very first character in the sequence is part of the first argument

    //We need to know which argument we're currently in
    //The first argument (argumentIndex = 0) needs to be skipped, because it's the path of the 'Windows Games on Linux' executable
    int argumentIndex = 0;

    while (fgets(buffer, 1024, cmdline)) {
      for (int i = 0; i < 1024; i++) {
        //Handle a NULL character
        if (buffer[i] == 0) {
          //If we're already outside of an argument (meaning that there was another NULL character before this one),
          //this means that it's the end of the sequence
          if (!insideArgument) {
            break;
          }

          //Quit the argument
          insideArgument = false;

          //Allocate a byte for a quote character that ends the argument
          //Note: First argument is skipped, see above
          if (argumentIndex > 0) {
            length++;
          }

          argumentIndex++;
          continue;
        }

        //Handle all the other characters
        //Note: First argument is skipped, see above
        if (argumentIndex > 0) {
          //If we're currently outside of an argument, that means that we're entering a new argument
          if (!insideArgument) {
            insideArgument = true;

            //If this is the first argument that will be put into the command line buffer,
            //simply allocate a byte for a quote character
            if (argumentIndex == 1) {
              length++;
            } else {
              //If it's any other argument, allocate 2 bytes: one for a separating space character, and one for the opening quote
              length += 2;
            }
          }

          length++;
        }
      }
    }
  }

  //Now, allocate a command line buffer and write to it using an algorithm similar to the above one
  commandLineW = new char16_t[length + 1];

  //The current position in the command line buffer
  int j = 0;

  {
    fseek(cmdline, 0, SEEK_SET);
    char buffer[1024];

    //Are we currently inside of an argument?
    bool insideArgument = true; //The very first character in the sequence is part of the first argument

    //We need to know which argument we're currently in
    //The first argument (argumentIndex = 0) needs to be skipped, because it's the path of the 'Windows Games on Linux' executable
    int argumentIndex = 0;

    while (fgets(buffer, 1024, cmdline)) {
      for (int i = 0; i < 1024; i++) {
        //Handle a NULL character
        if (buffer[i] == 0) {
          //If we're already outside of an argument (meaning that there was another NULL character before this one),
          //this means that it's the end of the sequence
          if (!insideArgument) {
            break;
          }

          //Quit the argument
          insideArgument = false;

          //End the argument with a quote character
          //Note: First argument is skipped, see above
          if (argumentIndex > 0) {
            commandLineW[j++] = '"';
          }

          argumentIndex++;
          continue;
        }

        //Handle all the other characters
        //Note: First argument is skipped, see above
        if (argumentIndex > 0) {
          //If we're currently outside of an argument, that means that we're entering a new argument
          if (!insideArgument) {
            insideArgument = true;

            //If this is the first argument that will be put into the command line buffer,
            //simply start it with a quote character
            if (argumentIndex == 1) {
              commandLineW[j++] = '"';
            } else {
              //If it's any other argument, add a separating space character and start the argument with a quote character
              commandLineW[j++] = ' ';
              commandLineW[j++] = '"';
            }
          }

          commandLineW[j++] = buffer[i];
        }
      }
    }
  }

  //Finally, end the command line with a NULL character
  commandLineW[j++] = 0;

  fclose(cmdline);
  return commandLineW;
}

LPWCH WINAPI GetEnvironmentStringsW() {
  extern char** environ;

  //First, calculate the total size of all environment strings (including NULL characters)
  int size = 0;
  {
    char** str = environ;
    while (*str) {
      size += strlen(*str) + 1;
      str++;
    }

    //Final NULL character
    size++;
  }

  //Now, allocate the buffer and copy the strings
  LPWCH environmentStringsW = new char16_t[size];
  {
    int i = 0;
    char** str = environ;
    while (*str) {
      for (char* c = *str; ; c++) {
        environmentStringsW[i++] = (unsigned char)*c;
        if (*c == 0) {
          break;
        }
      }

      str++;
    }

    environmentStringsW[i++] = 0;
  }

  return environmentStringsW;
}

BOOL WINAPI FreeEnvironmentStringsW(LPWCH penv) {
  delete[] penv;
  return 1;
}

