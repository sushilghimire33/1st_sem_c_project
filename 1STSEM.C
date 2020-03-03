#include<conio.h>+
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<time.h>

// y coordinate of board
#define y1 425
#define y2 435

void moveRight(int, int);
void moveLeft(int, int);
void ball();

int x=30, y=60, r=6;

void main()
{
	//for drawing background
	int gd=0,gm;
	int x1=250,x2=150, gameover = 0;
	initgraph(&gd,&gm,"C://TURBOC3//BGI");
	setbkcolor(BLACK);
	setcolor(RED);
	rectangle(0,0,639,450);
	rectangle(10,10,629,440);  //smaller rectangle

	// for horizontally moving rectangular bar

	setcolor(BLUE);
	setfillstyle(1,6);
	rectangle(x1,y1,x2,y2);
	// floodfill(250,425,6);
	while(!gameover)
	{
		ball();
		// keyboard input to move bar
		if(kbhit())
		{
			// movements
			switch(getch())
			{
			  case 27:
				closegraph();
				exit(0);
			  case 'd':
			  case 77:
				x1+=5;
				x2+=5;
				moveRight(x1, x2);
				break;
			  case 'a':
			  case 75:
				x1-=5;
				x2-=5;
				moveLeft(x1, x2);
				break;
			  default:
				break;
			}
		}
	}
	 getch();
	 closegraph();
}


void moveRight(int x1, int x2)
{
	setcolor(BLACK);
	rectangle(x1-5, y1, x2-5, y2);
	setcolor(BLUE);
	rectangle(x1, y1, x2, y2);
}


void moveLeft(int x1, int x2)
{
	setcolor(BLACK);
	rectangle(x1+5,y1, x2+5, y2);
	setcolor(BLUE);
	rectangle(x1, y1, x2, y2);
}

void ball()
{
	setcolor(BLACK);
	circle(x-1, y-1, r);
	delay(20);
	// rule for moving ball
	if(x >= 10) {
		x++;
		y++;
	} else if(y > 100) {
		x--;
		y--;
	}
	else {
		x++;
		y++;
	}
	setcolor(RED);
	circle(x, y, r);
}