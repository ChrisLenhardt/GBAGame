#include "main.h"

#include <stdio.h>
#include <stdlib.h>

#include "gba.h"
#include "images/garbage.h"
#include "images/shallowsleep.h"
#include "images/lightfade.h"
#include "images/awoke.h"

extern player p1;
/* TODO: */
// Include any header files for title screen or exit
// screen images generated by nin10kit. Example for the provided garbage
// image:
// #include "images/garbage.h"

/* TODO: */
// Add any additional states you need for your app. You are not requried to use
// these specific provided states.
enum gba_state {
  START,
  PLAY,
  WIN,
  LOSE,
};

int main(void) {
  /* TODO: */
  // Manipulate REG_DISPCNT here to set Mode 3. //
  *((volatile unsigned char *)(&REG_DISPCNT)) = MODE3;
  *((volatile unsigned char *)(&REG_DISPCNT) + 1) = 0x04;
  // Save current and previous state of button input.
  u32 previousButtons = BUTTONS;
  u32 currentButtons = BUTTONS;

  // Load initial application state
  enum gba_state state = START;
  enum gba_state prevState = START;
  drawImageDMA(0,0,240,160,shallowsleep);
  struct enemy e1 = {0,0,5,5,RED};
  struct player p1 = {(WIDTH / 2 + 4), (HEIGHT / 2 + 3), 4, 3, GREEN};
  struct oldPos oldPos;
  struct oldPos oldPosEnemy;
  int vBlankCounterOffset = 0;
  char timerValue[2];
  int timerColor = WHITE;
  int timerValueLiteral;

  while (1) {
    currentButtons = BUTTONS; // Load the current state of the buttons

    /* TODO: */
    // Manipulate the state machine below as needed //
    // NOTE: Call waitForVBlank() before you draw

    switch (state) {
      case START:
        if (prevState != START) {
            drawImageDMA(0,0,240,160,shallowsleep);
            prevState = START;
        }
        waitForVBlank();
        drawCenteredString(60,160,70,140,"shallowsleep",BLACK);
        if (KEY_JUST_PRESSED(BUTTON_START,currentButtons,previousButtons)) {
          state = PLAY;
        }
        break;
      case PLAY:
        if (prevState != PLAY) {
            drawPlay();
            e1.x = 0;
            e1.y = 0;
            vBlankCounterOffset = vBlankCounter;
            prevState = PLAY;
        }
        if (KEY_JUST_PRESSED(BUTTON_SELECT,BUTTONS,previousButtons)) {
            p1.x = (WIDTH / 2 + 4);
            p1.y = (HEIGHT / 2 + 3);
            prevState = PLAY;
            state = START;
        }
          enemy *e1p = &e1;
          player *p1p = &p1;
          oldPos = PlayState(p1p);
          oldPosEnemy = enemyPlayState(e1p, p1p);
          timerValueLiteral = (vBlankCounter- vBlankCounterOffset) / 60;
          sprintf(timerValue, "%d", timerValueLiteral);
          if (timerValueLiteral > 20) {
            timerColor = RED;
          }
          waitForVBlank();
          drawRectDMA(0,60,42,20,GRAY);
          drawCenteredString(0,60,40,20, timerValue ,timerColor);
          drawRectDMA(p1p->y,p1p->x,p1p->w,p1p->h,p1p->playerColor);
          drawRectDMA(e1p->y,e1p->x,e1p->w,e1p->h,e1p->playerColor);
          drawRectDMA(oldPos.oldy,oldPos.oldx,oldPos.oldw,oldPos.oldh,GRAY);
          drawRectDMA(oldPosEnemy.oldy,oldPosEnemy.oldx,oldPosEnemy.oldw,oldPosEnemy.oldh,GRAY);
          if (isConsumed(p1p,e1p) == 1) {
            state = LOSE;
          }
          if (timerValueLiteral > 30) {
            state = LOSE;
          }

        
        break;
      case WIN:
        if (prevState != WIN) {
          drawImageDMA(0,0,240,160,awoke);
          drawCenteredString(60,10,70,140,"You woke up!",BLACK);
          prevState = WIN;
        }
        if (KEY_JUST_PRESSED(BUTTON_SELECT,BUTTONS,previousButtons)) {
            p1.x = (WIDTH / 2 + 4);
            p1.y = (HEIGHT / 2 + 3);
            prevState = WIN;
            state = START;
        }
        break;
      case LOSE:
        if (prevState != LOSE) {
          drawImageDMA(0,0,240,160,lightfade);
          drawCenteredString(100,45,160,100,"You Never Escape Slumber...",WHITE);
          prevState = LOSE;
        }
        if (KEY_JUST_PRESSED(BUTTON_SELECT,BUTTONS,previousButtons)) {
            p1.x = (WIDTH / 2 + 4);
            p1.y = (HEIGHT / 2 + 3);
            prevState = LOSE;
            state = START;
        }
        break;
    }

    previousButtons = currentButtons; // Store the current state of the buttons
  }

  UNUSED(previousButtons); // You can remove this once previousButtons is used

  return 0;
}
