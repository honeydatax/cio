#include <stdio.h>
#include <termios.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>


int xx=1;
int yy=1;
int color=7;
int bcolor=0;
void setbcolor(int c);
void setcolor(int c);
void clear();
void setx(int x);
void sety(int y);
void gotoxy(int x,int y);
void cls();


void setx(int x){
xx=x;
}


void sety(int y){
yy=y;
}

void gotoxy(int x,int y)
{
printf("\e[%d;%df",y,x);
}

void clear(){
int n;
for(n=0;n<26;n++){
printf("\n");
}
gotoxy(1,1);
}

void setcolor(int c){
int cc;
cc=c+30;
color=c;
printf("\e[%dm",cc);
}

void setbcolor(int c){
int cc;
cc=c+40;
bcolor=c;
printf("\e[%dm",cc);
}


void cls(){
printf("\033c");
}




























