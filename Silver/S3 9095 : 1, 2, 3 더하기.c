#include <stdio.h>

int main(void) {
	int t, s[12] = { 0,1,2,4 };
	scanf("%d", &t);
	for (int o = 0; o < t; o++) {
		int n;
		scanf("%d", &n);
		if (n < 4) printf("%d\n", s[n]);
		else {
			for (int i = 4; i <= n; i++) {
				s[i] = s[i - 1] + s[i - 2] + s[i - 3];
			}
			printf("%d\n", s[n]);
		}
	}
	return 0;
}
