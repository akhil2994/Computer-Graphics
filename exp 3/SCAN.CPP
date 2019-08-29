/*----------------------------------------------------------------

      Polygon filling using SCAN LINE ALGORITHM

-----------------------------------------------------------------*/
#include<iostream.h>
#include<conio.h>
#include<graphics.h>

void main()
{
     int n,i,j,k,dy,dx,x,y,t;
     int gd=DETECT,gm;
     int a[20][2],xi[20];
     float m[20];
     clrscr();
     cout<<"Enter the no. of edges of polygon:";
     cin>>n;
     cout<<"Enter the coordinates  of polygon:"<<"\n";
     for(i=0;i<n;i++)
     {
	cout<<i<<i;
	cin>>a[i][0]>>a[i][1];
      }
      a[n][0]=a[0][0];
      a[n][1]=a[0][1];
      initgraph(&gd,&gm,"c:\\turboc3\\bgi");
     for(i=0;i<n;i++)
     {
       line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
     }
     for(i=0;i<n;i++)
     {
	dy=a[i+1][1]-a[i][1];
	dx=a[i+1][0]-a[i][0];
	if(dy==0)
	    m[i]=1.0;
	if(dx==0)
	    m[i]=0.0;
	if((dy!=0)&&(dx!=0))
	{
	   m[i]=(float)dx/dy;
	}
     }
    for(y=0;y<480;y++)
   {
      k=0;
      for(i=0;i<n;i++)
      {
	if(((a[i][1]<=y) && (a[i+1][1]>y)) || ((a[i][1]>y) && (a[i+1][1]<=y)))
	{
	    xi[k]=(int)(a[i][0]+m[i] *(y-a[i][1]));
	    k++;
	}
      }
      for(j=0;j<k-1;j++)
	 for(i=0;i<k-1;i++)
	 {
	   if(xi[i]>xi[i+1])
	   {
	      t=xi[i];
	      xi[i]=xi[i+1];
	      xi[i+1]=t;
	   }
	 }
      setcolor(6);
      for(i=0;i<k;i+=2)
      {
	line(xi[i],y,xi[i+1],y);
      }
   }
  getch();
  closegraph();
}