#include <bits/stdc++.h>
using namespace std;

int n, m, t, ax, ay;
int dx[4] = { 0,-1,0,1 }, dy[4] = { 1,0,-1,0 };

class node {
public:
	int n, next; // 현재 값, 바뀔 값
};

bool inrange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

// 바뀔 값을 현재값에 적용
void wjdtkdghk(vector<vector<node>>& v) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			v[i][j].n = v[i][j].next;
			v[i][j].next = 0;
		}
	}
}

//미세먼지가 퍼지는 것을 구현
void spread(vector<vector<node>>& v) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			v[i][j].next += v[i][j].n;

			if (v[i][j].n > 0) {
				for (int k = 0; k < 4; k++) {
					int dxx = i + dx[k], dyy = j + dy[k];

					if (inrange(dxx, dyy)) {
						if (v[dxx][dyy].n == -1) continue;
						v[dxx][dyy].next += v[i][j].n / 5;
						v[i][j].next -= v[i][j].n / 5;
					}
				}
			}
		}
	}
	wjdtkdghk(v);
	v[ax][ay].n = v[ax - 1][ay].n = -1;
}

// 공기청정기가 돌아간다
void air(vector<vector<node>>& v) {
	int upax = ax - 1, upay = ay;
	vector<pair<int, int>> stack; // 바람에 영향을 받는 위치들만 기록

	int i = 0, nx = upax, ny = upay;
	// 위쪽방향
	while (4) {
		int nxx = nx + dx[i], nyy = ny + dy[i];
		stack.push_back({ nx,ny });

		if (inrange(nxx, nyy)) {
			if (v[nx][ny].n == -1) v[nxx][nyy].next = 0;
			else if (v[nxx][nyy].n == -1) break;
			else v[nxx][nyy].next = v[nx][ny].n;
		}
		else {
			i++;
			nxx = nx + dx[i], nyy = ny + dy[i];
			v[nxx][nyy].next = v[nx][ny].n;
		}

		nx += dx[i], ny += dy[i];
	}

	i = 0, nx = ax, ny = ay;
	// 아랫방향
	while (1) {
		int nxx = nx + dx[i], nyy = ny + dy[i];
		stack.push_back({ nx,ny });

		if (inrange(nxx, nyy)) {
			if (v[nx][ny].n == -1) v[nxx][nyy].next = 0;
			else if (v[nxx][nyy].n == -1) break;
			else v[nxx][nyy].next = v[nx][ny].n;
		}
		else {
			i--;
			if (i < 0)i += 4;
			nxx = nx + dx[i], nyy = ny + dy[i];
			v[nxx][nyy].next = v[nx][ny].n;
		}
		nx += dx[i], ny += dy[i];
	}

	// 바람에 영향을 받은 위치들만 값을 변경
	for (auto k : stack) {
		v[k.first][k.second].n = v[k.first][k.second].next;
		v[k.first][k.second].next = 0;
	}
	v[ax][ay].n = v[upax][upay].n = -1;
}

int sum(vector<vector<node>>& v) {
	int a = 0;
	for (auto i : v) {
		for (auto j : i) a += j.n;
	}
	return a + 2;
}

int main() {
	cin >> n >> m >> t;
	vector<vector<node>> v(n, vector<node>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j].n;
			if (v[i][j].n == -1) ax = i, ay = j; // 공기청정기 위치 기록
		}
	}

	while (t--) {
		spread(v);
		air(v);
	}
	cout << sum(v);
	return 0;
}
