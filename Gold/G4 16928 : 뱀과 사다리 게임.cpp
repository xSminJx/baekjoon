#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> v(106, 0);
vector<int> vs(106, 0);

bool bfs(int num1, int num2, queue<int>& qu, vector<int>& in, vector<int>& out) {
	if (num1 == num2) return 1;
	int o[6] = { 1,2,3,4,5,6 };

	for (int i = 0; i < 6; i++) {
		if (num1 + o[i] > num2) break;
		if (v[num1 + o[i]] == 0) {
			auto it = find(in.begin(), in.end(), num1 + o[i]);
			int k;
			if (it != in.end()) {
				v[num1 + o[i]] = 1;
				k = out[it - in.begin()];
				if (v[k] == 1) continue;
			}
			else k = num1 + o[i];
			qu.push(k);
			v[k] = 1;
			vs[k] = vs[num1] + 1;
		}
	}
	return 0;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> in(n + m);
	vector<int> out(n + m);

	for (int i = 0; i < n + m; i++) {
		cin >> in[i] >> out[i];
	}

	queue<int> qu;

	qu.push(1);
	v[1] = 1;
	int qs = 1;
	while (qs != 0) {
		qs = qu.size();
		for (int j = 0; j < qs; j++) {
			if (bfs(qu.front(), 100, qu, in, out)) {
				cout << vs[100] << endl;
				qs = 0;
				break;
			}
			qu.pop();
		}
	}

	return 0;
}
