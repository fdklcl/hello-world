#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdarg.h>
//.ʹ�ÿɱ������ʵ�ֺ���������������ƽ��ֵ��

//ʹ�ÿɱ������ʵ�ֺ������������������ֵ��
int average(int n,...)
{
	int sum = 0;
	va_list arg=NULL;
	va_start(arg, n);
	for (int i = 0; i < n; i++)
	{
		sum = sum + _crt_va_arg(arg, int);
	}
	_crt_va_end(arg);
	return sum / n;
}
int Max(int n, ...)
{
	va_list arg = NULL;
	va_start(arg, n);
	int max = va_arg(arg, int);
	for (int i = 1; i < n; i++)
	{
		int ret = va_arg(arg, int);
		if (ret>max)
		{
			max = ret;
		}
	}
	va_end(arg);
	return max;
}
int main()
{
	//int ret = average(2, 1, 2);
	int ret = Max(2, 1, 2);
	printf("%d", ret);
	getchar();
	return 0;
}