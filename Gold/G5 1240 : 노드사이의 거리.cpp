#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int visit = 0;
	vector<pair<int, int>> edge;
};

int dfs(int cur, int en, vector<node>& v) {
	v[cur].visit = 1;

	for (auto [a, b] : v[cur].edge) {
		if (v[a].visit == 0) {
			if (a == en) return b;
			int res = dfs(a, en, v);
			if (res != 0) return res += b;
		}
	}
	return 0;
}

void tclear(vector<node>& v) {
	for (int i = 1; i < v.size(); i++) v[i].visit = 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, num = 1;
	cin >> n >> m;
	vector<node> v(n + 1);

	for (int i = 0; i < n - 1; i++) {
		int c, d, e;
		cin >> c >> d >> e;
		v[c].edge.push_back({ d,e });
		v[d].edge.push_back({ c,e });
	}

	while (m--) {
		int st, en;
		cin >> st >> en;
		tclear(v);
		cout << dfs(st, en, v) << '\n';
	}
	return 0;
}
