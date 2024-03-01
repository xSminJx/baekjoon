#include <stdio.h>

int s[100001];
int main(void) {
	int n, m, a, b, ssum = 0;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &s[i]);
		s[i] += s[i - 1];
	}
	while (m-- > 0) {
		int sum = 0;
		scanf("%d %d", &a, &b);
		sum = s[b] - s[a - 1];
		printf("%d\n", sum);
	}
}
