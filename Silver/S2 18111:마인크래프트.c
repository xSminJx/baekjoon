#include <stdio.h>
#include <limits.h>

int main(void) {
	int n, m, b, s[500][500], top = 0, mean = 0, t = 0, time = INT_MAX, high = 0;
	scanf("%d %d %d", &n, &m, &b);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &s[i][j]);
			top += s[i][j];
			mean += s[i][j];
		}
	}
	top = (top + b) / (n * m);
	mean /= n * m;
	
	for (int k = top; k >= mean; k--) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (k > s[i][j]) {
					t += k - s[i][j];
				}
				else t += 2 * (s[i][j] - k);
			}
		}
		if (time > t) {
			time = t;
			high = k;
		}
		t = 0;
	}

	printf("%d %d", time, high);
	return 0;
}
