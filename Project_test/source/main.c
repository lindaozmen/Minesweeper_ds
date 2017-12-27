/*
 * Template Nintendo DS
 * May 2011
 */

#include <nds.h>
#include <stdio.h>
#include "graphic_main.h"
#include "sound.h"
#include "timer.h"

void startGame(){};
void stopGame(){};
void stopChronoDisplay_Main(){};
void handleInput();
void handleTouchPad();


int main(void) {
	consoleDemoInit();
	Audio_Init();
    configureGraphics_Main_Up();
    while(1)
    {
    	handleInput();
    	swiWaitForVBlank();
    }
}

void handleTouchPad(){
	touchPosition touch;
	touchRead(&touch);
	//If the touch received is different to (0,0)
	if(touch.px || touch.py)
	{
		/*BOMB TOUCHED*/
		/*
		  if a bomb is touched, put the explosion effect and call the endGame
		  function. (reveal the map and end the game).
		*/
	}

}

void handleInput(){
	scanKeys();
	unsigned keys = keysDown();
	if( keys & KEY_START ){
		mmStart(MOD_WILDWEST, MM_PLAY_LOOP);
		startGame();
		initChronoDisp_Main();
		Audio_PlayMusic();
	}
	if (keys & KEY_B ){
		irqDisable(IRQ_TIMER0);
		stopGame();
		stopMusic();
		changeColorDisp_Main(BLACK);
		configureGraphics_Main_Up();

	}
		handleTouchPad();
}

