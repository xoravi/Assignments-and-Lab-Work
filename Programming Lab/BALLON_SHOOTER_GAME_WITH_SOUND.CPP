//BALLON SHOOTER WITH SOUND
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
union REGS in, out;
int n,miss,hits,check,scr;float sr;
char mis[10],hts[10],bul[10],score[10],suc[10],play='y';
void scrn1()
{	settextstyle(0,0,4);
	setcolor(CYAN);
	outtextxy(40,220,"!BALLOON SHOOTER!");
	setcolor(WHITE);settextstyle(0,0,1);
	outtextxy(270,280,"PRESS ENTER");
	getch();
	cleardevice();
}
void frntend()
{   settextstyle(0,0,1);setcolor(WHITE);
	rectangle(20,40,620,440);
	line(520,40,520,440);
	for(int i=120;i<440;i+=80)
		line(520,i,620,i);
	setcolor(GREEN);
	outtextxy(530,50,"SCORE:");
	outtextxy(530,130,"BULLETS:");
	outtextxy(530,210,"HITS:");
	outtextxy(530,290,"MISS:");
	outtextxy(530,370,"SUCCESS %:");
	setcolor(YELLOW);
	int polypnt[]={25,230,35,230,45,238,45,242,35,250,25,250,25,230};
	setfillstyle(INTERLEAVE_FILL,LIGHTBLUE);
	fillpoly(7,polypnt);
}
void ready()
{	frntend();
	setcolor(WHITE);settextstyle(0,0,2);
	outtextxy(270,240,"3");
	sound(100);delay(30);nosound();
	delay(1000);
	cleardevice();
	frntend();setcolor(WHITE);settextstyle(0,0,2);
	outtextxy(270,240,"2");
	sound(200);delay(30);nosound();
	delay(1000);
	cleardevice();
	frntend();setcolor(WHITE);settextstyle(0,0,2);
	outtextxy(270,240,"1");
	sound(300);delay(30);nosound();
	delay(1000);
	cleardevice();
	frntend();setcolor(WHITE);settextstyle(0,0,2);
	outtextxy(240,240,"READY!!");
	sound(350);delay(60);nosound();
	delay(1000);
	cleardevice();
	frntend();
}
void bckend()
{       n=10;miss=0;hits=0;scr=0;sr=0;
	int button;
	randomize();
	rec:
	while(n)
	{
		check=0;
		for(int i=420,j=random(5-1+1)+1;i>60;i--)
		{
			in.x.ax = 3;
			int86(0X33,&in,&out);
			button=out.x.bx&7;
			if(button)
			{	n--;
				sound(300);
				delay(100);
				nosound();
				for(int k=49;k<516&&i>60;k=k+3,i--)
				{	settextstyle(0,0,2);
					sprintf(bul,"%d",n);sprintf(mis,"%d",miss);sprintf(hts,"%d",hits);sprintf(score,"%d",scr);sprintf(suc,"%0.1f%",sr);
					outtextxy(530,150,bul);outtextxy(530,230,hts);outtextxy(530,310,mis);outtextxy(530,70,score);outtextxy(530,390,suc);
					setcolor(CYAN);
					circle(k,240,4);
					setcolor(RED);
					setfillstyle(11,LIGHTRED);
					fillellipse((j*90)+15,i,10,15);
					delay(10);
					cleardevice();
					frntend();
					if((k+4)>=((j*90)+5)&&(k+4)<=((j*90)+25)&&i>223&&i<257)
					{	sound(100);
						settextstyle(0,0,1);setcolor(WHITE);
						outtextxy(k+4,i,"POP");
						delay(70);
						nosound();
						hits++;
						scr=scr+100;
						check=1;
						break;
					}
				}
				if(check==0)
				{	sound(50);
					settextstyle(0,0,1);setcolor(WHITE);
					outtextxy(k-30,240,"MISS");
					delay(70);
					nosound();
					miss++;
					scr=scr-50;
				}
				sr=((float)hits/(float)(hits+miss))*100;
				goto rec;
			}
			settextstyle(0,0,2);
			sprintf(bul,"%d",n);sprintf(mis,"%d",miss);sprintf(hts,"%d",hits);sprintf(score,"%d",scr);sprintf(suc,"%0.1f%",sr);
			outtextxy(530,150,bul);outtextxy(530,230,hts);outtextxy(530,310,mis);outtextxy(530,70,score);outtextxy(530,390,suc);
			setcolor(RED);
			setfillstyle(11,LIGHTRED);
			fillellipse((j*90)+15,i,10,15);
			delay(10);
			cleardevice();
			frntend();
		}
	}
}
void endscrn()
{	cleardevice();
	frntend();
	settextstyle(0,0,2);setcolor(YELLOW);
	sprintf(bul,"%d",n);sprintf(mis,"%d",miss);sprintf(hts,"%d",hits);sprintf(score,"%d",scr);sprintf(suc,"%0.1f%",sr);
	outtextxy(530,150,bul);outtextxy(530,230,hts);outtextxy(530,310,mis);outtextxy(530,70,score);outtextxy(530,390,suc);
	outtextxy(220,240,"GAME OVER");
	getch();
	cleardevice();
	frntend();
	setcolor(YELLOW);settextstyle(0,0,2);
	outtextxy(220,240,"PLAY AGAIN?");
	setcolor(WHITE);settextstyle(0,0,2);
	outtextxy(270,260,"Y/N?");
	play=getch();
	cleardevice();
}
void main()
{	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	scrn1();
	while(play=='y')
	{	ready();
		bckend();
		endscrn();
	}
	closegraph();
}