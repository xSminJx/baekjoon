#include <stdio.h>

int main(void) {
	int t, m,day;
	long long n;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%lld %d", &n, &m);
		for (day = 2; n < m; day++) n += day / 2;
		printf("%d\n", day-2);
	}
	return 0;
}
