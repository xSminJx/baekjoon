#include <stdio.h>
#include <limits.h>

int pow2(int a) {
	int b = 1;
	return b <<= a;
}

int calalp(int n) {
	int alp = 0;
	while (n > 0) {
		if (n % 2) {
			n = (n - 1) >> 1;
			alp++;
		}
		else {
			n >>= 1;
		}
	}
	return alp;
}

int main(void) {
	int n, k, powstc = 0, ans = 0;
	scanf("%d %d", &n, &k);

	while (calalp(n) > k) {
		if (n % 2) {
			n = (n + 1) >> 1;
			ans += pow2(powstc);
		}
		else {
			n >>= 1;
		}
		powstc++;
	}

	printf("%d", ans);
	return 0;
}
