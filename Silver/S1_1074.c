#include <stdio.h>

int pow(int a) {
	int b = 1;
	for (int i = 0; i < a; i++) {
		b = b * 2;
	}
	return b;
}
void a(int n, int r, int c,int*ps) {
	n -= 1;
	if (r < pow(n)) {
		if (c < pow(n)) {
			*ps += 0*pow(n)*pow(n);
		}
		else if (c >= pow(n)) {
			*ps += 1* pow(n) * pow(n);
			c -= pow(n);
		}
	}
	else if (r >= pow(n)) {
		if (c < pow(n)) {
			*ps += 2 * pow(n) * pow(n);
			r -= pow(n);
		}
		else if (c >= pow(n)) {
			*ps += 3 * pow(n) * pow(n);
			r -= pow(n);
			c -= pow(n);
		}
	}
	if (n == 0) return 0;
	a(n, r, c, ps);
}

int main(void) {
	int N, r, c,sum=0;
	scanf("%d %d %d", &N, &r, &c);
	a(N, r, c, &sum);
	printf("%d", sum);
	return 0;
}
