#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0)
using matrix = vector<vector<int>>;

int k, w, h;
int dx[12] = { 1,-1,0,0,-2,-2,-1,1,2,2,1,-1 };
int dy[12] = { 0,0,1,-1,-1,1,2,2,1,-1,-2,-2 };
queue<vector<int>> qu;

bool inrange(int a, int b) {
	return 0 <= a && a < h && 0 <= b && b < w;
}

void bfs(int t, matrix& map, vector<matrix>& visit) {
	while (!qu.empty()) {
		int level = qu.front()[0], x = qu.front()[1], y = qu.front()[2];
		qu.pop();

		for (int i = 0; i < 12; i++) {
			int dxx = x + dx[i], dyy = y + dy[i];
			if (inrange(dxx, dyy) && map[dxx][dyy] == 0) {
				if (i < 4 && visit[level][dxx][dyy] == 0) {
					qu.push({ level,dxx,dyy });
					visit[level][dxx][dyy] = t + 1;
				}
				else if (i >= 4 && visit[level + 1][dxx][dyy] > t + 1) {
					qu.push({ level + 1,dxx,dyy });
					visit[level + 1][dxx][dyy] = t + 1;
				}
			}
		}
	}
}

int main() {
	fastio;
	cin >> k >> w >> h;
	matrix map(h, vector<int>(w));
	vector<matrix> visit(k + 1, matrix(h, vector<int>(w)));

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) cin >> map[i][j];
	}

	visit[0][0][0] = 1;
	qu.push({ 0,0,0 });
	bfs(1, map, visit);

	int mn = 40000;
	for (auto i : visit) {
		if (i[h - 1][w - 1] != 0) mn = min(mn, i[h - 1][w - 1]);
	}
	cout << mn;
	return 0;
}
