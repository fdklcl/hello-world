#define _CRT_SECURE_NO_WARNINGS
//5.дһ������Խ�һ�����ֵ�����λ��ż��λ������
//6.ʹ�ú�ʵ������������ϴ�ֵ��

#include<stdio.h>
//#define MAX(x,y) x > y ? x : y
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int max = MAX(a, b);
//	printf("%d", max);
//	getchar();
//	return 0;
//}
#define CHANGE(m) ((a & 0xaaaaaaaa)>>1) |((a & 0x5555555555)<<1)
int main()
{
	int a = 10;
	int b = CHANGE(a);
	printf("%d", b);
	getchar();
	return 0;
}