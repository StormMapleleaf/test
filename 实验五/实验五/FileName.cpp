#include<iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define maxsize 100
int mg[6][6] = { {1,1,1,1,1,1},{1,0,0,0,1,1},
      {1,0,1,0,0,1},{1,0,0,0,1,1},
      {1,1,0,0,0,1},{1,1,1,1,1,1} };
//�����Թ� 1Ϊǽ��0Ϊ·

typedef struct {
    int i, j, di;
}box;//����ջ��Ԫ��

typedef struct {
    box data[maxsize];
    int top;
}stack;//����ջ������

void Initstack(stack*& s)//��ʼ��ջ
{
    s = new stack;
    s->top = -1;
}

bool push(stack*& s, box e)//��ջ
{
    if (s->top == maxsize - 1)
        return false;
    s->top++;
    s->data[s->top] = e;
    return true;
}

bool pop(stack*& s, box& e)//��ջ
{
    if (s->top == -1)
        return false;
    e = s->data[s->top];
    s->top--;
    return true;
}

bool gettop(stack*& s, box& e) //ȡջ��Ԫ��
{
    if (s->top == -1)
        return false;
    e = s->data[s->top];
    return true;
}

//����ջ
void DestroyStack(stack*& s)
{
    free(s);
}

//�жϿ�
bool StackEmpty(stack* s)
{
    return (s->top == -1);
}

bool mgpath(int x1, int y1, int x2, int y2)//Ѱ��·��
{
    box e;
    int l = 100, min = 1, count = 1;
    int i, j, di, k, a, b;
    int flag = 0;//�н�
    bool find;
    stack* s;
    Initstack(s);//��ʼ��ջ

    e.i = x1;//�Թ����
    e.j = y1;
    e.di = -1;
    push(s, e);
    mg[x1][y1] = -1;//��ֹ�ظ���
    while (!StackEmpty(s))//�ǿ�ʱѭ��
    {
        gettop(s, e);//ȡջ������e(i,j)
        i = e.i;
        j = e.j;
        di = e.di;
        if (i == x2 && j == y2)//�ҵ����������·��
        {
            flag = 1;
            if (s->top + 1 < l)//���·���Ƚ�
            {
                l = s->top + 1;//����
                min = count;//��̳��ȶ�Ӧ�ĵڼ���·
            }
            cout << "·��һ:" << count++ << endl;
            for (k = 0; k <= s->top; k++)
                cout << '('<<s->data[k].i << ',' << s->data[k].j<<')'<<' ';
            cout << endl;
            pop(s, e);//���ݵ�·
            mg[e.i][e.j] = 0;
            continue;//��������ѭ��
        }
        find = false;
        while (di < 4 && !find)//������һ������
        {
            di++;//��ֵΪ-1
            switch (di)//��̽����
            {
            case 0:a = i - 1, b = j; break;
            case 1:a = i, b = j + 1; break;
            case 2:a = i + 1, b = j; break;
            case 3:a = i, b = j - 1; break;
            }
            if (mg[a][b] == 0)
                find = true;//ִ�п���·��(a,b)
        }
        if (find)//�������Ϊ��
        {
            s->data[s->top].di = di;
            e.i = a;
            e.j = b;
            e.di = -1;
            push(s, e);//���飨a��b����ջ
            mg[a][b] = -1;//��ֹ�ظ�ִ��
        }
        else //����ʧ��
        {
            pop(s, e);
            mg[e.i][e.j] = 0;//�ָ�
        }
    }
    if (flag == 1)
    {
        cout << "���Ϊ:" << min << endl;
        cout << "��̳�����" << l << endl;
        return true;
    }
    DestroyStack(s);//�ͷ�ջ
    return false;
}

int main()
{
    if (!mgpath(1, 1, 4, 4))
        cout << "�޽�" << endl;
    return 0;
}
