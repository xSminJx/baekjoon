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
		len[i] = v[i + 1] - v[i]; // 센서 간 거리
	}
	sort(len.begin(), len.end(), greater<int>());
	// 기지국을 k개 건설 가능 = 가장 긴 센서 간 거리 k-1개를 무시 가능(막대기에 칼질 4번하면 5등분 나는 원리)
	for (int i = k - 1; i < n - 1; i++) res += len[i]; // 가장 긴 거리 k-1개 제끼고 그 뒤의 값만 더하면 최소값

	cout << res;
	return 0;
}
