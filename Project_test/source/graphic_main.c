/*
 *	File Name	:	graphic_main.c
 *	Author		:
 *	Last Update :	23.12.2017
 *
 *	Implementation of graphics on main screen
 */


#include "graphic_main.h"
#include "up.h"
#include "timer.h"


void configureGraphics_Main_Up()
{
	VRAM_A_CR = VRAM_ENABLE | VRAM_A_MAIN_BG;
	// Configure the engine in Mode 5 and use the BG3
	REG_DISPCNT = MODE_5_2D | DISPLAY_BG3_ACTIVE;
	//BGCTRL[1] = BG_32x32 | BG_COLOR_256 | BG_MAP_BASE(1) | BG_TILE_BASE(0);
	// Configure background BG3 in extended rotoscale mode using 8 bit pixels and "0" for the base address
	BGCTRL[3] = BG_BMP_BASE(0)| BG_BMP8_256x256;
	// Transfer image bitmap and palette to the corresponding memory locations
	swiCopy(upBitmap,BG_GFX,upBitmapLen/2);
	swiCopy(upPal,BG_PALETTE,upPalLen/2);
	//swiCopy(numbersTiles, BG_TILE_RAM(1), numbersTilesLen/2);
	//swiCopy(numbersPal, BG_PALETTE, numbersPalLen/2);
	//IRQ_initialize();
	//irqEnable(IRQ_TIMER0);
	//BG_PALETTE[0] = ARGB16(1,0,31,31);
	//BG_PALETTE[1] = ARGB16(1,0,0,0);
	//memset(BG_MAP_RAM(0), 32,32*32*2);
	//updateChronoDisp_Main(-1,-1,-1);
	// Set up affine matrix
	REG_BG3PA = 256;
	REG_BG3PC = 0;
	REG_BG3PB = 0;
	REG_BG3PD = 256;
}



