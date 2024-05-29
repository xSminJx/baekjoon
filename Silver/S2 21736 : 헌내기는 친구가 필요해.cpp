#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> v;
vector<vector<int>> visit;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
int cnt = 0;

void dfs(int i, int j, int n, int m) {
	if (0 <= i && i < n && 0 <= j && j < m && visit[i][j] == 0 && v[i][j] != 'X') {
		visit[i][j] = 1;
		if (v[i][j] == 'P') cnt++;
		for (int k = 0; k < 4; k++) dfs(i + dx[k], j + dy[k], n, m);
	}
}

void dfsmanage(int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == 'I') {
				dfs(i, j, n, m);
			}
		}
	}
	if (cnt) cout << cnt;
	else cout << "TT";
}

int main() {
	int n, m;
	string str;
	cin >> n >> m;
	visit = vector<vector<int>>(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		cin >> str;
		v.push_back(str);
	}
	dfsmanage(n, m);

	return 0;
}
