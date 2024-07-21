#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> v(100002, -1);
	v[n] = 0;

	for (int i = n - 1; i >= 0; i--) v[i] = v[i + 1] + 1;

	for (int i = n + 1; i <= 100000; i++) {
		v[i] = v[i - 1] + 1;
		if (v[i + 1] != -1) v[i] = min(v[i], v[i + 1] + 1);
		int k = i;
		while (k % 2 == 0) {
			v[k] = min(v[k], v[k / 2]);
			k /= 2;
		}

		for (int o = i; o > 0 && v[o - 1] > v[o] + 1; o--) {
			v[o - 1] = v[o] + 1;
		}
	}

	cout << v[k];
	return 0;
}
