#include <stdio.h>

void FloorN(int a, int b, int c) {
	if (a > 1) FloorN(a - 1, b, 6 - (b + c));
	printf("%d %d\n", b, c);
	if (a > 1) FloorN(a - 1, 6 - (b + c), c);
}

int intlen(int a) {
	int len = 0;
	while (a) {
		a /= 10;
		len++;
	}
	return len;
}

int main(void) {
	int n, s[5] = { 1 };;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int o = 0; o < 5; o++) s[o] *= 2;
		for (int o = 0; o < 5; o++) {
			if (s[o] >= 1000000000) {
				s[o] -= 1000000000;
				s[o + 1]++;
			}
		}
	}
	s[0]--;

	for (int o = 3; o >= 0; o--) {
		if (s[o] == 0) continue;
		if (intlen(s[o]) == 9) printf("%d", s[o]);
		else {
			if (s[o + 1] == 0) printf("%d", s[o]);
			else {
				for (int i = 0; i < 9 - intlen(s[o]); i++) printf("0");
				printf("%d", s[o]);
			}
		}
	}
	if (n < 21) {
		printf("\n");
		FloorN(n, 1, 3);
	}
	return 0;
}
