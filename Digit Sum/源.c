#define _CRT_SECURE_NO_WARNINGS 
//дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ�
//���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19
#include<stdio.h>
int DigitSum(int n)
{
	if (n < 10)
		return n;
	else
	{
		return n % 10 + DigitSum(n / 10);
	}
}
int main()
{
	int ret=DigitSum(1729);
	printf("%d", ret);
	getchar();
	return 0;
}

