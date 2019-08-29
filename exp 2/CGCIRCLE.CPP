/*PROBLEM STATEMENT:Circle drawing using DDA,Midpoint and Bresenham Algorithm with
		    keyboard/Mouse interface
-------------------------------------------------------------------------*/
#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include<math.h>

void ddacircle(float r,int h,int k);
void midcircle(int r,int h,int k);
void circ_bre(int,int,int);

void main()
{
	int gd=DETECT,gm;    //for storing graphics driver n mode, DETECT for detecting highest possible value
	int h,k,ch,r;
	initgraph (&gd,&gm,"c:\\turboc3\\bgi");     //initialize graphics mode for the system(i.e switch frm txt to graphics mode)
	cleardevice();
	do
	{
	   cout<<"\n****MENU****\n"<<endl;
	   cout<<"1.DDA Circle Algorithm"<<endl;
	   cout<<"2.MID POINT Circle Algorithm"<<endl;
	   cout<<"3.BRESENHAM'S CIRCLE ALGORITHM"<<endl;
	   cout<<"4.EXIT";
	   cout<<"\nEnter your choice=";
	   cin>>ch;
	   switch(ch)
	   {
	      case 1:cleardevice();
		     cout<<"\nEnter the center co-ordinates of circle: ";
		     cin>>h>>k;
		     cout<<"\nEnter the radius: "<<endl;
		     cin>>r;
		     line(320,1,320,480);
		     line(1,240,640,240);
		     ddacircle(r,h,k);
		     outtextxy(320+h,240-k,"DDA CIRCLE");
		     break;
	      case 2:cleardevice();
		     cout<<"\nEnter the center co-ordinates of circle: ";
		     cin>>h>>k;
		     cout<<"\nEnter the radius: "<<endl;
		     cin>>r;
		     line(320,1,320,480);
		     line(1,240,640,240);
		     midcircle(r,h,k);
		     outtextxy(320+h,240-k,"MID POINT CIRCLE");
		     break;
	      case 3: cleardevice();
		      cout<<"\n Enter the center co-ordinates for circle: ";
		      cin>>h>>k;
		      cout<<"\n Enter the radius: ";
		      cin>>r;
		      line(320,1,320,480);
		      line(1,240,640,240);
		      circ_bre(h,k,r);
		      outtextxy(320+h,240-k,"BRESSENHAM CIRCLE");
		      break;
	      case 4: break;
	  }
	}while(ch!=4);
	closegraph();            //back to text mode
	getch();
}
void ddacircle(float r,int h,int k)
{
   int i=0,val;
   float start_x=r,start_y=0;  //initialization of starting point
   float x1,y1,x2,y2;
   float e;
   //epsilon calculation
   do
   {
	val=pow(2,i);
	i++;
   }while(val<r);
   e=1/pow(2,i-1);
   x1=start_x;
   y1=start_y;
   do
   {
     x2=x1+(e*y1);
     y2=y1-(e*x2);
     putpixel(320+(x2+h),240-(y2+k),WHITE);
     //reinitialization of current point
     x1=x2;
     y1=y2;
   }while((y1-start_y)<e || (start_x-x1)>e);
}


void midcircle(int r,int h,int k)
{
   int x,y,d;
   x=0;
   y=r;
   d=1-r;  //initial decision making parameter
   while(x<=y)                //use of octant symmetric property to plot the pixel
   { //ploting the pixels
     putpixel(320+(x+h),240-(y+k),GREEN);
     putpixel(320+(y+h),240-(x+k),RED);
     putpixel(320+(-y+h),240-(x+k),WHITE);
     putpixel(320+(-x+h),240-(y+k),YELLOW);
     putpixel(320+(-x+h),240-(-y+k),GREEN);
     putpixel(320+(-y+h),240-(-x+k),RED);
     putpixel(320+(y+h),240-(-x+k),WHITE);
     putpixel(320+(x+h),240-(-y+k),YELLOW);
     if(d<0)
	  d=d+(2*x)+1;
     else
     {
	  d=d+2*(x-y)+1;
	  y=y-1;
     }
     x=x+1;
  }
}
void circ_bre(int x,int y,int rad)
{
     float dp;
     int x1,y1;
     x1=0;
     y1=rad;
     dp=3-2*rad;
     while(x1<=y1)
     {
	 if(dp<=0)
	      dp+=(4*x1)+6;
	 else
	 {
	     dp+=4*(x1-y1)+10;
	     y1--;
	 }
	 x1++;
	  putpixel(320+(x1+x),240-(y1+y),WHITE);
	  putpixel(320+(x1+x),240-(y-y1),WHITE);
	  putpixel(320+(x-x1),240-(y1+y),WHITE);
	  putpixel(320+(x-x1),240-(y-y1),WHITE);
	  putpixel(320+(x+y1),240-(y+x1),WHITE);
	  putpixel(320+(x+y1),240-(y-x1),WHITE);
	  putpixel(320+(x-y1),240-(y+x1),WHITE);
	  putpixel(320+(x-y1),240-(y-x1),WHITE);
     }
}

