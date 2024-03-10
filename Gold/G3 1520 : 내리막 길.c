#include <iostream>
using namespace std;

typedef struct {
	int data, visit, edge[5][2], dp;
}mount;
mount s[500][500];

void put_edge(int a, int b, int n, int m) {
	int c[4][2] = { {a,b - 1},{a,b + 1},{a + 1,b},{a - 1,b} }, eidx = 0;
	for (int i = 0; i < 4; i++) {
		int x = c[i][0], y = c[i][1];
		if ((0 <= x && x < n && 0 <= y && y < m) && s[x][y].data > s[a][b].data) {
			s[a][b].edge[eidx][0] = x, s[a][b].edge[eidx++][1] = y;
		}
	}
	s[a][b].edge[eidx][0] = -1;
	return;
}

void dfs(int a, int b) {
	s[a][b].visit = 1;
	for (int i = 0; s[a][b].edge[i][0] != -1; i++) {
		int x = s[a][b].edge[i][0], y = s[a][b].edge[i][1];
		if (s[x][y].visit == 0) dfs(x, y);
		s[a][b].dp += s[x][y].dp;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int o = 0; o < m; o++) cin >> s[i][o].data;
	}
	s[0][0].dp = 1, s[0][0].visit = 1;

	for (int i = 0; i < n; i++) {
		for (int o = 0; o < m; o++) put_edge(i, o, n, m);
	}

	dfs(n - 1, m - 1);
	cout << s[n - 1][m - 1].dp;

	return 0;
}
