#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0), cout.tie(0)
// 인접한 공유기들의 최소 거리를 이분탐색으로 구한다.

// 공유기들의 최소 거리를 n으로 배치 할 수 있는지 검사
bool check(int n, int c, vector<int>& v) {
	int cur = v[0], curidx = 0;
	c--;

	while (c--) {
		bool isfind = 0;
		int target = cur + n;

		int l = curidx, r = v.size() - 1, mid;
		while (l <= r) {
			mid = (l + r) / 2;
			if (v[mid] < target) l = mid + 1;
			else {
				if (mid > 0 && v[mid - 1] < target) {
					cur = v[mid], curidx = mid;
					isfind = 1;
					break;
				}
				else r = mid - 1;
			}
		}
		if (isfind == 0) return 0;
	}
	return 1;
}

int main() {
	int n, c;
	cin >> n >> c;
	vector<int> v(n);
	for (int i = 0; i < n; cin >> v[i++]);
	sort(v.begin(), v.end());

	int l = 1, r = (v.back() - v.front() + 1 - c) / (c - 1) + 1, mid = 0;
	while (l <= r) {
		mid = (l + r) / 2;
		bool is = check(mid, c, v);
		if (is) {
			if (check(mid + 1, c, v) == 0) break;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << mid;
	return 0;
}
