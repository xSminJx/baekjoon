#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class node {
public:
	int x, y, dist, masic;
};

queue<node> qu;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;

bool inzone(int x, int y) {
	if (0 < x && x <= n && 0 < y && y <= m) return 1;
	return 0;
}

void bfs(int x, int y, int k, int masic, vector<vector<vector<int>>>& v) {
	for (int i = 0; i < 4; i++) {
		int dxx = x + dx[i], dyy = y + dy[i];
		if (inzone(dxx, dyy)) {
			if (v[dxx][dyy][masic] == 0) {
				v[dxx][dyy][masic] = k + 1;
				qu.push({ dxx,dyy,k + 1,masic });
			}
			else if (masic == 1 && v[dxx][dyy][0] == -1) {
				v[dxx][dyy][0] = k + 1;
				qu.push({ dxx,dyy,k + 1,0 });
			}
		}
	}
}

int main() {
	int hx, hy, ex, ey;
	cin >> n >> m >> hx >> hy >> ex >> ey;
	vector <vector<vector<int>>> v(n + 1, vector<vector<int>>(m + 1, vector<int>(2)));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int t;
			cin >> t;
			if (t == 1) v[i][j][0] = v[i][j][1] = -1;
		}
	}
	v[hx][hy][0] = v[hx][hy][1] = 1;

	qu.push({ hx,hy,0,1 });
	while (!qu.empty()) {
		node cur = qu.front();
		bfs(cur.x, cur.y, cur.dist, cur.masic, v);
		qu.pop();
	}

	int result = -1;
	if (v[ex][ey][1] != 0 && v[ex][ey][0] != 0) result = min(v[ex][ey][1], v[ex][ey][0]);
	else if (v[ex][ey][1] != 0 || v[ex][ey][0] != 0) result = max(v[ex][ey][1], v[ex][ey][0]);
	cout << result;
	return 0;
}
