#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> v;
vector<vector<int>> visit;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

void dfs(int i, int j, char c, int n) {
	if (0 <= i && i < n && 0 <= j && j < n && visit[i][j] == 0 && v[i][j] == c) {
		visit[i][j] = 1;
		for (int k = 0; k < 4; k++) dfs(i + dx[k], j + dy[k], c, n);
	}
}

int dfsmanage(int n) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == 0) {
				dfs(i, j, v[i][j], n);
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	int n;
	string str;
	cin >> n;
	visit = vector<vector<int>>(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		cin >> str;
		v.push_back(str);
	}
	cout << dfsmanage(n) << " ";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visit[i][j] = 0;
			if (v[i][j] == 'G') v[i][j] = 'R';
		}
	}
	cout << dfsmanage(n);

	return 0;
}
