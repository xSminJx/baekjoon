#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int n, m, k, cnt = 0;
string str;

class node {
public:
	char c;
	vector<int> dp;
	node() :c(0), dp(81, -1) {}
};

bool inrange(int a, int b) {
	return 0 <= a && a < n && 0 <= b && b < m;
}

int dfs(int a, int b, int o, vector<vector<node>>& v) {
	if (o == str.size() - 1) return 1;
	else if (v[a][b].dp[o] != -1) return v[a][b].dp[o];
	v[a][b].dp[o] = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= k; j++) {
			int x = a + j * dx[i], y = b + j * dy[i];
			if (inrange(x, y) && v[x][y].c == str[o + 1]) {
				v[a][b].dp[o] += dfs(x, y, o + 1, v);
			}
		}
	}
	return v[a][b].dp[o];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	vector<vector<node>> v(n, vector<node>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j].c;
		}
	}
	cin >> str;

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j].c == str[0]) {			
				cnt += dfs(i, j, 0, v);
			}
		}
	}

	cout << cnt;
	return 0;
}
