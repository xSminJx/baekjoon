#include <stdio.h>

char s[397];
int max_index, stc = 1;

void star(int l, int r) {
	if (stc) {
		if (s[l] == ' ' || s[l] == 0) for (int i = l; i <= r; i++) s[i] = '*';
		else if (s[l] == '*') for (int i = l; i <= r; i++) s[i] = ' ';
	}
	else {
		if (s[l] == ' ' || s[l] == 0) for (int i = l; i <= r; i++) s[i] = ' ';
		else if (s[l] == '*') for (int i = l; i <= r; i++) s[i] = '*';
	}
	printf("%s\n", s);

	if (l == r || stc == 0) {
		stc = 0;
		return;
	}
	if (stc) star(l + 1, r - 1);
	star(l, r);
}

int main(void) {
	int n, lindex, rindex;
	scanf("%d", &n);
	lindex = 0, max_index = rindex = 4 * (n - 1);
	star(lindex, rindex);
	return 0;
}
