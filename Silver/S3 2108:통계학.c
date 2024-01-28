#include <stdio.h>
#include <stdlib.h>

int Compare(int* a, int* b) {
	return *a - *b;
}

int Mean(double Sum, int N) {
	if (Sum > 0) {
		return (int)((Sum / N) + 0.5) / 1;
	}
	else if (Sum == 0) {
		return 0;
	}
	else {
		return (int)((Sum / N) - 0.5) / 1;
	}
}

int main(void) {
	int n, ss[8001] = { 0 }, max = 0, mod, stc2 = 0;
	double sum = 0;
	scanf("%d", &n);
	int* s = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &s[i]);
		sum += s[i];
		ss[s[i] + 4000]++;
	}
	for (int i = 0; i < 8001; i++) {
		max = (ss[i] > max) ? ss[i] : max;
	}
	for (int i = 0; i < 8001; i++) {
		if (ss[i] == max) stc2++;
	}
	for (int i = 0; i < 8001; i++) {
		static int stc = 0;
		if (stc2 != 1) {
			if (ss[i] == max && stc == 1) {
				mod = i - 4000;
				break;
			}
			else if (ss[i] == max) {
				stc = 1;
			}
		}
		else {
			if (ss[i] == max) {
				mod = i - 4000;
				break;
			}
		}
	}

	qsort(s, n, sizeof(int), Compare);
	printf("%d\n%d\n%d\n%d", Mean(sum, n) / 1, s[n / 2], mod, s[n - 1] - s[0]);

	free(s);
	return 0;
}
