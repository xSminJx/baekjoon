#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0), cout.tie(0)

class node {
public:
	int cnt = 0;
	vector<int> next; // 자신을 요구하는 부품들
	vector<int> need; // 선행 부품들
	vector<int> basic_need; // 기본 부품들 필요한 양
	node() : basic_need(101), need(101) {}
};

int main() {
	fastio;
	int n, m;
	cin >> n >> m;
	vector<node> v(n + 1);
	vector<int> basic_idx; // 기본 부품을 인덱스 저장하는 벡터
	queue<int> qu;

	int a, b, c;
	while (m--) {
		cin >> a >> b >> c;
		v[b].next.push_back(a);
		v[a].need[b] = c;
		v[a].cnt++;
	}
	for (int i = 1; i <= n; i++) {
		if (v[i].cnt == 0) { // v[i].cnt가 0이면 i번째 부품은 기본 부품
			qu.push(i);
			basic_idx.push_back(i);
			v[i].basic_need[i] = 1; // 자기 자신을 1만큼 필요하게 해야지 나중에 기본부품 중간부품 구별 안하고 부품 갯수를 집어넣기 편하다.
		}
	}

	while (!qu.empty()) {
		int cur = qu.front();
		qu.pop();

		for (auto i : v[cur].next) {
			for (auto j : basic_idx) {
				v[i].basic_need[j] += v[cur].basic_need[j] * v[i].need[cur]; // 기본 부품들 갯수 집어넣기
			}
			v[i].cnt--;
			if (v[i].cnt == 0) qu.push(i);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (v[n].basic_need[i] != 0) {
			cout << i << " " << v[n].basic_need[i] << '\n';
		}
	}
	return 0;
}
