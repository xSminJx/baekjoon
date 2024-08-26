#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int visit = 0;
	vector<int> edge;
};

int cyclefind = 0;
void dfs(int cur, int prev, int k, vector<node>& v) {
	v[cur].visit = k;
	for (auto i : v[cur].edge) {
		if (i == prev) continue;
		else if (v[i].visit != 0) cyclefind = 1;
		else dfs(i, cur, k, v);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, num = 1;
	while (1) {
		int k = 1;
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		vector<node> v(n + 1);

		for (int i = 0; i < m; i++) {
			int c, d;
			cin >> c >> d;
			v[c].edge.push_back(d);
			v[d].edge.push_back(c);
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (v[i].visit == 0) {
				dfs(i, 0, k++, v);
				if (cyclefind == 0) cnt++;
				cyclefind = 0;
			}
		}

		if (cnt > 1) cout << "Case " << num++ << ": A forest of " << cnt << " trees.\n";
		else if (cnt == 1) cout << "Case " << num++ << ": There is one tree.\n";
		else cout << "Case " << num++ << ": No trees.\n";
	}
	return 0;
}
