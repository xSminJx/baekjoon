#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, b1 = 0, b2 = 0, idx = 0, idx1 = 0, idx2 = 0, cnt = 0, maxcnt = 0, k, i;
	cin >> n;
	vector<int> v(n);

	for (i = 0; i < n; i++) {
		cin >> k;
		if (b1 == 0) b1 = k, idx = idx1 = i;
		else if (k != b1 && b2 == 0) b2 = k, idx2 = i;
		else if (k == b1 || k == b2) {
			if (k == b1 && idx1 < idx2)idx1 = i;
			else if (k == b2 && idx2 < idx1) idx2 = i;
		}
		else {
			maxcnt = max(maxcnt, i - idx);
			if (idx1 < idx2) b1 = b2, idx = idx2;
			else idx = idx1;
			b2 = k;
			idx2 = i;
		}
	}

	maxcnt = max(maxcnt, i - idx);
	cout << maxcnt;

	return 0;
}
