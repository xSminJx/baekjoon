#include <stdio.h>

int top, stc = 1;
char s[5] = { 0,'A','B','C','D' };

void FloorN(int a, int b, int c) {
	if (a <= 0) return;
	else if (a == 1 && top == 1) {
		printf("%c %c\n", s[b], s[4]);
		top--;
	}

	if (stc && top >= 3) {
		stc = 0;
		FloorN(a - 2, b, c);
	}
	else if (stc == 0) {
		if (a > 1) FloorN(a - 1, b, 6 - (b + c));
		printf("%c %c\n", s[b], s[c]);
		if (a > 1) FloorN(a - 1, 6 - (b + c), c);
	}

	if (a == top) {
		printf("%c %c\n", s[b], s[6 - (b + c)]);
		printf("%c %c\n", s[b], s[4]);
		printf("%c %c\n", s[6 - (b + c)], s[4]);
		top -= 2;
		stc = 1;
		if (top <= 0) return;
		else if (top == 1) printf("%c %c\n", s[c], s[4]);
		else FloorN(a - 2, c, b);
	}
}

int pow2(int a) {
	if (a == 0) return 1;
	return 2 * pow2(a - 1);
}

int main(void) {
	int n, cnt = 0;
	scanf("%d", &n);
	top = n;
	if (n == 3) printf("%d\n", 5);
	else if (n == 2) printf("%d\n", 3);
	else if (n == 1) printf("%d\n", 1);
	else {
		for (int i = n - 2; i > 1; i -= 2) {
			cnt += pow2(i) + 2;
			if (i == 3) cnt += 5;
			else if (i == 2) cnt += 3;
		}
		printf("%d\n", cnt);
	}
	FloorN(n, 1, 3);
	return 0;
}
