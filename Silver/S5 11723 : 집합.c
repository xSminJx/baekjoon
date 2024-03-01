#include <stdio.h>
#include <string.h>

int main(void) {
	int m, s[21] = { 0 }, a;
	char com[10];
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%s", com);
		if (!strcmp(com, "add")) {
			scanf("%d", &a);
			s[a] |= 1;
		}
		else if (!strcmp(com, "remove")) {
			scanf("%d", &a);
			s[a] &= 0;
		}
		else if (!strcmp(com, "check")) {
			scanf("%d", &a);
			printf("%d\n", s[a]);
		}
		else if (!strcmp(com, "toggle")) {
			scanf("%d", &a);
			s[a] ^= 1;
		}
		else if (!strcmp(com, "all")) {
			for (int i = 1; i < 21; i++) s[i] |= 1;
		}
		else if (!strcmp(com, "empty")) {
			for (int i = 1; i < 21; i++) s[i] &= 0;
		}
	}
}
