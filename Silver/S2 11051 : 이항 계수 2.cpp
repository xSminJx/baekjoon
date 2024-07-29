#include <iostream>
#include <vector>
using namespace std;

void input(int n, vector<int>& v) {
	for (int i = 0; i < n; i++) v[i] = i + 1;
}

int rhddir(int a, int b) {
	if (b == 0) return a;
	return rhddir(b, a % b);
}

void check(vector<int>& a, vector<int>& b, int n) {
	for (int i = 0; i < a.size(); i++) {
		int k = rhddir(a[i], b[n]);
		if (k == 1) continue;
		else {
			a[i] /= k, b[n] /= k;
		}
	}
}

int main() {
	int n, k, ans = 1;
	cin >> n >> k;
	vector<int> a(n);
	vector<int> b(n - k);
	vector<int> c(k);

	input(n, a);
	input(n - k, b);
	input(k, c);

	for (int i = 0; i < n - k; i++) {
		while (b[i] != 1) check(a, b, i);
	}
	for (int i = 0; i < k; i++) {
		while (c[i] != 1) check(a, c, i);
	}

	for (auto i : a) {
		ans *= (i % 10007);
		ans %= 10007;
	}
	cout << ans;
	return 0;
}
