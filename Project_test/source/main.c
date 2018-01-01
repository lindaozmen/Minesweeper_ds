/*
 * Template Nintendo DS
 * May 2011
 */

#include <nds.h>
#include <stdio.h>
#include "P_Controls.h"
#include "graphic_main.h"
#include "graphic_sub.h"
#include "sound.h"


int main(void) {

	consoleDemoInit();
	Audio_Init();
    configureGraphics_Main_Up();
	configureGraphics_Sub();
	init_game(1);

    while(1)
    {
    	handleInput();
    	swiWaitForVBlank();
    }
}

