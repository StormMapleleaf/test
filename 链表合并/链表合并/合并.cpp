//By StormMapleleaf_代齐祥

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS 
//结构体定义
struct Stu {
	char name[10];
	int age;
};
typedef Stu ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LinkNode;
//输出链表长度
int Length(LinkNode*L) {
	int n = 0;
	LinkNode* p = L;
	while (p->next != NULL) {
		n++;
		p = p->next;
	}
	return n;
}

//By StormMapleleaf_代齐祥

//合并函数
void fun(LinkNode*& L1, LinkNode*& L2) {
	int n = Length(L1);  //获取链表1的长度
	LinkNode* p = L1;
	for (int i = 0; i < n; i++) {
		p = p->next;
	}
	LinkNode* s = L2;
	p->next = s->next; //将链表1的尾元素指向链表2的首元素
	
}
//插入
bool ListInsert(LinkNode*& L, int i, ElemType e) {
	int j = 0;
	LinkNode* p = L;                            //p指向头结点
	LinkNode* s = NULL;
	if (i <= 0) return false;                   //参数判断
	while (j < i - 1 && p != NULL) {
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else {
		s = (LinkNode*)malloc(sizeof(LinkNode));  //插入部分
		if (s != NULL) {
			s->data = e;
			s->next = p->next;
			p->next = s;
			return true;
		}

	}
	return true;
}
//输出
void print(LinkNode* L) {
	printf("链表表输出:\n");
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
	Stu a1, a2, b1, b2;                     //创建链表L1，L2并各自添加两个变量a1,a2,b1,b2
	a1 = { "a1",11};
	a2 = { "a2",12 };
	b1 = { "b1",13 };
	b2 = { "b2",14 };
	Stu arr[4] = { a1,a2,b1,b2 };
	ListInsert(L1, 1, a1);                 //初始化两个链表
	ListInsert(L1, 2, a2);
	ListInsert(L2, 1, b1);
	ListInsert(L2, 2, b2);
	print(L1);
	print(L2);
	fun(L1, L2);
	printf("合并后的链表输出:\n");
	print(L1);
}