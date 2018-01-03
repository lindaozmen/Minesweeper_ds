/*
 *	File Name	:	graphic_sub.c
 *	Author		:
 *	Last Update :	23.12.2017
 *
 *	Implementation of graphics on sub screen
 */

#include "graphic_sub.h"

void configureGraphics_Sub()
{
	REG_DISPCNT_SUB = MODE_5_2D | DISPLAY_BG2_ACTIVE;

	VRAM_C_CR = VRAM_ENABLE | VRAM_C_SUB_BG;

	configBG2_Sub();

}


void configBG2_Sub(){
	BGCTRL_SUB[2] = BG_BMP_BASE(0) | BG_BMP16_256x256;

    // Set up affine matrix
    REG_BG2PA_SUB = 256;
    REG_BG2PC_SUB = 0;
    REG_BG2PB_SUB = 0;
    REG_BG2PD_SUB = 256;
    fillScreen_Sub(WHITE);
}

void fill_sub(){
	int i,j;
	for ( j = 32; j<225; j+=19)
	{
		for(i = 0; i<192; i+=19)
		{
			fill_19x19_button(i, j, GREY, LIGHT_GREY);

		}
	}
	fill_19x19_button(5,235,GREY,LIGHT_GREY);
	fill_19x19_flag(5,235);
	fill_19x19_button(24,235,GREY,LIGHT_GREY);
	fill_19x19_no_flag(24,235);
	fill_19x19_button(50,235,GREY,LIGHT_GREY);
	fill_19x19_sound(50,235);
	fill_19x19_button(69,235,GREY,LIGHT_GREY);
	fill_19x19_no_sound(69,235);
	fill_19x19_button(95,235,GREY,LIGHT_GREY);
	fill_19x19_stop(95,235);
	fill_19x19_button(0,0,GREY,LIGHT_GREY);
	fill_19x19_smiley_happy(0,0);

}

void fillScreen_Sub(){
	//Fill the buffer of the screen with the given input color
	int i,j;
	for(i = 0; i<192; i++){
		for(j = 0;j<256; j++){
			BG_BMP_RAM_SUB(0)[i*256+j] = PINK_TIMER;
		}
	}
}

void fill_19x19_button(unsigned int top, unsigned int left, u16 out, u16 in) {
	//Sanity check. If the coordinates are not correct (the button will be
	//partially or fully outside the screen) return without doing anything
	if (top > 192 || (left > 220 && left != 235)) return;

	//Draw the button of 19x19 pixels given the top left corner and the outside
	//color (out) and the inside color (in)
	int col, row;

	for (row = 0; row<19; row++)
	{
		for(col = 0; col<19; col++)
		{
			if((row <2) || (row>= 17) || (col<2) || (col >= 17))
			{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = out;
			}
			else
			{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = in;
			}

		}
	}
}

void  fill_19x19_one(unsigned int top, unsigned int left)
{
	int col, row;
	for (row = 15; row<16; row++)
	{
		for(col = 6; col<14; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = BLUE;
		}
	}
	for (row = 4; row<15; row++)
	{
		for(col = 9; col<11; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = BLUE;
		}
	}
	for (row = 4; row<6; row++)
	{
		for(col = 8; col<9; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = BLUE;
		}
	}
	for (row = 5; row<7; row++)
	{
		for(col = 7; col<8; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = BLUE;
		}
	}
	for (row = 6; row<8; row++){
		for(col = 6; col<7; col++){
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = BLUE;
		}
	}
}

void  fill_19x19_two(unsigned int top, unsigned int left)
{
	int col, row;
	for (row = 3; row<5; row++)	{
		for(col = 7; col<12; col++){
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = GREEN;
		}
	}
	for (row = 5; row<7; row++){
		for(col = 5; col<7; col++){
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = GREEN;
		}
	}
	for (row = 5; row<8; row++){
		for(col = 12; col<14; col++){
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = GREEN;
		}
	}
	for (row = 8; row<10; row++)	{
		for(col = 10; col<12; col++){
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = GREEN;
		}
	}
	for (row = 10; row<12; row++)
	{
		for(col = 9; col<11; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = GREEN;
		}
	}
	for (row = 11; row<13; row++)
		{
			for(col = 7; col<9; col++)
			{
					BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = GREEN;
			}
		}
	for (row = 13; row<16; row++)
		{
			for(col = 5; col<7; col++)
			{
					BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = GREEN;
			}
		}
	for (row = 15; row<16; row++)
		{
			for(col = 7; col<14; col++)
			{
					BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = GREEN;
			}
		}
}

