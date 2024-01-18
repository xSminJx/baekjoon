#include <stdio.h>
#include <stdlib.h>

void next(int* pi, int N) {
	*pi += 1;
	if (*pi == N) *pi -= N;
}

int pop(int* pi, int* s) {
	int a = s[*pi];
	s[*pi] = 0;
	return a;
}

void insert(int* pi, int* s, int n) {
	s[*pi] = n;
}

int main(void) {
	int N, lfirst, llast;
	scanf("%d", &N);
	lfirst = 0, llast = N - 1;
	int* s = (int*)malloc(sizeof(int) * N);

	if (s == NULL) {
		fprintf(stderr, "메모리 할당 실패\n");
		return 1; // 메모리 할당에 실패한 경우 오류 처리
	}

	for (int i = 0; i < N; i++) {
		s[i] = i + 1;
	}


	while (lfirst != llast) {
		static int stc = 1;
		if (stc) {
			pop(&lfirst, s);
			next(&lfirst, N);
			stc--;
		}
		else {
			int a = pop(&lfirst, s);
			next(&lfirst, N);
			next(&llast, N);
			insert(&llast, s, a);
			stc++;
		}
	}
	printf("%d\n", s[lfirst]);
	free(s);
	return 0;
}
