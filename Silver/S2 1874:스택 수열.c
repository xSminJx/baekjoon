#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, stclen = -1, qstlen = 0, anslen = -1;
	scanf("%d", &n);
	int* stack = (int*)malloc(sizeof(int) * n);
	int* qst = (int*)malloc(sizeof(int) * n);
	char* ans = (char*)malloc(sizeof(char) * n * 2);

	for (int i = 0; i < n; i++) scanf("%d", &qst[i]);
	for (int i = 1; i <= n; i++) {
		stack[++stclen] = i;
		ans[++anslen] = '+';

		while (stack[stclen] == qst[qstlen]) {
			stclen--;
			qstlen++;
			ans[++anslen] = '-';
			if (stclen < 0) break;
		}
	}

	if (stclen == -1) {
		for (int i = 0; i < 2 * n; i++) {
			printf("%c\n", ans[i]);
		}
	}
	else printf("NO");


	free(stack);
	free(qst);
	free(ans);
	return 0;
}
