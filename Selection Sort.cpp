//Visual Selection Sort

#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void object(int,int,int);
void select(int);
void flow(int,int);
void mixing(int,int);
int el[10];
int main()
{
 int n,i,d=0,m=0;
 printf("Enter the No of Elements : " );
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  printf("Enter the %d Element : ",i+1);
  scanf("%d",&el[i]);
 }
 initgraph(&d,&m,"");
 initwindow(700,500);
 settextstyle(3,0,1);
 outtextxy(250,50,"GIVEN NUMBERS ");
// outtextxy(250,260," AFTER SORTING ");
// line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
 for(i=0;i<n;i++)
 {
  object(100+i*50,150,el[i]);
  getch();
 }
 select(n);
/* for(i=0;i<n;i++)
 {
  object(100+i*50,350,el[i]);
  getch();
 }*/
 getch();
}
void select(int n)
{
 int i,j,temp,index;

 for(i=0;i<n-1;i++)
 {
    index=i;
    for(j=i+1;j<n;j++)
    {
        if(el[j]<el[index])
        {
            index=j;
        }
    }
    if(i!=index)
    {
        getch();
        flow(i,index);
        temp=el[i];
        el[i]=el[index];
        el[index]=temp;
    }
 }
 outtextxy(170,300," NUMBERS SORTED");
}
void object(int x,int y,int no)
{
 char s[8];
 sprintf(s,"%d",no);
 //arc(x,y,0,180,20);
 circle(x,y,20);
 settextstyle(0,0,3);
 outtextxy(x-10,y-10,s);
}
void flow(int f,int s)
{
 int i;
 for(i=0;i<50;i++)
 {
  setcolor(YELLOW);
  object(100+f*50,150+i*4,el[f]);
  delay(15);
  setcolor(0);
  object(100+f*50,150+i*4,el[f]);
 }
 setcolor(YELLOW);
 object(100+f*50,150+i*4,el[f]);
 for(i=0;i<50;i++)
 {
  setcolor(LIGHTGREEN);
  object(100+s*50,150+i*4,el[s]);
  delay(10);
  setcolor(0);
  object(100+s*50,150+i*4,el[s]);
 }
 setcolor(LIGHTGREEN);
 object(100+s*50,150+i*4,el[s]);
 mixing(f,s);
 for(i=50;i>0;i--)
 {
  setcolor(LIGHTGREEN);
  object(100+f*50,150+i*4,el[s]);
  delay(10);
  setcolor(0);
  object(100+f*50,150+i*4,el[s]);
 }
 setcolor(WHITE);
 object(100+f*50,150+i*4,el[s]);
 for(i=50;i>0;i--)
 {
  setcolor(WHITE);
  object(100+s*50,150+i*4,el[f]);
  delay(15);
  setcolor(0);
  object(100+s*50,150+i*4,el[f]);
 }
 setcolor(WHITE);
 object(100+s*50,150+i*4,el[f]);
}
void mixing(int f,int s)
{
 int i;
 for(i=0;i<(s-f)*50;i++)
 {
  setcolor(MAGENTA);
  object(100+f*50+i,350,el[f]);
  object(100+s*50-i,350,el[s]);
  delay(20);
  setcolor(0);
  object(100+f*50+i,350,el[f]);
  object(100+s*50-i,350,el[s]);
  }
  setcolor(MAGENTA);
  object(100+f*50+i,350,el[f]);
  object(100+s*50-i,350,el[s]);
}
