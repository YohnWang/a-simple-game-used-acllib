#include "initconstant.h"
#include "acllib.h"
#include "sound.h"
#include <stdio.h>
#include <string.h>

void setAll() //initialize
{
    FILE *fp_name;
    char s[100];
    fp_name=fopen("init/name.ini","r");
    fscanf(fp_name,"%s",s);
    sprintf(FrameName,"%s v0.9",s);
    fclose(fp_name);

    FILE *fp_music;
    fp_music=fopen("init/music.ini","r");
    fscanf(fp_music,"%s",MusicDirectory);
    fclose(fp_music);

    //set bgm style
    sprintf(MenuMsc,"music/%s/menu.wav",MusicDirectory);
    sprintf(HelpMsc,"music/%s/help.wav",MusicDirectory);
    sprintf(SetMsc ,"music/%s/set.wav" ,MusicDirectory);
    sprintf(GameMsc,"music/%s/game.wav",MusicDirectory);
    sprintf(GameEft1,"music/%s/eft1.wav",MusicDirectory);
    sprintf(GameEft2,"music/%s/eft2.wav",MusicDirectory);
    sprintf(GameEft3,"music/%s/eft3.wav",MusicDirectory);
    sprintf(GameEft4,"music/%s/eft4.wav",MusicDirectory);
    sprintf(GameEft5,"music/%s/eft5.wav",MusicDirectory);
    sprintf(GameEft6,"music/%s/eft6.wav",MusicDirectory);
    sprintf(GameEft7,"music/%s/eft7.wav",MusicDirectory);

    FILE *fp_sound;
    fp_sound=fopen("init/sound.ini","r");

    fscanf(fp_sound,"%d%d%d",&Cycle,&CouldPlay,&SoundEffect);
    fclose(fp_sound);
}

void setSoundNow()
{
    FILE *fp_sound;
    fp_sound=fopen("init/sound.ini","w");
    fprintf(fp_sound,"%d %d %d",Cycle,CouldPlay,SoundEffect);
    fclose(fp_sound);
}

void setStyleNow()
{
    FILE *fp_style;
    fp_style=fopen("init/music.ini","w");
    if(strcmp(MusicDirectory,"otomad")==0)
    {
        fprintf(fp_style,"metalmax");
        strcpy(MusicDirectory,"metalmax");
    }
    else if(strcmp(MusicDirectory,"metalmax")==0)
    {
        fprintf(fp_style,"otomad");
        strcpy(MusicDirectory,"otomad");
    }
    fclose(fp_style);
    //change bgm and effect style.
    sprintf(MenuMsc,"music/%s/menu.wav",MusicDirectory);
    sprintf(HelpMsc,"music/%s/help.wav",MusicDirectory);
    sprintf(SetMsc ,"music/%s/set.wav" ,MusicDirectory);
    sprintf(GameMsc,"music/%s/game.wav",MusicDirectory);
    sprintf(GameEft1,"music/%s/eft1.wav",MusicDirectory);
    sprintf(GameEft2,"music/%s/eft2.wav",MusicDirectory);
    sprintf(GameEft3,"music/%s/eft3.wav",MusicDirectory);
    sprintf(GameEft4,"music/%s/eft4.wav",MusicDirectory);
    sprintf(GameEft5,"music/%s/eft5.wav",MusicDirectory);
    sprintf(GameEft6,"music/%s/eft6.wav",MusicDirectory);
    sprintf(GameEft7,"music/%s/eft7.wav",MusicDirectory);
}

void startSet(int *wId)
{
    *wId=SetWndId;
    ACL_Image pic;
    loadImage(SetPic,&pic);
    drawPictureScale(&pic,0,0,WndWidth,WndHeight);

    ACL_Image bgm,effect,style;

    if(CouldPlay==1)
    {
        loadImage(BtnBgmOn,&bgm);
    }
    else
    {
        loadImage(BtnBgmOff,&bgm);
    }
    if(SoundEffect==1)
    {
        loadImage(BtnEftOn,&effect);
    }
    else
    {
        loadImage(BtnEftOff,&effect);
    }
    if(strcmp(MusicDirectory,"otomad")==0)
    {
        loadImage(Btnotomad,&style);
    }
    else if(strcmp(MusicDirectory,"metalmax")==0)
    {
        loadImage(Btnmetalmax,&style);
    }
    ACL_Image back;
    //loadImage(BtnArrowLeft,&btn1);
    //loadImage(BtnSetMscQuiet,&btn2);
    loadImage(BtnSetBack,&back);
    beginPaint();
    //putImageTransparent(&btn1,50,50,256,256,RGB(255,255,255));
    putImageScale(&bgm,BgmLx,BgmLy,BtnWidth,BtnHeight);
    putImageScale(&effect,EftLx,EftLy,BtnWidth,BtnHeight);
    putImageScale(&style,StyLx,StyLy,BtnWidth,BtnHeight);
    putImageScale(&back,BackLx,BackLy,BtnWidth,BtnHeight);
    endPaint();

}









