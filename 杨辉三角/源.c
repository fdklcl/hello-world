#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>

int main()
{
	
	int arr[100][100] = {0};
	int row = 6;
	for (int n = 0; n <row; n++)
	{//��ӡ�ո�
		for (int i = 0; i < row-1 - n; i++)
		{
			printf(" ");
		}
		//��ӡ����
		for (int j = 0; j <= n ; j++)
		{
			printf("%3d", (arr[n][j] = (n == j || j == 0) ? 1: // ��β�� 1
				arr[n - 1][j] + arr[n - 1][j - 1])); // ʹ����һ�м��� 
		}
		printf("\n");
	}
	getchar();
	return 0;
}