void fill_19x19_three(unsigned int top, unsigned int left)
{
	int col, row;
	for (row = 3; row<5; row++)
	{
		for(col = 7; col<12; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = RED;
		}
	}
	for (row = 5; row<7; row++)
	{
		for(col = 5; col<7; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = RED;
		}
	}
	for (row = 5; row<8; row++)
	{
		for(col = 12; col<14; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = RED;
		}
	}
	for (row = 8; row<10; row++)
	{
		for(col = 8; col<12; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = RED;
		}
	}
	for (row = 10; row<15; row++)
	{
		for(col = 12; col<14; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = RED;
		}
	}
	for (row = 13; row<15; row++)
		{
			for(col = 5; col<7; col++)
			{
					BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = RED;
			}
		}
	for (row = 15; row<17; row++)
		{
			for(col = 7; col<12; col++)
			{
					BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = RED;
			}
		}
}

void fill_19x19_four(unsigned int top, unsigned int left)
{
	int col, row;
	for (row = 3; row<17; row++)
	{
		for(col = 11; col<13; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = DARK_BLUE;
		}
	}
	for (row = 12; row<14; row++)
	{
		for(col = 5; col<15; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = DARK_BLUE;
		}
	}
	for (row = 9; row<11; row++)
	{
		for(col = 5; col<7; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = DARK_BLUE;
		}
	}
	for (row = 5; row<7; row++)
	{
		for(col = 9; col<11; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = DARK_BLUE;
		}
	}
	for (row = 7; row<9; row++)
	{
		for(col = 7; col<9; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = DARK_BLUE;
		}
	}
}

void fill_19x19_five(unsigned int top, unsigned int left)
{
	int col, row;
	for (row = 4; row<8-2; row++)
	{
		for(col = 5; col<13; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = DARK_RED;
		}
	}
	for (row = 8-2; row<10-2; row++)
	{
		for(col = 5; col<7; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = DARK_RED;
		}
	}
	for (row = 10-2; row<12-2; row++)
	{
		for(col = 5; col<11; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = DARK_RED;
		}
	}
	for (row = 12-2; row<16-2; row++)
	{
		for(col = 11; col<13; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = DARK_RED;
		}
	}
	for (row = 14-2; row<16-2; row++)
	{
		for(col = 5; col<7; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = DARK_RED;
		}
	}
	for (row = 16-2; row<18-2; row++)
	{
		for(col = 7; col<11; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = DARK_RED;
		}
	}
}

void fill_19x19_six(unsigned int top, unsigned int left)
{
	int col, row;
	for (row = 4; row<6; row++)
	{
		for(col = 8; col<12; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = LIGHT_BLUE;
		}
	}
	for (row = 6; row<8; row++)
	{
		for(col = 6; col<8; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] =LIGHT_BLUE ;
		}
	}
	for (row = 8; row<14; row++)
	{
		for(col = 4; col<6; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = LIGHT_BLUE;
		}
	}
	for (row = 9; row<11; row++)
	{
		for(col = 6; col<12; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = LIGHT_BLUE;
		}
	}
	for (row = 11; row<14; row++)
	{
		for(col = 12; col<14; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = LIGHT_BLUE;
		}
	}
	for (row = 14; row<16; row++)
	{
		for(col = 6; col<12; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = LIGHT_BLUE;
		}
	}
}

void fill_19x19_seven(unsigned int top, unsigned int left)
{
	int col, row;
	for (row = 2+2; row<4+2; row++)
	{
		for(col = 5; col<13; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = MAGENTA;
		}
	}
	for (row = 4+2; row<6+2; row++)
	{
		for(col = 11; col<13; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = MAGENTA;
		}
	}
	for (row = 6+2; row<10+2; row++)
	{
		for(col = 9; col<11; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = MAGENTA;
		}
	}
	for (row = 10+2; row<14+2; row++)
	{
		for(col = 7; col<9; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = MAGENTA;
		}
	}
}

