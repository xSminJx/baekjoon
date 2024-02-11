#include <stdio.h>

int main(void) {
	char c;

	while (1) {
		int slast = 0, stc = 0;
		char s[101] = { '\0' }, ss[102];
		fgets(ss, sizeof(ss), stdin);
		for (int i = 0; i < sizeof(ss); i++) {
			c = ss[i];
			if (c == '.' && i == 0) return 0;
			else if (c == '.' || c == '\n') {
				if (slast == 0) stc = 1;
				break;
			}

			if (c == '(' || c == '[') s[slast++] = c;
			else if ((c == ')' || c == ']') && slast == 0) break;
			else if (c == ')' && s[--slast] != '(') break;
			else if (c == ']' && s[--slast] != '[') break;
		}
		if (stc) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
