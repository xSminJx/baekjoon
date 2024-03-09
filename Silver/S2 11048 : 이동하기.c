#include <iostream>
using namespace std;

int s[1000][1000];

void dp(int r, int c) {
	int n = 0, as[3][2] = { {r - 1,c},{r,c - 1},{r - 1,c - 1} };
	for (int i = 0; i < 3; i++) {
		if (as[i][0] >= 0 && as[i][1] >= 0) n = (n > s[as[i][0]][as[i][1]]) ? n : s[as[i][0]][as[i][1]];
	}
	s[r][c] += n;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int o = 0; o < m; o++) cin >> s[i][o];
	}

	for (int i = 0; i < n; i++) {
		for (int o = 0; o < m; o++) dp(i, o);
	}

	cout << s[n - 1][m - 1];
	return 0;
}
