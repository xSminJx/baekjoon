#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int n, m;
queue<pair<int, int>> qu; // 얼음 담는곳(얼음큐)
queue<pair<int, int>> bfsqu; // 탐색을 시작할 지점을 담아둔 큐

bool inrange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

// 모든 얼음 중, 다음에 사라질 얼음들만 얼음큐에 담는다
void firstice(vector<vector<int>>& v) {
	int qusize = qu.size();

	while (qusize--) {
		int x = qu.front().first, y = qu.front().second;
		qu.pop();
		int stc = 0; // 주변에 맞닿은 물의 개수

		for (int i = 0; i < 4; i++) {
			int dxx = x + dx[i], dyy = y + dy[i];
			if (inrange(dxx, dyy) && (v[dxx][dyy] >= 0 || v[dxx][dyy] == -2)) stc++; // 백조가 있는 곳도 물로 취급한다.
			if (stc >= 1) {
				qu.push({ x,y });
				break;
			}
		}
		stc = 0;
	}
}

// 얼음을 물로 바꾼다. 그리고 인접한 얼음을 -4(다음에 녹을 얼음)으로 마킹하고 얼음큐에 집어넣음
void ice(vector<vector<int>>& v) {
	int qusize = qu.size();

	while (qusize--) {
		int x = qu.front().first, y = qu.front().second;
		qu.pop();
		v[x][y] = 0;

		for (int i = 0; i < 4; i++) {
			int dxx = x + dx[i], dyy = y + dy[i];

			if (inrange(dxx, dyy) && v[dxx][dyy] == -1) {
				qu.push({ dxx,dyy });
				v[dxx][dyy] = -4;
			}
		}
	}
}

// 백조끼리 연결되었는지 확인하는 함수. 0(미연결 물)을 1(연결된 물)로 바꾼다.
int findl(int bfsqs, vector<vector<int>>& v) {
	queue<pair<int, int>> temp; // bfs를 위한 임시 큐

	while (bfsqs--) {
		int a = bfsqu.front().first, b = bfsqu.front().second;
		bfsqu.pop();
		temp.push({ a,b });

		while (!temp.empty()) {
			int x = temp.front().first, y = temp.front().second;
			temp.pop();
			v[x][y] = 1;

			for (int i = 0; i < 4; i++) {
				int dxx = x + dx[i], dyy = y + dy[i];

				if (inrange(dxx, dyy)) {
					if (v[dxx][dyy] == -4) bfsqu.push({ dxx,dyy }), v[dxx][dyy] = -3; // 다음에 녹을 얼음을 다음에 탐색할 지점으로 삼는다. 그리고 -3으로 바꿔서 중복을 막음
					else if (v[dxx][dyy] == -2) return 1; // 백조를 찾았으면 1반환.
					else if (v[dxx][dyy] == 0) temp.push({ dxx,dyy }), v[dxx][dyy] = 1; // 미연결 물을 찾으면 계속 탐색
				}
			}
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	int day = 1;
	char c;
	vector<vector<int>> v(n, vector<int>(m)); // -4: 다음에 녹을 얼음, -3: 큐에 집어넣은 얼음, -2: 백조, -1: 얼음, 0: 미연결된 물, 1: 연결된 물

	int lx = -1, ly = -1; // 백조의 위치
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			if (c == '.') v[i][j] = 0;
			else if (c == 'X') v[i][j] = -1;
			else if (c == 'L') v[i][j] = -2, lx = i, ly = j;
			if (v[i][j] == -1) qu.push({ i,j });
		}
	}
	bfsqu.push({ lx,ly });

	firstice(v);

	while (1) {
		ice(v);
		if (findl(bfsqu.size(), v) == 1) break;
		day++;
	}

	cout << day;
	return 0;
}
