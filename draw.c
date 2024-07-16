#include "main.h"
#include "gba.h"

void drawPlay(void) {
    waitForVBlank();
    drawRectDMA(0,0,240,160,GRAY);  //FILL with gray screen
}