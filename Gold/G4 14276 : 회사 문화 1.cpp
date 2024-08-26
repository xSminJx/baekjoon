#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int up = 0;
	int happy = 0;
	vector<int> down;
};

void dfs(int cur, vector<node>& v, vector<int>& cldcks) {
	v[cur].happy += cldcks[cur];
	for (auto i : v[cur].down) {
		cldcks[i] += v[cur].happy;
		dfs(i, v, cldcks);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<node> v(n + 1);

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		v[i].up = a;
		if (a > 0) v[a].down.push_back(i);
	}

	vector<int> cldcks(n + 1);
	while (m--) {
		int i, w;
		cin >> i >> w;
		cldcks[i] += w;
	}
	dfs(1, v, cldcks);
	for (int i = 1; i <= n; i++) cout << v[i].happy << " ";
	return 0;
}
