# include<iostream>
using namespace std;
# define OK 1
# define ERROR 0
# define TRUE 1
# define FALSE 0
typedef int ElemType; // ElemType���͸���ʵ������������������Ϊint
typedef int Status;
typedef struct Node {
	ElemType data;
	struct Node* next;
}Node, *LinkList;
//typedef struct Node* LinkList;
Status InitList(LinkList *L) {
	*L = (LinkList)malloc(sizeof(Node));  //����ͷ�ڵ�
	(*L)->next = NULL;    //������L��ʼ��Ϊ��
	return OK;
}
Status ListEmpty(LinkList L) {
	if (L->next==NULL)
		return TRUE;
	return FALSE;
}
Status GetElem(LinkList L, int i, ElemType* e) {
	int j = 1;
	LinkList p = L->next;
	while (p && j < i) {
		j++;
		p = p->next;
	}
	if (j == i) {
		*e = p->data;
		return OK;
	}
	else if (!p || j > i)
		return ERROR;
}
void CreateListHead(LinkList* L, int n) {
	// �������������-ͷ�巨
	// Random create n element, create a Linear List L which have head node(Head Insert Method)
	srand(time(0));// ��ʼ�����������
	(*L) = (LinkList)malloc(sizeof(Node)); // Initial Head Node, ��ʼ��ͷ���
	(*L)->next = NULL;// Set L->next as NULL
	LinkList p;
	for (int i = 0; i < n; i++) {// create n nodes
		p = (LinkList)malloc(sizeof(Node)); // Initial the node
		p->data = rand() % 100 + 1; // Randomly create between zero to one hundred
		p->next = (*L)->next; // The next of p point to the next of (*L)
		(*L)->next = p; // Insert to the head of LinkList
	}
}
void CreateListTail(LinkList* L, int n) {
	// �������������-β�巨
	// Rancom create n element, create a Linear List L which have head node(Tail Insert Method)
	srand(time(0)); // Initial random seed
	(*L) = (LinkList)malloc(sizeof(Node));
	LinkList p;
	LinkList r = (*L);
	for (int i = 0;i < n;i++) {
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		p->next = NULL;
		r->next = p;
		r = p;
	}
}
Status ListInsert(LinkList* L, int i, ElemType e) {
	/*
		��ʼ������˳�����Ա�L�Ѵ��ڣ�1��L��ListLength(L)
		�����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ���+1
	*/
	int j = 1;// ����һ�£��������Ҫ���뵽��һ��λ�ã�����Ҫ����ͷ���ĺ��棬�ʳ�ʼʱj��1��������whileѭ��ֱ�Ӳ��롣
	LinkList p = *L;
	while (p && j < i) {// Ѱ�ҵ�i����㣬ֻ��pΪ�ջ�j=iʱ������ѭ��
		p = p->next;
		j++;
	}
	if (!p || j > i) //��i��Ԫ�ز�����
		return ERROR;
	// ��������������������j==i��˵���ҵ��˲���λ��
	LinkList s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}
Status ListDelete(LinkList* L, int i, ElemType *e) {
	int j = 1;
	LinkList p = *L;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	if (!p || j > i) // ����Ҳ������ɾ����λ��
		return ERROR;
	LinkList q = p->next; // qʵ���Ͼ��Ǵ�ɾ����Ԫ��
	*e = q->data; // ����ɾ����ֵ
	p->next = q->next;//Խ����ɾ�����
	free(q); // �ͷ�ɾ������ڴ�
	return OK;
}
Status ClearList(LinkList *L) {
	LinkList p, q;
	p = (*L)->next;
	while (p != NULL) {
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	return OK;
}
int ListLength(LinkList L) {
	int i = 0;
	LinkList p = L;
	while (p) {
		p = p->next;
		i++;
	}
	return i;
}
void ReadList(LinkList L) {
	LinkList p = L->next;
	cout << p->data << " ";
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
int main() {
	LinkList L;
	// ��ʼ������
	cout << "�����ʼ���ɹ����1��" << InitList(&L) << endl;
	cout << "----------------" << endl << endl;
	// �ж������Ƿ�Ϊ��
	cout << "����Ϊ�����1��" << ListEmpty(L) << endl;
	cout << "----------------" << endl << endl;
	// ����Ԫ��
	cout << "�������ɹ����1��" << ListInsert(&L, 1, 1) << endl;
	ListInsert(&L, 1, 3);
	ListInsert(&L, 1, 5);
	ListInsert(&L, 1, 7);
	ListInsert(&L, 1, 9);
	cout << "----------------" << endl << endl;
	// ɾ��Ԫ��
	int e;
	cout << "����ɾ���ɹ����1��" << ListDelete(&L, 5, &e) << endl;
	cout << "e��ֵ��" << e << endl;
	cout << "----------------" << endl << endl;
	// �������������-ͷ�巨
	LinkList LHeadInsert;
	CreateListHead(&LHeadInsert, 10);
	ReadList(LHeadInsert);
	cout << "----------------" << endl << endl;
	// �������������-β�巨
	LinkList LTailInsert;
	CreateListTail(&LTailInsert, 10);
	ReadList(LTailInsert);
	cout << "----------------" << endl << endl;
	// ����������
	cout << "��������������ɹ����1��" << ClearList(&L) << endl;
	cout << "----------------" << endl << endl;

	return 0;
}