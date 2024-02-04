#include <stdio.h>

int s[100000] = { 0 };

int main(void) {
	int n, a, slast = 0, sum = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a);

		if (a) s[slast++] = a;
		else s[--slast] = 0;
	}
	for (int i = 0; i < slast; i++) {
		if (s[i]) sum += s[i];
	}
	printf("%d", sum);
	return 0;
}
