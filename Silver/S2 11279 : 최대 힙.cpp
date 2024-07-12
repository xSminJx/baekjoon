#include <iostream>
#include <vector>
using namespace std;

void heap_pop(int hsize, vector<int>& v) {
	cout << v[1] << '\n';
	v[1] = v[hsize];
	int i = 1;

	while (i * 2 <= hsize) {
		if (i * 2 == hsize) {
			if (v[i] < v[i * 2])
				swap(v[i], v[i * 2]);
			return;
		}
		int k = (v[i * 2] > v[i * 2 + 1]) ? i * 2 : i * 2 + 1;
		if (v[i] < v[k])
			swap(v[i], v[k]);
		i = k;
	}
}

void heap_up(int h, vector<int>& v) {
	if (h == 1) return;
	else if (v[h] > v[h / 2]) {
		swap(v[h], v[h / 2]);
		heap_up(h / 2, v);
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
			hsize++;
			v[hsize] = k;
			heap_up(hsize, v);
		}
	}
	return 0;
}
