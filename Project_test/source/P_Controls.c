#include "P_Controls.h"
#include "game.h"

#define OFF 1
#define ON 2
int bool_start ;
int verification;
int control_flags;
int flag_mode_control;

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
			/*
			if (x>235 && x<250)
			{
				if(y>5 && y<22)
				{
					if ((control_flags % 2) != 0)
					{
						fill_19x19_button(5, 235, GREY, PINK);
						fill_19x19_flag(5,235);
						flag_mode_control = ON;
					}
					 if (control_flags % 2 == 0)
					{
						fill_19x19_button(5, 235, GREY, LIGHT_GREY);
						fill_19x19_flag(5,235);
						flag_mode_control = OFF;
					}
					 control_flags++;
				}
			}
			if (flag_mode_control == OFF)
			{
				normal_mode(x,y);
			}
			if (flag_mode_control == ON)
			{
				flag_mode(x,y);
			}
			*/
			normal_mode(x,y);
			}

	}
	}
void flag_mode(int x,int y)
{
	if (x>= 32 && x<=222)
	{
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

				fill_19x19_flag(compteur_y*19, compteur_x*19+32);
			}
	}


}
void normal_mode(int x, int y)
{
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
