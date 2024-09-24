#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define MOD 1234567891

// 행성들을 크기 순으로 정렬 한 다음 인덱스 값의 순서가 같으면 같은 우주이다.
// 근데 인덱스 값 들을 하나하나 다 비교할 수는 없으니 해시값을 따서 비교했다.

class uni {
public:
	vector<pair<int, int>> p; // 행성 크기, 인덱스
	long long hash = 0; // 인덱스 값 들의 해시 값
	uni(int n) :p(n) {}
};

bool compare(pair<int, int>& a, pair<int, int>& b) {
	if (a.first != b.first) return a.first < b.first;
	return a.second < b.second;
}

long long hashing(vector<pair<int, int>>& p) {
	long long hv = 10007, a = 1, res = 0;
	for (auto i : p) {
		res += (i.second * a) % MOD;
		a = (a * hv) % MOD;
	}
	return res;
}

int main() {
	fastio;
	int n, m, ans = 0;
	cin >> m >> n;
	vector<uni> v(m, uni(n));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i].p[j].first;
			v[i].p[j].second = j;
		}
		sort(v[i].p.begin(), v[i].p.end(), compare);
		for (int k = 0; k < n - 1; k++) {
			if (v[i].p[k].first == v[i].p[k + 1].first) v[i].p[k + 1].second = v[i].p[k].second; // 입력이 정렬된 상태일 때 대응
		}

		v[i].hash = hashing(v[i].p);
	}

	for (int i = 0; i < m; i++) {
		for (int j = i; j < m; j++) {
			if (i == j) continue;
			else if (v[i].hash == v[j].hash) ans++;
		}
	}

	cout << ans;
	return 0;
}
