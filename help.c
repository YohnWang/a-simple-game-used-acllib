#include "initconstant.h"
#include "acllib.h"
//help performance
void startHelp(int *wId)
{
    *wId=HelpWndId;
    ACL_Image pic;
    loadImage(HelpPic,&pic);
    drawPictureScale(&pic,0,0,WndWidth,WndHeight);

}
