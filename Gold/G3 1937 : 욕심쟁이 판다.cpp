#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int n, cnt = 0;

class node {
public:
	int h = 0;
	int cnt = 0;
};

bool inrange(int a, int b) {
	return 0 <= a && a < n && 0 <= b && b < n;
}

void dfs(int a, int b, vector<vector<node>>& v) {
	for (int i = 0; i < 4; i++) {
		int x = a + dx[i], y = b + dy[i];

		if (inrange(x, y) && v[x][y].h > v[a][b].h) {
			if (v[x][y].cnt == 0) dfs(x, y, v);
			v[a][b].cnt = max(v[a][b].cnt, v[x][y].cnt + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	vector<vector<node>> v(n, vector<node>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j].h;
		}
	}

	int mx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j].cnt == 0) dfs(i, j, v);
			mx = max(mx, v[i][j].cnt);
		}
	}

	cout << mx + 1;
	return 0;
}
