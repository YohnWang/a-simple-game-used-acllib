#include "acllib.h"
#include "initconstant.h"
#include <stdio.h>
//this code is used to start background
//now just the earth
void startWnd(int *wId)
{
    *wId=StartWndId;
    static int now=0;
    char s[100];
    sprintf(s,"picture/text/Text Wipe%.3d.jpg",now);
    ACL_Image start;
    loadImage(s,&start);

    drawPictureScale(&start,0,0,WndWidth,WndHeight);
    if(now<155)
        now+=2;
}


