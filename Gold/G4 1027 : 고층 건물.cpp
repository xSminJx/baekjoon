#include <iostream>
#include <vector>
using namespace std;

bool check(int i, int j, vector<int>& v) {
	if (i == j) return 0;
	if (i > j) swap(i, j);

	double k = (v[j] - v[i]) / (double)(j - i);
	for (int o = i + 1; o < j; o++) {
		if (v[o] >= k * (o - i) + v[i]) return 0;
	}
	return 1;
}

int main() {
	int n, mx = 0;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (check(i, j, v)) cnt++;
		}
		mx = max(mx, cnt);
	}
	cout << mx;
	return 0;
}
