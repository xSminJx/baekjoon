#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

class node {
public:
	vector<int> edge; // 연결된 도시의 인덱스
	vector<int> val;  // 연결된 도시의 가중치(비용)
	int range = INT_MAX; // 출발점에서의 거리
	int visit = 0;
};

void Dijkstra(int a, vector<node>& v) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 출발점에서 도시 까지의 거리, 도시의 인덱스
	pq.push({ 0,a });

	while (!pq.empty()) {
		int idx = pq.top().second; // 도시의 인덱스
		pq.pop();

		if (v[idx].visit == 1) continue;
		v[idx].visit = 1;

		for (int i = 0; i < v[idx].val.size(); i++) {
			int target = v[idx].edge[i]; // target에 idx도시의 i번째 연결된 도시의 인덱스 저장
			if (v[target].range > v[idx].range + v[idx].val[i]) {
				v[target].range = v[idx].range + v[idx].val[i];
				pq.push({ v[target].range ,target });
			}
		}
	}

}

int main() {
	int n, m, a, b;
	cin >> n >> m;
	vector<node> v(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].edge.push_back(b);
		v[a].val.push_back(c);
	}

	cin >> a >> b;
	v[a].range = 0;
	Dijkstra(a, v);
	cout << v[b].range;
	return 0;
}
