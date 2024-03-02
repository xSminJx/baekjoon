#include <stdio.h>

int main(void) {
	int n, m, a[101] = { 0 }, b[101] = { 0 };
	long long alpha[26] = { 0 };
	char com[51][51];

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", com[i]);
	}
	for (int i = n, o = 1; i > 0; i--, o++) {
		a[o] += i * 2 + a[o - 1];
		a[n * 2 + 1 - o] = a[o];
	}
	for (int i = m, o = 1; i > 0; i--, o++) {
		b[o] += i * 2 + b[o - 1];
		b[m * 2 + 1 - o] = b[o];
	}

	for (int i = 0; i < n; i++) {
		for (int o = 0; o < m; o++) {
			alpha[com[i][o]-65] += a[1 + i] * b[1 + o] + a[1 + i + n] * b[1 + o + m] + a[1 + i] * b[1 + o + m] + a[1 + i + n] * b[1 + o];
		}
	}

	for (int i = 0; i < 26; i++) printf("%lld\n", alpha[i]);

	return 0;
}
