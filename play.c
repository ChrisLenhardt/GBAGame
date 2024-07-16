#include "gba.h"
#include "main.h"

void PlayState(player *p1, u32 previousButtons, int* i) {
        if (KEY_JUST_PRESSED(BUTTON_RIGHT, BUTTONS, previousButtons)) {
            p1->x = p1->x + 1;
        } else if (KEY_JUST_PRESSED(BUTTON_LEFT, BUTTONS, previousButtons)) {
            p1->x = p1->x - 1;
        } else if (KEY_JUST_PRESSED(BUTTON_UP, BUTTONS, previousButtons)) {
            p1->y = p1->y - 1;
        }else if (KEY_JUST_PRESSED(BUTTON_DOWN, BUTTONS, previousButtons)) {
            p1->y = p1->y + 1;
        }
        else if (KEY_JUST_PRESSED(BUTTON_DOWN, BUTTONS, previousButtons)) {
            i++;
        }

        waitForVBlank();
        drawRectDMA(p1->y,p1->x,p1->w,p1->h,p1->playerColor);
}