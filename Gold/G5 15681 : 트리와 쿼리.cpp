#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int lv = 0;
	int dp = 0;
	vector<int> edge;
};

int dfs(int cur, int level, vector<node>& v) {
	v[cur].lv = level;
	int stc = 0;
	for (auto i : v[cur].edge) {
		if (v[i].lv == 0) stc += dfs(i, level + 1, v);
	}
	v[cur].dp = stc + 1;
	return v[cur].dp;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, r, q, num = 1;
	cin >> n >> r >> q;
	vector<node> v(n + 1);

	for (int i = 0; i < n - 1; i++) {
		int c, d;
		cin >> c >> d;
		v[c].edge.push_back(d);
		v[d].edge.push_back(c);
	}

	dfs(r, 1, v);

	int k;
	while (cin >> k) {
		cout << v[k].dp << '\n';
	}
	return 0;
}
