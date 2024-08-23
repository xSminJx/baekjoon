#include <bits/stdc++.h>
using namespace std;

// 몇 자리인지 계산
int getlen(int n) {
	int a = 1;
	while (n / 10) {
		n /= 10;
		a++;
	}
	return a;
}

// n,n의 위치가 항상 (1+n*2)^2의 값을 가진다는 것을 이용, 나선을 돌면서 특정 위치의 값을 찾는다.
int getnum(int a, int b) {
	int k = max(abs(a), abs(b)), n = pow(1 + k * 2, 2), temp = k * 2;

	if (a == k) return n - (k - b); // 왼쪽으로 갔다가
	n -= temp;

	if (b == -k) return n - (k - a); // 위로 갔다가
	n -= temp;

	if (a == -k) return n - (k + b); // 오른쪽으로 갔다가
	n -= temp;

	return n - abs(k + a);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int xmx = abs(x2 - x1) + 1, ymx = abs(y2 - y1) + 1;
	vector<vector<int>> v(xmx, vector<int>(ymx));

	// 배열에 값을 넣으면서 값들 중 최대 길이를 찾는다.
	int mxlen = 0;
	for (int i = 0; i < xmx; i++) {
		int a = x1 + i;
		for (int j = 0; j < ymx; j++) {
			int b = y1 + j;
			v[i][j] = getnum(a, b);
			mxlen = max(mxlen, getlen(v[i][j]));
		}
	}

	// 이쁘게 출력
	for (auto i : v) {
		int k = 0;
		for (auto j : i) {
			for (int o = 0; o < mxlen - getlen(j); o++) cout << " ";
			if (k == 0) cout << j, k++;
			else cout << " " << j;
		}
		cout << '\n';
	}
	return 0;
}
