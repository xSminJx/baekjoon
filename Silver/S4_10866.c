#include <stdio.h>
#include <string.h>

char c[11];
int Check() {
	scanf("%s", &c);
	if (strcmp(c, "push_front") == 0) return 1;
	else if (strcmp(c, "push_back") == 0) return 2;
	else if (strcmp(c, "pop_front") == 0) return 3;
	else if (strcmp(c, "pop_back") == 0) return 4;
	else if (strcmp(c, "size") == 0) return 5;
	else if (strcmp(c, "empty") == 0) return 6;
	else if (strcmp(c, "front") == 0) return 7;
	else if (strcmp(c, "back") == 0) return 8;
}

int main(void) {
	int N, a, s[20001] = { 0 };
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		static int first=10000, last=9999;
		switch (Check()) {
		case 1:
			scanf("%d", &a);
			s[--first] = a;
			break;
		case 2:
			scanf("%d", &a);
			s[++last] = a;
			break;
		case 3:
			if (first - last == 1) printf("%d\n", -1);
			else {
				printf("%d\n", s[first]);
				s[first++] = 0;
			}
			break;
		case 4:
			if (first - last == 1) printf("%d\n", -1);
			else {
				printf("%d\n", s[last]);
				s[last--] = 0;
			}
			break;
		case 5:
			printf("%d\n", last - first + 1);
			break;
		case 6:
			if (first - last == 1) printf("%d\n", 1);
			else printf("%d\n", 0);
			break;
		case 7:
			if (first - last == 1) printf("%d\n", -1);
			else printf("%d\n", s[first]);
			break;
		case 8:
			if (first - last == 1) printf("%d\n", -1);
			else printf("%d\n", s[last]);
			break;
		}
	}
	return 0;
}
