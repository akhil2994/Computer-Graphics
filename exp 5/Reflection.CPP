/*----------------------------------------------------------------------

	       2D Transformations:
		   Reflection about X and Y axis and about arbitrary axis

------------------------------------------------------------------------*/

#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<iostream.h>
void quadrant();
class matrix
{	float tm[5][3];
	int rows,cols;
	float a,b;
	public:
		matrix()
		{ }
		matrix(float v[5][3],int m,int n);
		void display(int m,int n);

		friend polygon;
		matrix mul(matrix m2,int m,int n);
		void ref_x(int m,int n)
		{
			rows=m;
			cols=n;
			tm[0][1]=tm[0][2]=tm[1][0]=tm[1][2]=tm[2][0]=tm[2][1]=0;
			tm[0][0]=tm[2][2]=1;
			tm[1][1]=-1;
		}
		void ref_y(int m,int n)
		{
			rows=m;
			cols=n;
			tm[0][1]=tm[0][2]=tm[1][0]=tm[1][2]=tm[2][0]=tm[2][1]=0;
			tm[1][1]=tm[2][2]=1;
			tm[0][0]=-1;
		}

	  void ref_arb_line(float a1,float b1,int m,int n)
		{
			rows=m;
			cols=n;
			a=a1;
			b=b1;
			tm[0][2]=tm[1][2]=0;
			tm[2][2]=1;
			tm[0][1]=tm[1][0]=(2*a)/((a*a)+1);
			tm[0][0]=(1-(a*a))/((a*a)+1);
			tm[1][1]=((a*a)-1)/((a*a)+1);
			tm[2][0]=(-2*(b*a))/((a*a)+1);
			tm[2][1]=(2*b)/((a*a)+1);
		 }
};
void matrix::display(int m,int n)
{
	rows=m;
	cols=n;
	for(int i=0;i<rows;i++)
	{
		cout<<"\n";
		for(int j=0;j<cols;j++)
		cout<<"\t"<<tm[i][j];
		getch();
	}
}
matrix::matrix(float v1[5][3],int m,int n)
{
	rows=m;cols=n;
	for(int i=0;i<rows;i++)
	for(int j=0;j<cols;j++)
	{
		tm[i][j]=v1[i][j];
	}
}
class polygon
{
	public:
		void drawpoly(matrix m,int nv);
};

void polygon::drawpoly(matrix m,int nv)
{
	int s=5;
	matrix mm;
	int midx=getmaxx()/2;
	int midy=getmaxy()/2;
	for(int i=0;i<nv;i++)
	{
		mm.tm[i][0]=midx+s*m.tm[i][0];
		mm.tm[i][1]=midy-s*m.tm[i][1];
	}
	for(i=0;i<nv-1;i++)

		line(mm.tm[i][0],mm.tm[i][1],mm.tm[i+1][0],mm.tm[i+1][1]);
		line(mm.tm[i][0],mm.tm[i][1],mm.tm[0][0],mm.tm[0][1]);
}

void quadrant()
{

	int midx,midy,xmax,ymax,i,j;
	char a[10],*s;

	xmax = getmaxx();

	ymax = getmaxy();

	midx = xmax / 2;

	midy = ymax / 2;

	line(midx, 0, midx, ymax);

	line(0, midy, xmax, midy);

	outtextxy(midx+5,midy+5,"O(0,0)");

	for(i = 50,j=10; i<ymax; i=i+50,j=j+10)
	{
		s=itoa(j,a,10);
		outtextxy(midx+i+2,midy+2,s);
	}

	for(i = -50,j=10; i<=midx; i=i-50,j=j+10)
	{
		s=itoa(j,a,10);
		outtextxy(midx+i+2,midy+2,s);
	}

	for(i = 50,j=10; i<=midx; i=i+50,j=j+10)
	{
		s=itoa(j,a,10);
		outtextxy(midx+2,midy-i+2,s);
	}

	for(i = -50,j=10; i<=midx; i=i-50,j=j+10)
	{
		s=itoa(j,a,10);
		outtextxy(midx+2,midy-i+2,s);
	}
}

matrix matrix::mul(matrix m1,int m,int n)
{
	rows=m;cols=n;
	matrix m3;
	for(int i=0;i<rows;i++)
	for(int j=0;j<cols;j++)
	{
		m3.tm[i][j]=0;
		for(int k=0;k<m1.cols;k++)
			m3.tm[i][j]=m3.tm[i][j]+tm[i][k]*m1.tm[k][j];
	}
	return m3;
}

void main()
{
	int gd=DETECT,gm,c;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	int m,n,nv,angle,xc,yc;
	float v[5][3];
	cout<<"\nEnter the number of vertices: ";
	cin>>nv;
	cout<<"\nEnter the co-ordinates of vertices: ";
	for(int i=0;i<nv;i++)
	{
		cin>>m>>n;
		v[i][0]=m;
		v[i][1]=n;
		v[i][2]=1;
	}
	polygon p;
	matrix m1(v,nv,3);
	cout<<"\n\nCo-ordinates in matrix form";
	m1.display(nv,3);
	quadrant();
	p.drawpoly(m1,nv);
	int ch;
	float a1,b1;
	do
	{
		cout<<"\n\n\n\n\n---Menu---";
		cout<<"\n1Reflection about X\n2Reflection about Y";
		cout<<"\n3Reflection about arbitrary line\n4Exit";
		cout<<"\nEnter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
				matrix m2;
				m2.ref_x(3,3);
				matrix m3;
				cout<<"\n X Matrix";
				m2.display(3,3);
				cout<<"\n\n Resultant matrix";
				m3=m1.mul(m2,nv,3);
				m3.display(nv,3);
				getch();
				cleardevice();
				quadrant();
				p.drawpoly(m1,nv);
				p.drawpoly(m3,nv);
				getch();
				break;
			case 2:
				matrix m4,m5;
				m4.ref_y(3,3);
				cout<<"\n\n Y Matrix";
				m4.display(3,3);
				cout<<"\n\n Resultant matrix";
				m5=m1.mul(m4,nv,3);
				m5.display(nv,3);
				getch();
				cleardevice();
				quadrant();
				p.drawpoly(m1,nv);
				p.drawpoly(m5,nv);
				getch();
				break;
	  case 3:cout<<"Enter the value of a and b: ";
				cin>>a1>>b1;
				matrix m6,m7;
				m6.ref_arb_line(a1,b1,3,3);
				cout<<"\n\n Matrix";
				m6.display(3,3);
				cout<<"\n\n Resultant matrix";
				m7=m1.mul(m6,nv,3);
				m7.display(nv,3);
				getch();
				cleardevice();
				quadrant();
				p.drawpoly(m1,nv);
				p.drawpoly(m7,nv);
				getch();
				break;
			case 4:exit(0);

		}
  }while(ch!=4);
	getch();
	closegraph();
}