void fill_19x19_eight(unsigned int top, unsigned int left)
{
	int col, row;
	for (row = 4; row<6; row++)
	{
		for(col = 6; col<12; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = LIGHT_GREY;
		}
	}
	for (row = 6; row<9; row++)
	{
		for(col = 4; col<6; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = LIGHT_GREY;
		}
	}
	for (row = 6; row<9; row++)
	{
		for(col = 12; col<14; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = LIGHT_GREY;
		}
	}
	for (row = 9; row<11; row++)
	{
		for(col = 6; col<12; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = LIGHT_GREY;
		}
	}
	for (row = 11; row<15; row++)
	{
		for(col = 4; col<6; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = LIGHT_GREY;
		}
	}
	for (row = 11; row<15; row++)
	{
		for(col = 12; col<14; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = LIGHT_GREY;
		}
	}
	for (row = 15; row<17; row++)
	{
		for(col = 6; col<12; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = LIGHT_GREY;
		}
	}
}

void fill_19x19_bomb(unsigned int top, unsigned int left)
{
	int col, row;
	for (row = 2; row<3; row++)
	{
		for(col = 11; col<13; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = YELLOW;
		}
	}
	BG_MAP_RAM_SUB(0)[256*(3+top)+(11+left)] = LIGHT_GREY;
	BG_MAP_RAM_SUB(0)[256*(4+top)+(10+left)] = LIGHT_GREY;
	BG_MAP_RAM_SUB(0)[256*(5+top)+(10+left)] = LIGHT_GREY;
	BG_MAP_RAM_SUB(0)[256*(7+top)+(10+left)] = WHITE;
	BG_MAP_RAM_SUB(0)[256*(7+top)+(11+left)] = WHITE;
	BG_MAP_RAM_SUB(0)[256*(8+top)+(10+left)] = WHITE;

		for(col = 8; col<12; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(6+top)+(col+left)] = BLACK;
		}
	for (row = 7; row<11; row++)
	{
		for(col = 7; col<10; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = BLACK;
		}
	}
	for (row = 8; row<11; row++)
	{
		for(col = 11; col<14; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] =	BLACK ;
		}
	}
	BG_MAP_RAM_SUB(0)[256*(7+top)+(12+left)] = BLACK;
	for (row = 8; row<11; row++){
		BG_MAP_RAM_SUB(0)[256*(row+top)+(6+left)] = BLACK;
	}
	for (row = 9; row<11; row++){
		BG_MAP_RAM_SUB(0)[256*(row+top)+(10+left)] = BLACK;

	}
		for(col = 7; col<13; col++){
				BG_MAP_RAM_SUB(0)[256*(11+top)+(col+left)] = BLACK;
		}
		for(col = 8; col<11; col++){
				BG_MAP_RAM_SUB(0)[256*(12+top)+(col+left)] = BLACK;
		}
}

void fill_19x19_flag(unsigned int top, unsigned int left)
{
	int col, row;
	for (row = 4-2; row<13-2; row++){
		for(col = 10; col<12; col++){
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = RED;
		}
	}
	for (row = 5-2; row<12-2; row++){
		for(col = 8; col<10; col++)	{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = RED;
		}
	}
	for (row = 6-2; row<11-2; row++)
	{
		for(col = 6; col<8; col++)
		{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] =	RED ;
		}
	}
	for (row = 7-2; row<10-2; row++){
		for(col = 4; col<6; col++){
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] =	RED ;
		}
	}
	for (col = 2; col<4; col++){
		BG_MAP_RAM_SUB(0)[256*(8-2+top)+(col+left)] = RED;
	}
	for (row = 13-2; row<16-2; row++){
		for(col = 10; col<12; col++){
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] =	BLACK;
		}
	}
	for(col = 7; col<15; col++){
			BG_MAP_RAM_SUB(0)[256*(16-2+top)+(col+left)] = BLACK;
	}
	for(col = 5; col<17; col++){
			BG_MAP_RAM_SUB(0)[256*(17-2+top)+(col+left)] = BLACK;
	}
}

