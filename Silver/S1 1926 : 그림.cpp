#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };

int bfs(int x, int y, vector<vector<int>>& v, int n, int m) {
	queue<pair<int, int>> qu;
	int stc = 1;
	qu.push({ x,y });
	v[x][y] = 2;
	
	while (!qu.empty()) {
		pair<int, int> cur = qu.front();
		qu.pop();

		for (int i = 0; i < 4; i++) {
			int dxx = cur.first + dx[i], dyy = cur.second + dy[i];

			if ((0 <= dxx && dxx < n && 0 <= dyy && dyy < m) && v[dxx][dyy] == 1) {
				v[dxx][dyy] = 2;
				qu.push({ dxx,dyy });
				stc++;
			}
		}
	}
	return stc;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m)); // 0: 빈공간, 1: 그림, 2: 방문한 곳

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> v[i][j];
	}

	int cnt = 0, maxsize = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == 1) {
				cnt++;
				maxsize = max(maxsize, bfs(i, j, v, n, m));
			}

		}
	}

	cout << cnt << '\n' << maxsize;
	return 0;
}
