#define _CRT_SECURE_NO_WARNINGS ch
#include<stdio.h>
#include<Windows.h>
#include<math.h>
#include<time.h>
//��д����ģ��������������ĳ�����
//����������������룬������ȷ����ʾ����¼�ɹ���, ������󣬿����������룬����������Ρ�
//���ξ�������ʾ�˳�����
int main(){
	char arr[10] = { 0 };
	int count = 3;
	while (count--){
		printf("���������룺");
		scanf("%s", arr);
		if (0 == strcmp(arr, "123456")){
			printf("������ȷ����½�ɹ�\n");
		}
		else{
			printf("������%d�λ���\n", count);
		}
	}
	system("pause");

	return 0;
}