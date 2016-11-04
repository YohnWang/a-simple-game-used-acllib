#include "initconstant.h"
#include "acllib.h"
void startMainMenu(int *wId)
{
    *wId=MenuWndId;
    ACL_Image pic;
    loadImage(MenuPic,&pic);
    drawPictureScale(&pic,0,0,WndWidth,WndHeight); //background

    ACL_Image btn1,btn2,btn3,btn4;
    loadImage(BtnStartGamePic,&btn1);
    loadImage(BtnOptions,&btn2);
    loadImage(BtnHelp,&btn3);
    loadImage(BtnExit,&btn4);
    beginPaint();
    putImageScale(&btn1,StartLx,StartLy,BtnWidth,BtnHeight);//start game
    putImageScale(&btn2,SetLx,SetLy,BtnWidth,BtnHeight); //options
    putImageScale(&btn3,HelpLx,HelpLy,BtnWidth,BtnHeight); //help
    putImageScale(&btn4,ExitLx,ExitLy,BtnWidth,BtnHeight); //exit
    endPaint();
}
