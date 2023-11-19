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

//插入
bool ListInsert(LinkNode*& L, int i, ElemType e) {
	int j = 0;
	LinkNode* p = L;                            //p指向头结点
	LinkNode* s=NULL;        
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
//删除
bool ListDelete(LinkNode*& L, int i, ElemType& e) {
	int j = 0;
	LinkNode* p = L, * q;
	if (i <= 0) return false;               //参数判断
	while (j < i - 1 && p != NULL) {
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else {
		q = p->next;                        //将元素从链表删除并返回到e
		if (q == NULL)
			return false;
		e = q->data;
		p->next = q->next;
		free(q);
		return true;
	}
}
//按序号查找
bool GetElem(LinkNode* L, int i, ElemType& e) {
	int j = 0;
	LinkNode* p = L;
	if (i <= 0) return false;               //参数判断
	while (j < i && p != NULL) {
		j++;
		p = p->next;
	}
	if (p == NULL)                           //不存在返回false
		return false;
	else {
		e = p->data;
		return true;
	}
}
//输出
void print(LinkNode* L) {
	printf("顺序表输出:\n");
	LinkNode* p = L->next;
	while (p != NULL) {
		printf("%s %d\n", p->data.name, p->data.age);
		p = p->next;
	}
	printf("\n");
}
int main() {
	printf("###输入0退出###\n");
	printf("###输入1插入###\n");
	printf("###输入2删除###\n");
	printf("###输入3查找###\n");
	LinkNode* L;
	L = (LinkNode*)malloc(sizeof(LinkNode));
	if(L!=NULL)
	L->next = NULL;
	while (1) {
		printf("请输入:");
		int num;
		scanf_s("%d", &num);
		switch (num) {
		case 0:
			return 0;
			break;
		case 1:
			Stu s;
			int in;
			printf("请输入名字,年龄:");
			scanf_s("%s%d", &s.name,3,&s.age);
			printf("请输入插入的序号:");
			scanf_s("%d", &in);
			ListInsert(L, in, s);
			print(L);
			break;

		case 2:
			int del;
			Stu se;
			printf("请输入需要删除元素的序号:");
			scanf_s("%d", &del);
			ListDelete(L, del, se);
			print(L);
			break;

		case 3:
			Stu sg;
			int get;
			printf("请输入查找的序号:");
			scanf_s("%d", &get);
			GetElem(L, get, sg);
			printf("查找结果:");
			printf("%s %d\n", sg.name, sg.age);
			printf("\n");
			break;
		}
	}
}