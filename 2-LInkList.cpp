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
}Node;
typedef struct Node* LinkList;
Status InitList(LinkList *L) {
	*L = (LinkList)malloc(sizeof(Node));  //����ͷ�ڵ�
	(*L)->next = NULL;    //������LΪ��
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
int ListLength(LinkList L) {
	int i = 0;
	LinkList p = L;
	while (p) {
		p = p->next;
		i++;
	}
	return i;
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

	return 0;
}