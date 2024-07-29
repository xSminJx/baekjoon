#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, w, l, cnt = 0, buffer = 0, idx = 0;
	cin >> n >> w >> l;
	vector<int> v(n);
	vector<int> out(n * w + 1);
	for (int i = 0; i < n; i++) cin >> v[i];

	while (buffer || idx < v.size()) {
		buffer -= out[cnt];
		if (idx < v.size() && buffer + v[idx] <= l) {
			buffer += v[idx];
			out[cnt + w] = v[idx++];
		}
		cnt++;
	}

	cout << cnt;
	return 0;
}
