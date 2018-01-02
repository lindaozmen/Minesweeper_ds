#include "P_Controls.h"
#include "game.h"

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
				//fill_19x19_button(compteur_y*19, comptechur_x*19+32, GREY, WHITE);
				//fill_19x19_eight(compteur_y*19, compteur_x*19+32,RED);
				//fill_19x19_bomb(compteur_y*19, compteur_x*19+32);
				on_matrix_clicked(compteur_y, compteur_x);	//x->column, y->row
				Result_Effect_Play();
			}
		}
	}
}

void handleInput(){
	scanKeys();
	unsigned keys = keysDown();
	int level = 1; //default easy
	if(keys & KEY_Y)
	{
		level = 1;
		verification = 1;
	}
	if (keys & KEY_A)
	{
		level = 2;
		verification = 1;
	}
	if( keys & KEY_START){
		if (verification == 1)
		{
			// start the game
			bool_start = 1;
			fill_sub();
			init_game(level);
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
