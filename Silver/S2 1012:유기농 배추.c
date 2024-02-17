#include <stdio.h>

typedef struct {
	int plant, worm;
}ground;
ground s[52][52];
int stc = 0;

void Initialize(int a, int b) {
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			s[i][j].plant = s[i][j].worm = 0;
		}
	}
}

void worm(int a, int b) {
	if (s[a][b].plant == 1 && s[a][b].worm == 0) {
		s[a][b].worm = 1;
		worm(a + 1, b);
		worm(a - 1, b);
		worm(a, b + 1);
		worm(a, b - 1);
	}
}

void Check(int a, int b) {
	if (s[a][b].plant == 1 && s[a][b].worm == 0) {
		stc++;
		worm(a, b);
	}
}

int main(void) {
	int t, x, y;
	scanf("%d", &t);
	Initialize(52, 52);

	for (int j = 0; j < t; j++) {
		int m, n, k;
		scanf("%d %d %d", &n, &m, &k);//m=행 n=열
		for (int i = 0; i < k; i++) {
			scanf("%d %d", &y, &x);//x=행 y=열
			s[x + 1][y + 1].plant = 1;
		}

		for (int i = 1; i < m + 1; i++) {
			for (int o = 1; o < n + 1; o++) {
				Check(i, o);
			}
		}
		printf("%d\n", stc);
		stc = 0;
		Initialize(m + 1, n + 1);
	}

	return 0;
}
