#include <iostream>
#include <vector>
using namespace std;

//dp+dfs로 풀었다

class node {
public:
	int t = -1; //건설까지 걸린 시간 (-1이면 건설 안했다는 뜻)
	vector<int> need; //건설 시 요구되는 다른 노드들의 목록
};

void acm(int n, vector<int>& times, vector<node>& v) {
	if (v[n].need.size() == 0) v[n].t = times[n]; //선행해야하는 노드가 없을 시 건설시간 대입
	else {
		int mx = 0;
		for (int i = 0; i < v[n].need.size(); i++) {
			if (v[v[n].need[i]].t == -1) acm(v[n].need[i], times, v); //건설되지 않았으면 건설하러감
			mx = max(mx, v[v[n].need[i]].t); //선행 노드들이 모두 건설되야 n번째 노드를 건설할 수 있으니 가장 큰 시간을 찾는다
		}
		v[n].t = mx + times[n]; //가장 큰 시간+n번째 노드의 건설시간
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, k, a, b, target;
		cin >> n >> k;
		vector<int> times(n + 1);
		vector<node> v(n + 1);

		for (int i = 1; i <= n; i++) cin >> times[i];
		for (int i = 0; i < k; i++) {
			cin >> a >> b;
			v[b].need.push_back(a);
		}
		cin >> target;
		acm(target, times, v);
		cout << v[target].t << '\n';
	}
	return 0;
}
