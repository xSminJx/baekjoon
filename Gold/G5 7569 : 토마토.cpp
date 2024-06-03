#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int m, n, h;
int dx[6] = { 1,0,-1,0,0,0 };
int dy[6] = { 0,-1,0,1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
queue <vector<int>> q;

bool in_box(int i, int j, int k) {
	if (0 <= i && i < h && 0 <= j && j < n && 0 <= k && k < m)  return 1;
	return 0;
}

int bfs(vector<vector<vector<int>>>& v, int i, int j, int k) {
	int cnt = 0;
	for (int a = 0; a < 6; a++) {
		int i1 = i + dz[a], j1 = j + dy[a], k1 = k + dx[a];
		if (in_box(i1, j1, k1) && v[i1][j1][k1] == 0) {
			v[i1][j1][k1] = 1;
			q.push({ i1,j1,k1 });
			cnt++;
		}
	}
	return cnt;
}

int bfs_manage(vector<vector<vector<int>>>& v, int vsum) {
	int day = 0, cnt = 0, sum = 0;
	while (1) {
		int day_size = q.size();
		for (int i = 0; i < day_size; i++) {
			vector<int> qq = q.front();
			q.pop();
			cnt += bfs(v, qq[0], qq[1], qq[2]);
		}
		sum += cnt;
		if (cnt == 0 && vsum == sum) return day;
		else if (cnt == 0) return -1;
		cnt = 0;
		day++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int sum;
	cin >> m >> n >> h;
	sum = m * n * h;
	vector<vector<vector<int>>> v(h, vector<vector<int>>(n, vector<int>(m)));

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> v[i][j][k];
				if (v[i][j][k]) {
					sum--;
					if (v[i][j][k] == 1) q.push({ i, j, k });
				}
			}
		}
	}
	cout << bfs_manage(v, sum);

	return 0;
}
