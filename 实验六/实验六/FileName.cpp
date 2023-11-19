#include<iostream>
using namespace std;
#define max 100
//定义病人数据类型
typedef struct {
	char name[8];
	int num;
}pat;

//队列定义
typedef struct {
	pat data[max];
	int front, rear;
}que;

//初始化队列
void Great(que*& q) {
	q = (que*)malloc(sizeof(que));
	q->front = q->rear = -1;
}

//进队列
bool enter(que*& q, pat e) {
	if (q->rear == max - 1)
		return false;
	q->rear++;
	q->data[q->rear] = e;
	return true;
}

//出队列
bool del(que*& q, pat& e) {
	if (q->rear == q->front)
		return false;
	q->front++;
	e = q->data[q->front];
	return true;
}

//输出队列
void print(que*& q) {
	int n = q->front + 1;
	while (n != q->rear+1) {
		cout << q->data[n].name << ' ' << q->data[n].num << endl;
		n++;
	}
}

int main() {
	que* q;
	Great(q); //队列创建
	cout << "==菜单==" << endl << "输入0下班" <<endl<< "输入1排队" << endl << "输入2就诊" << endl << "输入3查看排队" << endl << "输入4不再排队"  << endl;
	while(1){
		int n;
		cin >> n;
		switch (n) {
		case 0:                                             //下班
			return 0;
		case 1:                                             //排队
			cout << "请输入患者名字，病历号:";
			pat a;
			cin >> a.name >> a.num;
			enter(q, a);
			cout << a.num << "号病人已排队" << endl;
			break;
		case 2:                                             //就诊
			pat e;
			del(q, e);
			cout << e.num << "号病人已就诊" << endl;
			break;
		case 3:                                             //查看
			cout << "所有排队病人:" << endl;
			print(q);
			break;
		case 4:                                             //不再排队
			cout << "不再排队，剩余排队病人:" << endl;
			print(q);
				return 0;
			}
		}
	}



