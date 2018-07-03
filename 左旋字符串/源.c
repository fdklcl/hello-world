#define _CRT_SECURE_NO_WARNINGS 
//1.ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB
//һ ������ⷨ
#include<stdio.h>
#include<assert.h>
//void left_spin(char arr[], int k)
//{
//	int len = strlen(arr);
//	for (int i = 0; i < k; i++)
//	{
//		int temp = arr[0];
//		for (int j = 0; j < len-1; j++)
//		{
//			arr[j] = arr[j+1];
//		}
//		arr[len-1] = temp;
//	}
//}
//2,��������
void reserve(char arr[],int left ,int right)
{
	while (left < right)
	{
		char temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
		left++;
		right--;
	}
}
void left_move(char arr[],int k)
{
	int len = strlen(arr);
	assert(k <= len);
	reserve(arr,0, k-1);
	reserve(arr, k,len-1);
	reserve(arr,0, len - 1);
}
int main()
{
	char arr[] = "abcdef";
	left_move(arr, 2);
	printf("%s", arr);
	getchar();
	return 0;
}