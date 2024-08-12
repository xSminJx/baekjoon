#include <bits/stdc++.h>
using namespace std;

int n, dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0,0,1,-1 };

class node {
public:
	int c = 0, br = 100000; // 섬 구별 번호, 다리 길이
};

bool inrange(int x, int y) { return 0 <= x && x < n && 0 <= y && y < n; }

// 섬을 구별하기 위해 섬마다 색칠
void coloring(int a, int b, int k, vector<vector<node>>& v) {
	queue<pair<int, int>> qu;
	qu.push({ a,b });
	v[a][b].c = k;

	while (!qu.empty()) {
		int x = qu.front().first, y = qu.front().second;
		qu.pop();

		for (int i = 0; i < 4; i++) {
			int dxx = x + dx[i], dyy = y + dy[i];

			if (inrange(dxx, dyy) && v[dxx][dyy].c == 1) {
				v[dxx][dyy].c = k;
				qu.push({ dxx,dyy });
			}
		}
	}
}

int bridge(int a, int b, int k, vector<vector<node>>& v) {
	queue<pair<int, int>> qu;
	qu.push({ a,b });
	v[a][b].br = 0;

	while (!qu.empty()) {
		int x = qu.front().first, y = qu.front().second;
		qu.pop();

		for (int i = 0; i < 4; i++) {
			int dxx = x + dx[i], dyy = y + dy[i];

			// 다음 지점이 바다고, 더 짧게 다리를 건설할 수 있으면 다리 길이를 갱신
			if (inrange(dxx, dyy) && v[dxx][dyy].c == 0 && v[dxx][dyy].br > v[x][y].br + 1) {
				v[dxx][dyy].br = v[x][y].br + 1;
				qu.push({ dxx,dyy });
			}

			// 다른 섬과 연결되었으면 다리 길이 반환
			else if (inrange(dxx, dyy) && v[dxx][dyy].c != 0 && v[dxx][dyy].c != k) {
				return v[x][y].br;
			}
		}
	}
	return 100000; // 다른 섬을 못찾았을 때(다리 길이가 길어져서 갱신이 안됐을 때) 이거 안하면 런타임 에러가 발생함
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	vector<vector<node>> v(n, vector<node>(n));


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> v[i][j].c;
	}

	//색칠
	int k = 2; // 색깔
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j].c == 1) coloring(i, j, k++, v);
		}
	}
	
	//다리 짓기
	int minrange = 100000;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j].c != 0) minrange = min(minrange, bridge(i, j, v[i][j].c, v));
		}
	}

	cout << minrange;
	return 0;
}
