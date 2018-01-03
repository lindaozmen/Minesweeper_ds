/*
 *	File Name	:	timer.c
 *	Author		:
 *	Last Update :	23.12.2017
 *
 *	Implementation of time in project
 */

#include "timer.h"

uint32 sec_init = 0; // Reset
// Current value of the countdown timer (in milli-sec, sec and min)
uint32 min = 0, sec = 0, msec = 0;

void printDigit(u16* map, int number, int x, int y)
{
	int i,j;
	if(number < 10)
		for(i = 0; i<8;i++)
			for(j = 0; j<4; j++)
				if(number >= 0)
					map[(i + y)*32+j+x] = (u16)(i*4+j)+32*number;
				else
					map[(i + y)*32+j+x] = 32;
	if(number == 10)
		for(i = 0; i<8;i++)
			for(j = 0; j<2; j++)
				map[(i + y)*32+j+x] = (u16)(i*4+j)+32*10+2;
	if(number==11)
		for(i = 0; i<8;i++)
			for(j = 0; j<2; j++)
				map[(i + y)*32+j+x] = (u16)(i*4+j)+32*10;
}

void updateChronoDisp(u16* map,int min, int sec, int msec)
{
	int x = 0, y = 0;
	int number;

	/*****MINUTES******/
	number = min;
	if(min > 59) min = number = -1;
	//First digit
	x = 0; y = 8;
	if(min>=0) number = min/10;
	printDigit(map, number, x,y);
	//Second digit
	x = 4; y = 8;
	if(min>=0) number = min %10;
	printDigit(map, number, x,y);

	/*****POINTS******/
	x = 8; y = 8;
	number = 10;
	printDigit(map, number, x,y);

	/*****SECONDS******/
	number = sec;
	if(sec > 59) sec = number = -1;
	//First digit
	x = 10; y = 8;
	if(sec>=0) number = sec / 10;
	printDigit(map, number, x,y);
	//Second digit
	x = 14; y = 8;
	if(sec>=0) number = sec % 10;
	printDigit(map, number, x,y);

	/*****POINT MSEC******/
	x = 18; y = 8;
	number = 11;
	printDigit(map, number, x,y);

	/*****M.SECONDS******/
	number = msec;
	if(msec > 999) msec = number = -1;
	//First digit
	x = 20; y = 8;
	if(msec>=0) number = msec / 100;
	printDigit(map, number, x,y);

	//Second digit
	x = 24; y = 8;
	if(msec>=0) number = (msec % 100) / 10;
	printDigit(map, number, x,y);

	//Third digit
	x = 28; y = 8;
	if(msec>=0) number = (msec % 10) % 10;
	printDigit(map, number, x,y);
}

void updateChronoDisp_Main(int min, int sec, int msec)
{
	changeColorDisp_Main(BLACK);
	updateChronoDisp(BG_MAP_RAM(0), min,sec,msec);
}

void ISR_countdown_timer()
{
		msec = (msec + 1) % 1000;
		if(!msec)
		{
			sec = (sec + 1) % 60;
			if(!sec)
				min++;
		}
}

void ISR_VBlank()
{
	// Update the time value printed on the MAIN screen
	updateChronoDisp_Main(min, sec, msec);
}

void stopTimer()
{
	min = 0;
	sec = 0;
	msec = 0;
}

void IRQ_initialize()
{
	// Timer 0 will trigger an interrupt every 1 ms
	TIMER0_DATA = TIMER_FREQ_1024(1000);
	TIMER0_CR = TIMER_DIV_1024 | TIMER_IRQ_REQ | TIMER_ENABLE;

	irqSet(IRQ_TIMER0, &ISR_countdown_timer);

	// Main screen refreshing:
	// Associate the ISR (ISR_VBlank) to the interrupt line VBLANK and enable it
	irqSet(IRQ_VBLANK, &ISR_VBlank);
	irqEnable(IRQ_VBLANK);

}

void changeColorDisp_Main(uint16 c)
{
	BG_PALETTE[0] = c;
}

void initChronoDisp_Main()
{
	VRAM_A_CR = VRAM_ENABLE
				| VRAM_A_MAIN_BG;
	REG_DISPCNT = MODE_0_2D | DISPLAY_BG0_ACTIVE;
	BGCTRL[0] = BG_32x32 | BG_COLOR_256 | BG_MAP_BASE(0) | BG_TILE_BASE(1);

	swiCopy(numbersTiles, BG_TILE_RAM(1), numbersTilesLen);
	swiCopy(numbersPal, BG_PALETTE, numbersPalLen);
	IRQ_initialize();
	irqEnable(IRQ_TIMER0);
	BG_PALETTE[0] = ARGB16(1,0,31,31);
	BG_PALETTE[1] = ARGB16(1,0,0,0);
	memset(BG_MAP_RAM(0), 32,32*32*2);
	updateChronoDisp_Main(-1,-1,-1);
}
