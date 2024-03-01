#include <stdio.h>

typedef struct {
	int rec, edge[101], index;
}arr;
arr s[101];

void Dfs(int a) {
	if (s[a].rec == 0) s[a].rec = 1;
	for (int i = 0; i < s[a].index; i++) {
		if (s[s[a].edge[i]].rec != 1) {
			Dfs(s[a].edge[i]);
		}
	}
}

int main(void) {
	int n, m, sum = -1;
	scanf("%d %d", &n, &m);
	s[1].rec = 1;

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		s[a].edge[s[a].index++] = b;
		s[b].edge[s[b].index++] = a;
	}

	Dfs(1);

	for (int i = 1; i <= n; i++) {
		if (s[i].rec) sum++;
	}

	printf("%d", sum);
	return 0;
}
