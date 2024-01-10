#include <stdio.h>
#include <stdlib.h>

struct info {
	int age;
	char name[101];
};

int compare(const void* a, const void* b) {
	const struct info* i1 = (const struct info*)a;
	const struct info* i2 = (const struct info*)b;
	return i1->age - i2->age;
}

int main(void) {
	int N;
	scanf("%d", &N);
	struct info *s = (struct info*)malloc(sizeof(struct info) * N);

	if (s == NULL) {
		fprintf(stderr, "메모리 할당 실패\n");
		return 1; // 메모리 할당에 실패한 경우 오류 처리
	}

	for (int i = 0; i < N; i++) {
		scanf("%d", &s[i].age);
		scanf("%s", &s[i].name);
	}
	
	qsort(s, N, sizeof(struct info), compare);
	
	for (int i = 0; i < N; i++) {
		printf("%d %s\n", s[i].age, s[i].name);
	}
	free(s);
	return 0;
}
