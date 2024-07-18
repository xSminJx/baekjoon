#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n + 1, vector<int>(n + 1));
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			cin >> v[i][j];
			v[i][j] += v[i][j - 1];
		}
	}

	for (int i = 0; i < m; i++) {
		int x1, y1, x2, y2, sum = 0;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int j = x1; j <= x2; j++) {
			sum += v[j][y2] - v[j][y1 - 1];
		}
		cout << sum << '\n';
	}
	return 0;
}
