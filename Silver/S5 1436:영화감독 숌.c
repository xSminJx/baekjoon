#include <stdio.h>

int Pow(int P) {
	int a = 1;
	for (int i = 0; i < P; i++) a *= 10;
	return a;
}


int main(void) {
	int n, i = 0, j = 0, stc = 0;
	scanf("%d", &n);

	for (j;; j++) {
		for (int p = 1;; p++) {
			if (j < Pow(p-1)) break;
			if ((j % Pow(p)) / Pow(p - 1) == 6) {
				stc++;
			}
			else stc = 0;
			if (stc == 3) break;
		}
		if (stc == 3) i++;
		if (i == n) break;
		stc = 0;
	}
	printf("%d", j);
	return 0;
}
