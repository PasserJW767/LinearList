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
Status InitList(LinkList &L) {
	L->next = NULL;
}
Status GetElem(LinkList L, int i, ElemType* e) {
	int j = 1;
	p = L->next;
	while (p && j < i) {
		j++;
		p = p->next;
	}
	if (j == i) {
		e = p->data;
		return OK;
	}
	else if (!p || j > i)
		return ERROR;
}
int main() {
	return 0;
}