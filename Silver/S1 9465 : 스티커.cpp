#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		vector<vector<int>> v(max(n, 2), vector<int>(2));
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < n; k++) cin >> v[k][j];
		}
		v[1][0] += v[0][1], v[1][1] += v[0][0];
		for (int j = 2; j < n; j++) {
			v[j][0] += max({ v[j - 1][1], v[j - 2][0], v[j - 2][1] });
			v[j][1] += max({ v[j - 1][0], v[j - 2][0], v[j - 2][1] });
		}
		if (n == 1) cout << max(v[0][0], v[0][1]) << endl;
		else cout << max({ v[n - 1][0], v[n - 1][1], v[n - 2][0], v[n - 2][1] }) << endl;
	}
	return 0;
}
