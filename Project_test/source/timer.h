/*
 *	File Name	:	timer.h
 *	Author		:
 *	Last Update :	23.12.2017
 *
 *	Header file of time in project
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <nds.h>
#include <stdio.h>
#include "graphic_sub.h"
#include "graphic_main.h"
#include "game.h"
#include "string.h"
#include "numbers.h"
#include "up.h"
#include "P_Controls.h"

//Define to use paletes easily
#define PALETTE(x)	(x << 12)



/************************
 * Macros for the colors
 ***********************/
#define	RED ARGB16(1,31,0,0)
#define PINK_TIMER ARGB16(1,27,13,13)
#define PINK ARGB16(1,31,22,22)
#define LIGHTYELLOW ARGB16(1,31,31,27);
#define GREEN ARGB16(1,0,31,0)
#define DARK_GREEN ARGB16(1,0,25,0)
#define	BLUE ARGB16(1,0,0,31)
#define DARK_BLUE ARGB16(1,0,0,15)
#define DARK_RED ARGB16(1,15,0,0)
#define	YELLOW ARGB16(1,31,31,0)
#define	LIGHT_BLUE ARGB16(1,0,31,31)
#define	WHITE ARGB16(1,31,31,31)
#define	BLACK ARGB16(1,0,0,0)
#define GREY ARGB16(1,10,10,10)
#define LIGHT_GREY ARGB16(1,20,20,20)
#define MAGENTA ARGB16(1,31,0,31)

void ISR_VBlank(); //To Refresh the screen (MAIN)

void ISR_countdown_timer(); //To increment the chrono

void initChronoDisp_Main(); //Configure the main for the chrono

void updateChronoDisp_Main(int min, int sec, int msec);

void changeColorDisp_Main(uint16 c);

void IRQ_initialize(); //Initialisation of the counter

void stopTimer(); //Disables the timer and resets it

#endif /* TIMER_H_ */
