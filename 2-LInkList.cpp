# include<iostream>
using namespace std;
# define OK 1
# define ERROR 0
# define TRUE 1
# define FALSE 0
typedef int ElemType; // ElemType类型根据实际情况而定，这里假设为int
typedef int Status;
typedef struct Node {
	ElemType data;
	struct Node* next;
}Node, *LinkList;
//typedef struct Node* LinkList;
Status InitList(LinkList *L) {
	*L = (LinkList)malloc(sizeof(Node));  //建立头节点
	(*L)->next = NULL;    //单链表L初始化为空
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
	// 单链表的整表创建-头插法
	// Random create n element, create a Linear List L which have head node(Head Insert Method)
	srand(time(0));// 初始化随机数种子
	(*L) = (LinkList)malloc(sizeof(Node)); // Initial Head Node, 初始化头结点
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
	// 单链表的整表创建-尾插法
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
		初始条件：顺序线性表L已存在，1≤L≤ListLength(L)
		操作结果：在L中第i个位置之前插入新的数据元素e，L的长度+1
	*/
	int j = 1;// 想象一下，如果我们要插入到第一个位置，就是要插在头结点的后面，故初始时j置1。即跳过while循环直接插入。
	LinkList p = *L;
	while (p && j < i) {// 寻找第i个结点，只有p为空或j=i时会跳出循环
		p = p->next;
		j++;
	}
	if (!p || j > i) //第i个元素不存在
		return ERROR;
	// 若不满足以上条件，则j==i，说明找到了插入位置
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
	if (!p || j > i) // 如果找不到这个删除的位置
		return ERROR;
	LinkList q = p->next; // q实际上就是待删除的元素
	*e = q->data; // 赋待删除的值
	p->next = q->next;//越过待删除结点
	free(q); // 释放删除结点内存
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
	// 初始化链表
	cout << "链表初始化成功输出1：" << InitList(&L) << endl;
	cout << "----------------" << endl << endl;
	// 判断链表是否为空
	cout << "链表为空输出1：" << ListEmpty(L) << endl;
	cout << "----------------" << endl << endl;
	// 插入元素
	cout << "链表插入成功输出1：" << ListInsert(&L, 1, 1) << endl;
	ListInsert(&L, 1, 3);
	ListInsert(&L, 1, 5);
	ListInsert(&L, 1, 7);
	ListInsert(&L, 1, 9);
	cout << "----------------" << endl << endl;
	// 删除元素
	int e;
	cout << "链表删除成功输出1：" << ListDelete(&L, 5, &e) << endl;
	cout << "e的值：" << e << endl;
	cout << "----------------" << endl << endl;
	// 单链表的整表创建-头插法
	LinkList LHeadInsert;
	CreateListHead(&LHeadInsert, 10);
	ReadList(LHeadInsert);
	cout << "----------------" << endl << endl;
	// 单链表的整表创建-尾插法
	LinkList LTailInsert;
	CreateListTail(&LTailInsert, 10);
	ReadList(LTailInsert);
	cout << "----------------" << endl << endl;
	// 单链表的清除
	cout << "单链表整表清除成功输出1：" << ClearList(&L) << endl;
	cout << "----------------" << endl << endl;

	return 0;
}