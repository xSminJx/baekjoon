#include <stdio.h>

int main(void) {
	int n, m,a,b;
	scanf("%d %d", &n, &m);
	getchar();
	int min = (n > m) ? m : n;
	int c[50][50] = {'\0'};
	for (a = 0; a < n; a++) {
		for (b = 0; b < m; b++) {
			int p;
			scanf("%1d", &p);
			c[a][b] = p;
		}
	}
	for (int j=0;;j++) {
		static int i = 0;
		if (i <= n - min && j <= m - min) {
			if (c[i][j] == c[i][j + min - 1] && c[i][j] == c[i + min - 1][j] && c[i + min - 1][j] == c[i + min - 1][j + min - 1]) {
				break;
			}
			if (i == n - min && j == m - min) {
				i = 0, j = -1, min--;
				if (min == 1) break;
			}
			else if (j == m - min) {
				i++; j = -1;
			}
		}
	}
	printf("%d", min * min);
	return 0;
}