void fill_19x19_no_flag(unsigned int top, unsigned int left)
{
	int col, row,i;
	for (row = 4-2; row<13-2; row++){
		for(col = 10; col<12; col++){
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = RED;
		}
	}
	for (row = 5-2; row<12-2; row++){
		for(col = 8; col<10; col++){
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = RED;
		}
	}
	for (row = 6-2; row<11-2; row++){
		for(col = 6; col<8; col++)	{
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] =	RED ;
		}
	}
	for (row = 7-2; row<10-2; row++){
		for(col = 4; col<6; col++){
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] =	RED ;
		}
	}
	for (col = 2; col<4; col++){
		BG_MAP_RAM_SUB(0)[256*(8-2+top)+(col+left)] = RED;
	}
	for (row = 13-2; row<16-2; row++){
		for(col = 10; col<12; col++){
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] =	BLACK;
		}
	}
	for(col = 7; col<15; col++){
			BG_MAP_RAM_SUB(0)[256*(16-2+top)+(col+left)] = BLACK;
	}
	for(col = 5; col<17; col++){
			BG_MAP_RAM_SUB(0)[256*(17-2+top)+(col+left)] = BLACK;
	}
	row = 3;
	col = 3;
	i =0;
	while (i<= 11){
		BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] =BLACK;
		row ++;
		col ++;
		i ++;
	}
	row = 4;
	col = 3;
	i = 0;
	while (i<= 11){
		BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] =BLACK;
		row ++;
		col ++;
		i ++;
	}
	row = 3;
	col = 15;
	i = 0;
	while (i<= 11){
		BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] =BLACK;
		row ++;
		col --;
		i ++;
	}
	row = 3;
	col = 14;
	i = 0;
	while (i<= 11){
	BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] =BLACK;
		row ++;
		col --;
		i ++;
	}

}
void fill_19x19_sound (unsigned int top, unsigned int left)
{
	int col, row;
	for (row = 6; row<11; row++){
		for(col = 3; col<6; col++){
			BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = WHITE;
		}
	}
	for (row = 5; row<12; row++){
			BG_MAP_RAM_SUB(0)[256*(row+top)+(7+left)] =WHITE;
	}
	for (row = 4; row<13; row++){
			BG_MAP_RAM_SUB(0)[256*(row+top)+(8+left)] =WHITE;
	}
	for (row = 3; row<14; row++){
			BG_MAP_RAM_SUB(0)[256*(row+top)+(9+left)] =WHITE;
	}
	BG_MAP_RAM_SUB(0)[256*(6+top)+(11+left)] = 	WHITE;
	BG_MAP_RAM_SUB(0)[256*(4+top)+(13+left)] = WHITE;
	BG_MAP_RAM_SUB(0)[256*(5+top)+(14+left)] = WHITE;
	BG_MAP_RAM_SUB(0)[256*(10+top)+(11+left)] = WHITE;
	BG_MAP_RAM_SUB(0)[256*(12+top)+(13+left)] = WHITE;
	BG_MAP_RAM_SUB(0)[256*(11+top)+(14+left)] = WHITE;
	for (row = 7; row<10; row++){
			BG_MAP_RAM_SUB(0)[256*(row+top)+(12+left)] =WHITE;
	}
	for (row = 6; row<11; row++){
			BG_MAP_RAM_SUB(0)[256*(row+top)+(15+left)] =WHITE;
	}

}
void fill_19x19_no_sound (unsigned int top, unsigned int left)
{
	int col, row,i;
	for (row = 6; row<11; row++){
		for(col = 3; col<6; col++){
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = WHITE;
		}
	}
	for (row = 5; row<12; row++){
			BG_MAP_RAM_SUB(0)[256*(row+top)+(7+left)] =WHITE;
	}
	for (row = 4; row<13; row++){
			BG_MAP_RAM_SUB(0)[256*(row+top)+(8+left)] =WHITE;
	}
	for (row = 3; row<14; row++){
			BG_MAP_RAM_SUB(0)[256*(row+top)+(9+left)] =WHITE;
	}
	BG_MAP_RAM_SUB(0)[256*(6+top)+(11+left)] = 	WHITE;
	BG_MAP_RAM_SUB(0)[256*(4+top)+(13+left)] = WHITE;
	BG_MAP_RAM_SUB(0)[256*(5+top)+(14+left)] = WHITE;
	BG_MAP_RAM_SUB(0)[256*(10+top)+(11+left)] = WHITE;
	BG_MAP_RAM_SUB(0)[256*(12+top)+(13+left)] = WHITE;
	BG_MAP_RAM_SUB(0)[256*(11+top)+(14+left)] = WHITE;
	for (row = 7; row<10; row++){
			BG_MAP_RAM_SUB(0)[256*(row+top)+(12+left)] =WHITE;
	}
	for (row = 6; row<11; row++){
			BG_MAP_RAM_SUB(0)[256*(row+top)+(15+left)] =WHITE;
	}
	row = 3;
	col = 3;
	i =0;
	while (i<= 11){
		BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] =BLACK;
		row ++;
		col ++;
		i ++;
	}
	row = 4;
	col = 3;
	i = 0;
	while (i<= 11){
		BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] =BLACK;
		row ++;
		col ++;
		i ++;
	}
	row = 3;
	col = 15;
	i = 0;
	while (i<= 11){
		BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] =BLACK;
		row ++;
		col --;
		i ++;
	}
	row = 3;
	col = 14;
	i = 0;
	while (i<= 11){
		BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] =BLACK;
		row ++;
		col --;
		i ++;
	}

}

