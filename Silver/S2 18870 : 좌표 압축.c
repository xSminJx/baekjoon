#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int index, data;
}axis;
axis s[1000001];
int stc;

int compare(const void* a, const void* b) {
	axis* ax1 = (axis*)a;
	axis* ax2 = (axis*)b;
	if (stc) return ax1->index - ax2->index;
	else return ax1->data - ax2->data;
}

int main(void) {
	int n, in = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &s[i].data);
		s[i].index = i;
	}
	qsort(s, n, sizeof(axis), compare);
	stc++;

	for (int i = 1; i <= n; i++) {
		if (s[i - 1].data == s[i].data) s[i - 1].data = in;
		else s[i - 1].data = in++;
	}
	qsort(s, n, sizeof(axis), compare);

	for (int i = 0; i < n; i++) printf("%d ", s[i].data);

	return 0;
}
