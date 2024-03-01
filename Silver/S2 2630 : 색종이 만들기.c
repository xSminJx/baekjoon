#include <stdio.h>

int s[128][128], cut_count[2];

void cut(int a, int b, int n) {
	int stc_cut = 0, stc_scan = 0;

	for (int i = a; i < n + a; i++) {
		for (int o = b; o < n + b; o++) {
			if (s[a][b] != s[i][o]) {
				stc_cut = 1;
				i = n + a;
				break;
			}
		}
	}
	if (stc_cut == 1) {
		cut(a, b, n / 2);
		cut(a + n / 2, b, n / 2);
		cut(a, b + n / 2, n / 2);
		cut(a + n / 2, b + n / 2, n / 2);
	}
	else cut_count[s[a][b]]++;
}

int main(void) {
	int n, index = 1;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int o = 0; o < n; o++) scanf("%d", &s[i][o]);
	}

	cut(0, 0, n);
	printf("%d\n%d", cut_count[0], cut_count[1]);
	return 0;
}
