//By StormMapleleaf_代齐祥
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MaxSize 10
//结构体类型定义
struct Stu {
	char name[10];
	int m;
};
typedef Stu ElemType;
typedef struct {
	ElemType data[MaxSize];
	int length;
}SqList;

//插入
bool ListInsert(SqList*& L, int i, ElemType e) {
	int j;
	if (i < 1 || i>L->length + 1 || L->length == MaxSize)
		return false;                                     //判断参数是否正确
	i--;                                                  //物理与逻辑序号转化 
	for (j = L->length; j > i; j--)                       //插入位置及以后元素后移
		L->data[j] = L->data[j - 1];
	L->data[i] = e;
	L->length++;                                          //表长加一
	return true;
}
//删除
bool ListDelete(SqList*& L, int i, ElemType& e) {
	int j;
	if (i<1 || i>L->length)
		return false;                                     //判断参数是否正确
	i--;                                                  //物理与逻辑序号转化 
	e = L->data[i];                                       //插入位置及以后元素后移
	for (j = i; j < L->length - 1; j++)
		L->data[j] = L->data[j + 1];
	L->length--;                                          //表长减一
	return true;
}
//按序号查找
bool GetElem(SqList* L, int i, ElemType& e) {
	if (i<1 || i>L->length)
		return false;                                     //判断i存在性
	e = L->data[i - 1];
	return true;
}
//输出
void print(SqList* L) {
	printf("顺序表输出:\n");
	for (int i = 0; i < L->length; i++) {
		printf("%s %d\n", L->data[i].name, L->data[i].m);
		
	}
	printf("\n");
}
 int main() {
	 printf("###输入0退出###\n");
	 printf("###输入1插入###\n");
	 printf("###输入2删除###\n");
	 printf("###输入3查找###\n");
	SqList *L;
	L = (SqList*)malloc(sizeof(SqList));
	if(L!=NULL)
	L->length = 0;
	while (1) {
		printf("请输入:");
		int num;
		scanf("%d", &num);
		switch (num) {
		case 0:
			return 0;
			break;
		case 1:
			Stu s;
			int in;
			printf("请输入名字,分数:");
			scanf("%s%d", &s.name, &s.m);
			printf("请输入插入的序号:");
			scanf("%d", &in);
			ListInsert(L, in, s);
			print(L);
			break;

		case 2:
			int del;
			Stu se;
			printf("请输入需要删除元素的序号:");
			scanf("%d", &del);
			ListDelete(L, del, se);
			print(L);
			break;

		case 3:
			Stu sg;
			int get;
			printf("请输入查找的序号:");
			scanf("%d", &get);
			GetElem(L, get, sg);
			printf("查找结果:");
			printf("%s %d\n", sg.name, sg.m);
			printf("\n");
			break;
		}
	}
}