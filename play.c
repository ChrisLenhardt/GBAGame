#include "gba.h"
#include "main.h"

oldPos PlayState(player *p1) {
        int oldy = p1->y;   //save oldstate
        int oldx = p1->x;
        int oldw = p1->w;
        int oldh = p1->h;
        if (KEY_DOWN(BUTTON_RIGHT, BUTTONS)) {  //button logic
            p1->x = p1->x + 1;
        } else if (KEY_DOWN(BUTTON_LEFT, BUTTONS)) {
            p1->x = p1->x - 1;
        } else if (KEY_DOWN(BUTTON_UP, BUTTONS)) {
            p1->y = p1->y - 1;
        }else if (KEY_DOWN(BUTTON_DOWN, BUTTONS)) {
            p1->y = p1->y + 1;
        }
        if (p1->x >= 230) { //border logic
            p1->x = 230;
        }
        if (p1->x <= 5) {
            p1->x = 5;
        }
        if (p1->y >= 153) {
            p1->y = 153;
        }
        if (p1->y <= 5) {
            p1->y = 5;
        }

        drawRectDMA(p1->y,p1->x,p1->w,p1->h,p1->playerColor);   //paint player if still
        if (oldx != p1->x) {    //transformation for grey cover up
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

oldPos enemyPlayState(enemy *e1, player *p1) {
        int oldy = e1->y;   //save old state
        int oldx = e1->x;
        int oldw = e1->w;
        int oldh = e1->h;
        if (randint(0,10) > 7) {
            if ((e1->x - p1->x) < 0) {  //follow player logic
            e1->x++;
        } else {
            e1->x--;
        }
        if ((e1->y - p1->y) < 0) {
            e1->y++;
        } else {
            e1->y--;
        }
        }
        

        if (e1->x >= 230) { //border logic
            e1->x = 230;
        }
        if (e1->x <= 5) {
            e1->x = 5;
        }
        if (e1->y >= 153) {
            e1->y = 153;
        }
        if (e1->y <= 5) {
            e1->y = 5;
        }
        drawRectDMA(e1->y,e1->x,e1->w,e1->h,e1->playerColor);   //paint enemy even if still
        if (oldx != e1->x) {    //transformation for grey cover up
            if (oldx > e1->x) {
                oldw--;
            } else {
                oldw++;
            }
        }  
        if (oldy != e1->y) {
            if (oldy > e1->y) {
                oldh--;
            } else {
                oldh++;
            }
        }

        struct oldPos oldpos = {oldy, oldx, oldw, oldh};
        return oldpos;
}
int isConsumed(player *p1, enemy *e1) {
    if ((p1->x - e1->x) < 5 && (p1->y - e1->y) < 5) {
        return 1;
    }
    return 0;
}
