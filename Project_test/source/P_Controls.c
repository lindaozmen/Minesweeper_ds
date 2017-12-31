#include "P_Controls.h"

int bool_start ;
int verification;

void handleTouchPad(){
	if (bool_start == 1)
	{
		touchPosition touch;
		touchRead(&touch);
		//If the touch received is different than (0,0)
		if(touch.px || touch.py)
		{
			int x = touch.px;
			int y = touch.py;
			int compteur_x=0;
			int compteur_y=0;
			if (x>= 32){
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
		    	oamSet(&oamSub, 	// oam handler
		    		10,				// Number of sprite
		    		compteur_x*19+32+3,compteur_y*19+4,			// Coordinates
		    		0,				// Priority
		    		0,				// Palette to use
		    		SpriteSize_16x16,			// Sprite size
		    		SpriteColorFormat_256Color,	// Color format
		    		gfx,			// Loaded graphic to display
		    		-1,				// Affine rotation to use (-1 none)
		    		false,			// Double size if rotating
		    		false,			// Hide this sprite
		    		false, false,	// Horizontal or vertical flip
		    		false			// Mosaic
		    		);
		    	//Update the sprites
		    	swiWaitForVBlank();
				oamUpdate(&oamSub);
				//fill_19x19_button(compteur_y*19, compteur_x*19+32, GREY, RED);
				Result_Effect_Play();
			}


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
	if(keys & KEY_Y)
	{
		//playerPlaysTen();
		verification = 1;
	}
	if (keys & KEY_A)
	{
		verification = 1;
		//playerPlaysTwenty();
	}
	if( keys & KEY_START){
		if (verification == 1)
		{
			// start the game
			bool_start = 1;
			fill_sub();
			mmStart(MOD_INFLUENCA, MM_PLAY_LOOP);
			initChronoDisp_Main();
			Audio_PlayMusic();
		}

	}
	if (keys & KEY_B){
		verification = 0;
		bool_start = 0;
		irqDisable(IRQ_TIMER0);
		stopTimer();
		stopMusic();
		changeColorDisp_Main(BLACK);
		configureGraphics_Main_Up();
	}
	handleTouchPad();
}
