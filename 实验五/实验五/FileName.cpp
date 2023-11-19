#include<iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define maxsize 100
int mg[6][6] = { {1,1,1,1,1,1},{1,0,0,0,1,1},
      {1,0,1,0,0,1},{1,0,0,0,1,1},
      {1,1,0,0,0,1},{1,1,1,1,1,1} };
//设置迷宫 1为墙，0为路

typedef struct {
    int i, j, di;
}box;//定义栈的元素

typedef struct {
    box data[maxsize];
    int top;
}stack;//定义栈的类型

void Initstack(stack*& s)//初始化栈
{
    s = new stack;
    s->top = -1;
}

bool push(stack*& s, box e)//进栈
{
    if (s->top == maxsize - 1)
        return false;
    s->top++;
    s->data[s->top] = e;
    return true;
}

bool pop(stack*& s, box& e)//出栈
{
    if (s->top == -1)
        return false;
    e = s->data[s->top];
    s->top--;
    return true;
}

bool gettop(stack*& s, box& e) //取栈顶元素
{
    if (s->top == -1)
        return false;
    e = s->data[s->top];
    return true;
}

//销毁栈
void DestroyStack(stack*& s)
{
    free(s);
}

//判断空
bool StackEmpty(stack* s)
{
    return (s->top == -1);
}

bool mgpath(int x1, int y1, int x2, int y2)//寻找路径
{
    box e;
    int l = 100, min = 1, count = 1;
    int i, j, di, k, a, b;
    int flag = 0;//有解
    bool find;
    stack* s;
    Initstack(s);//初始化栈

    e.i = x1;//迷宫入口
    e.j = y1;
    e.di = -1;
    push(s, e);
    mg[x1][y1] = -1;//防止重复走
    while (!StackEmpty(s))//非空时循环
    {
        gettop(s, e);//取栈顶方块e(i,j)
        i = e.i;
        j = e.j;
        di = e.di;
        if (i == x2 && j == y2)//找到出口输出该路径
        {
            flag = 1;
            if (s->top + 1 < l)//最短路径比较
            {
                l = s->top + 1;//长度
                min = count;//最短长度对应的第几条路
            }
            cout << "路径一:" << count++ << endl;
            for (k = 0; k <= s->top; k++)
                cout << '('<<s->data[k].i << ',' << s->data[k].j<<')'<<' ';
            cout << endl;
            pop(s, e);//回溯道路
            mg[e.i][e.j] = 0;
            continue;//结束当次循环
        }
        find = false;
        while (di < 4 && !find)//检索下一个方块
        {
            di++;//初值为-1
            switch (di)//试探方块
            {
            case 0:a = i - 1, b = j; break;
            case 1:a = i, b = j + 1; break;
            case 2:a = i + 1, b = j; break;
            case 3:a = i, b = j - 1; break;
            }
            if (mg[a][b] == 0)
                find = true;//执行可走路径(a,b)
        }
        if (find)//检索结果为真
        {
            s->data[s->top].di = di;
            e.i = a;
            e.j = b;
            e.di = -1;
            push(s, e);//方块（a，b）入栈
            mg[a][b] = -1;//防止重复执行
        }
        else //检索失败
        {
            pop(s, e);
            mg[e.i][e.j] = 0;//恢复
        }
    }
    if (flag == 1)
    {
        cout << "最短为:" << min << endl;
        cout << "最短长度是" << l << endl;
        return true;
    }
    DestroyStack(s);//释放栈
    return false;
}

int main()
{
    if (!mgpath(1, 1, 4, 4))
        cout << "无解" << endl;
    return 0;
}
