#include<stdio.h>
#include<conio.h>
#include<windows.h>
void gotoxy(int x, int y)
{
    COORD coord = {x, y};   
    /*COORD��Windows API�ж����һ�ֽṹ����ʾһ���ַ��ڿ���̨��Ļ�ϵ����ꡣ�䶨��Ϊ��

    typedef struct _COORD {

    SHORT X; // horizontal coordinate

    SHORT Y; // vertical coordinate
    } COORD;*/

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int main(void)
{
	int i,j,x,y;
	x=9;y=5;
	for(i=1;i<=9;i++){
		gotoxy(x,y);
		printf("%2d ",i);
		x+=3;
	}
	x=7;y=6;
	for(i=1;i<=9;i++){
		gotoxy(x,y);
		printf("%2d",i);
		y++;
	}
	x=9;y=6;
	for(i=1;i<=9;i++){
		for(j=1;j<=9;j++){
			gotoxy(x,y);
			printf("%2d ",i*j);
			y++;
		}
		y-=9;
		x+=3; 
	}
	printf("\n\n");
}
