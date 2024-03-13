#include <iostream>
using namespace std;

int main() {
	int n, num[302], list[300][2] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++) cin >> num[i + 2];

	for (int i = 2; i < n + 2; i++) {
		int a, b;
		a = max(list[i - 2][0], list[i - 2][1]);
		b = list[i - 1][0];

		list[i][0] = a + num[i];
		list[i][1] = b + num[i];
	}

	cout << max(list[n + 1][0], list[n + 1][1]);
	return 0;
}
