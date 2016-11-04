#include "acllib.h"
#include "initconstant.h"
#include "start.h"
#include "menu.h"
#include "help.h"
#include "sound.h"
#include "set.h"
#include "game.h"



#ifdef DEBUG
#include<stdio.h>
#endif // DEBUG

static int Wnd_Id;  //window id
static ACL_Sound Bgd_Snd;  // background music

void timerDriver(int timerId)
{
    switch (timerId)
    {
    case StartTimerUseOnce: //just once ,be used to start
        startMainMenu(&Wnd_Id);
        cancelTimer(StartTimerUseOnce);
        cancelTimer(TimerMain);
        //endPaint();
        soundDriver(MenuMsc,&Bgd_Snd);
        /*
        loadSound(MenuMsc,&Bgd_Snd);
        playSound(Bgd_Snd,0);*/
        break;
    case TimerMain:

        startWnd(&Wnd_Id);
        break;
    default:
#ifdef DEBUG
        printf("This case will never be choosen!\n"
               "If happened,it is in timerDrive!\n");
#endif // DEBUG
        break;
    }
}

void mouseDriver(int x,int y,int button,int event)
{
#ifdef DEBUG
    printf("x=%d y=%d button=%d event=%d  "
           "window ID=%d\n",
           x,y,button,event,Wnd_Id);
#endif
    switch (Wnd_Id)
    {
    case MenuWndId:
        goto MENU;
    case HelpWndId:
        goto HELP;
    case SetWndId:
        goto SET;
    case GameWndId:
        goto GAME;
    }
    return ; //notice ! must be here.

MENU:
    if(x>ExitLx && x<ExitRx && y>ExitLy && y<ExitRy && button==1 && event ==0)
    {
        exit(0);
    }
    else if(x>HelpLx && x<HelpRx && y>HelpLy && y<HelpRy && button==1 && event ==0)
    {
        startHelp(&Wnd_Id);
        soundDriver(HelpMsc,&Bgd_Snd);
        /*
        stopSound(Bgd_Snd);
        loadSound(HelpMsc,&Bgd_Snd);
        playSound(Bgd_Snd,0);*/
    }
    else if(x>SetLx && x<SetRx && y>SetLy && y<SetRy && button==1 && event ==0)
    {
        startSet(&Wnd_Id);
        soundDriver(SetMsc,&Bgd_Snd);
    }
    else if(x>StartLx && x<StartRx && y>StartLy && y<StartRy && button==1 && event ==0)
    {
        startGame(&Wnd_Id);
        soundDriver(GameMsc,&Bgd_Snd);
    }
    return ;

HELP:
    if(button==1 && event==0)
    {
        goto RETMENU;
        /*
        stopSound(Bgd_Snd);
        loadSound(MenuMsc,&Bgd_Snd);
        playSound(Bgd_Snd,0);*/
    }
    return ;

SET:
    if(x>BackLx && x<BackRx && y>BackLy && y<BackRy && button==1 && event ==0)//back
    {
        goto RETMENU;
    }
    else if(x>BgmLx && x<BgmRx && y>BgmLy && y<BgmRy && button==1 && event ==0) //bgm
    {
        /*
        if(CouldPlay==1)
        {
            CouldPlay=0;
        }
        else
        {
            CouldPlay=1;
        }*/
        CouldPlay==0?(CouldPlay=1):(CouldPlay=0);

        startSet(&Wnd_Id);
        soundDriver(SetMsc,&Bgd_Snd);

        setSoundNow();
    }
    else if(x>EftLx && x<EftRx && y>EftLy && y<EftRy && button==1 && event ==0)
    {
        SoundEffect==0?(SoundEffect=1):(SoundEffect=0);
        startSet(&Wnd_Id);
        setSoundNow();
    }
    else if(x>StyLx && x<StyRx && y>StyLy && y<StyRy && button==1 && event ==0)
    {
        setStyleNow();
        startSet(&Wnd_Id);
        soundDriver(SetMsc,&Bgd_Snd);
    }
    return ;

GAME:

    if(x>GameZoneLx && x<GameZoneRx && y>GameZoneLy && y<GameZoneRy && button==1 && event ==0)
    {
        gameDriver(x,y,button,event);
    }
    else if(x>GameBackLx && x<GameBackRx && y>GameBackLy && y<GameBackRy && button==1 && event ==0)
    {
        goto RETMENU;
    }
    else if(x>GameRestartLx && x<GameRestartRx && y>GameRestartLy && y<GameRestartRy && button==1 && event ==0)
    {
        gameRestart();
    }

    return ;

RETMENU:  //return to menu
    startMainMenu(&Wnd_Id);
    soundDriver(MenuMsc,&Bgd_Snd);
    return ;
}
int Setup()
{
    setAll();
    initWindow(FrameName,DEFAULT,DEFAULT,WndWidth,WndHeight);
#ifdef DEBUG
    initConsole();
#endif // DEBUG
    //startWnd(&Wnd_Id);
    //beginPaint();
    startTimer(TimerMain,1);
    startTimer(StartTimerUseOnce,5000);
    registerTimerEvent(timerDriver);
    registerMouseEvent(mouseDriver);
    return 0;
}
