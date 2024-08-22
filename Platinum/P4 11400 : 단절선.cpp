#include <bits/stdc++.h>
using namespace std;

int n, m, num;
vector<pair<int, int>> stc;

class node {
public:
	int visit = 0;
	vector<int> edge;
};

// 노드 a와 b가 같은 사이클에 존재하지 않으면 stc에 넣는다.
int dfs(int cur, int b, vector<node>& v) {
	v[cur].visit = ++num;
	int k = v[cur].visit; // 현재 방문값을 함부로 건드리면 큰일나서 따로 변수를 만든다
	for (auto i : v[cur].edge) {
		if (i == b) continue;
		if (v[i].visit == 0) {
			int ther = dfs(i, cur, v);
			if (ther > v[cur].visit) stc.push_back({min(i,cur),max(i,cur)}); // 만약 현재 방문값보다 다음 방문값이 더 작다면(다음 노드가 현재 노드나 그 뒤의 노드와 연관되었다면)
			k = min(k, ther);
		}
		else k = min(k, v[i].visit);
	}
	return k;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	vector<node> v(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].edge.push_back(b);
		v[b].edge.push_back(a);
	}

	dfs(1, 0, v);
	sort(stc.begin(), stc.end());
	cout << stc.size() << '\n';
	for (auto [x, y] : stc) cout << x << " " << y << '\n';
	return 0;
}
