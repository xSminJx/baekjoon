#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
}cord;

int compare1(const void* a, const void* b) {
	const cord* c1 = (const cord*)a;
	const cord* c2 = (const cord*)b;
	if (c1->x!=c2->x) return c1->x - c2->x;
	return c1->y - c2->y;
}

int main(void) {
	int N;
	cord s[100000];
	scanf("%d", &N);

	//구조체에 좌표 할당
	for (int i = 0; i < N; i++) scanf("%d %d", &s[i].x, &s[i].y);

	qsort(s, N, sizeof(cord), compare1);
	for (int i = 0; i < N; i++) printf("%d %d\n", s[i].x, s[i].y);

	return 0;
}
