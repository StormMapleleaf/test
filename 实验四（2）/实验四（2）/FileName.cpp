#include<iostream>
#define max 4
using namespace std;
//���ζ������͵Ķ���
typedef struct {
	int data[max];
	int front, rear,c;
}queue;

//��ʼ������
void Qu(queue*& q) {
	q = (queue*)malloc(sizeof(queue));
	q->front  =q->c= 0;//������ͷβ��ʼ��Ϊ0
}
//������
bool enter(queue*& q, int e) {
	if (q->c == max)//�ж��Ƿ����
	{
		cout << "���������";
		return false;
	}
		int rear;
		rear = (q->front + q->c) % max;
		rear = (rear + 1) % max;
		q->data[rear] = e;
		q->c++;
		return true;
}
//������
bool del(queue*& q, int& e) {
	if (q->c==0)//�ж��Ƿ�ӿ�
		return false;
	q->front = (q->front + 1) % max;
	e = q->data[q->front];
	q->c--;
	return true;
}

//�����Ԫ����
int count(queue*& q) {
	return q->c;
}

int main() {
	cout << "����0�˳�" << endl;
	cout << "����1������" << endl;
	cout << "����2������" << endl;
	cout << "����3ȡ����Ԫ�ظ���" << endl;
	queue* q;//�������
	Qu(q);
	while (1) {
		cout << "������:";
		int n, e;
		cin >> n;
		switch (n) {
		case 0:
			return 0;
			break;
		case 1:
			cout << "���������Ԫ��:";
			cin >> e;
			enter(q, e);
			break;
		case 2:
			del(q, e);
			cout << e << "�ѳ�����" << endl;
			break;
		case 3:
			int s=count(q);
			cout << "����Ԫ�ظ���Ϊ:" << s << endl;
			break;
		}
	}

}