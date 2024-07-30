#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, buffer;
	cin >> n >> m;
	vector<bool> v(n + 1);
	vector<int> fib(42);

	for (int i = 0; i < m; i++) {
		cin >> buffer;
		v[buffer] = 1;
	}

	fib[0] = 0, fib[1] = 1;
	for (int i = 2; i < 42; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}

	int stc = 0, sum = 1;
	for (int i = 1; i <= n; i++) {
		if (v[i]) {
			sum *= fib[stc + 1];
			stc = 0;
		}
		else stc++;
	}
	sum *= fib[stc + 1];
	cout << sum;
	return 0;
}
