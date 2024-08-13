#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int r, c;

bool inrange(int x, int y) {
	return 0 <= x && x < r && 0 <= y && y < c;
}

int dfs(int a, int b, int k, vector<vector<char>>& v, vector<bool>& alist) {
	int mx = k;
	for (int i = 0; i < 4; i++) {
		int x = a + dx[i], y = b + dy[i];

		if (inrange(x, y) && alist[v[x][y] - 65] == 0) {
			alist[v[x][y] - 65] = 1;
			mx = max(mx, dfs(x, y, k + 1, v, alist));
			alist[v[x][y] - 65] = 0;
		}
	}
	return mx;
}

int main() {
	cin >> r >> c;
	vector<vector<char>> v(r, vector<char>(c));
	vector<bool> alist(26);

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) cin >> v[i][j];
	}

	alist[v[0][0] - 65] = 1;
	cout << dfs(0, 0, 1, v, alist);
	return 0;
}
