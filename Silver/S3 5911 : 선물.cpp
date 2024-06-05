#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const vector<int>& a, const vector<int>& b) {
	if ((a[0] + a[1]) == (b[0] + b[1])) return a[0] > b[0];
	return a[0] + a[1] < b[0] + b[1];
}

int main() {
	int n, b, sum = 0, cnt = 0;
	cin >> n >> b;
	vector<vector<int>> v(n, vector<int>(2));

	for (int i = 0; i < n; i++) {
		cin >> v[i][0] >> v[i][1];
	}
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < n; i++) {
		sum += v[i][0] + v[i][1];
		if (sum <= b) cnt++;
		else {
			for (int j = 0; j <= i; j++) {
				if (sum - v[j][0] + v[j][0] / 2 <= b) {
					cnt++;
					break;
				}
			}
			break;
		}
	}

	cout << cnt;
	return 0;
}
