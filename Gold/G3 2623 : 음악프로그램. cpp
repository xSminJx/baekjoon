#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)

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
	vector<int> ans;
	queue<int> qu;

	int k, a, b;
	while (m--) {
		cin >> k >> a;
		k--;
		while (k--) {
			cin >> b;
			v[a].next.push_back(b);
			v[b].cnt++;
			a = b;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (v[i].cnt == 0) qu.push(i);
	}

	while (!qu.empty()) {
		int cur = qu.front();
		qu.pop();
		ans.push_back(cur);

		for (auto i : v[cur].next) {
			v[i].cnt--;
			if (v[i].cnt == 0) qu.push(i);
		}
	}

	if (ans.size() == n) {
		for (auto i : ans) cout << i << '\n';
	}
	else cout << 0;

	return 0;
}
