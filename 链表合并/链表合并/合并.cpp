//By StormMapleleaf_������

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS 
//�ṹ�嶨��
struct Stu {
	char name[10];
	int age;
};
typedef Stu ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LinkNode;
//���������
int Length(LinkNode*L) {
	int n = 0;
	LinkNode* p = L;
	while (p->next != NULL) {
		n++;
		p = p->next;
	}
	return n;
}

//By StormMapleleaf_������

//�ϲ�����
void fun(LinkNode*& L1, LinkNode*& L2) {
	int n = Length(L1);  //��ȡ����1�ĳ���
	LinkNode* p = L1;
	for (int i = 0; i < n; i++) {
		p = p->next;
	}
	LinkNode* s = L2;
	p->next = s->next; //������1��βԪ��ָ������2����Ԫ��
	
}
//����
bool ListInsert(LinkNode*& L, int i, ElemType e) {
	int j = 0;
	LinkNode* p = L;                            //pָ��ͷ���
	LinkNode* s = NULL;
	if (i <= 0) return false;                   //�����ж�
	while (j < i - 1 && p != NULL) {
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else {
		s = (LinkNode*)malloc(sizeof(LinkNode));  //���벿��
		if (s != NULL) {
			s->data = e;
			s->next = p->next;
			p->next = s;
			return true;
		}

	}
	return true;
}
//���
void print(LinkNode* L) {
	printf("��������:\n");
	LinkNode* p = L->next;
	while (p != NULL) {
		printf("%s %d\n", p->data.name, p->data.age);
		p = p->next;
	}
	printf("\n");
}
int main() {
	LinkNode* L1,*L2;
	L1 = (LinkNode*)malloc(sizeof(LinkNode));
	L2 = (LinkNode*)malloc(sizeof(LinkNode));
	if (L1 != NULL && L2 != NULL) {
		L1->next = NULL;
		L2->next = NULL;
	}
	Stu a1, a2, b1, b2;                     //��������L1��L2�����������������a1,a2,b1,b2
	a1 = { "a1",11};
	a2 = { "a2",12 };
	b1 = { "b1",13 };
	b2 = { "b2",14 };
	Stu arr[4] = { a1,a2,b1,b2 };
	ListInsert(L1, 1, a1);                 //��ʼ����������
	ListInsert(L1, 2, a2);
	ListInsert(L2, 1, b1);
	ListInsert(L2, 2, b2);
	print(L1);
	print(L2);
	fun(L1, L2);
	printf("�ϲ�����������:\n");
	print(L1);
}