#include<iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> v(50001, -1);

int dp(int n) {
	if (v[n] != -1) return v[n];
	else {
		int k = sqrt(n), mn = 50000;
		for (int i = k; i > 0; i--) {
			if (n - i * i >= 0) mn = min(mn, dp(n - i * i) + 1);
		}
		v[n] = mn;
		return v[n];
	}
}

int main() {
	int n;
	cin >> n;
	v[0] = 0;

	cout << dp(n);
	return 0;
}
