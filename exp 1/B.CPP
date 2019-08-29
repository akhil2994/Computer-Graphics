#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>

void co_od_system()
{
 int i;
 int gd=DETECT,gm;
 initgraph(&gd,&gm, "c:\\tuboc3\\bgi");
 cleardevice();
 line(0,240,640,240);
 line(320,0,320,480);
 for(i=0;i<=610;i=i+30)
 {
  line(50+i,238,50+i,242);
 }
 for(i=0;i<=450;i=i+30)
 {
  line(318,30+i,322,30+i);
 }
 outtextxy(320,240,"");
 outtextxy(320,210,"");
 outtextxy(320,180,"");
 outtextxy(320,150,"");
 outtextxy(320,120,"");
 outtextxy(320,90,"");
 outtextxy(320,60,"");
 outtextxy(320,30,"");
 outtextxy(320,270,"");
 outtextxy(320,300,"");
 outtextxy(320,330,"");
 outtextxy(320,360,"");
 outtextxy(320,390,"");
 outtextxy(320,420,"");
 outtextxy(320,450,"");
 outtextxy(290,240,"");
 outtextxy(260,240,"");
 outtextxy(230,240,"");
 outtextxy(200,240,"");
 outtextxy(170,240,"");
 outtextxy(140,240,"");
 outtextxy(110,240,"");
 outtextxy(80,240,"");
 outtextxy(50,240,"");
 outtextxy(20,240,"");
 outtextxy(350,240,"");
 outtextxy(380,240,"");
 outtextxy(410,240,"");
 outtextxy(440,240,"");
 outtextxy(470,240,"");
 outtextxy(510,240,"");
 outtextxy(540,240,"");
 outtextxy(570,240,"");
 outtextxy(610,240,"");
}
class line1
{
 int x1,y1,x2,y2;
 public:
 void bresenham_line(int,int,int,int);
};
void line1::bresenham_line(int x1,int y1,int x2,int y2)
{
 int p,k,j,choice;
 float dx,dy,x,y,w,wy,step,dx1,dy1,m;
 co_od_system();
 putpixel(x1+320,240-y1,15);
 dx=x2-x1; dy=y2-y1;
 do
 {
  cout<<"1:Simple line\n2:Thick line\n3:Dash line\n4:Dotted line\n5:Exit";
  cout<<"\nEnter choice\t";
  cin>>choice;
  switch(choice)
  {
   case 1:co_od_system();
	  x=x1; y=y1;
	  p=(2*dy)-dx; k=0;
	  while(k<=abs(dx))
	  {
	   if(p<0)
	   {
	    x=x+1;
	    putpixel(x+320,240-y,15);
	    delay(15);
	    p=p+(2*dy);
	   }
	   else
	   {
	    x=x+1; y=y+1;
	    putpixel(x+320,240-y,15);
	    delay(15);
	    p=p+(2*dy)-(2*dx);
	   }
	   k++;
	  }
	  break;
   case 2:cout<<"Enter thickness\t";
	  cin>>w;
	  wy=((w-1)/2)*(sqrt((dx*dx)+(dy*dy))/abs(dx));
	  co_od_system();
	  x=x1; y=y1;
	  p=(2*dy)-dx; k=0;
	  while(k<=abs(dx))
	  {
	   if(p<0)
	   {
	    x=x+1;
	    j=1;
	    while(j<=wy)
	    {
	     putpixel(x+320,240-y,15);
	     putpixel(x+320,240-(y+j),15);
	     putpixel(x+320,240-(y-j),15);
	     delay(15);
	     j++;
	    }
	    p=p+(2*dy);
	   }
	   else
	   {
	    x=x+1; y=y+1;
	    j=1;
	    while(j<=wy)
	    {
	     putpixel(x+320,240-y,15);
	     putpixel(x+320,240-(y+j),15);
	     putpixel(x+320,240-(y-j),15);
	     delay(15);
	     j++;
	    }
	    p=p+(2*dy)-(2*dx);
	   }
	   k++;
	  }
	  break;
   case 3:co_od_system();
	  x=x1; y=y1;
	  p=(2*dy)-dx; k=0;
	  while(k<=abs(dx))
	  {
	   if(p<0)
	   {
	    x=x+1;
	    if(k%4!=0)
	      putpixel(x+320,240-y,15);
	    delay(15);
	    p=p+(2*dy);
	   }
	   else
	   {
	    x=x+1; y=y+1;
	    if(k%4!=0)
	      putpixel(x+320,240-y,15);
	    delay(15);
	    p=p+(2*dy)-(2*dx);
	   }
	   k++;
	  }
	  break;
   case 4:co_od_system();
	  x=x1; y=y1;
	  p=(2*dy)-dx; k=0;
	  while(k<=abs(dx))
	  {
	   if(p<0)
	   {
	    x=x+1;
	    if(k%2!=0)
	      putpixel(x+320,240-y,15);
	    delay(15);
	    p=p+(2*dy);
	   }
	   else
	   {
	    x=x+1; y=y+1;
	    if(k%2!=0)
	      putpixel(x+320,240-y,15);
	    delay(15);
	    p=p+(2*dy)-(2*dx);
	   }
	   k++;
	  }
	  break;
   case 5:break;
   default:cout<<"Please enter valid choice\t";
	   break;
  }
 }while(choice!=5);
}
int main()
{
 int gd=DETECT,gm;
 int choice,choice1,x1,y1,x2,y2;
 line1 l;
 initgraph(&gd,&gm,"c:\\turboc3\\bgi");
 cleardevice();
 cout<<"Enter x1: ";
 cin>>x1;
 cout<<"Enter y1: ";
 cin>>y1;
 cout<<"Enter x2: ";
 cin>>x2;
 cout<<"Enter y2: ";
 cin>>y2;
 l.bresenham_line(x1,y1,x2,y2);
 getch();
 closegraph();
 return 0;
}