#include <iostream>
#include <vector>
using namespace std;

int idx_find(int start, int n, vector<int>& v) {
	for (int i = start; i < v.size(); i++) {
		if (v[i] == n) return i;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		long long n, stc = 0, sum = 0;
		cin >> n;
		vector<int> v(n);
		vector<int> nums(10001);

		for (int i = 0; i < n; i++) {
			cin >> v[i];
			nums[v[i]]++;
		}

		int l = 0, r = 0, num_idx = 10000;
		while (l < v.size() && num_idx) {
			if (nums[num_idx] == 0) {
				num_idx--;
				continue;
			}
			else if ((r = idx_find(l, num_idx, v)) != -1) {
				nums[num_idx]--;
				for (int i = l; i < r; i++) sum -= v[i], stc++;
				sum += stc * v[r];
				stc = 0, l = r + 1, r = -1;
			}
			else if (r == -1) num_idx--;
		}
		cout << sum << '\n';
	}
	return 0;
}
