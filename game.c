#include "acllib.h"
#include "initconstant.h"
#include "sound.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
//this file is developed quickly
//many constants...

static int game_map[10][10];
static ACL_Color clr_table[20]={[10]=RED,[11]=GREEN,[12]=YELLOW,
                            [13]=BLUE,[14]=MAGENTA,
                            [0]=WHITE};

static int BlockNum;

static int Record;
static int mark=0;
/*
static const char * eft_table[]={NULL,GameEft1,GameEft1,GameEft2,GameEft2,GameEft3,GameEft3,
                                 GameEft4,GameEft5,GameEft6,GameEft1,
                                };*/
static void initGameMap(int m,int n,int a[m][n])
{
    int tab[20]={0};
    srand(time(NULL));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            int tmp;
            tmp=rand()%5+10;
            while(tab[tmp]>=25)  //each clour have 25
            {
                tmp=rand()%5+10;
            }
            tab[tmp]++;
            a[i][j]=tmp;
        }
    }
}

static void paint(int x,int y,int clr)
{

    for(int i=x;i<x+BlockLength;i++)
    {
        for(int j=y;j<y+BlockLength;j++)
            putPixel(i,j,clr_table[clr]);
    }
}
static void drawGameMap(int m,int n,int a[m][n])
{
    beginPaint();
    for(int j=0;j<m;j++)
    {
        for(int i=0;i<n;i++)
        {
            paint(i*BlockLength,j*BlockLength,a[j][i]);
        }
    }
    endPaint();
}

static void bfs(int *deep,int clr,int x,int y,int m,int n,int isVisite[m][n],int a[m][n])
{
    isVisite[y][x]=1;

    if(a[y][x]!=clr)
        return ;
    *deep=*deep+1;
    if(x>0 && isVisite[y][x-1]==0)
        bfs(deep,clr,x-1,y,m,n,isVisite,a);
    if(x<9 && isVisite[y][x+1]==0)
        bfs(deep,clr,x+1,y,m,n,isVisite,a);
    if(y>0 && isVisite[y-1][x]==0)
        bfs(deep,clr,x,y-1,m,n,isVisite,a);
    if(y<9 && isVisite[y+1][x]==0)
        bfs(deep,clr,x,y+1,m,n,isVisite,a);
    a[y][x]=0;

}
static int search(int x,int y,int m,int n,int a[m][n])
{
    int isVisite[m][n];
    int num=0;

    if(a[y][x]==0)
        return num;

    memset(isVisite,0,sizeof isVisite);
    bfs(&num,a[y][x],x,y,m,n,isVisite,a);
    return num;
}
static inline void swap(int *a,int *b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
static void makedown(int m,int n,int a[m][n])
{
    int output[20];
    int k;
    for(int i=0;i<n;i++)
    {
        k=0;
        for(int j=0;j<m;j++)
        {
            if(a[j][i]!=0)
            {
                output[k++]=a[j][i];
            }
        }
        for(int j=0;j<m;j++)
            a[j][i]=0;
        for(int j=m-1;j>=0 && k>0;j--)
        {
            a[j][i]=output[--k];
        }
    }
}
static void makeleft(int m,int n,int a[m][n])
{
    int output[20];
    int k=0;
    for(int i=0;i<10;i++)
    {
        if(a[9][i]!=0)
            output[k++]=i;
    }
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<10;j++)
        {
            a[j][i]=a[j][output[i]];
        }
    }
    for(int i=k;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            a[j][i]=0;
        }
    }
}

static void putInformation(char *str)
{
    beginPaint();
    setTextColor(BLACK);
    setTextBkColor(WHITE);
    setTextSize(24);
    setTextFont("Courier New");
    paintText(500,100,str);
    char rcd[20];
    sprintf(rcd,"record:%5d",Record);
    paintText(500,50,rcd);
    endPaint();
}

static void getRecord()
{
    FILE *fp_record;
    fp_record=fopen("init/record.sav","r");

    fscanf(fp_record,"%d",&Record);

    fclose(fp_record);
}
static void renewRecord(int mark)
{
    FILE *fp_record;
    fp_record=fopen("init/record.sav","w");

    fprintf(fp_record,"%d",mark);

    fclose(fp_record);

    Record=mark;
}
void startGame(int *wId)
{
    *wId=GameWndId;

    BlockNum=100; //the first num of block is 10*10
    mark=0;
    getRecord();


    ACL_Image background;
    loadImage(GamePic,&background);
    drawPictureScale(&background,0,0,WndWidth,WndHeight);

    //test code
    /*
    ACL_Image test;
    loadImage("picture/11.jpg",&test);
    beginPaint();
    putImageTransparent(&test,0,0,100,100,RGB(0,0,0));
    endPaint();*/
    //end

    ACL_Image back,restart;
    loadImage(Btnrestart,&restart);
    loadImage(BtnGameBack,&back);
    beginPaint();
    putImageScale(&back,GameBackLx,GameBackLy,BtnWidth,BtnHeight);
    putImageScale(&restart,GameRestartLx,GameRestartLy,BtnWidth,BtnHeight);
    endPaint();

    initGameMap(10,10,game_map);
    drawGameMap(10,10,game_map);

    putInformation("score :    0");
}

void gameRestart()
{
    BlockNum=100;
    mark=0;
    initGameMap(10,10,game_map);
    drawGameMap(10,10,game_map);
    putInformation("score :    0");
}

static void gameEftSound(int num)
{
    if(num<1)
    {
#ifdef DEBUG

        printf("something wrong,this case should never be shown!\n");
#endif // DEBUG
    }
    else if(num<2)
        soundEft(GameEft1);
    else if(num<4)
        soundEft(GameEft2);
    else if(num<6)
        soundEft(GameEft3);
    else if(num<8)
        soundEft(GameEft4);
    else if(num<10)
        soundEft(GameEft5);
    else if(num<12)
        soundEft(GameEft6);
    else if(num<14)
        soundEft(GameEft6);
    else if(num<16)
        soundEft(GameEft6);
    else
        soundEft(GameEft6);
#ifdef DEBUG

    printf("file=%s\n",GameEft1);
#endif // DEBUG
}

static int caclMark(int t)
{
    double i=600*(sin(t*(3.1416/25)-(3.1416/2))+1);
    return (int)i;
}

void gameDriver(int x,int y,int button,int event)
{
    int px,py;
    px=x/BlockLength;
    py=y/BlockLength;

#ifdef DEBUG

    printf("the color is %d\n",game_map[py][px]);
#endif // DEBUG

    int t=search(px,py,10,10,game_map);
    BlockNum-=t;
    if(t>0)
    {
        gameEftSound(t);    //play effect
        makedown(10,10,game_map);
        makeleft(10,10,game_map);
        drawGameMap(10,10,game_map);
    }


    mark+=caclMark(t);
    char inf[100];
    sprintf(inf,"score :%5d",mark);
    putInformation(inf);
    if(BlockNum == 0) //end of game
    {
        if(mark>Record)
            renewRecord(mark);
        mark=0;
        sprintf(inf,"score :%5d",mark);
        //putInformation(inf);
    }

    //test code.
#ifdef DEBUG
    printf("cut off block num=%d\n",t);
    printf("there are %d blocks now\n",BlockNum);
    //end
#endif // DEBUG
}








