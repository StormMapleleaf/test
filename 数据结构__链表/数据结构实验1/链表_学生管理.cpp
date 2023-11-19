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

//����
bool ListInsert(LinkNode*& L, int i, ElemType e) {
	int j = 0;
	LinkNode* p = L;                            //pָ��ͷ���
	LinkNode* s=NULL;        
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
//ɾ��
bool ListDelete(LinkNode*& L, int i, ElemType& e) {
	int j = 0;
	LinkNode* p = L, * q;
	if (i <= 0) return false;               //�����ж�
	while (j < i - 1 && p != NULL) {
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else {
		q = p->next;                        //��Ԫ�ش�����ɾ�������ص�e
		if (q == NULL)
			return false;
		e = q->data;
		p->next = q->next;
		free(q);
		return true;
	}
}
//����Ų���
bool GetElem(LinkNode* L, int i, ElemType& e) {
	int j = 0;
	LinkNode* p = L;
	if (i <= 0) return false;               //�����ж�
	while (j < i && p != NULL) {
		j++;
		p = p->next;
	}
	if (p == NULL)                           //�����ڷ���false
		return false;
	else {
		e = p->data;
		return true;
	}
}
//���
void print(LinkNode* L) {
	printf("˳������:\n");
	LinkNode* p = L->next;
	while (p != NULL) {
		printf("%s %d\n", p->data.name, p->data.age);
		p = p->next;
	}
	printf("\n");
}
int main() {
	printf("###����0�˳�###\n");
	printf("###����1����###\n");
	printf("###����2ɾ��###\n");
	printf("###����3����###\n");
	LinkNode* L;
	L = (LinkNode*)malloc(sizeof(LinkNode));
	if(L!=NULL)
	L->next = NULL;
	while (1) {
		printf("������:");
		int num;
		scanf_s("%d", &num);
		switch (num) {
		case 0:
			return 0;
			break;
		case 1:
			Stu s;
			int in;
			printf("����������,����:");
			scanf_s("%s%d", &s.name,3,&s.age);
			printf("�������������:");
			scanf_s("%d", &in);
			ListInsert(L, in, s);
			print(L);
			break;

		case 2:
			int del;
			Stu se;
			printf("��������Ҫɾ��Ԫ�ص����:");
			scanf_s("%d", &del);
			ListDelete(L, del, se);
			print(L);
			break;

		case 3:
			Stu sg;
			int get;
			printf("��������ҵ����:");
			scanf_s("%d", &get);
			GetElem(L, get, sg);
			printf("���ҽ��:");
			printf("%s %d\n", sg.name, sg.age);
			printf("\n");
			break;
		}
	}
}