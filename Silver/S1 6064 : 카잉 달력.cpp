#include <iostream>
using namespace std;

int rhddir(int a, int b) {
	if (b == 0) return a;
	return rhddir(b, a % b);
}

int main() {
	int t, m, n, x, y;
	cin >> t;

	for (int o = 0; o < t; o++) {
		cin >> m >> n >> x >> y;
		int mx = m * n / rhddir(max(m, n), min(m, n));
		while (x <= mx) {
			if (x == y) break;
			else if (x < y) x += m;
			else y += n;
		}
		if (x <= mx) cout << x << endl;
		else cout << -1 << endl;

	}
	return 0;
}
