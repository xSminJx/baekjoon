#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int cnt, visit[101], point[101];
queue<int> que;
vector<vector<int>> edge(101);

void bfs(int a) {
	visit[a] = 1;
	cnt += point[a];
	for (int i = 0; i < edge[a].size(); i++) {
		int x = edge[a][i];
		if (visit[x] == 0) {
			que.push(x);
			point[x] = point[a] + 1;
			visit[x] = 1;
		}
	}
}

void act() {
	while (que.size() != 0) {
		bfs(que.front());
		que.pop();
	}
}

int main() {
	int n, m, mncnt = 10000, mnn = 0;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		for (int o = 1; o <= n; o++) visit[o] = point[o] = 0;
		cnt = 0;
		bfs(i);
		act();
		if (mncnt > cnt) mncnt = cnt, mnn = i;
	}

	cout << mnn;
	return 0;
}
