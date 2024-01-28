#include <stdio.h>

int main(void) {
	int n, stc5 = 0, a;
	scanf("%d", &n);
	
	for (int i = 1; i < n + 1; i++) {
		a = i;
		while (a % 5 == 0) {
			a /= 5;
			stc5++;
		}
	}

	printf("%d",stc5);
	return 0;
}
