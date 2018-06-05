#define _CRT_SECURE_NO_WARNINGS 
#include "game.h"
init_board(char board[ROW][COL], int row, int  col)//��ʼ������
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] =' ';
		}
	}
}
print_board(char board[ROW][COL], int row,int  col)//��ӡ����
{
	for (int i = 0; i < row; i++)
	{
		
			printf(" %c | %c | %c \n", board[i][0],board[i][1],board[i][2]);
			if (i<row-1)
			printf("---|---|---\n");
		
			
	}
}
player_move(char board[ROW][COL], int row, int  col)
{
	int row1 = 0;
	int col1 = 0;
	do
	{
	printf("����ߣ�");
	printf("���������꣺");
	scanf("%d %d", &row1,&col1);
		if (row1 > 0 && row1 <= ROW && col1 >0 && col1 <= COL)
		{//�������ĺϷ���
			if (board[row1-1][col1-1] ==' ')
			{
				board[row1 - 1][col1 - 1] = 'X';
				break;
			}
			else
			{
				printf("�����Ѿ���ռ�ã�����������\n");
			}
		}
		else
		{
			printf("�������\n");
		}
	} while (1);

}
computer_move(char board[ROW][COL], int row, int  col)
{
	int x = 0;
	int y = 0;
	printf("�����ߣ�\n");
	do{
	x=rand()%row;
	y = rand()%col;
	
		if (board[x][y] == ' ')
		{
			board[x][y] = 'O';
			break;
		}
	}while (1);
}
int full_is_board(char board[ROW][COL], int row, int  col)
{//���������0������п�λ�÷���1
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 1;
			}
		}
	}
	 return 0;
}
char check_win(char board[ROW][COL], int row, int  col)
{//���Ӯ����X,����Ӯ����O,ƽ�ַ���p,����δ������j
	for (int i = 0; i < row; i++)
	{
		if (board[i][0] ==board[i][1] && board[i][1] == board[i][2]&&board[i][1]!=' ')
		{
			return board[i][0];
		}
	}
	for (int i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[0][i];
		}
	}
	if (board[0][0] == board[1][1]&&board[1][1] == board[2][2]&&board[1][1]!=' ')
	{
		return board[1][1];
	}
	else if (board[0][2] == board[1][1]&&board[1][1] == board[2][0] &&board[1][1]!= ' ')
	{
		return board[1][1];
	}
	else if (full_is_board(board, row, col) == 0)
	{
		return  'p';
	}
	else if (full_is_board(board, row, col) == 1)return 'j';
}