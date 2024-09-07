#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0), cout.tie(0)

class node {
public:
	int cnt = 0;
	vector<int> next;
};

int main() {
	fastio;
	int n, m;
	cin >> n >> m;
	vector<node> v(n + 1);
	priority_queue<int, vector<int>, greater<int>> pqu;

	int a, b;
	while (m--) {
		cin >> a >> b;
		v[a].next.push_back(b);
		v[b].cnt++;
	}
	for (int i = 1; i <= n; i++) {
		if (v[i].cnt == 0) pqu.push(i);
	}

	while (!pqu.empty()) {
		int cur = pqu.top();
		pqu.pop();
		cout << cur << " ";

		for (auto i : v[cur].next) {
			v[i].cnt--;
			if (v[i].cnt == 0) pqu.push(i);
		}
	}

	return 0;
}
