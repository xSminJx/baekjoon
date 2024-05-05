#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(vector<int>& a, vector<int>& b) {
	return a[0] < b[0];
}

int main() {
	int n, m, a, b;
	cin >> n >> m;
	vector<vector<int>> v(m * 2, vector<int>(2));
	for (int i = 0; i < m; i++) {
		cin >> v[i * 2][0] >> v[i * 2 + 1][0];
		v[i * 2 + 1][1] = v[i * 2][1] = i + 1;
	}
	sort(v.begin(), v.end(), compare);
	cout << v[(n - 1) % (m * 2)][1];
	return 0;
}
