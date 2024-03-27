#include <iostream>
using namespace std;

int main() {
	long long a, b, c, stc = 1;
	cin >> a >> b >> c;
	a = a %= c;

	while (b > 1) {
		if (b % 2) {
			stc *= a;
		}
		b /= 2;
		a = a * a % c;
		stc %= c;
	}

	cout << a * stc % c;
	return 0;
}
