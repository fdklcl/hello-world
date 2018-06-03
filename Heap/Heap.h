#include<stdio.h>
#include<assert.h>
#include<malloc.h>
typedef  int DataType;
typedef int(*compare)(DataType, DataType);//����ָ�루Ϊ��ʵ�ּȿ��Դ�������ֿ��Դ���С��
typedef struct Heap{
	DataType * array;//��̬����
	int capacity;//����
	int size;//ʵ�ʴ�С
	compare com;
}Heap;
typedef struct prorityQueue{//���ȼ�����
	Heap hp;
}prorityQueue;
int less(DataType left, DataType right){
	return left > right;
}
int greater(DataType left, DataType right){
	return left < right;
}
void swap(DataType* pdata1, DataType* pdata2){//�������������ڵ��ֵ
	assert(pdata1);
	assert(pdata2);
	DataType temp = *pdata1;
	*pdata1 = *pdata2;
	*pdata2 = temp;
}
void _AdjustDown(Heap*Hp, DataType root){//���µ���
	assert(Hp);
	DataType size = Hp->size;
	DataType parent = root;
	DataType child = (root * 2) + 1;//���ȱ��childΪ���ӣ�childʵ�ʱ�����Һ����н�С�ģ�
	while (child<size){//����Խ��
		if (child + 1<size && Hp->com(Hp->array[child],Hp->array[child+1])){//�Һ��Ӵ��ڣ������Һ��Ӵ�������
			child = child + 1;
		}
		if (Hp->com((Hp->array[parent]) , (Hp->array[child]))){//˫��С�����ĺ���
			swap(&(Hp->array[parent]),&(Hp->array[child]));
			parent = child;//˫���ߵ����ӵ�λ��
			child = (parent * 2) + 1;
		}
		else{//�ź��ˣ�˫�ױ����ĺ��Ӵ�
			return;
		}
	}
}
void CreateHeap(Heap*Hp, DataType *array1, int size,compare com){//������(ע�⣺������com��ʾҪ������ѻ���С��
	assert(Hp);
	DataType root = (size - 2) >> 1;//�����һ����Ҷ�ӽڵ㿪ʼ��
	int i = 0;
	Hp->array = (DataType*)malloc(sizeof(DataType)*size);
	if (Hp->array == NULL){
		return;
	}
	Hp->capacity = size;
	Hp->size = size;
	Hp->com = com;
	for (i = 0; i < size; i++){
		Hp->array[i] = array1[i];
	}
	//�����ɶѣ������һ����Ҷ�ӿ�ʼ�ţ��ŵ����ڵ�Ϊֹ��
	for (i = root; i>=0; i--){
		_AdjustDown(Hp,i);
	}
}
//1 ���¿������Ŀռ� 2 ����Ԫ�� 3 �ͷžɵĿռ� 4 ��ָ��ָ���¿ռ�
void Check_capity(Heap *Hp){//�������
	if (Hp->capacity == Hp->size){
		int newcpacity = 2 * (Hp->capacity);
		DataType * temp = (DataType*)malloc(sizeof(DataType)*(Hp->capacity));
		if (NULL == temp){
			return;
		}
		for (int i = 0; i < Hp->size; i++){
			temp[i] = Hp->array[i];
		}
		free(Hp->array);
		Hp->array = temp;
		Hp->capacity = newcpacity;
	}
}
void _Adjustup(Heap* Hp, int child){//���ϵ���
	assert(Hp);
	DataType parent = (child - 1) >> 1;
	while (child){
		if (Hp->com((Hp->array[parent]), (Hp->array[child]))){
			swap(&Hp->array[parent], &Hp->array[child]);
			child = parent;
			parent = (parent - 1) >> 1;
		}
		else{
			return;
		}
	}
}
void InsertHeap(Heap* Hp, DataType data){//���루˼�룬�嵽��β�����ϵ�����
	assert(Hp);
	Check_capity(Hp);//���������Զ�����
	Hp->array[Hp->size++] = data;//�嵽��β
	//���ϵ���
	_Adjustup(Hp, Hp->size-1);
}
void delect(Heap *Hp){//ע�⣺�ѵ�ɾ��ÿ�α���ɾ���Ѷ�Ԫ��
	assert(Hp);
	Hp->array[0] = Hp->array[Hp->size - 1];
	Hp->size = Hp->size - 1;
	_AdjustDown(Hp, 0);
}
int Heapsize(Heap*Hp){//���Ԫ�صĸ���
	return Hp->size;
}
void InitHeap(Heap *Hp,compare com){//�ѳ�ʼ��
	Hp->array = (DataType*)malloc(sizeof(DataType)*3);
	if (Hp->array == NULL){
		return;
	}
	Hp->capacity =3;
	Hp->size = 0;
	Hp->com = com;
}
int temptyHeap(Heap*Hp){
	if (Hp->size == 0){
		return 1;
	}
	else{
		return 0;
	}
}
//�ѵ�Ӧ��
// ���ȼ�����
void InitprorityQueue(prorityQueue*pq){//��ʼ�����ȼ�����
	InitHeap(&(pq->hp), greater);
}
void pushprorityQueue(prorityQueue *pq,DataType data){
	InsertHeap(&(pq->hp), data);
}
void popprorityQueue(prorityQueue *pq){
	delect(&(pq->hp));
}
int sizepQ(prorityQueue*pq){
	return  Heapsize(&(pq->hp));
}
int temppQ(prorityQueue*pq){
	temptyHeap(&(pq->hp));
}
int greatst(prorityQueue*pq){//ȡ���ȼ����Ľڵ��ֵ
	return (&(pq->hp))->array[0];
}
void test(){//���ȼ����в�������
	prorityQueue pq;
	InitprorityQueue(&pq);
	pushprorityQueue(&pq, 3);
	pushprorityQueue(&pq, 2);
	pushprorityQueue(&pq, 1);
	pushprorityQueue(&pq, 8);
	pushprorityQueue(&pq, 6);
	int ret = greatst(&pq);
	int ret2=sizepQ(&pq);
	printf("���ȼ����е�Ԫ�ظ���Ϊ%d\n",ret2);
	printf("���ȼ����������ȼ���ߵ���%d\n", ret);

}
void _AdjustDown2(Heap*Hp, DataType root,int size){//���ڶ���������µ���
	assert(Hp);
	DataType parent = root;
	DataType child = (root * 2) + 1;//���ȱ��childΪ���ӣ�childʵ�ʱ�����Һ����н�С�ģ�
	while (child<size){
		if (child + 1<size && Hp->com(Hp->array[child], Hp->array[child + 1])){//�Һ��Ӵ��ڣ������Һ��Ӵ�������
			child = child + 1;
		}
		if (Hp->com((Hp->array[parent]), (Hp->array[child]))){
			swap(&(Hp->array[parent]), &(Hp->array[child]));
			parent = child;
			child = (parent * 2) + 1;
		}
		else{//�ź���
			return;
		}
	}
}
void sortHeap(Heap *Hp,int* arr,int sz){//������(����
	assert(Hp);
	int i = 0;
	CreateHeap(Hp, arr, sz, greater);//����һ�����
	int end = sz - 1;
	while (end){
		swap(&(Hp->array[0]), &(Hp->array[end]));//�Ѷ������һ��Ԫ�ؽ��н���
		_AdjustDown2(Hp, 0,end);//ʣ�µ�Ԫ�����µ����ɶ�
		end--;
	}
}
void test1(){//�������������
	Heap Hp;
	int arr[10] = { 3, 9, 4, 1, 2, 8, 6, 7, 5, 0 };
	sortHeap(&Hp, arr, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i <sizeof(arr) / sizeof(arr[0]); i++){
		printf("%d ", (&Hp)->array[i]);
	}
}