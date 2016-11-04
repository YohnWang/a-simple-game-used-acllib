#include "acllib.h"
int Cycle=1;
int CouldPlay=1;
int SoundEffect=1;
//this function is about background sound
//maybe the name is wrong
void soundDriver(const char *sndname,ACL_Sound *bgm)
{
    if(CouldPlay == 1)
    {
        stopSound(*bgm);
        loadSound(sndname,bgm);
        playSound(*bgm,Cycle);
    }
    else
    {
        stopSound(*bgm);
    }
}

void soundEft(const char * eftname)
{
    static ACL_Sound eft=0;
    if(SoundEffect==1)
    {
        stopSound(eft);
        loadSound(eftname,&eft);
        playSound(eft,0);     //just play once
    }
    else
    {

    }
}










