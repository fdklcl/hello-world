#define _CRT_SECURE_NO_WARNINGS 
//��дһ������reverse_string(char * string)���ݹ�ʵ�֣�
//ʵ�֣��������ַ����е��ַ��������С�
//Ҫ�󣺲���ʹ��C��������
//���ַ�������������
char* reverse_string(char * string)
{
	int len = strlen(string);
	char temp = *(string);
	*(string) = *(string + len - 1);
	*(string + len - 1) = '\0';
	if (strlen(string)> 1)
		reverse_string(string + 1);
	*(string + len - 1) = temp;
}
#include<stdio.h>
int main()
{
	char arr[100] = "abcdef";
	reverse_string(arr);
	printf("%s", arr);
	getchar();
	return 0;
}
