#include <stdio.h>

long long pow2(int a) {
	if (a < 0) return 1;
	return 1ll << a;
}

long long cal(int n) {
	if (n == 0) return 0;
	int a = 0, n2;
	long long sum = 0;
	while (pow2(a) <= n) a++;
	a--;
	n2 = n - pow2(a);
	n -= n2;

	for (int i = 1; n > 0; i++) {
		sum += pow2(i) * pow2(--a);
		n -= pow2(a);
	}

	return sum + cal(n2);
}

int main(void) {
	int n;
	scanf("%d", &n);

	printf("%lld", cal(n));
	return 0;
}

