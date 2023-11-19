//By StormMapleleaf_������
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MaxSize 10
//�ṹ�����Ͷ���
struct Stu {
	char name[10];
	int m;
};
typedef Stu ElemType;
typedef struct {
	ElemType data[MaxSize];
	int length;
}SqList;

//����
bool ListInsert(SqList*& L, int i, ElemType e) {
	int j;
	if (i < 1 || i>L->length + 1 || L->length == MaxSize)
		return false;                                     //�жϲ����Ƿ���ȷ
	i--;                                                  //�������߼����ת�� 
	for (j = L->length; j > i; j--)                       //����λ�ü��Ժ�Ԫ�غ���
		L->data[j] = L->data[j - 1];
	L->data[i] = e;
	L->length++;                                          //����һ
	return true;
}
//ɾ��
bool ListDelete(SqList*& L, int i, ElemType& e) {
	int j;
	if (i<1 || i>L->length)
		return false;                                     //�жϲ����Ƿ���ȷ
	i--;                                                  //�������߼����ת�� 
	e = L->data[i];                                       //����λ�ü��Ժ�Ԫ�غ���
	for (j = i; j < L->length - 1; j++)
		L->data[j] = L->data[j + 1];
	L->length--;                                          //����һ
	return true;
}
//����Ų���
bool GetElem(SqList* L, int i, ElemType& e) {
	if (i<1 || i>L->length)
		return false;                                     //�ж�i������
	e = L->data[i - 1];
	return true;
}
//���
void print(SqList* L) {
	printf("˳������:\n");
	for (int i = 0; i < L->length; i++) {
		printf("%s %d\n", L->data[i].name, L->data[i].m);
		
	}
	printf("\n");
}
 int main() {
	 printf("###����0�˳�###\n");
	 printf("###����1����###\n");
	 printf("###����2ɾ��###\n");
	 printf("###����3����###\n");
	SqList *L;
	L = (SqList*)malloc(sizeof(SqList));
	if(L!=NULL)
	L->length = 0;
	while (1) {
		printf("������:");
		int num;
		scanf("%d", &num);
		switch (num) {
		case 0:
			return 0;
			break;
		case 1:
			Stu s;
			int in;
			printf("����������,����:");
			scanf("%s%d", &s.name, &s.m);
			printf("�������������:");
			scanf("%d", &in);
			ListInsert(L, in, s);
			print(L);
			break;

		case 2:
			int del;
			Stu se;
			printf("��������Ҫɾ��Ԫ�ص����:");
			scanf("%d", &del);
			ListDelete(L, del, se);
			print(L);
			break;

		case 3:
			Stu sg;
			int get;
			printf("��������ҵ����:");
			scanf("%d", &get);
			GetElem(L, get, sg);
			printf("���ҽ��:");
			printf("%s %d\n", sg.name, sg.m);
			printf("\n");
			break;
		}
	}
}