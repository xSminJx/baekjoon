#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0)
#define LOG 18

// 비트 리프팅이라는 최소 공통 조상을 찾는 알고리즘을 사용. 

class node {
public:
	int level = 50002;
	vector<int> ups; // 여기에 조상들이 들어감. 0은 2^0번째 조상(부모), 1은 2^1번째 조상(부모의 부모)...
	vector<int> edge;
	node() :ups(LOG) {}
};

void pushlevel(int cur, int l, vector<node>& v) {
	v[cur].level = l;
	for (int i = 1; i < LOG; i++) { // v[cur].ups[i-1]가 존재한다면, cur의 2^i-1번째 부모의 2^i-1번째 부모를 통해 cur의 2^i번째 부모를 찾을 수 있다.
		if (v[cur].ups[i - 1] != -1) v[cur].ups[i] = v[v[cur].ups[i - 1]].ups[i - 1];
		else v[cur].ups[i] = -1;
	}

	for (auto i : v[cur].edge) {
		if (v[i].level == 50002) {
			v[i].ups[0] = cur;
			pushlevel(i, l + 1, v);
		}
	}
}

int findan(int a, int b, vector<node>& v) {
	if (v[a].level < v[b].level) swap(a, b);
	for (int i = LOG - 1; i >= 0; i--) { // a와 b의 레벨을 맞춰준다. 왜냐하면 같은 높이만큼 점프해서 최소 공통 조상을 찾을거라서. 당연히 레벨이 다르면 공통 조상을 못찾겠지?
		if (v[a].level - (1 << i) >= v[b].level) a = v[a].ups[i];
	}
	if (a == b) return a;

	for (int i = LOG - 1; i >= 0; i--) { // 2^i번째 조상이 다르다면 a와 b를 점프시킨다. 최소 공통 조상이 a와 b에서 얼마나 올라가야 할진 모르지만, 그 높이를 이진수로 표현 가능하기에 무조건 도달 가능.
		if (v[a].ups[i] != v[b].ups[i]) {
			a = v[a].ups[i];
			b = v[b].ups[i];
		}
	}
	return v[a].ups[0];
}

int main() {
	fastio;
	int n, m;
	cin >> n;
	vector<node> v(n + 1);

	v[1].level = 1;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].edge.push_back(b);
		v[b].edge.push_back(a);
	}
	v[1].ups[0] = -1;
	pushlevel(1, 0, v);

	cin >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		cout << findan(a, b, v) << '\n';
	}
	return 0;
}
