/*------------------------------------------------------------------
            2 D Transformations:
                     i) Simple Translation 
		     ii) Scaling, rotation about origin
		     iii)Rotation about arbitrary point
-------------------------------------------------------------------*/

#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<iostream.h>
void quadrant();
class matrix
{	float tm[5][3];
	int rows,cols;
	public:
		matrix()
		{ }
		matrix(float v[5][3],int m,int n);
		void display(int m,int n);

		friend polygon;
		matrix mul(matrix m2,int m,int n);
		void trmatrix(int tx,int ty,int m,int n)
		{
			rows=m;
			cols=n;
			tm[0][1]=tm[0][2]=tm[1][0]=tm[1][2]=0;
			tm[2][0]=tx;
			tm[2][1]=ty;
			tm[0][0]=tm[1][1]=tm[2][2]=1;
		}
		void scalematrix(int sx,int sy,int m,int n)
		{
			rows=m;
			cols=n;
			tm[0][1]=tm[0][2]=tm[1][0]=tm[1][2]=tm[2][0]=tm[2][1]=0;
			tm[0][0]=sx;
			tm[1][1]=sy;
			tm[2][2]=1;
		}

		void rot_matrix(int angle1,int m,int n)
		{
			rows=m;
			cols=n;
			tm[0][2]=tm[1][2]=tm[2][0]=tm[2][1]=0;
			tm[2][2]=1;
			tm[0][0]=tm[1][1]=cos(angle1*3.14/180);
			tm[0][1]=sin(angle1*3.14/180);
			tm[1][0]=-sin(angle1*3.14/180);
		 }
		void rot_pt_matrix(int angle,int xc,int yc,int m,int n)
		{
			rows=m;
			cols=n;
			tm[0][2]=tm[1][2]=tm[2][2]=0;
			tm[0][0]=tm[1][1]=cos(angle*3.14/180);
			tm[0][1]=sin(angle*3.14/180);
			tm[1][0]=-sin(angle*3.14/180);
			tm[2][0]=-xc*cos(angle*3.14/180)+yc*sin(angle*3.14/180)+xc;
			tm[2][1]=-xc*sin(angle*3.14/180)-yc*cos(angle*3.14/180)+yc;
			tm[2][2]=1;
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
		void drawpoly(matrix m,int nv,int col);
};

void polygon::drawpoly(matrix m,int nv,int col)
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

	setcolor(col);
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
	int m,n,nv,angle,angle1,xc,yc;
	float v[5][3];
	cout<<"\nEnter the number of vertices: ";
	cin>>nv;
	cout<<"\nEnter the co-ordinates of vertices:";
	for(int i=0;i<nv;i++)
	{
		cin>>m>>n;
		v[i][0]=m;
		v[i][1]=n;
		v[i][2]=1;
	}
	polygon p;
	matrix m1(v,nv,3);
	cout<<"\n\n Coordinates in Matrix form";
	m1.display(nv,3);
	quadrant();
	p.drawpoly(m1,nv,4);

	int ch;
	int tx,ty,sx,sy;
	do
	{
		cout<<"\n           ---Menu---";
		cout<<"\n1Translation\n2Scaling\n3Rotation";
		cout<<"\n4Rotation about arbitrary point\n5Exit";
		cout<<"\nEnter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:cout<<"\n\n Enter the translation factors tx,ty: ";
				cin>>tx>>ty;
				matrix m2;
				m2.trmatrix(tx,ty,3,3);
				matrix m3;
				cout<<"\n\n Translation matrix";
				m2.display(3,3);
				cout<<"\n\n Resultant matrix";
				m3=m1.mul(m2,nv,3);
				m3.display(nv,3);
				getch();
				cleardevice();
				quadrant();
				outtextxy(350,5,"TRANSLATION");
				p.drawpoly(m1,nv,4);
				p.drawpoly(m3,nv,10);
				getch();
				break;
			case 2:cout<<"\n\n Enter the Scaling factors sx,sy: ";
				cin>>sx>>sy;
				matrix m4,m5;
				m4.scalematrix(sx,sy,3,3);
				cout<<"\n\n Scaling matrix";
				m4.display(3,3);
				cout<<"\n\n Resultant matrix";
				m5=m1.mul(m4,nv,3);
				m5.display(nv,3);
				getch();
				cleardevice();
				quadrant();
				outtextxy(350,5,"SCALING");
				p.drawpoly(m1,nv,4);
				p.drawpoly(m5,nv,10);
				getch();
				break;
		case 3:cout<<"Enter the Rotation angle: ";
				 cin>>angle1;
				matrix m6,m7;
				m6.rot_matrix(angle1,3,3);
				cout<<"\n\n Rotation matrix";
				m6.display(3,3);
				cout<<"\n\n Resultant matrix";
				m7=m1.mul(m6,nv,3);
				m7.display(nv,3);
				getch();
				cleardevice();
				quadrant();
				outtextxy(350,5,"ROTATION");
				p.drawpoly(m1,nv,4);
				p.drawpoly(m7,nv,10);
				getch();
				break;
	  case 4:cout<<"Enter the co-ordinates for arbitrary point(xc,yc): ";
				cin>>xc>>yc;
				cout<<"Enter the rotation angle:";
				cin>>angle;
				matrix m8,m9;
				m8.rot_pt_matrix(angle,xc,yc,3,3);
				cout<<"\n\n Rotation matrix";
				m8.display(3,3);
				cout<<"\n\n Resultant matrix";
				m9=m1.mul(m8,nv,3);
				m9.display(nv,3);


				getch();
				cleardevice();
				quadrant();
				outtextxy(350,5,"ROTATION ABOUT ARBITRARY POINT");
				p.drawpoly(m1,nv,4);
				p.drawpoly(m9,nv,10);
				getch();
				break;
			case 5:exit(0);

		}
  }while(ch!=5);
	getch();
	closegraph();
}
