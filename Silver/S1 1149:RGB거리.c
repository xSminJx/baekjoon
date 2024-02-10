#include <stdio.h>

int main(void) {
	int n, a, b, c, A, B, C;
	scanf("%d", &n);
	scanf("%d %d %d", &a, &b, &c);

	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d %d", &A, &B, &C);
		A += (b > c) ? c : b;
		B += (a > c) ? c : a;
		C += (b > a) ? a : b;

		a = A, b = B, c = C;
	}
	printf("%d", (a < b ? a : b) < c ? (a < b ? a : b) : c);
	return 0;
}
