#include<assert.h>
#include<stdio.h>
#include<malloc.h>
typedef int DataType;

typedef struct Node
{
	struct Node* _pNext;
	DataType _data;
}Node, *PNode;
typedef  struct CListNode{
	struct CListNode*_pNext;
	struct CListNode*_random;
	DataType _data;
}CListNode,*PCListNode;

//////////////////����ͷ���ĵ�����////////////////////////////////////// 
// .h 
//��ӡ������
void printSList(PNode pHead);

// �����ʼ�� 
void SListInit(PNode* ppHead);

//�½ڵ������
PNode NewNode(DataType data);


// β�� 
void SListPushBack(PNode* ppHead, DataType data);

// βɾ 
void SListPopBack(PNode* ppHead);

// ͷ�� 
void SListPushFront(PNode* ppHead, DataType data);

// ͷɾ 
void SListPopFront(PNode* ppHead);

// ����ֵΪdata�Ľ�㣬���ظý���������е�λ�� 
PNode SListFind(PNode pHead, DataType data);

// ������posλ�ú������data 
void SListInsert(PNode* ppHead, PNode pos, DataType data);

// ɾ������posλ���ϵĽ�� 
void SListErase(PNode* ppHead, PNode pos);

// ���ٵ����� 
void SListDestroy(PNode* ppHead);

// �������н��ĸ��� 
int SListSize(PNode pHead);

// �������еĽ����� 
void SListClear(PNode* ppHead);

// ��ȡ��� 
PNode BuySListNode(DataType data);

// ��ȡ�����е����һ����㣬���ظý��ĵ�ַ 
PNode SListBack(PNode pHead);


////////�����ֵ�����������ȥ��ɣ��ǳ���Ҫ���ǳ���Ҫ���ǳ���Ҫ������//////////

// ��β��ͷ��ӡ������ 
void PrintListFromTail2Head(PNode pHead);
void THprint2(PNode pHead);

// ɾ����ͷ������ķ�β��㣬Ҫ�󣺲��ܱ������� 
void DeleteNotTailNode(PNode pos);

// ����ͷ������posλ��ǰ����ֵΪ���data�Ľ�� �����ܱ���������
void InsertPosFront(PNode pos, DataType data);

//1.����
void circle(PNode pHead);

// �õ�����ģ��ʵ��Լɪ�� 
void JosephCircle(PNode* pHead, const int M);

// ʹ��ð�����򷽷��Ե������������ 
void BubbleSort(PNode pHead);

// �����������--����ָ�� 
void ReverseSList(PNode* pHead);

// �����������--ͷ�巨 
PNode ReverseSListOP(PNode pHead);

// �ϲ��������������ϲ�֮����Ȼ���� 
PNode MergeSList(PNode pHead1, PNode pHead2);

// ����������м��㣬Ҫ��ֻ�ܱ���һ������ 
PNode FindMiddleNode(PNode pHead);

// ��������ĵ�����K����㣬Ҫ��ֻ�ܱ�������һ�� 
PNode FindLastKNode(PNode pHead, int K);

// ɾ������ĵ�����K����㣬Ҫ��ֻ�ܱ�������һ�� 
void DeleteLastKNode(PNode* pHead, int K);

// �жϵ������Ƿ��ཻ���������� 
int IsCrossWithoutCircle(PNode pHead1, PNode pHead2);

// �󲻴����������ཻ���� 
PNode GetCrossNode(PNode pHead1, PNode pHead2);

// �ж������Ƿ���� 
PNode IsCircle(PNode pHead);

void test();//����
void test2();
void test3();
// �󻷵ĳ��� 
int GetCircleLen(PNode pHead);

// �󻷵���ڵ�--ע���ƶϹ��� 
PNode GetEnterNode(PNode pHead, PNode pMeetNode);

// �ж������Ƿ��ཻ��������ܴ��� 
int IsListCrossWithCircle(PNode pHead1, PNode pHead2);

// ��������ĸ��� 
PCListNode CopyComplexList(PCListNode pHead);
//�ܽ������˳������ȱ��