/*
 *	File Name	:	graphic_sub.h
 *	Author		:
 *	Last Update :	23.12.2017
 *
 *	Header file of graphics on sub screen
 */

#ifndef GRAPHIC_SUB_H_
#define GRAPHIC_SUB_H_
#include <nds.h>
#include "bomb.h"

u16* gfx;
void configureGraphics_Sub(); // To configure the SUB engine
void configureSprites(); //To configure the sprites (Bomb + Numbers)
void configBG2_Sub();
void fill_19x19_button(unsigned int top, unsigned int left, u16 out, u16 in); //The buttons
void fill_sub(); // Configure the sub engine with all the 100 buttons
void fillScreen_Sub(u16 color); //Initialize with a color

/************************
 * Macros for the colors
 ***********************/
#define	RED ARGB16(1,31,0,0)
#define GREEN ARGB16(1,0,31,0)
#define	BLUE ARGB16(1,0,0,31)
#define	YELLOW ARGB16(1,31,31,0)
#define	LIGHT_BLUE ARGB16(1,0,31,31)
#define	WHITE ARGB16(1,31,31,31)
#define	BLACK ARGB16(1,0,0,0)
#define GREY ARGB16(1,10,10,10)
#define LIGHT_GREY ARGB16(1,20,20,20)


#endif /* GRAPHIC_SUB_H_ */
