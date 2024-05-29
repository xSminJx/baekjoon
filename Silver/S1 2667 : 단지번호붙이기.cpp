#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<int>> v;
vector<int> nums;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

void dfs(int i, int j, int n, int num) {
	if (0 <= i && i < n && 0 <= j && j < n && v[i][j] == 1) {
		v[i][j] = num;
		nums[num - 2]++;
		for (int k = 0; k < 4; k++) dfs(i + dx[k], j + dy[k], n, num);
	}
}

void dfsmanage(int n) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j] == 1) {
				nums.push_back(0);
				dfs(i, j, n, cnt + 2);
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	sort(nums.begin(), nums.end());
	for (auto i : nums) cout << i << endl;
}

int main() {
	int n;
	char c;
	cin >> n;
	v = vector<vector<int>>(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c;
			v[i][j] = c - 48;
		}
	}
	dfsmanage(n);
	return 0;
}
