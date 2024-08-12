#include <bits/stdc++.h>
using namespace std;

int dx[8] = { 2,2,1,-1,-2,-2,-1,1 };
int dy[8] = { -1,1,2,2,1,-1,-2,-2 };

bool inrange(int x, int y, int n) {
	return (0 <= x && x < n && 0 <= y && y < n);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<vector<int>> v(n, vector<int>(n));
		queue<pair<int, int>> qu;
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;

		qu.push({ sx,sy });
		v[sx][sy] = 1;

		while (!qu.empty()) {
			int x = qu.front().first, y = qu.front().second;
			qu.pop();

			if (x == ex && y == ey) break;

			for (int i = 0; i < 8; i++) {
				int dxx = x + dx[i], dyy = y + dy[i];

				if (inrange(dxx, dyy, n) && v[dxx][dyy] == 0) {
					v[dxx][dyy] = v[x][y] + 1;
					qu.push({ dxx,dyy });
				}
			}
		}
		cout << v[ex][ey] - 1 << endl;
	}
	return 0;
}
