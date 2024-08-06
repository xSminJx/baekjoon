#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> val(n + 1); // 무게, 가치
	vector<vector<int>> dp(n + 1, vector<int>(k + 1));

	for (int i = 1; i <= n; i++) cin >> val[i].first >> val[i].second;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j < val[i].first) dp[i][j] = dp[i - 1][j];
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - val[i].first] + val[i].second);
			}
		}
	}
	cout << dp[n][k];
	return 0;
}
