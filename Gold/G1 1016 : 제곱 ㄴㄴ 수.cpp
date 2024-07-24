#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;

int main() {
	ll n, m, cpn, cnt = 0;
	cin >> n >> m;
	cpn = (ll)sqrt(m) + 1;
	vector<bool> v(m - n + 1, 1);
	vector<bool> cp(cpn, 1);
	vector<ll> cp2;

	cp[0] = cp[1] = 0;
	for (int i = 2; i < (int)sqrt(cpn); i++) {
		if (cp[i]) {
			int k = i;
			while (k + i < cpn) {
				k += i;
				cp[k] = 0;
			}
		}
	}
	for (int i = 0; i < cp.size(); i++) {
		if (cp[i]) cp2.push_back(i);
	}

	for (auto i : cp2) {
		ll k = n / (i * i);
		if (n % (i * i)) k++;
		k *= (i * i);

		while (k <= m && k >= n) {
			v[k - n] = 0;
			k += i * i;
		}
	}

	for (auto i : v) {
		if (i) cnt++;
	}

	cout << cnt;
	return 0;
}
