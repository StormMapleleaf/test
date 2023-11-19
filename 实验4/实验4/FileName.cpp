#include<iostream>
using namespace std;
#define max 100
//����ջ����
typedef struct {
	int data[max];
	int top;//ջ��ָ��
}stack;

//��ʼ��ջ
void Stack(stack*& s) {
	s = (stack*)malloc(sizeof(stack));
	s->top = -1;
}

//��ջ����
bool push(stack*& s, int e) {
	if (s->top == max - 1)//�ж�ջ�Ƿ����
		return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}

//��ջ����
bool pop(stack*& s, int& e) {
	if (s->top == -1)//�ж�ջ�Ƿ�Ϊ��
		return false;
	e = s->data[s->top];
	s->top--;
	return true;
}

//ȡջ��Ԫ��
bool get(stack* s, int& e) {
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	return true;
}

int main() {
	cout << "����0�˳�"<<endl;
	cout << "����1��ջ" << endl;
	cout << "����2��ջ" << endl;
	cout << "����3ȡջ��Ԫ��" << endl;
	stack *S;//����ջ
	Stack(S);
	while (1) {
		cout << "������:";
		int n,e;
		cin >> n;
		switch (n) {
		case 0:
			return 0;
			break;
		case 1:
			cout << "�����ջԪ��:";
			cin >> e;
			push(S, e);
			break;
		case 2:
			pop(S, e);
			cout << e << "�ѳ�ջ" << endl;
			break;
		case 3:
			get(S, e);
			cout << "ջ��Ԫ��Ϊ:" << e<<endl;
			break;
		}
	}

}