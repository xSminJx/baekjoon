#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int main(void) {
	int N, M;
	scanf("%d", &N);
	int* s = (int*)malloc(sizeof(int) * N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &s[i]);
	}
	qsort(s, N, sizeof(int), compare);

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		int temp;
		scanf("%d", &temp);
		int left = 0, right = N - 1, mid, mid1, mid2, stc = 1;

		while (left <= right) {
			mid = (right + left) / 2;
			if (s[mid] < temp) {
				left = mid + 1;
			}
			else if (s[mid] > temp) {
				right = mid - 1;
			}
			else {
				stc = 0;
				break;
			}
		}

		if (stc) {
			printf("%d ", 0);
			continue;
		}

		left = 0, right = N - 1;
		while (left <= right) {
			mid1 = (right + left) / 2;
			if (s[mid1] < temp) {
				left = mid1 + 1;
			}
			else if (s[mid1] >= temp) {
				if (s[mid1 - 1] < temp) break;
				right = mid1 - 1;
			}
		}

		left = 0, right = N - 1;
		while (left <= right) {
			mid2 = (right + left) / 2;
			if (s[mid2] <= temp) {
				if (s[mid2 + 1] > temp) break;
				left = mid2 + 1;
			}
			else if (s[mid2] > temp) {
				right = mid2 - 1;
			}
		}
		printf("%d ", mid2 - mid1 + 1);
	}

	free(s);
	return 0;
}
