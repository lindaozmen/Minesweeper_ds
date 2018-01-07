/*
 *	Implementation of graphics on main screen
 */


#include "graphic_main.h"
#include "up.h"
#include "upp.h"
#include "upwithoutB.h"
#include "timer.h"


void configureGraphics_Main_Up()
{
	VRAM_A_CR = VRAM_ENABLE | VRAM_A_MAIN_BG;
	// Configure the engine in Mode 5 and use the BG3
	REG_DISPCNT = MODE_5_2D | DISPLAY_BG3_ACTIVE;
	// Configure background BG3 in extended rotoscale mode using 8 bit pixels and "0" for the base address
	BGCTRL[3] = BG_BMP_BASE(0)| BG_BMP8_256x256;

	// Transfer image bitmap and palette to the corresponding memory locations
	swiCopy(upBitmap,BG_GFX,upBitmapLen/2);
	swiCopy(upPal,BG_PALETTE,upPalLen/2);

	// Set up affine matrix
	REG_BG3PA = 256;
	REG_BG3PC = 0;
	REG_BG3PB = 0;
	REG_BG3PD = 256;
}



