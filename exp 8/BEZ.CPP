﻿Aim:-Curve generation:Design any object such as flower,waves etc. Using following curve generation technique
1.Curve generation using interpolation
2.bezier curve

#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <iostream.h>
#include <stdlib.h>

int gd,gm,maxx,maxy;
float xxx[4][2];
void line1(float x2,float y2)
{
line(xxx[0][0],xxx[0][1],x2,y2);
xxx[0][0]=x2;
xxx[0][1]=y2;
}
void bezier(float xb,float yb,float xc,float yc,float xd,float yd,int n)
{
float xab,yab,xbc,ybc,xcd,ycd;
float xabc,yabc,xbcd,ybcd;
float xabcd,yabcd;
if(n==0)
{
line1(xb,yb);
line1(xc,yc);
line1(xd,yd);
}
else
{
xab=(xxx[0][0]+xb)/2;
yab=(xxx[0][1]+yb)/2;
xbc=(xb+xc)/2;
ybc=(yb+yc)/2;
xcd=(xc+xd)/2;
ycd=(yc+yd)/2;
xabc=(xab+xbc)/2;
yabc=(yab+ybc)/2;
xbcd=(xbc+xcd)/2;
ybcd=(ybc+ycd)/2;
xabcd=(xabc+xbcd)/2;
yabcd=(yabc+ybcd)/2;
n=n-1;
bezier(xab,yab,xabc,yabc,xabcd,yabcd,n);
bezier(xbcd,ybcd,xcd,ycd,xd,yd,n);
}
}
void igraph()
{
int gd,gm=DETECT;
detectgraph(&gd,&gm);
if(gd<0)
{
puts("cant detct graphs");
exit(1);
}
initgraph(&gd,&gm,"c:\\student\\tc\\bgi");
}
void main()
{
int i;
float temp1,temp2;
igraph();
for(i=0;i<4;i++)
{
printf("enter (x,y) coordinates of points %d:",i+1);
scanf("%f %f",&temp1,&temp2);
xxx[i][0]=temp1;
xxx[i][1]=temp2;
}
bezier(xxx[1][0],xxx[1][1],xxx[2][0],xxx[2][1],xxx[3][0],xxx[3][1],8);
getch();
closegraph();
}

