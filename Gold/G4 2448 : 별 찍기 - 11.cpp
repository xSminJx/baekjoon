#include <iostream>
#include <vector>
using namespace std;

int get_level(int n) {
	int cnt = -2;
	n /= 3;
	while (n) {
		n /= 2;
		cnt++;
	}
	return cnt;
}

int pow(int n) { return 1 << n; }

void tri(int n, int m, vector<vector<bool>>& v, int mx, int level) {
	if (level == -1) {
		v[n][m] = 1;
		v[n + 1][m - 1] = v[n + 1][m + 1] = 1;
		v[n + 2][m - 2] = v[n + 2][m - 1] = v[n + 2][m] = v[n + 2][m + 1] = v[n + 2][m + 2] = 1;
	}
	else {
		tri(n, m, v, mx, level - 1);
		tri(n + 3 * pow(level), m - 3 * pow(level), v, mx, level - 1);
		tri(n + 3 * pow(level), m + 3 * pow(level), v, mx, level - 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<vector<bool>> v(n, vector<bool>(n * 2 + 1));
	tri(0, n - 1, v, n, get_level(n));
	for (auto i : v) {
		for (auto j : i) {
			if (j == 1) cout << '*';
			else cout << ' ';
		}
		cout << endl;
	}

	return 0;
}
