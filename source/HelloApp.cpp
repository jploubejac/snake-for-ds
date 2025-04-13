#include <nds.h>
#include <stdio.h>
#include "HelloApp.hpp"

void HelloApp::run(){
    consoleDemoInit();
    iprintf("Hello from Nintendo DS++!");
    while(1)swiWaitForVBlank();
}