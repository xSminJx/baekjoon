#include <iostream>
#include <vector>
using namespace std;

bool findm(int i, int j, vector<int>& s, vector<vector<int>>& v, int n) {
	for (int k = 0; k < n; k++) {
		if (v[i][k] && k == j) return 1;
		else if (v[i][k] && !s[k]) {
			s[k] = 1;
			if (findm(k, j, s, v, n)) return 1;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> v[i][j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vector<int> s(n, 0);
			if (findm(i, j, s, v, n)) cout << 1 << " ";
			else cout << 0 << " ";
		}
		cout << "\n";
	}
	return 0;
}
