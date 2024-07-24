#include <iostream>
#include <queue>
using namespace std;

int s[4000001];

int main() {
	int n, cnt = 0;
	cin >> n;
	vector<long long> v(1);

	s[0] = s[1] = 1;
	for (int i = 2; i <= 2000; i++) {
		if (s[i] == 0) {
			int k = i;
			while (k + i <= 4000000) {
				k += i;
				s[k] = 1;
			}
		}
	}

	for (int i = 0; i < 4000000; i++) {
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
