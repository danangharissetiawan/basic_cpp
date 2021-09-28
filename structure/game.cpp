#include<iostream>
#include<ncurses.h>
// #include<dos.h>
// #include<windows.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

struct stack
{
	char barang[10];
	int x, y;
};

struct stack gudang[5];
int top=1;
int maks=10;
int score=50;


void gotoxy(int x, int y)
{
   	COORD k = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), k);
}

void lambatkan()
{
	int x;
	for(x=1;x<=100000;x++)
	   cout<<"";
}

void push(char a[10], int b, int c)
{
	if(top<=maks)
	{
		strcpy(gudang[top].barang,a);
		gudang[top].x=b;
		gudang[top].y=c;
		top++;
		score=score+10;
	}	
	else
	{
		score=score+100;
	}
}

void pop()
{
	if(top>1)
	{	
		score=score-10;
		top--;	
	}	
}

void tampilkan()
{
	int a;

	for(a=1;a<=10;a++)
	{
		gotoxy(62,20-a);printf("                 ");
	}

	for(a=1;a<top;a++)
	{
		gotoxy(62,20-a);printf("%d. %s %d %d",a, gudang[a].barang, gudang[a].x, gudang[a].y);
	}
}
int main()
{
	char ch;
	int kolom=40, brs=12,bk,bb;
	float mk=2, mb=2, bmk,bmb;
	int bmakan, kmakan;
	char y;
	srand((unsigned)time(0)); 
   	int x;
   	char food[5][10]={"*Garam","*Gula","*Tepung","*Teh","*SUSU"};
   	int f1;
   	
   for(x=0;x<60;x++)
	  {
	    gotoxy(x,0);printf("%c",196);
	    gotoxy(x,24);printf("%c",196);
	  }
   for(x=1;x<24;x++)
	  {
	    gotoxy(0,x);printf("%c",179);
	    gotoxy(60,x);printf("%c",179);
	  }
	gotoxy(0,0);printf("%c",218);
	gotoxy(60,24);printf("%c",217);	
	gotoxy(0,24);printf("%c",192);	
	gotoxy(60,0);printf("%c",191);	
	
   for(x=61;x<79;x++)
	  {
	    gotoxy(x,0);printf("%c",196);
	    gotoxy(x,24);printf("%c",196);
	  }
   for(x=0;x<24;x++)
	  {
	    gotoxy(61,x);printf("%c",179);
	    gotoxy(79,x);printf("%c",179);
	  }
	gotoxy(61,0);printf("%c",218);
	gotoxy(79,24);printf("%c",217);	
	gotoxy(61,24);printf("%c",192);	
	gotoxy(79,0);printf("%c",191);	
	
	gotoxy(63,1);cout<<"GAME SEDERHANA";
	gotoxy(63,2);cout<<"MIRIP  PACKMAN";
	gotoxy(63,3);cout<<"Versi 1.0-2021";
	gotoxy(63,23);cout<<"feri@gmail.com";
	
	bmakan=rand()%23+1;
	kmakan=rand()%50+1;
	f1=rand()%5;
    do
	{		
		gotoxy(kolom,brs);printf("L");
		gotoxy(int(mk),int(mb));printf("M");
		gotoxy(kmakan,bmakan);printf("%s",food[f1]);
		gotoxy(65,21);cout<<"Score : "<<score-50;
		bk=kolom;
		bb=brs;
		bmk=mk;
		bmb=mb;
		if(kbhit())
	  		ch = _getch();
       	if(ch==77) kolom++;
       	if(ch==75) kolom--;
       	if(ch==80) brs++;
       	if(ch==72) brs--;

		if(kolom<=1) kolom=1;
		if(kolom>59) kolom=59;
		if(brs<=1) brs=1;
		if(brs>=23) brs=23;
      	
		if(mk>kolom) mk=mk-0.2;
		if(mk<kolom) mk=mk+0.2;
		if(mb>brs) mb=mb-0.25;
		if(mb<brs) mb=mb+0.25;      	

		if((brs==bmakan) && (kolom==kmakan))
		{
			
			push(food[f1],bmakan,kmakan);
			gotoxy(kmakan,bmakan);printf("        ");	
			bmakan=rand()%23+1;
			kmakan=rand()%50+1;
			f1=rand()%5;
			tampilkan();
			
		}
       	lambatkan();
       	gotoxy(bk,bb);printf(" ");
		gotoxy(int(bmk),int(bmb));printf(" ");
		
		if((kolom==int(mk)) && (brs==int(mb)))
		{
			mk=2; 
			mb=2;
			if (top==1)	
			{
				gotoxy(20,21);cout<<"Game Over... ";
				gotoxy(20,22);cout<<"Press Any Key";
				getch();
				return 0;
			}
			else
			{
				pop();
				tampilkan();
			}
		}		
	}
	while(ch!=27);	
    return 0;
}