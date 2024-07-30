#include <iostream>
#include <vector>
using namespace std;
#define INF 2147483647

int get_stc(int mid, vector<int>& v) {
	int stc = 0;
	for (auto i : v) stc += i / mid;
	return stc;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int k, n;
	cin >> k >> n;
	vector<int> v(k);
	for (int i = 0; i < k; i++) cin >> v[i];

	int l = 0, r = INF, mid, stc;
	while (l <= r) {
		mid = l + (r - l) / 2;
		stc = get_stc(mid, v);
		if (stc >= n) {
			if (get_stc(mid + 1, v) < n) break;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << mid;

	return 0;
}
