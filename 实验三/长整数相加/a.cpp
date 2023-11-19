
#include<iostream>
#include<malloc.h>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS 
//结构体定义
struct N {
	int x;//系数
	int y;//指数
};
typedef N ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LinkNode;

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
	printf("输出:\n");
	LinkNode* p = L->next;
		while (p != NULL) {
			cout << p->data.x << "x^" << p->data.y << '+';
			p = p->next;
			if (p->next == NULL) {
				cout << p->data.x << "x^" << p->data.y << endl;
				p = p->next;
			}
			
		}
}

//多项式相乘
void fun(LinkNode* l1, LinkNode* l2,LinkNode* L3) {

	LinkNode* p1 = l1->next;
	LinkNode* p2 = l2->next;
	LinkNode* p3 = L3->next;
	N arr[99] = {};
	int i = 0;
	while (p1!= NULL) {
		while (p2 != NULL) {
			arr[i].x = (p1->data.x) * (p2->data.x);
			arr[i].y = (p1->data.y) + (p2->data.y);
			p2 = p2->next;
			i++;
		}
		p2 = l2->next;
		p1 = p1->next;
	}
	for (int j = 0; j < i; j++) {
		ListInsert(L3,j+1,arr[j]);
	}
}

//合并同类项
void merge(LinkNode* L) {
	LinkNode* p, * q, * pre;
	p = L->next;
	while (p) {
		pre = p;
		q = p->next;
		while (q) {
			if (p->data.y == q->data.y) {
				p->data.x += q->data.x;
				pre->next = q->next;
				free(q);
				q = pre->next;
			}
			else {
				pre = q;
				q = q->next;
			}
		}
		p = p->next;
	}
}
//以2+3x+4x^2
//和5x+5x^2为例

int main() {
	N s1 = { 2,0 }, s2 = { 3,1 }, s3 = { 4,2 }, t1 = { 5,1 }, t2 = { 5,2 };//多项式初始化部分
	LinkNode* L1, * L2,*L3;
	L1 = (LinkNode*)malloc(sizeof(LinkNode));
	L2 = (LinkNode*)malloc(sizeof(LinkNode));
	L3 = (LinkNode*)malloc(sizeof(LinkNode));
	if(L1!=NULL&&L2!=NULL&&L3!=NULL){
		L1->next = NULL;
		L2->next = NULL;
		L3->next = NULL;
	}
	ListInsert(L1, 1, s1);                //利用现有的函数进行插入
	ListInsert(L1, 2, s2);
	ListInsert(L1, 3, s3);
	ListInsert(L2, 1, t1);
	ListInsert(L2, 2, t2);
	print(L1);
	print(L2);
	fun(L1, L2,L3);
	cout << "相乘后";
	print(L3);
	merge(L3);
	cout << "合并后";
	print(L3);
}	