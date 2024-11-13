#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

int main() {
	fastio;
	int n, k, res = 0;
	cin >> n >> k;
	vector<int> v(n);
	vector<int> len(n - 1);
	for (auto& i : v) cin >> i;
	sort(v.begin(), v.end());
	for (int i = 0; i < n - 1; i++) {
		len[i] = v[i + 1] - v[i];
	}
	sort(len.begin(), len.end(), greater<int>());
	for (int i = k - 1; i < n - 1; i++) res += len[i];

	cout << res;
	return 0;
}
