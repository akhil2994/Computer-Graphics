/*------------------------------------------------------------
	       Polygon Filling using FLOOD FILL ALGORITHM
------------------------------------------------------------*/

#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>

void FloodFill(const int,const int,const int,const int);
void Circle(const int,const int,const int);
void Triangle(const int,const int,const int,const int,const int,const int);
void Rectangle(const int,const int,const int,const int);
void Line1(const int,const int,const int,const int);

int main( )
{
       int gd=DETECT,gm;
       initgraph(&gd,&gm,"c:\\turboc3\\bgi");

       setcolor(3);
       Rectangle(350,135,500,225);
       FloodFill(425,175,5,0);
       setcolor(3);
       settextstyle(0,0,1);
       outtextxy(390,235,"Rectangle");

       setcolor(3);
       Triangle(150,370,255,370,190,280);
       FloodFill(175,325,1,0);
       setcolor(3);
       settextstyle(0,0,1);
       outtextxy(145,380,"Triangle");

       setcolor(3);
       Circle(175,175,50);
       FloodFill(175,175,6,0);
       setcolor(3);
       settextstyle(0,0,1);
       outtextxy(150,235,"Circle");

       getch();
       return 0;
       closegraph();
}

 struct Pixel
    {
       int x;
       int y;

       Pixel *Next;
    };

 Pixel *Entry=NULL;
 Pixel *Start=NULL;
 Pixel *Last=NULL;

 void insert_pixel(const int x,const int y)
    {
       Entry=new Pixel;

       Entry->x=x;
       Entry->y=y;

       Entry->Next=NULL;
       Last->Next=Entry;
       Last=Entry;
    }

 void FloodFill(const int _x,const int _y,const int fill_color,const int old_color)
    {
       if(old_color==fill_color)
	  return;

       int x=_x;
       int y=_y;

       Start=new Pixel;

       Start->x=x;
       Start->y=y;

       Start->Next=NULL;
       Last=Start;

       while(Start!=NULL)
	  {
	     putpixel(x,y,fill_color);

	     if(getpixel((x-1),y)==old_color && (x-1)>=0)
		{
		   putpixel((x-1),y,fill_color);

		   insert_pixel((x-1),y);
		}

	     if(getpixel(x,(y-1))==old_color && (y-1)>=0)
		{
		   putpixel(x,(y-1),fill_color);

		   insert_pixel(x,(y-1));
		}

	     if(getpixel((x+1),y)==old_color && (x+1)<=getmaxx( ))
		{
		   putpixel((x+1),y,fill_color);

		   insert_pixel((x+1),y);
		}

	     if(getpixel(x,(y+1))==old_color && (y+1)<=getmaxy( ))
		{
		   putpixel(x,(y+1),fill_color);

		   insert_pixel(x,(y+1));
		}

	     Entry=Start;
	     Start=Start->Next;

	     x=Start->x;
	     y=Start->y;

	     delete Entry;
	  }
    }

 void Circle(const int h,const int k,const int r)
    {
       int color=getcolor( );

       int x=0;
       int y=r;
       int p=(1-r);

       do
	  {
	     putpixel((h+x),(k+y),color);
	     putpixel((h+y),(k+x),color);
	     putpixel((h+y),(k-x),color);
	     putpixel((h+x),(k-y),color);
	     putpixel((h-x),(k-y),color);
	     putpixel((h-y),(k-x),color);
	     putpixel((h-y),(k+x),color);
	     putpixel((h-x),(k+y),color);

	     x++;

	     if(p<0)
		p+=((2*x)+1);

	     else
		{
		   y--;
		   p+=((2*(x-y))+1);
		}
	  }
       while(x<=y);
    }


 void Triangle(const int x_1,const int y_1,const int x_2,const int y_2,const int x_3,const int y_3)
    {
       Line(x_1,y_1,x_2,y_2);
       Line(x_2,y_2,x_3,y_3);
       Line(x_3,y_3,x_1,y_1);
    }


 void Rectangle(const int x_1,const int y_1,const int x_2,const int y_2)
    {
       Line(x_1,y_1,x_2,y_1);
       Line(x_2,y_1,x_2,y_2);
       Line(x_2,y_2,x_1,y_2);
       Line(x_1,y_2,x_1,y_1);
    }


 void Line1(const int x_1,const int y_1,const int x_2,const int y_2)
    {
       int color=getcolor( );

       int x1=x_1;
       int y1=y_1;

       int x2=x_2;
       int y2=y_2;

       if(x_1>x_2)
	  {
	     x1=x_2;
	     y1=y_2;

	     x2=x_1;
	     y2=y_1;
	  }

       int dx=abs(x2-x1);
       int dy=abs(y2-y1);
       int inc_dec=((y2>=y1)?1:-1);

       if(dx>dy)
	  {
	     int two_dy=(2*dy);
	     int two_dy_dx=(2*(dy-dx));
	     int p=((2*dy)-dx);

	     int x=x1;
	     int y=y1;

	     putpixel(x,y,color);

	     while(x<x2)
		{
		   x++;

		   if(p<0)
		      p+=two_dy;

		   else
		      {
			 y+=inc_dec;
			 p+=two_dy_dx;
		      }

		   putpixel(x,y,color);
		}
	  }

       else
	  {
	     int two_dx=(2*dx);
	     int two_dx_dy=(2*(dx-dy));
	     int p=((2*dx)-dy);

	     int x=x1;
	     int y=y1;

	     putpixel(x,y,color);

	     while(y!=y2)
		{
		   y+=inc_dec;

		   if(p<0)
		      p+=two_dx;

		   else
		      {
			 x++;
			 p+=two_dx_dy;
		      }

		   putpixel(x,y,color);
		}
	  }
    }

