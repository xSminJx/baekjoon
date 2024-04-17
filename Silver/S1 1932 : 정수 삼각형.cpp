#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> v(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			int a;
			cin >> a;
			v[i].push_back(a);
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) v[i][j] += v[i - 1][j];
			else if (j == i) v[i][j] += v[i - 1][j - 1];
			else v[i][j] += max(v[i - 1][j], v[i - 1][j - 1]);
		}
	}

	int mx = 0;
	for (auto i:v[n-1]) {
		mx = max(mx, i);
	}
	cout << mx;
	return 0;
}
