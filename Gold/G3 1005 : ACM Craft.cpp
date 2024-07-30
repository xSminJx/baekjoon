#include <iostream>
#include <vector>
using namespace std;

class node {
public:
	int t = -1;
	vector<int> need;
};

void acm(int n, vector<int>& times, vector<node>& v) {
	if (v[n].need.size() == 0) v[n].t = times[n];
	else {
		int mx = 0;
		for (int i = 0; i < v[n].need.size(); i++) {
			if (v[v[n].need[i]].t == -1) acm(v[n].need[i], times, v);
			mx = max(mx, v[v[n].need[i]].t);
		}
		v[n].t = mx + times[n];
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
