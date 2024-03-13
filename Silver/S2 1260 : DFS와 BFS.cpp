#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct {
	int visit;
	vector<int> v;
}graph;
graph s[1001];
queue<int> que;

void dfs(int a) {
	s[a].visit = 1;
	cout << a << " ";
	for (int i = 0; i < s[a].v.size(); i++) {
		if (s[s[a].v[i]].visit != 1) dfs(s[a].v[i]);
	}
}

void bfs(int a) {
	s[a].visit = 1;
	cout << a << " ";
	for (int i = 0; i < s[a].v.size(); i++) {
		if (s[s[a].v[i]].visit != 1) {
			s[s[a].v[i]].visit = 1;
			que.push(s[a].v[i]);
		}
	}
}

void act() {
	int len;

	len = que.size();
	for (int i = 0; i < len; i++) {
		bfs(que.front());
		que.pop();
	}
	if (que.size() == 0) return;
	else act();
}

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		s[a].v.push_back(b);
		s[b].v.push_back(a);
	}
	for (int i = 1; i <= n; i++) sort(s[i].v.begin(), s[i].v.end());
	dfs(k);
	cout << endl;

	for (int i = 0; i < 1001; i++) s[i].visit = 0;
	bfs(k);
	act();

	return 0;
}
