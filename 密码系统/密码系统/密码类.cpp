#include<iostream>
#include<conio.h>
using namespace std;
class PW
{
private:
	char mima[6];
	char password[6];
	void cover(char a[]);
public:
	void DefPassword();
	void PutPassword();
};

int main()
{
	PW pw;
	pw.DefPassword();
	pw.PutPassword();
	return 0;
}


void PW::cover(char a[])
{
	char ch;
	int i = 0;
	while ((ch = _getch()) != '\r')
	{
		a[i] = ch;
		cout << "*";
		i++;
	}
}
void PW::DefPassword()
{
	cout << "Please define password:" << endl;
	cover(mima);
	cout << endl;
}
void PW::PutPassword()
{
	int i;
	for (i = 0; i < 3; i++)
	{
		cout << "Please input:" << endl;
		cover(password);
		cout << endl;
		int j = 0;
		for (int k = 0; k < 6; k++)

			if (mima[k] == password[k])
				j++;
		if (j == 6)
		{
			cout << "Right" << endl;
			break;
		}

		else
		{
			if (i == 2)
			{
				cout << "多次错误系统锁定";
				break;
			}
			cout << "Error,please again:" << endl;
		}
	}
}