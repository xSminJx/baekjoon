#include <stdio.h>

int s[1000000] = { 1 };

int main(void) {
	int m, n;
	scanf("%d %d", &m, &n);
	s[1] = 1;

	for (int i = 2; i < 1001; i++) {
		if (s[i] == 0) {
			for (int j = 2; j <= n / i; j++) {
				s[i * j] = 1;
			}
		}
	}

	for (int i = m; i <= n; i++) {
		if (s[i] == 0) {
			printf("%d\n", i);
		}
	}

	return 0;
}
