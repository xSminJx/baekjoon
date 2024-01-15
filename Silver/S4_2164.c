#include <stdio.h>
#include <stdlib.h>

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
		static int stc = 0;
		if (stc == 0) {
			s[lfirst++] = 0;
			if (lfirst == N) lfirst -= N;
			stc++;
		}
		else if (stc == 1) {
			if (llast+1 == N) {
				llast -= N-1;
				s[llast] = s[lfirst];
				s[lfirst++] = 0;
			}
			else {
				s[++llast] = s[lfirst];
				s[lfirst++] = 0;
			}
			if (lfirst == N) lfirst -= N;
			stc--;
		}
	}
	printf("%d\n", s[lfirst]);
	free(s);
	return 0;
}
