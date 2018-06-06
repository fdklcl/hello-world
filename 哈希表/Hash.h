#include<stdio.h>
#include<assert.h>
//�˴�ʵ�ֵ��Ǿ�̬˳��������ϣ��ͻ�ķ���Ϊ��ɢ���е�����̽��
#define Max_size 10
typedef int DataType;
typedef enum{EX,EM,DEL}state;//����ö�����ͣ���ʾ״̬
typedef struct HTelem{//��ϣ���д洢��Ԫ��
	DataType data;
	state state;
}HTelem;
typedef struct HashTable{//��ϣ��
	HTelem array[Max_size];
	int size;//��ЧԪ�صĸ���EX
	int total;//EX+DEL�ĸ���
}HashTable;

void InitHashTable(HashTable* Hash){//��ϣ��ĳ�ʼ��������ϣ��ÿ��Ԫ�ص�״̬��ΪEM
	assert(Hash);
	int i = 0;
	for (i = 0; i < Max_size; i++){
		(Hash->array[i]).state = EM;
	}
	Hash->size = 0;
	Hash->total = 0;
}
void InsertHashTable(HashTable*Hash, DataType data){//����
	assert(Hash);
	if (Hash->total == Max_size){//��ϣ���Ѿ����������
		return;
	}
	//�����ϣ��ַ
	int addr = data%Max_size;
	while (Hash->array[addr].state != EM){//��λ��
		if (Hash->array[addr].state == EX){
			if (Hash->array[addr].data == data){//״̬ΪEX����ֵ�Ѵ��ڵ����
				return;
			}
		}
		addr++;//״̬ΪEX����ֵ�����ڣ�����״̬ΪDEL��ֱ��������
		if (addr ==Max_size){//�����һ��Խ�磬����ַ��Ϊ0
			addr = 0;
		}
	}
	//�ҵ�λ�ã���ֵ����
	Hash->array[addr].data = data;
	Hash->array[addr].state = EX;
	(Hash->size)++;
	(Hash->total)++;
}
int FindHashTable(HashTable *Hash, DataType data){//����data
	assert(Hash);
	int addr = data%Max_size;
	int start = addr;
	while (Hash->array[addr].state != EM){
		if (Hash->array[addr].state == EX){
			if (Hash->array[addr].data == data){
				printf("Ԫ�ش���\n");
				return addr;
			}
		}
		addr = addr + 1;
		if (addr ==Max_size){
			addr =0;
		}
		if (addr == start){//����һȦ��û�ҵ�
			printf("Ԫ�ز�����\n");
			return -1;
		}
	}
	printf("Ԫ�ز�����\n");
	return -1;
}
void delectHashTable(HashTable*Hash, DataType data){//ɾ��data,���ҵ�data,�ٽ�״̬��ΪDEL
	assert(Hash);
	int ret = FindHashTable(Hash, data);
	Hash->array[ret].state = DEL;
	(Hash->size)--;
}
int SizeHashTable(HashTable*Hash){//���ϣ�����ЧԪ�صĸ���
	return Hash->size;
}
int EmptyHashTable(HashTable*Hash){//�жϹ�ϣ���Ƿ�Ϊ��
	return (Hash->size) == 0;
}