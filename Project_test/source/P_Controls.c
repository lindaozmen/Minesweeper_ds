#include "P_Controls.h"
#include "game.h"

#define OFF 1
#define ON 2

int level = 1; //default easy
int bool_start ; // if we started the game
int verification; // if the player selects a level
int flag_mode_control;
int stopTouch;


void handleInput(){
	scanKeys();
	unsigned keys = keysDown();

	if(keys & KEY_Y)
	{
		Selection_Effect_Play();
		level = 1;
		verification = 1;
	}
	if (keys & KEY_A)
	{
		Selection_Effect_Play();
		level = 2;
		verification = 1;
	}
	if(keys & KEY_START){
		if (verification == 1)
		{
			stopTimer();
			bool_start = 1;
			stopTouch = 1;
			flag_mode_control = OFF;
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
		stop_display_timer();
		changeColorDisp_Main(BLACK);
		configureGraphics_Main_Up();
		fill_sub();
	}
	handleTouchPad();
}

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

			if (x>235 && x<250)
			{
				if(y>5 && y<22) //flag
				{
					fill_19x19_button(24, 235, GREY, LIGHT_GREY);
					fill_19x19_no_flag(24,235);
					fill_19x19_button(5, 235, GREY, PINK);
					fill_19x19_flag(5,235);
					flag_mode_control = ON;
				}
				if (y>24 && y<43) //unflag
				{
					fill_19x19_button(5, 235, GREY, LIGHT_GREY);
					fill_19x19_flag(5,235);
					fill_19x19_button(24, 235, GREY, PINK);
					fill_19x19_no_flag(24,235);
					flag_mode_control = OFF;
				}
				if (y>50 && y<69) // play music
				{
					Audio_PlayMusic();
				}
				if (y>69 && y<88) // stop music
				{
					stopMusic();
				}
				if (y>95 && y<114) // stop sign
				{
					verification = 0;
					bool_start = 0;
					irqDisable(IRQ_TIMER0);
					stopTimer();
					stopMusic();
					stop_display_timer();
					changeColorDisp_Main(BLACK);
					configureGraphics_Main_Up();
					fill_sub();
				}
			}
			if (flag_mode_control == OFF) // unflag
			{
				normal_mode(x,y);
			}
			if (flag_mode_control == ON) // flag
			{
				flag_mode(x,y);
			}
			if (x>0 && x<19) // Smiley start
			{
				if(y>0 && y<19)
				{
					stopTimer();
					bool_start = 1;
					stopTouch = 1;
					flag_mode_control = OFF;
					fill_sub();
					init_game(level);
					mmStart(MOD_INFLUENCA, MM_PLAY_LOOP);
					initChronoDisp_Main();
					Audio_PlayMusic();
				}
			}
		}
	}
}

void normal_mode(int x, int y)
{
	if(stopTouch == 1)
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
			on_matrix_clicked(compteur_y, compteur_x);	//x->column, y->row
			Result_Effect_Play();
		}
	}
}

void flag_mode(int x,int y)
{
	if(stopTouch == 1)
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

				if (flagged(compteur_y, compteur_x))
					fill_19x19_flag(compteur_y*19, compteur_x*19+32);
			}
		}
	}
}

void stopTouching()
{
	stopTouch = 0;
}
