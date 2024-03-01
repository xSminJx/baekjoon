#include <stdio.h>

int main(void) {
	int n, s[1001] = { 0,1,2 };
	scanf("%d", &n);
	for (int i = 3; i <= n; i++) {
		s[i] = (s[i - 1] + s[i - 2]) % 10007;
	}
	printf("%d\n", s[n]);
	return 0;
}
