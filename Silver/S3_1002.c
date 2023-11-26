#include <stdio.h>
#include <math.h>

int main(void) {
	int n, a, x1, y1, r1, x2, y2, r2;
	double C,C2;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int b;
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		C2 = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
		C = sqrt(C2);
		b = (r1 < r2) ? r1 : r2;
		if (r2 > r1) {
			r1 = r2;
			r2 = b;
		}
		if (C > r1) {
			if (C > r1 + r2) a = 0;
			else if (C == r1 + r2) a = 1;
			else a = 2;
		}
		else if (C <= r1) {
			if (C + r2 < r1) a = 0;
			else if (C + r2 == r1) a = 1;
			else a = 2;
		}
		if (x1 == x2 && y1 == y2 && r1 == r2) a = -1;
		printf("%d\n", a);
	}
	return 0;
}
