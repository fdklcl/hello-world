#define _CRT_SECURE_NO_WARNINGS 
//1.��д������
//unsigned int reverse_bit(unsigned int value);
//��������ķ��� ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ��
//�磺
//��32λ������25���ֵ�������и�λ��
//00000000000000000000000000011001
//��ת�󣺣�2550136832��
//10011000000000000000000000000000
//���������أ�
//2550136832
#include<stdio.h>
#include<math.h>
int sum = 0;
int reverse_bit(unsigned int value)
{
	for (int i = 0; i < 32; i++)
	{
		sum=sum << 1;
		sum=((value >> i) & 1) | sum;
	}
	return sum;
}
int main()
{
	int ret=reverse_bit(25); 
	printf("%u", ret);
	getchar();
	return 0;
}