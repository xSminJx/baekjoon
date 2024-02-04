#include <stdio.h>

typedef struct {
	int weight, height;
}info;

int main(void) {
	int n;
	info s[50];
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &s[i].weight, &s[i].height);
	}

	for (int i = 0; i < n; i++) {
		int stc = 1;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (s[i].weight < s[j].weight && s[i].height < s[j].height) {
				stc++;
			}
		}
		printf("%d ", stc);
	}

	return 0;
}
