#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

class node {
public:
	int visit = 0;
	vector<int> edge;
	vector<int> w;
};

void clean(vector<node>& v) {
	for (auto& i : v) i.visit = 0;
}

bool bfs(vector<node>& v, int s, int e, int val) {
	queue<int> qu;
	qu.push(s);
	v[s].visit = 1;

	int cur;
	while (!qu.empty()) {
		cur = qu.front();
		qu.pop();
		if (cur == e) {
			clean(v);
			return 1;
		}

		int size = v[cur].edge.size();
		for (int i = 0; i < size; i++) {
			int t = v[cur].edge[i];
			if (v[cur].w[i] >= val && v[t].visit == 0) {
				qu.push(t);
				v[t].visit = 1;
			}
		}
	}
	clean(v);
	return 0;
}

int main() {
	fastio;
	int n, m, s, e;
	cin >> n >> m >> s >> e;
	vector<node> v(n + 1);

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v[a].edge.push_back(b);
		v[a].w.push_back(c);
		v[b].edge.push_back(a);
		v[b].w.push_back(c);
	}

	int l = 0, r = 1000000, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (!bfs(v, s, e, mid)) r = mid - 1;
		else {
			if (!bfs(v, s, e, mid + 1)) {
				cout << mid;
				return 0;
			}
			l = mid + 1;
		}
	}
	cout << 0;
	return 0;
}
