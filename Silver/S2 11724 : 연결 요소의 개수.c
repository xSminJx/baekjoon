#include <stdio.h>

typedef struct {
	int rec, edge[1000], index;
}arr;
arr s[1001];
int cnt;

void Dfs(int a) {
	if (s[a].rec == 0) s[a].rec = 1;
	for (int i = 0; i < s[a].index; i++) {
		if (s[s[a].edge[i]].rec != 1) {
			cnt++;
			Dfs(s[a].edge[i]);
		}
	}
}

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		s[a].edge[s[a].index++] = b;
		s[b].edge[s[b].index++] = a;
	}

	for (int i = 1; i <= n; i++) {
		if (s[i].edge[0] != 0 && s[i].rec == 0) {
			Dfs(i);
		}
	}

	printf("%d", n - cnt);
	return 0;
}
