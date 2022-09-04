# include<iostream>
using namespace std;
# define MAXSIZE 10 // �洢�ռ��ʼ�������
# define OK 1
# define ERROR 0
# define TRUE 1
# define FALSE 0
typedef int ElemType; // ElemType���͸���ʵ������������������Ϊint
typedef int Status;
typedef struct {
	ElemType data[MAXSIZE]; // ���ݴ洢����Ԫ�أ����ֵΪMAXSIZE
	int length; // ���Ա�ǰ����
}SqList;
Status InitList(SqList *L) {
	L->length = 0;
	for (int i = 0; i < MAXSIZE; i++)
		L->data[i] = 0;
	return OK;
}
Status ListEmpty(SqList L) {
	if (L.length == 0)
		return TRUE;
	return FALSE;
}
Status ClearList(SqList *L) {
	for (int i = 0; i < L->length; i++)
		L->data[i] = 0;
	L->length = 0;
	return OK;
}
Status GetElem(SqList *L, int i, ElemType *e) {
	if (L->length == 0 || i < 1 || i > L->length) // ����ȡ��0�����ݡ���ȡֵΪ�������ݡ���ȡ�������Ա��ȵ����ݽ��ǲ��Ϸ���
		return ERROR;
	*e = L->data[i - 1]; // ��ֵ��������
	return OK;
}
int LocateElem(SqList L, ElemType e) {
	for (int i = 0; i < L.length; i++)
		if (L.data[i] == e)
			return i + 1;
	return ERROR;
}
Status ListInsert(SqList *L, int i, ElemType e) {
	if (L->length == MAXSIZE) // ���Ա������������ٲ�������
		return ERROR;
	if (i < 1 || i > L->length + 1) // ����λ�ò��Ϸ�
		// i > L->length + 1����������������һ��Ҳ�岻��ȥ��Ϊʲô��дi > L->lengthӦ��ô��⣬�ڳ��ȣ����һ��Ԫ�أ����ڵ�λ���ǿ��Բ����
		return ERROR;
	// ��Ų����λ�޷�����
	if (i != L->length) // ���������Ա����һλ��������
		for (int j = L->length; j >= i; j--) 
			L->data[j] = L->data[j - 1];
	L->data[i - 1] = e; // ��Ϊi���������±꣬��ֵʱҪ�������������-1�Ի���±�
	L->length++; // ���Ա�������
	return OK;
}
Status ListDelete(SqList* L, int i, ElemType* e) {
	if (L->length == 0) // ���Ա�Ϊ�գ�����ɾ��
		return ERROR;
	if (i < 1 || i > L->length) //ɾ��λ�ò��Ϸ�
		return ERROR;
	// ɾ����Ų
	*e = L->data[i - 1];
	if (i != L->length) // ��ɾ���Ĳ������һλ����
		for (int j = i;j < L->length;j++)
			L->data[j - 1] = L->data[j];
	L->length--; // ���Ա��ȼ���
	return OK;
}
int ListLength(SqList L) {
	return L.length;
}
/*
int main() {
	SqList L;
	// ��ʼ��
	bool result = InitList(&L);
	cout << "����ʼ���ɹ�����result=1: result=" << result << endl;
	cout << endl;
	// �����б��Ƿ�Ϊ��
	result = ListEmpty(L);
	cout << "�б�Ϊ�գ���result=1������result=0: result=" << result << endl;
	cout << endl;
	// ����Ԫ��
	result = ListInsert(&L, 1, 1);
	cout << "������ɹ�����result=1: result=" << result << endl;
	cout << endl;
	// �����б��Ƿ�Ϊ��
	result = ListEmpty(L);
	cout << "�б�Ϊ�գ���result=1������result=0: result=" << result << endl;
	// ����뼸��Ԫ��
	result = ListInsert(&L, 2, 3);
	result = ListInsert(&L, 3, 5);
	result = ListInsert(&L, 4, 7);
	result = ListInsert(&L, 5, 9);
	cout << endl;
	// ����ֵΪ5��Ԫ���±�
	cout << "ֵΪ5��Ԫ������:" << LocateElem(L, 5) << endl;
	cout << "ֵΪ25��Ԫ���±꣨�����ڣ�����0��:" << LocateElem(L, 25) << endl;
	cout << endl;
	// ��ȡ��3��Ԫ�ط���e��
	int e;
	GetElem(&L, 3, &e);
	cout << "�����ҵ���Ԫ��e:" << e << endl;
	cout << endl;
	// ɾ����2��Ԫ�أ�3��
	ListDelete(&L, 2, &e);
	cout << "��ɾ����Ԫ��e:" << e << endl;
	GetElem(&L, 2, &e);
	cout << "Ŀǰ�ĵ�2��Ԫ�أ�ӦΪ5��:" << e << endl;
	cout << endl;
	// ɾ��һ��Ԫ�غ�Ԫ�ص�����ӦΪ4
	cout << "��ǰList���ȣ�ӦΪ4����" << ListLength(L) << endl;
	cout << endl;
	// ����б�
	result = ClearList(&L);
	cout << "����ճɹ�����result=1: result=" << result << endl;
	cout << "��ǰ���Ա��ȣ�" << ListLength(L) << endl;
	cout << "�б�Ϊ�գ���result=1������result=0: result=" << result << endl;
	return 0;
}*/