#ifndef INITCONSTANT_H_INC
#define INITCONSTANT_H_INC

#define DEBUG
//extern const int WndWidth;
//extern const int WndHeight;
//extern const int BlockLength;
extern char FrameName[];
extern const char * StartPic;
extern const char * MenuPic;
extern const char * ThemePic;
extern const char * HelpPic;
extern const char * SetPic;
extern const char * GamePic;
extern const char * BtnStartGamePic;
extern const char * BtnOptions;
extern const char * BtnHelp;
extern const char * BtnExit;
extern const char * BtnSetMscPlay;
extern const char * BtnSetMscQuiet;
extern const char * BtnSetBack;
extern const char * BtnArrowLeft;
extern const char * BtnArrowRight;
extern const char * BtnBgmOff;
extern const char * BtnBgmOn;
extern const char * BtnEftOn;
extern const char * BtnEftOff;
extern const char * Btnmetalmax;
extern const char * Btnotomad;
extern const char * BtnGameBack;
extern const char * Btnrestart;

extern char MenuMsc[];
extern char HelpMsc[];
extern char SetMsc[];
extern char GameMsc[];
extern char GameEft1[];
extern char GameEft2[];
extern char GameEft3[];
extern char GameEft4[];
extern char GameEft5[];
extern char GameEft6[];
extern char GameEft7[];
extern char MusicDirectory[];




enum {WndWidth=760,WndHeight=480,BlockLength=40};
enum {TimerMain=0,StartTimerUseOnce=9};

enum {StartWndId=0,MenuWndId=1,GameWndId=2,
        SetWndId=3,HelpWndId=4};


//button size
enum {BtnWidth=200,BtnHeight=50,BtnDis=20};

//button position of the menu background
enum {StartLx=270,StartLy=190,StartRx=StartLx+BtnWidth,StartRy=StartLy+BtnHeight,
      SetLx=StartLx,SetLy=StartLy+BtnHeight+BtnDis,SetRx=SetLx+BtnWidth,SetRy=SetLy+BtnHeight,
      HelpLx=SetLx,HelpLy=SetLy+BtnHeight+BtnDis,HelpRx=HelpLx+BtnWidth,HelpRy=HelpLy+BtnHeight,
      ExitLx=HelpLx,ExitLy=HelpLy+BtnHeight+BtnDis,ExitRx=ExitLx+BtnWidth,ExitRy=ExitLy+BtnHeight};

//button position of the set background
enum {BgmLx=270,BgmLy=190,BgmRx=BgmLx+BtnWidth,BgmRy=BgmLy+BtnHeight,
      EftLx=BgmLx,EftLy=BgmLy+BtnHeight+BtnDis,EftRx=EftLx+BtnWidth,EftRy=EftLy+BtnHeight,
      StyLx=EftLx,StyLy=EftLy+BtnHeight+BtnDis,StyRx=StyLx+BtnWidth,StyRy=StyLy+BtnHeight,
      BackLx=ExitLx,BackLy=ExitLy,BackRx=BackLx+BtnWidth,BackRy=BackLy+BtnHeight};

//position of game
enum {GameZoneLx=0,GameZoneLy=0,GameZoneRx=400,GameZoneRy=400,
      GameBackLx=550,GameBackLy=400,GameBackRx=GameBackLx+BtnWidth,GameBackRy=GameBackLy+BtnHeight,
      GameRestartLx=550,GameRestartLy=330,GameRestartRx=GameRestartLx+BtnWidth,GameRestartRy=GameRestartLy+BtnHeight,

     };
#endif
