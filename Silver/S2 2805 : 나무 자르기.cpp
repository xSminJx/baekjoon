#include <iostream>
using namespace std;

int s[1000000];

long long sum(int a, int n) {
	long long sm = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] > a) sm += (long long)s[i] - a;
	}
	return sm;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i];

	int l = 0, r = 1000000000, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		long long cut = sum(mid, n);

		if (cut > m) l = mid + 1;
		else if (cut < m) r = mid - 1;
		else break;
	}

	cout << (l+r)/2;
	return 0;
}
