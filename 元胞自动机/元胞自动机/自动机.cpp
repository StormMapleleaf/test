#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;
#define N 17
void num(char a[][N], int b[][N])
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			int n = 0;
			if (a[i - 1][j - 1] == 'O')
				n++;
			if (a[i - 1][j] == 'O')
				n++;
			if (a[i - 1][j + 1] == 'O')
				n++;
			if (a[i][j - 1] == 'O')
				n++;
			if (a[i][j + 1] == 'O')
				n++;
			if (a[i + 1][j - 1] == 'O')
				n++;
			if (a[i + 1][j] == 'O')
				n++;
			if (a[i + 1][j + 1] == 'O')
				n++;
			b[i][j] = n;
		}
}
void trans(int b[][N], char c[][N], char a[][N])//(数量，原数组，转换数组)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			a[i][j] = c[i][j];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if ((a[i][j] == 'O') && (b[i][j] < 2))
				a[i][j] = ' ';
			else if ((a[i][j] == 'O') && (b[i][j] == (2 || 3)))
				a[i][j] = 'O';
			if ((a[i][j] == 'O') && (b[i][j] > 3))
				a[i][j] = ' ';
			if ((a[i][j] == ' ') && (b[i][j] == 3))
				a[i][j] = 'O';
		}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			c[i][j] = a[i][j];
}
int main()
{
	ofstream out("d:\\file\\f1.txt", ios::out);
	char a[N][N];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			a[i][j] = ' ';
	{	a[8][4] = a[8][5] = a[8][6] = a[8][7] = a[8][8] = a[8][9] = 
		a[8][10] = a[8][11] = a[8][12] = a[8][1] = 'O'; }
	int b[N][N];
	char tra[N][N];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			out << a[i][j];
		}
		out << endl;
	}
	fflush(stdin);
	Sleep(500);
	long l = out.tellp();
	l = 0;                               /////////////////////
	out.seekp(l, ios::beg);              //By StormMapleleaf//
	num(a, b);                           /////////////////////
	trans(b, a, tra);
	{
		ofstream out1("d:\\file\\f1.txt", ios::out);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				out1 << a[i][j];
			}
			out1 << endl;
		}
		fflush(stdin);
		Sleep(500);
		out1.seekp(l, ios::beg);
		num(a, b);
		trans(b, a, tra);

		ofstream out2("d:\\file\\f1.txt", ios::out);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				out2 << a[i][j];
			}
			out2 << endl;
		}
		fflush(stdin);
		Sleep(500);
		out2.seekp(l, ios::beg);
		num(a, b);
		trans(b, a, tra);

		ofstream out3("d:\\file\\f1.txt", ios::out);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				out3 << a[i][j];
			}
			out3 << endl;
		}
		fflush(stdin);
		Sleep(500);
		out3.seekp(l, ios::beg);
		num(a, b);
		trans(b, a, tra);

		ofstream out4("d:\\file\\f1.txt", ios::out);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				out4 << a[i][j];
			}
			out4 << endl;
		}
		fflush(stdin);
		Sleep(500);
		out4.seekp(l, ios::beg);
		num(a, b);
		trans(b, a, tra);

		ofstream out5("d:\\file\\f1.txt", ios::out);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				out5 << a[i][j];
			}
			out5 << endl;
		}
		fflush(stdin);
		Sleep(500);
		out5.seekp(l, ios::beg);
		num(a, b);
		trans(b, a, tra);

		ofstream out6("d:\\file\\f1.txt", ios::out);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				out6 << a[i][j];
			}
			out6 << endl;
		}
		fflush(stdin);
		Sleep(500);
		out6.seekp(l, ios::beg);
		num(a, b);
		trans(b, a, tra);

		ofstream out7("d:\\file\\f1.txt", ios::out);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				out7 << a[i][j];
			}
			out7 << endl;
		}
		fflush(stdin);
		Sleep(500);
		out7.seekp(l, ios::beg);
		num(a, b);
		trans(b, a, tra);

		ofstream out8("d:\\file\\f1.txt", ios::out);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				out8 << a[i][j];
			}
			out8 << endl;
		}
		fflush(stdin);
		Sleep(500);
		out8.seekp(l, ios::beg);
		num(a, b);
		trans(b, a, tra);

		ofstream out9("d:\\file\\f1.txt", ios::out);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				out9 << a[i][j];
			}
			out9 << endl;
		}
		fflush(stdin);
		Sleep(500);
		out9.seekp(l, ios::beg);
		num(a, b);
		trans(b, a, tra);

		ofstream out10("d:\\file\\f1.txt", ios::out);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				out10 << a[i][j];
			}
			out10 << endl;
		}
		fflush(stdin);
		Sleep(500);
		out10.seekp(l, ios::beg);
		num(a, b);
		trans(b, a, tra);

		ofstream out11("d:\\file\\f1.txt", ios::out);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				out11 << a[i][j];
			}
			out11 << endl;
		}
		fflush(stdin);
		Sleep(500);
		out11.seekp(l, ios::beg);
		num(a, b);
		trans(b, a, tra);

		ofstream out12("d:\\file\\f1.txt", ios::out);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				out12 << a[i][j];
			}
			out12 << endl;
		}
		fflush(stdin);
		Sleep(500);
		out12.seekp(l, ios::beg);
		num(a, b);
		trans(b, a, tra);

		ofstream out13("d:\\file\\f1.txt", ios::out);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				out13 << a[i][j];
			}
			out13 << endl;
		}
		fflush(stdin);
		Sleep(500);
		out13.seekp(l, ios::beg);
		num(a, b);
		trans(b, a, tra);

		ofstream out14("d:\\file\\f1.txt", ios::out);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				out14 << a[i][j];
			}
			out14 << endl;
		}
		fflush(stdin);
		Sleep(500);
		out14.seekp(l, ios::beg);
		num(a, b);
		trans(b, a, tra);

		ofstream out15("d:\\file\\f1.txt", ios::out);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				out15 << a[i][j];
			}
			out15 << endl;
		}
		fflush(stdin);
		Sleep(500);
		out15.seekp(l, ios::beg);
		num(a, b);
		trans(b, a, tra);

		ofstream out16("d:\\file\\f1.txt", ios::out);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				out16 << a[i][j];
			}
			out16 << endl;
		}
		fflush(stdin);
		Sleep(500);
		out16.seekp(l, ios::beg);
		num(a, b);
		trans(b, a, tra);

		ofstream out17("d:\\file\\f1.txt", ios::out);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				out17 << a[i][j];
			}
			out17 << endl;
		}
		fflush(stdin);
		Sleep(500);
		out17.seekp(l, ios::beg);
		num(a, b);
		trans(b, a, tra);

		ofstream out18("d:\\file\\f1.txt", ios::out);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				out18 << a[i][j];
			}
			out18 << endl;
		}
		fflush(stdin);
		Sleep(500);
		out18.seekp(l, ios::beg);
		num(a, b);
		trans(b, a, tra);

		ofstream out19("d:\\file\\f1.txt", ios::out);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				out19 << a[i][j];
			}
			out19 << endl;
		}
		fflush(stdin);
		Sleep(500);
		out19.seekp(l, ios::beg);
		num(a, b);
		trans(b, a, tra);

		ofstream out20("d:\\file\\f1.txt", ios::out);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				out20 << a[i][j];
			}
			out20 << endl;
		}
		fflush(stdin);
		Sleep(500);
		out20.seekp(l, ios::beg);
		num(a, b);
		trans(b, a, tra);

		ofstream out21("d:\\file\\f1.txt", ios::out);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				out21 << a[i][j];
			}
			out21 << endl;
		}
		fflush(stdin);
		Sleep(500);
		out21.seekp(l, ios::beg);
		num(a, b);
		trans(b, a, tra);

		ofstream out22("d:\\file\\f1.txt", ios::out);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				out22 << a[i][j];
			}
			out22 << endl;
		}
		fflush(stdin);
		Sleep(500);
		out22.seekp(l, ios::beg);
		num(a, b);
		trans(b, a, tra);

		ofstream out23("d:\\file\\f1.txt", ios::out);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				out23 << a[i][j];
			}
			out23 << endl;
		}
		fflush(stdin);
		Sleep(500);
		out23.seekp(l, ios::beg);
		num(a, b);
		trans(b, a, tra);

		ofstream out24("d:\\file\\f1.txt", ios::out);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				out24 << a[i][j];
			}
			out24 << endl;
		}
		fflush(stdin);
		Sleep(500);
		out24.seekp(l, ios::beg);
		num(a, b);
		trans(b, a, tra);

		ofstream out25("d:\\file\\f1.txt", ios::out);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				out25 << a[i][j];
			}
			out25 << endl;
		}
		fflush(stdin);
		Sleep(500);
		out25.seekp(l, ios::beg);
		num(a, b);
		trans(b, a, tra);

		ofstream out26("d:\\file\\f1.txt", ios::out);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				out26 << a[i][j];
			}
			out26 << endl;
		}
		fflush(stdin);
		Sleep(500);
		out26.seekp(l, ios::beg);
		num(a, b);
		trans(b, a, tra);

		ofstream out27("d:\\file\\f1.txt", ios::out);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				out27 << a[i][j];
			}
			out27 << endl;
		}
		fflush(stdin);
		Sleep(500);
		out27.seekp(l, ios::beg);
		num(a, b);
		trans(b, a, tra);

		ofstream out28("d:\\file\\f1.txt", ios::out);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				out28 << a[i][j];
			}
			out28 << endl;
		}
		fflush(stdin);
		Sleep(500);
		out28.seekp(l, ios::beg);
		num(a, b);
		trans(b, a, tra);

		ofstream out29("d:\\file\\f1.txt", ios::out);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				out29 << a[i][j];
			}
			out29 << endl;
		}
		fflush(stdin);
		Sleep(500);
		out29.seekp(l, ios::beg);
		num(a, b);
		trans(b, a, tra);

		ofstream out30("d:\\file\\f1.txt", ios::out);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				out30 << a[i][j];
			}
			out30 << endl;
		}
		fflush(stdin);
		Sleep(500);
		out30.seekp(l, ios::beg);
		num(a, b);
		trans(b, a, tra);
	}//
	//主体折叠
}