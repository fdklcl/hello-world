#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int main()
{
	int i = 1;
	int n = 0;
	for (i=1;i <= 100; i++)
	{
		if (i/10 == 9)
		{
			printf("%d\n", i);
			n++;

		}
		else if (i%10 == 9)
		{
			printf("%d\n", i);
			n++;

		}


	}
	printf("����9�Ĵ���Ϊ��%d", n);
	getchar();
	return 0;
}