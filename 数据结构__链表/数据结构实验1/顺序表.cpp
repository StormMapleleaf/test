//By StormMapleleaf_������
#include<stdio.h>
#include<malloc.h>
#define MaxSize 10

struct Stu {
	char name[10];
	int age;
};
typedef Stu ElemType;
bool ListInsert(SqList*& L, int i, ElemType e);
bool ListDelete(SqList*& L, int i, ElemType& e);
bool GetElem(SqList* L, int i, ElemType& e);
struct Stu {
	char name[10];
	int age;
};

typedef struct {
	ElemType data[MaxSize];
	int length;
}SqList;
main() {
	while (1) {
		printf("###����1����###\n");
		printf("###����2ɾ��###\n");
		printf("###����3����###\n");

	}
}
//����
bool ListInsert(SqList*& L, int i, ElemType e) {
	int j;
	if (i < 1 || i>L->length + 1 || L->length == MaxSize)
		return false;
	i--;
	for (j = L->length; j > i; j--)
		L->data[j] = L->data[j - 1];
	L->data[i] = e;
	L->length++;
	return true;
}
//ɾ��
bool ListDelete(SqList*& L, int i, ElemType& e) {
	int j;
	if (i<1 || i>L->length)
		return false;
	i--;
	e = L->data[i];
	for (j = i; j < L->length - 1; j++)
		L->data[j] = L->data[j + 1];
	L->length--;
	return true;
}
//����Ų���
bool GetElem(SqList* L, int i, ElemType& e) {
	if (i<1 || i>L->length)
		return false;//�ж�i������
	e = L->data[i - 1];
	return true;
}