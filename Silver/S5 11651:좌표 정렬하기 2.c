#include <stdio.h>
#include<stdlib.h>

typedef struct {
	int x;
	int y;
}cord;

int compare(const void* a, const void* b) {
	const cord* i1 = (const cord*)a;
	const cord* i2 = (const cord*)b;
	if (i1->y != i2->y) return i1->y - i2->y;
	return i1->x - i2->x;
}

int main(void) {
	int n;
	scanf("%d", &n);
	cord* s = (cord*)malloc(sizeof(cord) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &s[i].x, &s[i].y);
	}
	
	qsort(s, n, sizeof(cord), compare);
	for (int i = 0; i < n; i++) printf("%d %d\n", s[i].x, s[i].y);

	free(s);
	return 0;
}
