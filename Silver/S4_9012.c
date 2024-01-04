#include <stdio.h>

int main(void) {
	int T, i;
	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		int stc = 0, ans = 0;
		char s[51] = {'\0'};
		scanf("%s", &s);
		for (int j = 0; j < 51; j++) {
			if (s[j] == '(') {
				stc++;
			}
			else if (s[j] == ')') {
				stc--;
				if (stc == -1) {
					ans = 1;
					break;
				}
			}
			else break;
		}
		if (stc != 0) ans = 1;
		if (ans == 1) printf("NO\n");
		else if (ans == 0) printf("YES\n");
	}
	return 0;
}
