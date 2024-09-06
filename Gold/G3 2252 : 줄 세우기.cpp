#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)

//위상 정렬은, 자기보다 앞에 있는 놈이 앞에 있도록 정렬하는것. 그래서 만약 앞에 어떤놈이 있으면 먼저 보내고, 앞에 있는놈이 아무도 없으면 그냥 출력하면 된다. 

class node {
public:
	int cnt = 0;
	vector<int> next;
};

int main() {
	fastio;
	int n, m;
	cin >> n >> m;
	vector<node> v(n + 1);
	queue<int> qu;

	int a, b;
	while (m--) {
		cin >> a >> b;
		v[a].next.push_back(b);
		v[b].cnt++;
	}
	for (int i = 1; i <= n; i++) {
		if (v[i].cnt == 0) qu.push(i);
	}

	while (!qu.empty()) {
		int cur = qu.front();
		qu.pop();
		cout << cur << " ";
		
		for (auto i : v[cur].next) {
			v[i].cnt--;
			if (v[i].cnt == 0) qu.push(i);
		}
	}
	return 0;
}
