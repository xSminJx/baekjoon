#include <iostream>
using namespace std;

int main() {
	int n, k, s[10], idx, cnt = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> s[i];

	idx = n - 1;
	while (k) {
		cnt += k / s[idx];
		k %= s[idx];
		idx--;
	}

	cout << cnt;
	return 0;
}
