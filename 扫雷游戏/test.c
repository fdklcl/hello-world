#define _CRT_SECURE_NO_WARNINGS 
#include "game.h"
game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	INIT(mine, ROWS, COLS, '0');//��mine��ʼ��Ϊȫ0
	INIT(show, ROWS, COLS, '*');//��show��ʼ��Ϊ*
	PRINT(show, ROW, COL);
	SET_MINE(mine, ROW, COL);//����
	PRINT(mine, ROW, COL);
	clear(mine,show, ROW, COL);//����
	PRINT(mine, ROW, COL);
}
menu()
{
	printf("***********************\n");
	printf("*****1 ��ʼ 0 ����*****\n ");
	printf("***********************\n");
}
void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("��Ϸ������\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	fflush(stdin);//������뻺����
	getchar();
	return 0;
}