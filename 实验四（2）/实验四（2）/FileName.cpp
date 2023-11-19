#include<iostream>
#define max 4
using namespace std;
//环形队列类型的定义
typedef struct {
	int data[max];
	int front, rear,c;
}queue;

//初始化队列
void Qu(queue*& q) {
	q = (queue*)malloc(sizeof(queue));
	q->front  =q->c= 0;//环队列头尾初始化为0
}
//进队列
bool enter(queue*& q, int e) {
	if (q->c == max)//判断是否溢出
	{
		cout << "溢出！！！";
		return false;
	}
		int rear;
		rear = (q->front + q->c) % max;
		rear = (rear + 1) % max;
		q->data[rear] = e;
		q->c++;
		return true;
}
//出队列
bool del(queue*& q, int& e) {
	if (q->c==0)//判断是否队空
		return false;
	q->front = (q->front + 1) % max;
	e = q->data[q->front];
	q->c--;
	return true;
}

//求队列元素数
int count(queue*& q) {
	return q->c;
}

int main() {
	cout << "输入0退出" << endl;
	cout << "输入1进队列" << endl;
	cout << "输入2出队列" << endl;
	cout << "输入3取队列元素个数" << endl;
	queue* q;//定义队列
	Qu(q);
	while (1) {
		cout << "请输入:";
		int n, e;
		cin >> n;
		switch (n) {
		case 0:
			return 0;
			break;
		case 1:
			cout << "输入进队列元素:";
			cin >> e;
			enter(q, e);
			break;
		case 2:
			del(q, e);
			cout << e << "已出队列" << endl;
			break;
		case 3:
			int s=count(q);
			cout << "队列元素个数为:" << s << endl;
			break;
		}
	}

}