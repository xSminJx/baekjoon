#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void heap_pop(int hsize, vector<int>& v) {
	cout << v[1] << '\n';
	v[1] = v[hsize];
	int i = 1;

	while (i * 2 <= hsize) {
		if (i * 2 == hsize) {
			if ((abs(v[i]) == abs(v[i * 2]) && v[i] > v[i * 2]) || abs(v[i]) > abs(v[i * 2]))
				swap(v[i], v[i * 2]);
			return;
		}
		int k;
		if (abs(v[i * 2]) == abs(v[i * 2 + 1])) k = (v[i * 2] < v[i * 2 + 1]) ? i * 2 : i * 2 + 1;
		else k = (abs(v[i * 2]) < abs(v[i * 2 + 1])) ? i * 2 : i * 2 + 1;

		if ((abs(v[i]) == abs(v[k]) && v[i] > v[k]) || abs(v[i]) > abs(v[k]))
			swap(v[i], v[k]);
		i = k;
	}
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n, k, hsize = 0;
	cin >> n;
	vector<int> v(n + 1);

	for (int i = 0; i < n; i++) {
		cin >> k;
		if (k == 0) {
			if (hsize == 0) cout << 0 << '\n';
			else {
				heap_pop(hsize, v);
				hsize--;
			}
		}
		else {
			v[++hsize] = k;
			int h = hsize;
			while (h > 1 && abs(v[h]) <= abs(v[h / 2])) {
				if ((abs(v[h]) == abs(v[h / 2]) && v[h] < v[h / 2]) || abs(v[h]) < abs(v[h / 2])) swap(v[h], v[h / 2]);
				h /= 2;
			}
		}
	}
	return 0;
}
