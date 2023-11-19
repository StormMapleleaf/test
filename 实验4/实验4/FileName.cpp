#include<iostream>
using namespace std;
#define max 100
//定义栈类型
typedef struct {
	int data[max];
	int top;//栈顶指针
}stack;

//初始化栈
void Stack(stack*& s) {
	s = (stack*)malloc(sizeof(stack));
	s->top = -1;
}

//进栈函数
bool push(stack*& s, int e) {
	if (s->top == max - 1)//判断栈是否溢出
		return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}

//出栈函数
bool pop(stack*& s, int& e) {
	if (s->top == -1)//判断栈是否为空
		return false;
	e = s->data[s->top];
	s->top--;
	return true;
}

//取栈顶元素
bool get(stack* s, int& e) {
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	return true;
}

int main() {
	cout << "输入0退出"<<endl;
	cout << "输入1进栈" << endl;
	cout << "输入2出栈" << endl;
	cout << "输入3取栈顶元素" << endl;
	stack *S;//定义栈
	Stack(S);
	while (1) {
		cout << "请输入:";
		int n,e;
		cin >> n;
		switch (n) {
		case 0:
			return 0;
			break;
		case 1:
			cout << "输入进栈元素:";
			cin >> e;
			push(S, e);
			break;
		case 2:
			pop(S, e);
			cout << e << "已出栈" << endl;
			break;
		case 3:
			get(S, e);
			cout << "栈顶元素为:" << e<<endl;
			break;
		}
	}

}