#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int sum = 0; // 구간합
	int team = 0; // 사실상 방문 기록
	int go = 0; // 팀먹고 싶은 사람 번호
};

int bfs(int i, vector<node>& v) {  // 팀에 들어간 사람 수를 리턴
	queue<int> qu;
	qu.push(i);
	v[i].sum = 1;

	while (!qu.empty()) {
		int cur = qu.front(), next = v[cur].go;
		qu.pop();

		if (v[next].team == 0) {
			v[next].team = v[cur].team;
			v[next].sum = v[cur].sum + 1;
			qu.push(next);
		}
		else if (v[next].team == v[cur].team) {  // 같은 팀을 만났으면(사이클이 생성되었으면) 팀원 수 리턴
			return v[cur].sum - v[next].sum + 1; 
		}
		else return 0; // 다른 팀을 만났으면 0 반환(사이클 생성 못함)
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, cnt = 0;
		cin >> n;
		vector<node> v(n + 1);

		for (int i = 0; i < n; i++) {
			cin >> v[i + 1].go;
		}

		for (int i = 1; i <= n; i++) {
			if (v[i].team == 0) {
				v[i].team = i;
				cnt += bfs(i, v);
			}
		}
		cout << n - cnt << endl;
	}

	return 0;
}
