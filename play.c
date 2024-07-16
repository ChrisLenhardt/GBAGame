#include "gba.h"
#include "main.h"

oldPos PlayState(player *p1) {
        int oldy = p1->y;
        int oldx = p1->x;
        int oldw = p1->w;
        int oldh = p1->h;
        if (KEY_DOWN(BUTTON_RIGHT, BUTTONS)) {
            p1->x = p1->x + 1;
        } else if (KEY_DOWN(BUTTON_LEFT, BUTTONS)) {
            p1->x = p1->x - 1;
        } else if (KEY_DOWN(BUTTON_UP, BUTTONS)) {
            p1->y = p1->y - 1;
        }else if (KEY_DOWN(BUTTON_DOWN, BUTTONS)) {
            p1->y = p1->y + 1;
        }

        drawRectDMA(p1->y,p1->x,p1->w,p1->h,p1->playerColor);
        if (oldx != p1->x) {
            if (oldx > p1->x) {
                oldw--;
            } else {
                oldw++;
            }
        }  
        if (oldy != p1->y) {
            if (oldy > p1->y) {
                oldh--;
            } else {
                oldh++;
            }
        }

        struct oldPos oldpos = {oldy, oldx, oldw, oldh};
        return oldpos;
}