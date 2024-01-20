#include <stdio.h>
#include <stdlib.h>

void Move(int* idx, const int k, const int len) {
	*idx = (*idx + k) % len;
}

int Pop(int idx, int* ss) {
	int a = ss[idx];
	ss[idx] = 0;
	return a;
}

void Sort(int* ss, int len) {
	for (int i = 0; i < len-1; i++) {
		if (ss[i] == 0) {
			int temp = ss[i + 1];
			ss[i] = ss[i + 1];
			ss[i + 1] = 0;
		}
	}
}

int main(void) {
	int N, K;
	scanf("%d %d", &N, &K);
	int* s = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) s[i] = i+1;
	int slen = N;

	for (int i = 0; i < N; i++) {
		static int index = -1;
		Move(&index, K, slen);
		int temp = Pop(index, s);
		index--;
		Sort(s,slen);
		slen--;

		if (i == 0) printf("<%d", temp);
		else printf(", %d", temp);
	}
	printf(">");

	free(s);
	return 0;
}
