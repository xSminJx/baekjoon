#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {
	int N, K, i=0;
	scanf("%d %d", &N, &K);
	int* s = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &s[i]);
	}

	int left = 1, right = INT_MAX, mid;

	while (1) {
		mid = left + (right - left) / 2;
		int sum = 0, sum2 = 0;

		for (int j = 0; j < N; j++) {
			sum += (s[j] / mid);
			sum2 += s[j] / (mid + 1);
		}
		if (sum >= K) {
			if (sum2 < K) break;
			left = mid + 1;
		}
		else if (sum < K) {
			right = mid - 1;
		}
	}
	printf("%d", mid);

	free(s);
	return 0;
}
