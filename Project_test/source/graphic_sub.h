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

//u16* mapMemory;

void configureGraphics_Sub();
void configBG2_Sub();
void fill_32x32_button(unsigned int top, unsigned int left, u16 out, u16 in);
void fill_sub();

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
#define GREY ARGB16(1,16,16,16)


#endif /* GRAPHIC_SUB_H_ */
