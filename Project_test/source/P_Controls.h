
#include <nds.h>
#include "graphic_main.h"
#include "graphic_sub.h"
#include "sound.h"
#include "timer.h"

/*
 * This function handles the input by monitoring the keys and the touchscreen
 * and invoking the function GamePlay_HandleInput(...) with the correct input
 * value
 */
void handleInput();
void hanndleTouchPad();
void normal_mode(int x, int y);
void flag_mode(int x,int y);
void stopTouching();
