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
	//mmLoadEffect(SFX_);

}

void Audio_PlayMusic()
{
	//Start playing music in a loop
	mmStart(MOD_INFLUENCA, MM_PLAY_LOOP);
	//Set module volume to 512 (range 0...1024) using the function mmSetModuleVolume(...)
	mmSetModuleVolume(512);
}

void Explosion_Effect_Play()
{
	mmEffect(SFX_EXPLOSION);
}

void stopMusic()
{
	mmStop();
}
void Result_Effect_Play(){
	mmEffect(SFX_RESULT);
}
