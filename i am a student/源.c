#define _CRT_SECURE_NO_WARNINGS 
//��һ���ַ����������Ϊ : "student a am i", ���㽫��������ݸ�Ϊ"i am a student".
//	Ҫ��
//	����ʹ�ÿ⺯����ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���
//
#include<stdio.h>
#include<string.h>
#include<assert.h>
void reserve(char*left,char*right)
{
	assert(left != NULL);
	assert(right != NULL);
	while (left< right)
	{
		int temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}
}
void reserve_all(char*p)
{
	int len = strlen(p);
	reserve(p,p+len-1);//�����ַ���
	while (*p!='\0')
	{
		char* end = p;
		char* start = p;
		while ((*end != ' ') && (*end != '\0'))
		{
			end++;
		}
		reserve(start, end-1);
		if (*end == ' ')
			p = end + 1;
		/*else
			p = end;*/
	}

}
int main()
{
	char arr[] = "student a am i";
	reserve_all(arr);
	printf("%s", arr);
	getchar();
	return 0;
}