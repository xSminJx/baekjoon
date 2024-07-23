#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;

bool check(int k, int i, vector<int>& col) {
	for (int j = 0; j < k; j++) {
		if (col[j] == i || col[j] + k - j == i || col[j] - k + j == i) return 0;
	}
	return 1;
}

void findNQ(int k, int n, vector<int>& col) {
	if (k == n) cnt++;
	else {
		for (int i = 0; i < n; i++) {
			if (check(k, i, col)) {
				col[k] = i;
				findNQ(k + 1, n, col);
				col[k] = 0;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> col(n);
	findNQ(0, n, col);
	cout << cnt;
	return 0;
}
