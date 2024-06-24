#include "commctrl.h"

#include <iostream>

BOOL _TrackMouseEvent(LPTRACKMOUSEEVENT lpEventTrack) {
    std::cout << "_TrackMouseEvent" << std::endl;
}