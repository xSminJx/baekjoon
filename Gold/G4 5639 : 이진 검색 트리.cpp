#include <bits/stdc++.h>
using namespace std;

vector<int> v;

void out(int cur, int end) {
	if (cur > end) return;
	int i = cur + 1;
	while (i <= end && v[cur] > v[i]) i++;

	out(cur + 1, i - 1);
	out(i, end);
	cout << v[cur] << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	while (cin >> n) v.push_back(n);
	out(0, v.size() - 1);

	return 0;
}
