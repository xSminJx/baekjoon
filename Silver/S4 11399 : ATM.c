#include <stdio.h>

int main(void) {
	int n, s[1001] = { 0 }, total = 0, o = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		s[a]++;
	}
	while (n > 0) {
		if (s[o] != 0) {
			total += o * n;
			s[o]--;
			n--;
		}
		else o++;
	}
	printf("%d", total);
	return 0;
}
