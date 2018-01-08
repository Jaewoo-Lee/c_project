#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

void gotoxy(int x, int y);
void wall(int x, int y);

int keycode = 72;
int direct = 0;
int body[25][80];

void delay(int ndel);
int checkDie(int diex, int diey);


void delay(int ndel)
{
	int noldT = clock(), nnewT = clock();
	while ((nnewT - noldT) < ndel)
	{
		nnewT = clock();
	}

	
}

int checkDie(int diex, int diey)
{
	//°æ°è¼±
	if ((diex == 0) || (diey == 0) || (diex == 79) || (diey == 23))
	{
		return 0;
	}
	if (body[diey][diex] == 1)
	{
		return 0;
	}
	body[diey][diex] = 1;
	return 1;
}

void gotoxy(int x, int y)
{
	COORD Cur = { (SHORT)x, (SHORT)y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void setcolor(int color, int bgcolor)
{
	color &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}

void wall()
{
	for (int i = 0; i < 80; i++)
	{
		printf("x");
	}

	for (int j = 0; j < 22; j++)
	{
		printf("x");
		for (int k = 0; k < 78; k++)
		{
			printf(" ");
		} 
		printf("x");
	}
	for (int n = 0; n < 80; n++)
	{
		printf("x");
	}
}

void main(void)
{
	int haedx = 40, haedy = 12;

	wall();
	
	for (int x = 0; x < 80; x++)
	{
		for (int y = 0; y < 25; y++)
		{
			body[y] [x] = -1;
		}
	}
	while (1)
	{

		delay(100);
		if (kbhit() == 1)
		{
			keycode = getch();
			if (keycode == 72)
			{
				direct = 0;
			}
			else if (keycode == 80)
			{
				direct = 1;
			}
			else if (keycode == 75)
			{
				direct = 2;
			}
			else if (keycode == 77)
			{
				direct = 3;
			}
		}
		if (direct == 0)
		{
			haedy -= 1;
		}
		else if (direct == 1)
		{
			haedy += 1;
		}
		else if (direct == 2)
		{
			haedx -= 1;
		}
		else if (direct == 3)
		{
			haedx += 1;
		}
		gotoxy(haedx, haedy);
		printf("O", haedx, haedy);

		if (checkDie(haedx, haedy) == 0)
		{
			break;
		}

	}
	gotoxy(0, 25);
	setcolor(12, 0);
	printf("GAME OVER\n");
}
