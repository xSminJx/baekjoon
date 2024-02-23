#include <stdio.h>

int cnt = 1;
int intlen(int a) {
	int len = 0;
	while (a) {
		a /= 10;
		len++;
	}
	return len;
}

int pow10(int x) {
	if (x == 0) return 1;
	return 10 * pow10(x - 1);
}

void maken(int a, int l) {
	if (l == 1) return;
	if (a % pow10(l - 1) != a / 10) {
		cnt++;
		maken(a % pow10(l - 1), l - 1);
		maken(a / 10, l - 1);
	}
	else {
		maken(a / 10, l - 1);
	}
}

int main(void) {
	int n, len;
	scanf("%d", &n);
	len = intlen(n);
	if (n == 0) {
		printf("1");
		return 0;
	}
	maken(n, len);
	printf("%d", cnt);
	return 0;
}
