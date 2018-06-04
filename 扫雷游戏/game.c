#define _CRT_SECURE_NO_WARNINGS 
#include"game.h"
int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y - 1] + mine[x - 1][y]
		+ mine[x + 1][y] + mine[x - 1][y + 1] + mine[x][y + 1] + mine[x + 1][y + 1] - 8 * '0';
}
void ChangeMine( char mine[ROWS][COLS],char show[ROWS][COLS], int x, int y)
{

	int count = GetMineCount(mine, x, y);
	if (count == 0)//�����Χ�˸�����û�ף�����Χ�˸����ӵ�����
	{
		show[x][y] = count + '0';
		for (int i = x - 1; i <= x + 1; i++)
		{
			for (int j = y-1; j <= y + 1; j++)
			{
				show[i][j] = GetMineCount(mine, i, j) + '0';
				/*if (GetMineCount(mine, i, j) == 0)
				{
					ChangeMine(mine, show, i, j);
				}*/
			}
		}
	}
	else{//������ף�������Χ�˸����ӵ��׵���Ŀ
		show[x][y] = count + '0';
	}
		
		
}

void INIT(char arr[ROWS][COLS], int rows, int cols, char ret)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = ret;
		}
	}
}
void PRINT(char arr[ROWS][COLS], int row, int col)
{
	printf("  ");
	for (int i = 1; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (int i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void SET_MINE(char arr[ROWS][COLS], int row, int col)
{
	int count = EASY;
	while (count)
	{

		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (arr[x][y] == '0')
		{
			count--;
			arr[x][y] = '1';
		}
	}
}
void clear(char arr[ROWS][COLS], char arr1[ROWS][COLS], int row, int col)
{
	int c = 0;
	int d = 0;
	int x=0;
	int y = 0;
	while (c<row*col-EASY)
	{
		printf("���������꣺");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//������������Ϸ�
		{
			d++;
			if (1 == d&&arr[x][y] == '1')//��֤��һ���ȵ���Ҳ����ը�������׻�λ��
			{
				
					arr[x][y] ='0';
					arr1[x][y] ='0';
					while (1)
					{
						int a = rand() % row + 1;
						int b = rand() % col + 1;
						if (arr[a][b] == '0')
						{
							arr[a][b] = '1';
							break;
						}
					}PRINT(arr1, ROW, COL);
			}
			else//��һ��û�ȵ���
			{
				if (arr[x][y] == '0')
				{
					ChangeMine(arr, arr1, x, y);
					PRINT(arr1, ROW, COL);
					c++;
				}
				else if (arr[x][y] == '1')
				{
					printf("ը����,ը���ˣ�ը����\n");
					break;
				}
			}
		}
		else
		{
			printf("���겻�Ϸ�");
		}
	}
	if (c == row*col - EASY)
	{
		printf("���׳ɹ�\n");
	}
}


