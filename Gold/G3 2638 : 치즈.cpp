#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int n, m;
queue<pair<int, int>> qu;

bool inrange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

// 0인 공기가 외부와 연결되었다면 2로 바꿈
void airing(int a, int b, vector<vector<int>>& v) {
	v[a][b] = 2;

	for (int i = 0; i < 4; i++) {
		int x = a + dx[i], y = b + dy[i];
		if (inrange(x, y) && v[x][y] == 0) airing(x, y, v);
	}
}

// 치즈를 공기로 바꿔버리는 함수
void cheese(int& cnt, vector<vector<int>>& v) {
	int qusize = qu.size(); // 이거해야 일수를 측정가능
	vector<pair<int, int>> stack; // 공기로 바꿔버릴 치즈의 위치를 저장

	while (qusize--) {
		int x = qu.front().first, y = qu.front().second;
		qu.pop();
		int stc = 0; // 맞닿은 외부 공기의 수

		for (int i = 0; i < 4; i++) {
			int dxx = x + dx[i], dyy = y + dy[i];
			if (inrange(dxx, dyy) && v[dxx][dyy] == 2) stc++;
			if (stc >= 2) {
				cnt--;
				stack.push_back({ x,y });
				break;
			}
		}
		if (stc < 2) qu.push({ x,y }); // 치즈가 멀쩡하다면 다시 큐에 집어넣음
		stc = 0;
	}

	for (auto i : stack) {
		v[i.first][i.second] = 2;
		airing(i.first, i.second, v);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	int cnt = 0, day = 0;
	vector<vector<int>> v(n, vector<int>(m)); // 0: 내부 공기, 1: 치즈, 2: 외부 공기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
			if (v[i][j] == 1) cnt++, qu.push({ i,j });
		}
	}
	airing(0, 0, v);
	while (cnt) {
		cheese(cnt, v);
		day++;
	}

	cout << day;
	return 0;
}
