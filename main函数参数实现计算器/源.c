#define _CRT_SECURE_NO_WARNINGS 
//ʹ��main�����Ĳ�����ʵ��һ��������������������Խ���������������һ�������� - a��ѡ��ִ�мӷ���
//�� - s��ѡ��ִ�м������� - m��ѡ��ִ�г˷����� - d��ѡ��ִ�г�����������������Ϊ��������
//
//���磺�����в������룺test.exe -a 1 2
//ִ��1 + 2���3
#include <stdio.h>
int Add(int a, int b)
{
	return a + b;
}
int Sub(int a, int b)
{
	return a -b;
}
int Mul(int a, int b)
{
	return a *b;
}
int Div(int a, int b)
{
	return a / b;
}
int main(int argc,char *argv[],char *envp[])
{
	if (argc != 4)
	{
		printf("��������\n");
		exit(1);
	}
	int ret = 0;
	switch (*(argv[1] + 1))
	{
	case 'a':
		 ret = Add(atoi(argv[2]), atoi(argv[3]));
		 printf("%d", ret);
		break;
	case 's':
		 ret = Sub(atoi(argv[2]), atoi(argv[3]));
		 printf("%d", ret);
		break;
	case 'm':
		 ret = Mul(atoi(argv[2]), atoi(argv[3]));
		 printf("%d", ret);
		break;
	case 'd':
		 ret = Div(atoi(argv[2]), atoi(argv[3]));
		 printf("%d", ret);
		break;
	}
	getchar();
	return 0;
}
