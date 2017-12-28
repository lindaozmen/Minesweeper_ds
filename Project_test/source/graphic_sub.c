/*
 *	File Name	:	graphic_sub.c
 *	Author		:
 *	Last Update :	23.12.2017
 *
 *	Implementation of graphics on sub screen
 */

#include "graphic_sub.h"
/*
u8 tile[64] = {
		1,1,1,1,1,1,1,1,
		1,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,1,
		1,1,1,1,1,1,1,1
};
*/
void configureGraphics_Sub()
{
	REG_DISPCNT_SUB = MODE_5_2D | DISPLAY_BG2_ACTIVE;

	VRAM_C_CR = VRAM_ENABLE | VRAM_C_SUB_BG;

	configBG2_Sub();
/*
	BGCTRL_SUB[0] = BG_BMP_BASE(0)| BG_BMP8_256x256;

    dmaCopy(tile, &BG_TILE_RAM_SUB(0)[0], 64);

	// set up affine matrix
	REG_BG2PA_SUB = 256;
	REG_BG2PC_SUB = 256;
	REG_BG2PB_SUB = 256;
	REG_BG2PD_SUB = 256;

	BG_PALETTE_SUB[0] = WHITE;
	BG_PALETTE_SUB[1] = BLUE;

	//Set the pointer mapMemory to the RAM location of the chosen MAP_BASE
	//Hint: use the macro BG_MAP_RAM
	mapMemory = (u16*)BG_MAP_RAM_SUB(25);
	for (i = 0; i<32; i++)
		for(j = 0; j<32; j++)
		{
			BG_MAP_RAM_SUB(1)[32*(i)+j] = 0;
			BG_MAP_RAM_SUB(1)[32*(i+1)+j] = 0;
		    BG_MAP_RAM_SUB(1)[32*(i)+j +1] = 0;
		    BG_MAP_RAM_SUB(1)[32*(i+1)+j+1] = 0;
		}

*/
}

void configBG2_Sub(){
	BGCTRL_SUB[2] = BG_BMP_BASE(0) | BG_BMP16_256x256;

    // Set up affine matrix
    REG_BG2PA_SUB = 256;
    REG_BG2PC_SUB = 0;
    REG_BG2PB_SUB = 0;
    REG_BG2PD_SUB = 256;
}

void fill_32x32_button(unsigned int top, unsigned int left, u16 out, u16 in) {
	//Sanity check. If the coordinates are not correct (the button will be
	//partially or fully outside the screen) return without doing anything
	//...TO COMPLETE EXERCISE 4
	if (top > 160 || left > 224) return;

	//Draw the button of 32x32 pixels given the top left corner and the outside
	//color (out) and the inside color (in)
	//...TO COMPLETE EXERCISE 4
	int col, row;
	/*int row,col,row1,col1;
	for (row = top; row <= (top+32);row++)
		for (col = left; col < left + 32; col ++)
			BG_BMP_RAM_SUB(0)[row*(col+32) + col ] = out;
	for (row1 = (top+4); row1 <= (top-4);row1++)
				for (col1 =(left+4); col1 < (left + 32-4); col1 ++)
					BG_BMP_RAM_SUB(0)[row1*(col1+32-4) + col1 ] = in;*/
	for (row = 0; row<32; row++)
		for(col = 0; col<32; col++)
			if((row <4) || (row>= 28) || (col<4) || (col >= 28))
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = out;
			else
				BG_MAP_RAM_SUB(0)[256*(row+top)+(col+left)] = in;

}

void fill_sub(){
	int i,j;
	for (j = 0; j<256; j+=32 )
	{
		for(i = 0; i<192; i+=32)
		{
			fill_32x32_button(i, j, BLACK, GREY);
		}
	}


}


