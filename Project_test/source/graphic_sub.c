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

void configureSprites() {
	//Set up memory bank to work in sprite mode (offset since we are using VRAM A for backgrounds)
	VRAM_D_CR = VRAM_ENABLE | VRAM_D_SUB_SPRITE;

	//Initialize sprite manager and the engine
	oamInit(&oamSub, SpriteMapping_2D, false);

	//Allocate space for the graphic to show in the sprite
	gfx = oamAllocateGfx(&oamSub, SpriteSize_16x16, SpriteColorFormat_256Color);

	//Copy data for the graphic (palette and bitmap)
	swiCopy(bombPal, SPRITE_PALETTE, bombPalLen/2);
	swiCopy(bombTiles, gfx, bombTilesLen/2);
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

void fillScreen_Sub(u16 color){
	//Fill the buffer of the screen with the given input color
	int i,j;
	for(i = 0; i<192; i++){
		for(j = 0;j<256; j++){
			BG_BMP_RAM_SUB(0)[i*256+j] = color;
		}
}
}

void fill_19x19_button(unsigned int top, unsigned int left, u16 out, u16 in) {
	//Sanity check. If the coordinates are not correct (the button will be
	//partially or fully outside the screen) return without doing anything
	if (top > 192 || left > 220) return;

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

void fill_sub(){
	int i,j;
	for ( j = 32; j<225; j+=19)
	{
		for(i = 0; i<192; i+=19)
		{
			fill_19x19_button(i, j, GREY, LIGHT_GREY);
		}
	}
}




