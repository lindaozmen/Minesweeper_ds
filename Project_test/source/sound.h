/*
 *	Header file of sound in project
 */


#include <nds.h>
#include <stdio.h>
#include "soundbank.h"
#include "soundbank_bin.h"
#include <maxmod9.h>


void Audio_Init(); // Initialisation of the sound
void Audio_PlayMusic(); //PLay the music in a loop
void stopMusic(); //Stops the music
void Explosion_Effect_Play();
void Result_Effect_Play();
void Selection_Effect_Play();
void Applause_Effect_Play();

