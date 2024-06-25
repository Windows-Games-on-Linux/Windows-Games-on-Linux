#include "winuser.h"

#include <iostream>

BOOL GetWindowRect(HWND hWnd, LPRECT lpRect) {
  std::cout << "GetWindowRect" << std::endl;
  return 0;
}