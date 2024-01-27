#include <stdio.h>

int main(void) {
	int n, i, stc = -1;
	scanf("%d", &n);

	for (i = n / 5; i >= 0; i--) {
		for (int j = 0; n - (5 * i) - 3 * j >= 0; j++) {
			if (n - (5 * i) - 3 * j == 0) {
				stc = i + j;
				i = -2;
				break;
			}
		}
	}

	printf("%d", stc);
	return 0;
}