void fill_19x19_stop(unsigned int top, unsigned int left)
{
	int col, row;
	for (row = 5; row<14; row++){
		for(col = 5; col<14; col++){
			BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = BLACK;
		}
	}
}

void fill_19x19_smiley_face(unsigned int top, unsigned int left)
{
	int row,col;
	for (row = 7; row<12; row++){
			BG_MAP_RAM_SUB(0)[256*(row+top)+(2+left)] = BLACK;
	}
	for (row = 7; row<12; row++){
			BG_MAP_RAM_SUB(0)[256*(row+top)+(16+left)] = BLACK;
	}
	for (row = 5; row<7; row++){
			BG_MAP_RAM_SUB(0)[256*(row+top)+(3+left)] = BLACK;
	}
	for (row = 13; row<15; row++){
			BG_MAP_RAM_SUB(0)[256*(row+top)+(3+left)] = BLACK;
	}
	for (row = 5; row<7; row++){
			BG_MAP_RAM_SUB(0)[256*(row+top)+(15+left)] = BLACK;
	}
	for (row = 13; row<15; row++){
			BG_MAP_RAM_SUB(0)[256*(row+top)+(15+left)] = BLACK;
	}
	BG_MAP_RAM_SUB(0)[256*(4+top)+(4+left)] = 	BLACK;
	BG_MAP_RAM_SUB(0)[256*(4+top)+(14+left)] = 	BLACK;
	BG_MAP_RAM_SUB(0)[256*(14+top)+(4+left)] = 	BLACK;
	BG_MAP_RAM_SUB(0)[256*(14+top)+(14+left)] = BLACK;
	for(col = 5; col<7; col++){
			BG_MAP_RAM_SUB(0)[256*(3+top)+(col+left)] = BLACK;
	}
	for(col = 12; col<14; col++){
			BG_MAP_RAM_SUB(0)[256*(3+top)+(col+left)] = BLACK;
	}
	for(col = 5; col<7; col++){
			BG_MAP_RAM_SUB(0)[256*(15+top)+(col+left)] = BLACK;
	}
	for(col = 12; col<14; col++){
			BG_MAP_RAM_SUB(0)[256*(15+top)+(col+left)] = BLACK;
	}
	for(col = 7; col<12; col++){
			BG_MAP_RAM_SUB(0)[256*(2+top)+(col+left)] = BLACK;
	}
	for(col = 7; col<12; col++){
			BG_MAP_RAM_SUB(0)[256*(16+top)+(col+left)] = BLACK;
	}
	for (row = 3; row<16; row++){
		for(col = 7; col<12; col++){
			BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = YELLOW;
		}
	}	for (row = 3; row<16; row++){
		for(col = 7; col<12; col++){
			BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = YELLOW;
		}
	}
	for (row = 4; row<15; row++){
		for(col = 5; col<7; col++){
			BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = YELLOW;
		}
	}
	for (row = 4; row<15; row++){
		for(col = 12; col<14; col++){
			BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = YELLOW;
		}
	}
	for (row = 5; row<14; row++){
			BG_MAP_RAM_SUB(0)[256*(row+top)+(4+left)] =YELLOW;
	}
	for (row = 5; row<14; row++){
			BG_MAP_RAM_SUB(0)[256*(row+top)+(14+left)] = YELLOW;
	}
	for (row = 7; row<12; row++){
			BG_MAP_RAM_SUB(0)[256*(row+top)+(3+left)] = YELLOW;
	}
	for (row = 7; row<12; row++){
			BG_MAP_RAM_SUB(0)[256*(row+top)+(15+left)] = YELLOW;
	}
}

