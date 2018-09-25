#include <dos.h>
#include <conio.h>
#include <windows.h>
#include <graphics.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>;

using namespace std;
void help();
void game();
void check();
void dead();
void level();
void high();
void type();
void speed();
void border();
int snake_x[500],snake_y[500],snake_size =5,score,highscore,spd = 100,l;
bool checkdied = false,BONUS = false,easy = false, medium = false, hard = false;
main()
{

    int gdirect = DETECT,gmode;  /* request autodetection */
    initgraph(&gdirect,&gmode,""); /* initialize graphics and local variables */

    int cursor_y = 130;
    char ch;
    while(1)
    {

        setcolor(RED);
        settextstyle(6,0,6);
        outtextxy(180,30," Snake Game ");
        setcolor(WHITE);
        settextstyle(3,0,3); /*this part prints menu again but inside while loop,because other functions will return here*/
        outtextxy(200,130,"New Game");
        outtextxy(200,160,"Help");
        outtextxy(200,190,"Select Level");
        outtextxy(200,220,"Highscore");
        outtextxy(200,250,"Exit");
        setcolor(YELLOW);
        settextstyle(6,0,3);
        outtextxy(200,280,"Please Select Level First");
        outtextxy(160,cursor_y,">");

        if(kbhit){
        ch = getch();
        setcolor(BLACK);
        outtextxy(160,cursor_y,">");
        if(ch == 13) {
            if(cursor_y==250) exit(0);
            else if(cursor_y==160) help();
            else if(cursor_y==130) game();
            else if(cursor_y==190) level();
            else if(cursor_y==220) high();
        }
        }
        if(ch==80) {cursor_y+=30;
        if(cursor_y > 250) {cursor_y=130;}
        }
        if(ch==72) {cursor_y-=30;
        if(cursor_y < 130) {cursor_y=250;}
        }
    }

    return 0;
}
void help()
{
    clearviewport();
    setcolor(WHITE);
    outtextxy(100,200,"Move the snake using the Arrow keys.");
    outtextxy(100,230,"Get bonus after eating 4 food :)");
    outtextxy(100,260,"Press 'Alt' to Pause");
    char ch = getch();
    clearviewport();
    return;
}
void game()
{
    clearviewport();
    freopen("GameData.dat","r",stdin);
    cin >> highscore;

    cleardevice();
    char ch;
    string key = "right";
    int maxx = getmaxx()-12;
    int maxy = getmaxy()-50;
    int x = 260+26,y = 260+26;//13,13

    int food_x = rand()%maxx,food_y = rand()%maxy;
    int temp;
    temp = food_x%13;//13
    food_x-=temp;
    temp = food_y%13;//13
    food_y-=temp;
    int i = 0,w = 0;
    int bonus = 500;
    while(true)
        {
         clearviewport();
        if(medium || hard)
        {
            setcolor(RED);
            line(50,150,550,150);
            line(50,160,550,160);
            for(int k=50;k<=550;k=k+500)
            {
                line(k,150,k,160);
            }

            line(50,260,550,260);
            line(50,270,550,270);
            for(int k=50;k<=550;k=k+500)
            {
                line(k,260,k,270);
            }
        }
        if (hard)
        {
            setcolor(RED);
            line(2,0,2,maxy);
            line(12,0,12,maxy);
            for(int k=0;k<=maxy;k=k+415)
            {
                line(2,k,12,k);     //LEFT border
            }

            line(maxx-1,0,maxx-1,maxy);
            line(maxx-11,0,maxx-11,maxy);
            for(int k=0;k<maxy-10;k=k+430)
            {
                line(maxx-11,k,maxx-1,k);       //RIGHT  border
            }
            line(maxx-11,maxy-10,maxx-1,maxy-10);
        }
        if(score >0 && score%5==4) BONUS = true;
        else{ bonus = 500;
        BONUS = false;
        }
        if(!BONUS || bonus == 0){
        setcolor(BLACK);
        outtextxy(250,430,"Hurry!! 888");
        setcolor(GREEN);
        setfillstyle(SOLID_FILL,GREEN);
        circle(food_x,food_y,5); //x position,y position,size
        floodfill(food_x,food_y,GREEN);

        }
        else
        {
        setcolor(BLUE);
        setfillstyle(SOLID_FILL,BLUE);
        circle(food_x,food_y,5);
        floodfill(food_x,food_y,BLUE);

        char spp[1000];
        setcolor(BLACK);
        sprintf(spp,"Hurry!! %d",bonus);
        outtextxy(250,430,"Hurry!! 888");
        setcolor(GREEN);
        outtextxy(250,430,spp);
        }
        maxx = getmaxx()-12;/////no
        maxy = getmaxy()-50;
        setcolor(WHITE);
        line(0,maxy+8,maxx,maxy+8);
        if(kbhit())
        {
            ch = getch(); if(ch == 0) ch = getch();
            if(ch == 72 && key != "down" ) key = "up";
            if(ch == 80 && key != "up") key = "down";
            if(ch == 75 && key != "right") key = "left";
            if(ch == 77 && key != "left") key = "right";
            if(ch == 27) {
            cleardevice();
            return;
        }

        }

        if(i < 5)
        {
            snake_x[i] = x-240;
            snake_y[i] = y-285;
            i++;
        }
        else {
        for(int _size = snake_size-2;_size >= 0;_size--) {
        snake_x[_size+1] = snake_x[_size];
        snake_y[_size+1] = snake_y[_size];
        }
        snake_x[0] = x;
        snake_y[0] = y;

        setcolor(RED);
        circle(snake_x[0],snake_y[0],8);
        setfillstyle(SOLID_FILL,WHITE);
        floodfill(snake_x[0],snake_y[0],RED);

        setcolor(YELLOW);
        for(int _size = 1; _size < snake_size;_size++)
        {
        circle(snake_x[_size],snake_y[_size],5);
        setfillstyle(SOLID_FILL,YELLOW);
        floodfill(snake_x[_size],snake_y[_size],YELLOW);
        }

        char ara[100];
        sprintf(ara,"Score: %d",score);
        setcolor(WHITE);
        outtextxy(00,maxy+10,ara);
        sprintf(ara,"Bestscore: %d",highscore);
        setcolor(WHITE);
        outtextxy(450,maxy+10,ara);

        delay(spd);

        }
        if(x == food_x && y== food_y)
        {
            Beep(1000,50);
        snake_size++;score++;
            /* Snake eats food*/
        if(score%5==0 && score>0)score+=bonus;

        food_x = rand()%maxx,food_y = rand()%maxy;
        temp = food_x%13;
        food_x-=temp;
        temp = food_y%13;
        food_y-=temp;

        if(food_x < 5 || food_x > maxx - 5 || food_y < 5 || food_y > maxy - 5 ||((food_x>=50 && food_x<=550) && ((food_y>=150 && food_y<=160)|| (food_y>=260 && food_y<=270))) )
        {
            while(food_x < 5 || food_x > maxx - 5 || food_y < 5 || food_y > maxy - 5 ||((food_x>=50 && food_x<=550) && ((food_y>=150 && food_y<=170)|| (food_y>=260 && food_y<=270)))) {
            food_x = rand()%maxx,food_y = rand()%maxy;
            temp = food_x%13;
            food_x-=temp;
            temp = food_y%13;
            food_y-=temp;
            }
        }
        }
        if(key == "right") x = x+13; if(x > maxx) x =0;
        if(key == "left") x = x-13; if(x < 0) x = maxx-(maxx%13);
        if(key == "up") y = y-13; if(y > maxy) y = 0;
        if(key == "down") y = y+13; if(y < 0) y = maxy-(maxy%13);
        check();
        if(checkdied){
        dead();
        return;
        }
        if(medium || hard)
        border();

    if(BONUS){
    if(bonus>0)
    bonus-=10;
      }
        setcolor(BLACK);
        circle(snake_x[0],snake_y[0],8);
        setfillstyle(SOLID_FILL,BLACK);
        floodfill(snake_x[0],snake_y[0],BLACK);

        for(int _size = 1; _size < snake_size;_size++)
        {
        circle(snake_x[_size],snake_y[_size],5);
        setfillstyle(SOLID_FILL,BLACK);
        floodfill(snake_x[_size],snake_y[_size],BLACK);
        }

    }
}
void check()
{
    freopen("GameData.dat","w",stdout);
    if(highscore < score)
    cout << score << endl;
    else cout << highscore << endl;

    for(int i = 1;i < snake_size;i++)
    {
        if(snake_x[0] == snake_x[i] && snake_y[0] == snake_y[i])
        {
            delay(100);
            setcolor(WHITE);
            for(int i = 0;i < snake_size;i++)
             cleardevice();
  /*          {
                circle(snake_x[i],snake_y[i],5);
                setfillstyle(SOLID_FILL,RED);
                floodfill(snake_x[i],snake_y[i],WHITE);
            }

            */

            setcolor(RED);
            settextstyle(BOLD_FONT,HORIZ_DIR,5);
            outtextxy(170,160,"GAME OVER!!");
            while(1){
            if(kbhit()){
            char ch = getch() ;
            if(ch == 13){
            checkdied = true;
            return;
            }
            }
            }
        }
    }
    if(hard)
            {
            int maxx=getmaxx()-12;
            int maxy=getmaxy()-52;
            if(snake_x[0]<=14 || snake_x[0] >= maxx-12 ) //////
            {
                while(1)
                {
                    char ch=getch();
                    if(ch==13)
                    {
                        checkdied=true;
                        return;
                    }
                }
            }
    }
}
void dead()
{
    checkdied = false;
    snake_size = 5;
    score = 0;
    setcolor(RED);
    settextstyle(6,0,4);
    outtextxy(180,180," GAME OVER!! ");
    delay(850);
    clearviewport();
}
void level()
{
    clearviewport();
    char ch;
    char ara[100];
    int pointer = 200;
    while(true){
            setcolor(RED);
            outtextxy(200,200,"Difficulty");


            setcolor(BLUE);
            settextstyle(3,0,3);
            outtextxy(170,pointer,">");

  if(kbhit)
            {
               ch=getch();
               setcolor(BLACK);
               settextstyle(3,0,3);
               outtextxy(170,pointer,">");
               if(ch==13)
               {
                if(pointer==200)       type();
                else if(pointer==230) speed();
               }
            }
            if(ch==80)
               {
                   pointer+=30;
                   if(pointer>230)
                    pointer=200;
               }
               if(ch==72)
               {
                   pointer-=30;
                   if(pointer<200)
                    pointer=230;
               }
               if(ch==75)
               {
                    clearviewport();
                    return;
               }
                settextstyle(3,0,3);
                outtextxy(170,pointer,">");
        }
    clearviewport();
}
void speed()
{
    clearviewport();
    char ch;
    char ara[100];
    while(true){

    int i = abs(spd/10.-10);
    sprintf(ara,"SELECT LEVEL : %d",i);
    setcolor(WHITE);
    outtextxy(180,200,ara);

    if(kbhit())
    {
        ch = getch();
        if(ch == 80) {
        spd-=10;
        if(spd < 0) spd = 100;
        }
        else if(ch == 72) {
            spd+=10;
        if(spd > 100) spd = 0;
        }
        else if(ch == 13)
            break;
    sprintf(ara,"SELECT LEVEL : %d",i);
    setcolor(BLACK);
    outtextxy(180,200,ara);
    }
    }

    clearviewport();
}
void type()
{
    clearviewport();
        int pointer=200;
        char ch;
        while(1)
        {
            setcolor(RED);
outtextxy(200,200,"Easy");
        outtextxy(200,230,"Medium");
        outtextxy(200,260,"Hard");
        setcolor(BLUE);
        settextstyle(3,0,3);
        outtextxy(170,pointer,">");
        if(kbhit)
        {
            ch=getch();
            setcolor(BLACK);
            settextstyle(3,0,3);
            outtextxy(170,pointer,">");
            if(ch==13)
            {
                    if(pointer==200)       easy=true;
                    else if(pointer==230)  medium=true;
                    else if(pointer==260)  hard=true;
                    clearviewport();
                    break;
            }
        }
        if(ch==80)
        {
            pointer+=30;
            if(pointer>260)
                pointer=200;
        }
        if(ch==72)
        {
            pointer-=30;
            if(pointer<200)
                pointer=260;
        }
        settextstyle(3,0,3);
        outtextxy(170,pointer,">");
        }
        return;

    }

void high()
{
        clearviewport();
        freopen("GameData.dat","r",stdin);
        cin >> highscore;
        char ara[100];
        sprintf(ara,"Highscore: %d",highscore);
        setcolor(LIGHTBLUE);
        outtextxy(200,200,ara);
        char ch = getch();
        clearviewport();
}
void border()
    {
        if(snake_x[0]>=50 && snake_x[0]<=550)
        {
            if((snake_y[0]>=150 && snake_y[0]<=160) || (snake_y[0]>=260 && snake_y[0]<=270))
            {
                 while(1)
                {
                 if(kbhit())
                {
                char ch=getch();
                if(ch==13)
                {

                    checkdied=true;
                    return;

                }
                }
                }
            }

        }
    }
