#include <stdio.h>
#include <string.h>

int s[10001] = { 0 };
int main(void) {
	int N, sright = 0, sleft = 0, i;
	char command[10];
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%s", &command);
		if (strcmp(command, "push") == 0) {
			int a;
			scanf("%d", &a);
			s[sright++] = a;
		}
		else if (strcmp(command, "pop") == 0) {
			if (sleft == sright) printf("%d\n", -1);
			else printf("%d\n", s[sleft++]);
		}
		else if (strcmp(command, "size") == 0) {
			printf("%d\n", sright - sleft);
		}
		else if (strcmp(command, "empty") == 0) {
			if (sleft == sright) printf("%d\n", 1);
			else printf("%d\n", 0);
		}
		else if (strcmp(command, "front") == 0) {
			if (sleft == sright) printf("%d\n", -1);
			else printf("%d\n", s[sleft]);
		}
		else if (strcmp(command, "back") == 0) {
			if (sleft == sright) printf("%d\n", -1);
			else printf("%d\n", s[sright-1]);
		}
	}
	return 0;
}
