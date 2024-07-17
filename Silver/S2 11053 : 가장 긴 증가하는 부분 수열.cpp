#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> dp(n, 1);

	int mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		int mx2 = dp[i];
		for (int j = 0; j <= i; j++) {
			if (v[j] < v[i]) mx2 = max(mx2, dp[j] + 1);
		}
		dp[i] = mx2;
		mx = max(mx, mx2);
	}
	cout << mx;
	return 0;
}
