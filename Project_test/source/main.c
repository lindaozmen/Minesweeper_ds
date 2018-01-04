/*
 * Template Nintendo DS
 * May 2011
 */

#include <nds.h>
#include <stdio.h>
#include <sys/dir.h>
#include <fat.h>
#include <dirent.h>
#include "P_Controls.h"
#include "P_Score.h"
#include "graphic_main.h"
#include "graphic_sub.h"
#include "sound.h"


int main(void) {
	fatInitDefault();
	consoleDemoInit();
	Audio_Init();
    configureGraphics_Main_Up();
	configureGraphics_Sub();


    while(1)
    {
    	handleInput();
    	swiWaitForVBlank();
    }
}

