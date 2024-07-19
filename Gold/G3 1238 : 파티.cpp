#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
using namespace std;

class node {
public:
	vector<int> s;
	vector<int> e;
	int range = INT_MAX;
	int visit = 0;
};

void Dijkstra(int a, vector<node>& v) {
	for (int i = 1; i < v.size(); i++) {
		v[i].range = INT_MAX;
		v[i].visit = 0;
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,a });
	v[a].range = 0;

	while (!pq.empty()) {
		int idx = pq.top().second;
		pq.pop();

		if (v[idx].visit == 1) continue;
		v[idx].visit = 1;

		for (int i = 0; i < v[idx].s.size(); i++) {
			if (v[v[idx].s[i]].range > v[idx].range + v[idx].e[i]) {
				v[v[idx].s[i]].range = v[idx].range + v[idx].e[i];
				pq.push({ v[v[idx].s[i]].range ,v[idx].s[i] });
			}			
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m, x;
	cin >> n >> m >> x;
	vector<node> v(n + 1);
	vector<int> r(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].s.push_back(b);
		v[a].e.push_back(c);
	}

	for (int i = 1; i <= n; i++) {
		Dijkstra(i, v);
		r[i] = v[x].range;
	}

	Dijkstra(x, v);
	int mx = 0;
	for (int i = 1; i < n + 1; i++) {
		r[i] += v[i].range;
		mx = max(mx, r[i]);
	}
	cout << mx;
	return 0;
}
