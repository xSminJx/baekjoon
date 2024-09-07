#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0), cout.tie(0)

class node {
public:
	int cnt = 0;
	int t = 0; // 작업에 걸리는 시간
	int start = 0; // 작업을 시작한 시간
	vector<int> next;
};

int main() {
	fastio;
	int n;
	cin >> n;
	vector<node> v(n + 1);
	queue<int> qu;

	int a, m;
	for (int i = 1; i <= n; i++) {
		cin >> v[i].t;
		cin >> m;
		while (m--) {
			cin >> a;
			v[a].next.push_back(i);
			v[i].cnt++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (v[i].cnt == 0) qu.push(i);
	}

	int mxt = 0; // 모든 작업을 했을 때 걸리는 시간
	while (!qu.empty()) {
		int cur = qu.front();
		qu.pop();
		mxt = max(mxt, v[cur].start + v[cur].t);

		for (auto i : v[cur].next) {
			v[i].cnt--;
			v[i].start = max(v[i].start, v[cur].start + v[cur].t); // 선행 작업들 중 가장 큰 시간을 작업의 시작 시간으로 잡아야 함.

			if (v[i].cnt == 0) {
				qu.push(i);
			}
		}
	}

	cout << mxt;
	return 0;
}
