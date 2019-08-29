#include<iostream.h>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
   /* request auto detection */
   int gdriver = DETECT, gmode;
   float x1,y1,x2,y2;
   int radius,h,k,x,y,d,a1,b1,ch;
   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "C:\\tc\\bgi");
   cout<<"\n1. DDA Circle\n2. Bressenham Circle\n3. Mid Point Circle";
   cout<<"Enter Choice";
   cin>>ch;
   cout<<"Enter the radius";
   cin>>radius;
   cout<<"\n\nGive the location of radius.the x and y co ordinates\n";
   cin>>k>>h;
   a1=getmaxx();
   b1=getmaxy();
   line(0,b1/2,a1,b1/2);
   line(a1/2,0,a1/2,b1);

   switch(ch)
   {
     case 1:
     {
       float epsilon,n,val,start_x,start_y;
       int i=0;
       start_x=radius;
       start_y=0;
       x1=start_x;
       y1=start_y;
       do
       {
	 val=pow(2,i);
	 i++;
       }while(val<radius);
       epsilon=1/pow(2,i-1);
       do
       {
	 x2=x1+(epsilon * y1);
	 y2=y1-(epsilon * x2);
	 putpixel((x2+h)+319.5,239.5-(y2+k),15);
	 x1=x2;
	 y1=y2;
       }while((y1-start_y)<epsilon || (start_x-x1)>epsilon);
       break;
     }
     case 2:
     {
       x=0;
       y=radius;
       d=3-(2*radius);
       outtextxy(200,100, "This is bressenham circle algorithm.");
       while(x<=y)
       {
	 putpixel((x+h)+319.5,239.5-(y+k),15);
	 putpixel((y+h)+319.5,239.5-(x+k),20);
	 putpixel((-x+h)+319.5,239.5-(y+k),25);
	 putpixel((-y+h)+319.5,239.5-(x+k),30);
	 putpixel((-x+h)+319.5,239.5-(-y+k),15);
	 putpixel((-y+h)+319.5,239.5-(-x+k),20);
	 putpixel((x+h)+319.5,239.5-(-y+k),25);
	 putpixel((y+h)+319.5,239.5-(-x+k),30);
	 if(d<0)
	 {
	   d=d+4*x+6;
	 }
	 else
	 {
	   d=d+4*(x-y)+10;
	   y=y-1;
	 }
	   x=x+1;
       }
       break;
     }
     case 3:
     {
       x=0;
       y=radius;
       d=1-radius;
       outtextxy(200,100, "This is Mid point circle algorithm.");
       while(x<=y)
       {
	 putpixel((x+h)+319.5,239.5-(y+k),115);
	 putpixel((y+h)+319.5,239.5-(x+k),120);
	 putpixel((-x+h)+319.5,239.5-(y+k),125);
	 putpixel((-y+h)+319.5,239.5-(x+k),130);
	 putpixel((-x+h)+319.5,239.5-(-y+k),115);
	 putpixel((-y+h)+319.5,239.5-(-x+k),120);
	 putpixel((x+h)+319.5,239.5-(-y+k),125);
	 putpixel((y+h)+319.5,239.5-(-x+k),130);
	 if(d<0)
	 {
	   d=d+2*x+1;
	 }
	 else
	 {
	   d=d+2*(x-y)+1;
	   y=y-1;
	 }
	 x=x+1;
       }
       break;
     }
   }
   getch();
   closegraph();
}
