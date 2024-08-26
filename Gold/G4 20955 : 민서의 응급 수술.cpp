#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int visit = 0;
	vector<int> edge;
};

int cnt = 0, k = 1;
void findcycle(int cur, int k, int prev, vector<node>& v) {
	v[cur].visit = k;
	for (auto i : v[cur].edge) {
		if (v[i].visit == 0) findcycle(i, ++k, cur, v);
		else if (i != prev && v[i].visit < v[cur].visit) cnt++;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<node> v(n + 1);

	while (m--) {
		int a, b;
		cin >> a >> b;
		v[a].edge.push_back(b);
		v[b].edge.push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (v[i].visit == 0) findcycle(i, k, 0, v), cnt++;
	}
	cout << cnt - 1;
	return 0;
}
