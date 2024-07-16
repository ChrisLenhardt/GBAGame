#ifndef MAIN_H
#define MAIN_H

#include "gba.h"

// TODO: Create any necessary structs

/*
* For example, for a Snake game, one could be:
*
* struct snake {
*   int heading;
*   int length;
*   int row;
*   int col;
* };
*
* Example of a struct to hold state machine data:
*
* struct state {
*   int currentState;
*   int nextState;
* };
*
*/
// typedef struct state {
//     int currentState;
//     int nextState;
// } state;

typedef struct player {
    u16 x;  //top left x
    u16 y;  //top left y
    u16 w;  //width of player
    u16 h;  //height of player
    u16 playerColor;    //color of player sprite
} player;
typedef struct enemy {
    u16 x;  //top left x
    u16 y;  //top left y
    u16 w;  //width of enemy
    u16 h;  //height of enemy
    u16 playerColor;    //color of enemy sprite
} enemy;
typedef struct memory {
    u16 x;  //top left x
    u16 y;  //top left y
    u16 color; //color of mem coin
    u16 collected;
} memory;
typedef struct oldPos{
    u16 oldy;
    u16 oldx;
    u16 oldw;
    u16 oldh;
} oldPos;
void drawPlay(void);
oldPos PlayState(player *p1);
oldPos enemyPlayState(enemy *e1, player *p1);
void printCoins(struct memory mems[]);
void checkCollect(struct memory mems[], player *p1);
u16 coinCount(struct memory mems[], u16 c);
u16 isConsumed(player *p1, enemy *e1);
#endif