#include<iostream>
using namespace std;
#define max 100
//���岡����������
typedef struct {
	char name[8];
	int num;
}pat;

//���ж���
typedef struct {
	pat data[max];
	int front, rear;
}que;

//��ʼ������
void Great(que*& q) {
	q = (que*)malloc(sizeof(que));
	q->front = q->rear = -1;
}

//������
bool enter(que*& q, pat e) {
	if (q->rear == max - 1)
		return false;
	q->rear++;
	q->data[q->rear] = e;
	return true;
}

//������
bool del(que*& q, pat& e) {
	if (q->rear == q->front)
		return false;
	q->front++;
	e = q->data[q->front];
	return true;
}

//�������
void print(que*& q) {
	int n = q->front + 1;
	while (n != q->rear+1) {
		cout << q->data[n].name << ' ' << q->data[n].num << endl;
		n++;
	}
}

int main() {
	que* q;
	Great(q); //���д���
	cout << "==�˵�==" << endl << "����0�°�" <<endl<< "����1�Ŷ�" << endl << "����2����" << endl << "����3�鿴�Ŷ�" << endl << "����4�����Ŷ�"  << endl;
	while(1){
		int n;
		cin >> n;
		switch (n) {
		case 0:                                             //�°�
			return 0;
		case 1:                                             //�Ŷ�
			cout << "�����뻼�����֣�������:";
			pat a;
			cin >> a.name >> a.num;
			enter(q, a);
			cout << a.num << "�Ų������Ŷ�" << endl;
			break;
		case 2:                                             //����
			pat e;
			del(q, e);
			cout << e.num << "�Ų����Ѿ���" << endl;
			break;
		case 3:                                             //�鿴
			cout << "�����ŶӲ���:" << endl;
			print(q);
			break;
		case 4:                                             //�����Ŷ�
			cout << "�����Ŷӣ�ʣ���ŶӲ���:" << endl;
			print(q);
				return 0;
			}
		}
	}



