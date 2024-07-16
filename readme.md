# ShallowSleep Documentation

## Overview:
The game is called ShallowSleep where you attempt to wake up from your eternal sleep.
This is not deepwoken, however you do lose all progress upon death(you have one health).
You need to escape your slumber before fall to deep into your sleep state(you have 30 seconds).
To escape you must collect your memories, which will remind you are dreaming and help you wake up(the yellow dots are memories that need to be all collected);

## Gameplay
Collect all coinds before 30 seconds or the sleep pralaysis demon touches you.

use arrow keys to move

press delete at any screen to return to home screen

press enter to start from the menu screen

## Functionality
### Play.c
In Play.c most of the logic is encapsulated this include player and enemy movement and collision calculations
To prevent bogging down the system collisions are approximated with absolute distance per axis and not using an algorithm with pythagorean's theorem.
Player movement is decided with keypress rather than key just down to promote quick and smooth movement and it updates the passed in player's position variables
The enemy(sleep demon) is calculated by going the direction of the player each cycle. However to slow down the enemy I use a random number to decide if the demon will move or not
Is consumed and checkcollect are both collision calculations for the sprites and "coins" respectively
Print coins simplifies the process of printing the coins to screen
### main.c
Main.c contains all the other game logic. Using prevState and State i am able to create a state machine that accurately changes screen view and resets sprite information accordingly. Timer functionality is calculated here based off the clockspeed of completing one cycle of the play loop
Pointers are created to pass information to the methods, timer count is kept track of, and coin count keeps track of how many coins are collected
Coin count, timer count, and collision status all can change the game state autonomously. the user can change the play state to the start state by pressing delete.
WIN and LOSE states print an image to screen and reset player position.
### main.h 
Contains all of the structs and global methods. The structs clump data for coins, players, and enemies. Methods are accessed to abstract the functionality of the game from play.c



