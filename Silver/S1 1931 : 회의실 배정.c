#include <stdio.h>
#include <stdlib.h>

int s[100000][2];

int compare(const void* a, const void* b) {
	int* as = (int*)a;
	int* bs = (int*)b;
	if (as[1] != bs[1]) return as[1] - bs[1];
	return as[0] - bs[0];
}

int main(void) {
	int n, cnt = 0, first = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &s[i][0], &s[i][1]);
	}
	qsort(s, n, sizeof(s[0]), compare);

	for (int i = 0; i < n; i++) {
		if (s[i][0] >= first) {
			first = s[i][1];
			cnt++;
		}
	}

	printf("%d", cnt);
	return 0;
}
