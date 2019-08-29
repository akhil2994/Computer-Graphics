public class Practical_2_B_B extends Applet
{
public int x,y,r=40;

public double d;
 public void init()
  {
  
  
  
  
  }
 public void paint( Graphics g )
       {
 g.setColor(Color.black);
 
 d=1.25-(float)r;
 x=0; 
 y=r;
 do
 {
 g.setColor(Color.blue);
 g.drawRect(x+200,y+200,1,1);
 g.drawRect(-x+200,-y+200,1,1);
 //g.drawRect(y+200,x+200,1,1);
 g.drawRect(-y+200,-x+200,1,1);
 g.drawRect(-x+200,y+200,1,1);
 g.drawRect(y+200,-x+200,1,1);
 g.drawRect(x+200,-y+200,1,1);
 g.drawRect(-y+200,x+200,1,1);
 
 g.setColor(Color.black); 
 g.drawRect(x+300,y+200,1,1);
 g.drawRect(-x+300,-y+200,1,1);
 //g.drawRect(y+300,x+200,1,1);
 g.drawRect(-y+300,-x+200,1,1);
 g.drawRect(-x+300,y+200,1,1);
 g.drawRect(y+300,-x+200,1,1);
 g.drawRect(x+300,-y+200,1,1);
 g.drawRect(-y+300,x+200,1,1);
 
 g.setColor(Color.red);
 g.drawRect(x+400,y+200,1,1);
 g.drawRect(-x+400,-y+200,1,1);
 g.drawRect(y+400,x+200,1,1);
 g.drawRect(-y+400,-x+200,1,1);
 g.drawRect(-x+400,y+200,1,1);
 g.drawRect(y+400,-x+200,1,1);
 g.drawRect(x+400,-y+200,1,1);
 g.drawRect(-y+400,x+200,1,1);

 g.setColor(Color.yellow); 
 g.drawRect(x+250,y+250,1,1);
 g.drawRect(-x+250,-y+250,1,1);
 g.drawRect(y+250,x+250,1,1);
 //g.drawRect(-y+250,-x+250,1,1);
 g.drawRect(-x+250,y+250,1,1);
 g.drawRect(y+250,-x+250,1,1);
 g.drawRect(x+250,-y+250,1,1);
 g.drawRect(-y+250,x+250,1,1); 
 
 g.setColor(Color.green); 
 g.drawRect(x+350,y+250,1,1);
 g.drawRect(-x+350,-y+250,1,1);
 g.drawRect(y+350,x+250,1,1);
 //g.drawRect(-y+350,-x+250,1,1);
 g.drawRect(-x+350,y+250,1,1);
 g.drawRect(y+350,-x+250,1,1);
 g.drawRect(x+350,-y+250,1,1);
 g.drawRect(-y+350,x+250,1,1);



 g.setColor(Color.blue);
 g.drawRect(y+200,x+200,1,1);
 g.setColor(Color.black);
 g.drawRect(y+300,x+200,1,1);
 g.setColor(Color.yellow);
 g.drawRect(-y+250,-x+250,1,1);
 g.setColor(Color.green);
 g.drawRect(-y+350,-x+250,1,1);
 try{Thread.sleep(500);}
 catch(Exception e){}
 if(d<0)
 d=d+2*(x+1)+1;

 else
  {
  y--;
  d=d+2*(x+1)+1-2*y;
  }
 x++;
 }while(x<y);
     
 

}
}