#include <stdio.h>

int s[1000000] = { -1 };

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i <= n; i++) {
        if (i + 1 <= 1000000 && (s[i + 1] == 0 || s[i + 1] > s[i])) {
            s[i + 1] = s[i] + 1;
        }
        if (i * 2 <= 1000000 && (s[i * 2] == 0 || s[i * 2] > s[i])) {
            s[i * 2] = s[i] + 1;
        }
        if (i * 3 <= 1000000 && (s[i * 3] == 0 || s[i * 3] > s[i])) {
            s[i * 3] = s[i] + 1;
        }
	}
	printf("%d", s[n]);
	return 0;
}
