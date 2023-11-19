#include<iostream>
using namespace std;
int main() {
	double dm[5] = { 10.052,9.851,9.593,9.361,9.097 };
	double dn[5] = { 7.422,7.094,6.768,6.387,6.028 };
	for (int i = 0; i < 5; i++) {
		double m = 0, n = 0;
		 m = dm[i] * dm[i];
		cout << i <<"m" << m << endl;
		 n = dn[i] * dn[i];
		cout << i << "n" << n << endl;
		cout << m - n<<endl;
	}
	return 0;
}