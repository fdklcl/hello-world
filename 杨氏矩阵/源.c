#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>

//���Ͼ��� 
//��һ����ά����.
//�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����.
//�������������в���һ�������Ƿ���ڡ�
//ʱ�临�Ӷ�С��O(N);
//
//���飺
//1 2 3
//2 3 4
//3 4 5
//
//
//1 3 4
//2 4 5
//4 5 6

int search(int arr[3][3],int row,int col, int num)
{
	int x = 0;
	int y = col - 1;
	while ((x<row) && (y>0))
	{
		if (num > arr[x][y])
		{
			x++;
		}
		else if (num == arr[x][y])
		{
			return arr[x][y];
		}
		else if (num < arr[x][y])
		{
			y--;
		}
	}
	return -1;
}
int main()
{
	int arr[3][3] ={ { 1, 2, 3 }, { 2, 3, 4 }, { 3, 4, 5 }};
	int ret=search(arr,3,3,3);
	printf("%d", ret);
	getchar();
	return 0;
}