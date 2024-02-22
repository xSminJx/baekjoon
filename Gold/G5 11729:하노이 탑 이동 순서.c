#include <stdio.h>

int FloorN(int a, int b, int c) {
	if (a > 1) FloorN(a - 1, b, 6 - (b + c));
	printf("%d %d\n", b, c);
	if (a > 1) FloorN(a - 1, 6 - (b + c), c);
}

int pow2(int a) {
	if (a == 0) return 1;
	return 2 * pow2(a - 1);
}

int main(void) {
	int n;
	scanf("%d", &n);
	printf("%d\n", pow2(n) - 1);
	FloorN(n, 1, 3);
	return 0;
}
