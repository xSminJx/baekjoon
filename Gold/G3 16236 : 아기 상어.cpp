#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int cnt, ssize = 2, stc = 0; // 시간, 상어크기
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };

void ssize_plus() {
	if (ssize == ++stc) ssize++, stc = 0; // 상어의 크기를 증가시키는 함수
}

bool inar(int x, int y, int n) {
	return 0 <= x && x < n && 0 <= y && y < n; //배열 경계 체크
}

bool compare(vector<int>& a, vector<int>& b) {
	if (a[2] != b[2]) return a[2] < b[2];
	else if (a[0] != b[0]) return a[0] < b[0];
	return a[1] < b[1];
}

pair<int, int> find_food(int a, int b, vector<vector<int>>& v) {
	vector<vector<int>> visit(v.size(), vector<int>(v.size()));
	queue<pair<int, int>> qu;
	vector<vector<int>> food_list; // 찾은 먹이들이 여기로 들어감
	int isfound = 0; // 먹이를 찾으면 1이 되어서 큐에 삽입을 중단시키는 변수

	visit[a][b] = 1;
	qu.push({ a,b });

	// bfs로 탐색 후 먹이를 찾으면 food_list에 삽입. 그리고 isfound를 1로 바꿔줘서 큐에 불필요한 삽입을 막는다.
	while (!qu.empty()) {
		int x = qu.front().first, y = qu.front().second;
		qu.pop();

		for (int i = 0; i < 4; i++) {
			int dxx = x + dx[i], dyy = y + dy[i];
			if (inar(dxx, dyy, v.size()) && visit[dxx][dyy] == 0 && v[dxx][dyy] <= ssize) {
				if (v[dxx][dyy] < ssize && v[dxx][dyy] > 0) {
					isfound = 1;
					visit[dxx][dyy] = visit[x][y] + 1;
					food_list.push_back({ dxx,dyy,visit[dxx][dyy] });
				}
				else {
					visit[dxx][dyy] = visit[x][y] + 1;
					if (isfound == 0) qu.push({ dxx,dyy });
				}
			}
		}
	}

	if (food_list.size() == 0) return { -1,-1 }; // 먹이를 못찼았으면 -1,-1리턴

	sort(food_list.begin(), food_list.end(), compare);
	pair<int, int> ans = { food_list[0][0],food_list[0][1] };
	cnt += visit[ans.first][ans.second] - 1;
	return ans;
}

int main() {
	int n, a, b;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
			if (v[i][j] == 9) a = i, b = j;
		}
	}

	while (1) {
		pair<int, int> p = find_food(a, b, v);
		if (p.first == -1) break;
		v[a][b] = 0, v[p.first][p.second] = 9; // 상어 이동
		a = p.first, b = p.second;
		ssize_plus();
	}

	cout << cnt;
	return 0;
}
