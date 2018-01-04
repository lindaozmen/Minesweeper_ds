/*
 *	File Name	:	sound.h
 *	Author		:
 *	Last Update :	23.12.2017
 *
 *	Implementation of sound in project
 */
#include "sound.h"

void Audio_Init()
{
	//Init the sound library
	mmInitDefaultMem((mm_addr)soundbank_bin);
	//Load module
	mmLoad(MOD_INFLUENCA);
	//Load effects
	mmLoadEffect(SFX_EXPLOSION);
	mmLoadEffect(SFX_RESULT);
	mmLoadEffect(SFX_APPLAUSE);
	mmLoadEffect(SFX_WATER);
}
void Selection_Effect_Play()
{
	mmEffect(SFX_WATER);
	mmSetModuleVolume(512);
}

void Audio_PlayMusic()
{
	//Start playing music in a loop
	mmStart(MOD_INFLUENCA, MM_PLAY_LOOP);
	//Set module volume to 512
	mmSetModuleVolume(512);
}

void Explosion_Effect_Play()
{
	mmEffect(SFX_EXPLOSION);
	mmSetModuleVolume(512);
}

void stopMusic()
{
	mmStop();
}
void Result_Effect_Play(){
	mmEffect(SFX_RESULT);
	mmSetModuleVolume(512);
}
void Applause_Effect_Play(){
	mmEffect(SFX_APPLAUSE);
	mmSetModuleVolume(512);
}
