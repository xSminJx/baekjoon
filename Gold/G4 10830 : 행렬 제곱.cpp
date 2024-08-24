#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using matrix = vector<vector<int>>;
#define mod 1000

// n*n 행렬곱 계산
matrix matrhq(matrix& a, matrix& b) {
	int n = a.size();
	matrix ret = a;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp = 0;
			for (int k = 0; k < n; k++) {
				temp += a[i][k] * b[k][j] % mod;
			}
			ret[i][j] = temp % mod;
		}
	}
	return ret;
}

// 분할정복으로 거듭제곱
matrix cal(ll n, ll b, matrix& v) {
	matrix res(n, vector<int>(n)); // 기본행렬
	for (int i = 0; i < n * n; i++) {
		if (i / n == i % n) res[i / n][i % n] = 1;
	}

	while (b) {
		if (b % 2) res = matrhq(res, v);
		v = matrhq(v, v);
		b /= 2;
	}
	return res;
}

int main() {
	ll n, b;
	cin >> n >> b;
	matrix v(n, vector<int>(n));
	for (int i = 0; i < n * n; i++) cin >> v[i / n][i % n];
	v = cal(n, b, v);

	for (auto i : v) {
		for (auto j : i) cout << j << " ";
		cout << endl;
	}
	return 0;
}
