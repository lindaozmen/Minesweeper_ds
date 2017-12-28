/*
 * Template Nintendo DS
 * May 2011
 */

#include <nds.h>
#include <stdio.h>
#include "graphic_main.h"
#include "graphic_sub.h"
#include "sound.h"
#include "timer.h"
#include "game.h"

void startGame(){};
void stopChronoDisplay_Main(){};
void handleInput();
void handleTouchPad();


int bool_start ;

int main(void) {

	consoleDemoInit();
	Audio_Init();
    configureGraphics_Main_Up();
	configureGraphics_Sub();
	fill_sub();

    while(1)
    {
    	handleInput();
    	swiWaitForVBlank();
    }
}

void handleTouchPad(){
	if (bool_start == 1){
		touchPosition touch;
			touchRead(&touch);
			//If the touch received is different to (0,0)
			if(touch.px || touch.py)
			{
				int x = touch.px;
				int y = touch.py;

				int compteur_x=0;
				int compteur_y=0;

				while (y>=19)
				{
					y = y-19;
					compteur_y++;

				}

				while (x>=51)
				{
					x = x-19;
					compteur_x++;
				}

				fill_19x19_button(compteur_y*19, compteur_x*19+32, GREY, RED);
				Effect_Play();
				/*BOMB TOUCHED*/
				/*
				  if a bomb is touched, put the explosion effect and call the endGame
				  function. (reveal the map and end the game).
				*/
			}
	}
}

void handleInput(){
	scanKeys();
	unsigned keys = keysDown();

	if( keys & KEY_START){
		bool_start = 1;
		mmStart(MOD_WILDWEST, MM_PLAY_LOOP);
		startGame();
		initChronoDisp_Main();
		Audio_PlayMusic();
	}
	if (keys & KEY_B){
		bool_start = 0;
		irqDisable(IRQ_TIMER0);
		stopTimer();
		stopMusic();
		changeColorDisp_Main(BLACK);
		configureGraphics_Main_Up();
	}
	handleTouchPad();

}

