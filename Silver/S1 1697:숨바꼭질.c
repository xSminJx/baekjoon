#include <stdio.h>

int s[100002];

int main(void) {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = n - 1; i >= 0; i--) {
		s[i] = s[i + 1] + 1;
	}

	for (int i = n + 1; i <= 100000; i++) {
		s[i] = s[i - 1] + 1;
		if (s[i + 1] != 0) s[i] = (s[i] > s[i + 1] + 1) ? s[i + 1] + 1 : s[i];
		if (i % 2 == 0) s[i] = (s[i] > s[i / 2] + 1) ? s[i / 2] + 1 : s[i];

		for (int o = i; s[o - 1] > s[o] + 1; o--) {
			s[o - 1] = s[o] + 1;
		}
	}

	printf("%d", s[k]);

	return 0;
}
