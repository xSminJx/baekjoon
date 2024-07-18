#include <iostream>
#include <vector>
using namespace std;

class node {
public:
	vector<int> edge;
	int level = -1;
	int root = -1;
};

void dfs(int i, int l, int r, vector<node>& v) {
	v[i].level = l;
	v[i].root = r;
	for (auto k : v[i].edge) {
		if (v[k].level == -1) dfs(k, l + 1, i, v);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<node> v(n + 1);
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[a].edge.push_back(b);
		v[b].edge.push_back(a);
	}
	dfs(1, 0, -1, v);
	for (int i = 2; i <= n; i++) cout << v[i].root << '\n';
	return 0;
}
