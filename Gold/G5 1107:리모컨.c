#include <stdio.h>
#include <stdlib.h>

int pow(int b) {
	if (b == 0) return 1;
	else if (b < 0) return 0;
	return 10 * pow(b - 1);
}

int main(void) {
	int n, m, i, o, broken[10] = { 0 }, unbroken[10] = { 0 }, channel = 100, min = 500000, minch = 0, stc = 0, stc2 = 0, stc3 = 0, div = 1;
	int a, b, c, d, e, f, A, B, C, D, E, F;
	scanf("%d %d", &n, &m);

	if (abs(n - channel) < min) {
		min = abs(n - channel);
		minch = channel;
	}

	for (i = 0; i < m; i++) {
		int a;
		scanf("%d", &a);
		broken[a]++;
	}
	for (o = i = 0; i < 10; i++) {
		if (broken[i] == 0) {
			unbroken[o] = i;
			o++;
		}
	}

	for (A = 0; A < 10 - m; A++) {
		a = unbroken[A];
		for (B = 0; B < 10 - m; B++) {
			b = unbroken[B];
			for (C = 0; C < 10 - m; C++) {
				c = unbroken[C];
				for (D = 0; D < 10 - m; D++) {
					d = unbroken[D];
					for (E = 0; E < 10 - m; E++) {
						e = unbroken[E];
						for (F = 0; F < 10 - m; F++) {
							f = unbroken[F];
							channel = a * pow(stc - 5) + b * pow(stc - 4) + c * pow(stc - 3) + d * pow(stc - 2) + e * pow(stc - 1) + f * pow(stc);
							if (abs(n - channel) < min) {
								min = abs(n - channel);
								minch = channel;
							}
							if (F == 9 - m && stc2 == 0) stc++, stc2++, E = -1;
						}
						if (E == 9 - m && stc2 == 1) stc++, stc2++, D = -1;
					}
					if (D == 9 - m && stc2 == 2) stc++, stc2++, D = -1;
				}
				if (C == 9 - m && stc2 == 3) stc++, stc2++, B = -1;
			}
			if (B == 9 - m && stc2 == 4) stc++, stc2++, A = -1;
		}
	}

	if (minch == 0) stc3 = 1;
	while (minch > 0) {
		minch /= 10;
		stc3++;
	}

	if (abs(n - 100) < min + stc3) {
		printf("%d", abs(n - 100));
		return 0;
	}
	printf("%d", stc3+ min);

	return 0;
}
