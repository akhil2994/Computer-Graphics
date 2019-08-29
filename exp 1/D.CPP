#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<ctype.h>

void ddasimple(int x1,int y1,int x2,int y2);
void ddadotted(int x1,int y1,int x2,int y2);
void ddadash(int x1,int y1,int x2,int y2);
void ddathick(int x1,int y1,int x2,int y2);

void main()
{
	int gd=DETECT,gm;
	int x1,y1,x2,y2,ch;
	int ch1;
	initgraph (&gd,&gm,"c:\\turboc3\\bgi");
	cleardevice();
     menu:
	do
	{
	   cleardevice();
	   cout<<"\n****MENU*****\n"<<endl;
	   cout<<"1.DDA Line Algorithm"<<endl;
	   cout<<"2.Exit"<<endl;
	   cout<<"\nEnter your choice=";
	   cin>>ch;
	   switch(ch)
	   {
	      case 1:
		       do
		       {
			  cout<<"----Select type of line-----"<<endl;
			  cout<<"1.Simple line"<<endl;
			  cout<<"2.Dotted Line"<<endl;
			  cout<<"3.Dashed line"<<endl;
			  cout<<"4.Thick line"<<endl;
			  cout<<"5.goto main menu"<<endl;
			  cout<<"Enter your choice =";
			  cin>>ch1;
			  switch(ch1)
			  {
			     case 1:
				      cleardevice();
				      cout<<endl<<"Enter x1=";
				      cin>>x1;
				      cout<<endl<<"Enter y1=";
				      cin>>y1;
				      cout<<endl<<"Enter x2=";
				      cin>>x2;
				      cout<<endl<<"Enter y2=";
				      cin>>y2;
				      cleardevice();
				      line(320,1,320,480);
				      line(1,240,640,240);
				      ddasimple(320+x1,240-y1,320+x2,240-y2);
				      outtextxy(320,250," ");
				      outtextxy(320+x1-5,240-y1-5," ");  
				      outtextxy(320+x2,240-y2," ");
				      outtextxy(320+x2+10,240-y2+10," ");
				      break;
			    case 2:
				      cleardevice();
				      cout<<endl<<"Enter x1=";
				      cin>>x1;
				      cout<<endl<<"Enter y1=";
				      cin>>y1;
				      cout<<endl<<"Enter x2=";
				      cin>>x2;
				      cout<<endl<<"Enter y2=";
				      cin>>y2;
				      cleardevice();
				      line(320,1,320,480);
				      line(1,240,640,240);
				      outtextxy(320,250," ");
				      ddadotted(320+x1,240-y1,320+x2,240-y2);
				      outtextxy(320+x1-5,240-y1-5," ");
				      outtextxy(320+x2,240-y2," ");
				      outtextxy(320+x2+10,240-y2+10," ");
				      break;
			     case 3:
				      cleardevice();
				      cout<<endl<<"Enter x1=";
				      cin>>x1;
				      cout<<endl<<"Enter y1=";
				      cin>>y1;
				      cout<<endl<<"Enter x2=";
				      cin>>x2;
				      cout<<endl<<"Enter y2=";
				      cin>>y2;
				      cleardevice();
				      line(320,1,320,480);
				      line(1,240,640,240);
				      outtextxy(320,250," ");
				      ddadash(320+x1,240-y1,320+x2,240-y2);
				      outtextxy(320+x1-5,240-y1-5," ");
				      outtextxy(320+x2,240-y2," ");
				      outtextxy(320+x2+10,240-y2+10," ");
				      break;
			     case 4:
				     cleardevice();
				     cout<<endl<<"Enter x1=";
				     cin>>x1;
				     cout<<endl<<"Enter y1=";
				     cin>>y1;
				     cout<<endl<<"Enter x2=";
				     cin>>x2;
				     cout<<endl<<"Enter y2=";
				     cin>>y2;
				     cleardevice();
				     line(320,1,320,480);
				     line(1,240,640,240);
				     outtextxy(320,250," ");
				     ddathick(320+x1,240-y1,320+x2,240-y2);
				     outtextxy(320+x1-5,240-y1-5," ");
				     outtextxy(320+x2,240-y2," ");
				     outtextxy(320+x2+10,240-y2+10," ");
				     break;
			     case 5:
				     goto menu;
				     break;
			  }
		       }while(ch1!='F');
	      break;
       case 2:
		break;
     }
  }while(ch!=2);
  getch();
  closegraph();
}
void ddasimple(int x1,int y1,int x2,int y2)
{
  int i;
  float x,y,dx,dy,len,xinc,yinc;
	 dx=x2-x1;
	 dy=y2-y1;
	if(dx>=dy)
		len=dx;
	else
		len=dy;
	xinc=dx/len;
	yinc=dy/len;
	x=x1;
	y=y1;
  for(i=1;i<=len;i++)
  {
	 putpixel(ceil(x),ceil(y),WHITE);
	 x=x+xinc;
	 y=y+yinc;
  }
}

void ddadotted(int x1,int y1,int x2,int y2)
{
	int i,c=0;
	float x,y,dx,dy,len,xinc,yinc;
	 dx=(x2-x1);
	 dy=(y2-y1);
	if(dx>=dy)
		len=dx;
	else
		len=dy;
	xinc=dx/len;
	yinc=dy/len;
	x=x1;
	y=y1;

	 for(i=1;i<len;i++)
	 {
	 x=x+xinc;
	 y=y+yinc;
	 if(c%2==0)
		 c++;
	 else
		{
		putpixel(x,y,WHITE);
		c++;
		}
	 }
}


 void ddadash(int x1,int y1,int x2,int y2)
{
	int i;
	float x,y,dx,dy,len,xinc,yinc;
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	  if(dx>=dy)
		len=dx;
	else
		len=dy;

	  dx=(x2-x1)/len;
	  dy=(y2-y1)/len;
	  x=x1;
	  y=y1;
	  for(i=0;i<=len;i++)
	   {
	    if(i%9<2)
	     {}
	    else if(i%9==7)
	    {}
	    else
	     putpixel(x,y,RED);
	     x+=dx;
	     y+=dy;
	   }
}
void ddathick(int x1,int y1,int x2,int y2)
{
	int i,j;
	float x,y,dx,dy,len,xinc,yinc;
	 dx=x2-x1;
	 dy=y2-y1;
	if(dx>=dy)
		len=dx;
	else
		len=dy;
	xinc=dx/len;
	yinc=dy/len;
	x=x1;
	y=y1;
  for(i=0;i<=len;i++)
	{
	 x=x+xinc;
	 y=y+yinc;
	 putpixel(x,y,WHITE);
	  for(j=1;j<5;j++)
		{
		  putpixel(x+j,y,WHITE);
		}
	}
}
