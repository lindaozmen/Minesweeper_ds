/*
 *	File Name	:	graphic_main.h
 *	Author		:
 *	Last Update :	23.12.2017
 *
 *	Header file of graphics on main screen
 */


#ifndef GRAPHIC_MAIN_H_
#define GRAPHIC_MAIN_H_


#include <nds.h>
#include <string.h>


// Macros for the colors
#define	RED ARGB16(1,31,0,0)
#define DARK_GREEN ARGB16(1,0,25,0)
#define GREEN ARGB16(1,0,31,0)
#define	BLUE ARGB16(1,0,0,31)
#define	YELLOW ARGB16(1,31,31,0)
#define	LIGHT_BLUE ARGB16(1,0,31,31)
#define	WHITE ARGB16(1,31,31,31)
#define	BLACK ARGB16(1,0,0,0)

void configureGraphics_Main_Up(); //Configure the MAIN engine

#endif /* GRAPHIC_MAIN_H_ */
