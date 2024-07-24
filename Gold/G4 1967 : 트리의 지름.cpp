#include <iostream>
#include <vector>
using namespace std;

class node {
public:
	vector<pair<int, int>> edge;
};

pair<int, int> dfs(int i, pair<int, int> maxint, vector<node>& v, int before) {
	pair<int, int> mxbuffer = maxint;
	for (int j = 0; j < v[i].edge.size(); j++) {
		if (v[i].edge[j].first == before) continue;
		pair<int, int> dfsbuffer = dfs(v[i].edge[j].first, { v[i].edge[j].first,mxbuffer.second + v[i].edge[j].second }, v, i);
		if (maxint.second < dfsbuffer.second) maxint = dfsbuffer;
	}
	return maxint;
}

int main() {
	int n;
	cin >> n;
	vector<node> v(n + 1);

	int a, b, c;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		v[a].edge.push_back({ b,c });
		v[b].edge.push_back({ a,c });
	}

	int x = dfs(1, { 0,0 }, v, 0).first;
	cout << dfs(x, { 0,0 }, v, 0).second;
	return 0;
}
