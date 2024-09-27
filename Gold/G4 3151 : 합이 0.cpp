#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0), cout.tie(0)

int main() {
	int n;
	long long cnt = 0;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; cin >> v[i++]);
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (i != j) cnt += upper_bound(v.begin() + j + 1, v.end(), -(v[i] + v[j])) - lower_bound(v.begin() + j + 1, v.end(), -(v[i] + v[j]));
		}
	}
	cout << cnt;
	return 0;
}
