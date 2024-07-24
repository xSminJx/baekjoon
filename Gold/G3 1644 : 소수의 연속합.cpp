#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int main() {
	int n, cnt = 0;
	cin >> n;
	vector<bool> s(n + 1);
	vector<long long> v(1);

	s[0] = s[1] = 1;
	for (int i = 2; i <= (int)sqrt(n); i++) {
		if (s[i] == 0) {
			int k = i;
			while (k + i <= n) {
				k += i;
				s[k] = 1;
			}
		}
	}

	for (int i = 0; i <= n; i++) {
		if (s[i] == 0) v.push_back(i + v.back());
	}

	int l = 0, r = 1;
	while (r < v.size()) {
		if (v[r] - v[l] == n) cnt++, r++;
		else if (v[r] - v[l] < n) r++;
		else l++;
	}

	cout << cnt;
	return 0;
}
