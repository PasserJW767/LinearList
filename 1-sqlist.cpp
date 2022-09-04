# include<iostream>
using namespace std;
# define MAXSIZE 10 // 存储空间初始分配变量
# define OK 1
# define ERROR 0
# define TRUE 1
# define FALSE 0
typedef int ElemType; // ElemType类型根据实际情况而定，这里假设为int
typedef int Status;
typedef struct {
	ElemType data[MAXSIZE]; // 数据存储数据元素，最大值为MAXSIZE
	int length; // 线性表当前长度
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
	if (L->length == 0 || i < 1 || i > L->length) // 若获取第0个数据、获取值为负的数据、获取大于线性表长度的数据皆是不合法的
		return ERROR;
	*e = L->data[i - 1]; // 赋值返回数据
	return OK;
}
int LocateElem(SqList L, ElemType e) {
	for (int i = 0; i < L.length; i++)
		if (L.data[i] == e)
			return i + 1;
	return ERROR;
}
Status ListInsert(SqList *L, int i, ElemType e) {
	if (L->length == MAXSIZE) // 线性表已满，不能再插入数据
		return ERROR;
	if (i < 1 || i > L->length + 1) // 插入位置不合法
		// i > L->length + 1，若不是这样连第一个也插不进去，为什么不写i > L->length应这么理解，在长度（最后一个元素）所在的位置是可以插入的
		return ERROR;
	// 不挪出空位无法插入
	if (i != L->length) // 不是在线性表最后一位插入数据
		for (int j = L->length; j >= i; j--) 
			L->data[j] = L->data[j - 1];
	L->data[i - 1] = e; // 因为i不是数组下标，赋值时要将这个索引数字-1以获得下标
	L->length++; // 线性表长度增加
	return OK;
}
Status ListDelete(SqList* L, int i, ElemType* e) {
	if (L->length == 0) // 线性表为空，不能删除
		return ERROR;
	if (i < 1 || i > L->length) //删除位置不合法
		return ERROR;
	// 删了再挪
	*e = L->data[i - 1];
	if (i != L->length) // 若删除的不是最后一位数据
		for (int j = i;j < L->length;j++)
			L->data[j - 1] = L->data[j];
	L->length--; // 线性表长度减少
	return OK;
}
int ListLength(SqList L) {
	return L.length;
}
/*
int main() {
	SqList L;
	// 初始化
	bool result = InitList(&L);
	cout << "若初始化成功，则result=1: result=" << result << endl;
	cout << endl;
	// 测试列表是否为空
	result = ListEmpty(L);
	cout << "列表为空，则result=1，否则result=0: result=" << result << endl;
	cout << endl;
	// 插入元素
	result = ListInsert(&L, 1, 1);
	cout << "若插入成功，则result=1: result=" << result << endl;
	cout << endl;
	// 测试列表是否为空
	result = ListEmpty(L);
	cout << "列表为空，则result=1，否则result=0: result=" << result << endl;
	// 多插入几个元素
	result = ListInsert(&L, 2, 3);
	result = ListInsert(&L, 3, 5);
	result = ListInsert(&L, 4, 7);
	result = ListInsert(&L, 5, 9);
	cout << endl;
	// 查找值为5的元素下标
	cout << "值为5的元素索引:" << LocateElem(L, 5) << endl;
	cout << "值为25的元素下标（不存在，返回0）:" << LocateElem(L, 25) << endl;
	cout << endl;
	// 获取第3个元素放入e中
	int e;
	GetElem(&L, 3, &e);
	cout << "被查找到的元素e:" << e << endl;
	cout << endl;
	// 删除第2个元素（3）
	ListDelete(&L, 2, &e);
	cout << "被删除的元素e:" << e << endl;
	GetElem(&L, 2, &e);
	cout << "目前的第2个元素（应为5）:" << e << endl;
	cout << endl;
	// 删除一个元素后，元素的数量应为4
	cout << "当前List长度（应为4）：" << ListLength(L) << endl;
	cout << endl;
	// 清空列表
	result = ClearList(&L);
	cout << "若清空成功，则result=1: result=" << result << endl;
	cout << "当前线性表长度：" << ListLength(L) << endl;
	cout << "列表为空，则result=1，否则result=0: result=" << result << endl;
	return 0;
}*/