void fill_19x19_smiley_happy(unsigned int top, unsigned int left)
{
	int row,col;
	fill_19x19_smiley_face(top,left);
	BG_MAP_RAM_SUB(0)[256*(7+top)+(6+left)] = 	BLACK;
	BG_MAP_RAM_SUB(0)[256*(7+top)+(8+left)] = 	BLACK;
	BG_MAP_RAM_SUB(0)[256*(7+top)+(10+left)] = 	BLACK;
	BG_MAP_RAM_SUB(0)[256*(7+top)+(12+left)] = BLACK;
	BG_MAP_RAM_SUB(0)[256*(6+top)+(7+left)] = 	BLACK;
	BG_MAP_RAM_SUB(0)[256*(6+top)+(11+left)] = BLACK;
	for (row = 9; row<11; row++){
		for(col = 4; col<6; col++){
			BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = RED;
		}
		for(col = 13; col<15; col++){
			BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = RED;
		}
	}
	BG_MAP_RAM_SUB(0)[256*(11+top)+(6+left)] = 	BLACK;
	BG_MAP_RAM_SUB(0)[256*(12+top)+(7+left)] = 	BLACK;
	BG_MAP_RAM_SUB(0)[256*(11+top)+(12+left)] = BLACK;
	BG_MAP_RAM_SUB(0)[256*(12+top)+(11+left)] = BLACK;
	for(col = 8; col<11; col++){
			BG_MAP_RAM_SUB(0)[256*(13+top)+(col+left)] = BLACK;
	}
}

void fill_19x19_smiley_lose(unsigned int top, unsigned int left)
{
	int row,col;
	fill_19x19_smiley_face(top,left);
	BG_MAP_RAM_SUB(0)[256*(7+top)+(5+left)] = 	BLACK;
	BG_MAP_RAM_SUB(0)[256*(7+top)+(13+left)] = 	BLACK;
	BG_MAP_RAM_SUB(0)[256*(6+top)+(6+left)] = 	BLACK;
	BG_MAP_RAM_SUB(0)[256*(6+top)+(12+left)] =  BLACK;
	BG_MAP_RAM_SUB(0)[256*(12+top)+(9+left)] = 	BLACK;
	for (row = 9; row<14; row++){
		for(col = 6; col<8; col++){
			BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = LIGHT_BLUE;
		}
		for(col = 11; col<13; col++){
			BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = LIGHT_BLUE;
		}
	}
	for(col = 6; col<8; col++){
			BG_MAP_RAM_SUB(0)[256*(8+top)+(col+left)] = BLACK;
	}
	for(col = 11; col<13; col++){
			BG_MAP_RAM_SUB(0)[256*(8+top)+(col+left)] = BLACK;
	}
}

void fill_19x19_smiley_win(unsigned int top, unsigned int left)
{
	int row,col;
	fill_19x19_smiley_face(top,left);

}

