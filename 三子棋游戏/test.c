#define _CRT_SECURE_NO_WARNINGS 
#include "game.h"
game()
{
	    char ret = 0;
		char board[ROW][COL] = { 0 };
		init_board(board, ROW, COL);//��ʼ����ά����
		print_board(board, ROW, COL);//��ӡ����
		do
		{
		player_move(board, ROW, COL);
		print_board(board, ROW, COL);
		ret = check_win(board, ROW, COL);//��ӮX ����ӮO ƽ��p ����j
		if (ret !='j')
		{
			break;
		}
		computer_move(board, ROW, COL);
		print_board(board, ROW, COL);
		ret = check_win(board, ROW, COL);
		if (ret != 'j')
		{
			break;
		}
		
		//int ret = check_win(board, ROW, COL);
	} while (1);
		if (ret == 'X')
		{
			printf("���Ӯ\n");
		}
		if (ret == 'O')
		{
			printf("����Ӯ\n");
		}
		if (ret == 'p')
		{
			printf("ƽ��\n");
		}


}
menu()
{
	printf("***********************\n");
	printf("*****1 ��ʼ 0 ����*****\n ");
	printf("***********************\n");
}
void test()
{
	srand((unsigned int)time(NULL));//��ϵͳʱ��Ϊ�������������
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