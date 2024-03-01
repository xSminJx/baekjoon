#include <stdio.h>

int s[1000][1000], queue[1000000][2], n, m, day = 1, left, right;

void bfs(int a, int b, int d) {
	int abs[8] = { a,a,a - 1,a + 1,b - 1,b + 1,b,b };
	for (int i = 0; i < 4; i++) {
		int x = abs[i], y = abs[i + 4]; //x, y는 체크해야 하는 좌표
		if (x < n && x >= 0 && y < m && y >= 0) {
			if (s[x][y] == -1) {
				s[x][y] = d;
				queue[right][0] = x, queue[right][1] = y;
				right++;
			}
		}
	}
}

void act() {
	int stc = right;
	for (int i = left; i < stc; i++) {
		bfs(queue[i][0], queue[i][1], day);
		queue[i][0] = queue[i][1] = 0;
		left++;
	}

	if (left < right) {
		day++;
		act(left, right);
	}
	else return;
}

int main(void) {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int o = 0; o < m; o++) {
			scanf("%d", &s[i][o]);
			if (s[i][o] == 2) {
				s[i][o] = 0;
				queue[right][0] = i, queue[right][1] = o;
				right++;
			}
			else if (s[i][o] == 1) {
				s[i][o] = -1;
			}
		}
	}

	act();
	for (int i = 0; i < n; i++) {
		for (int o = 0; o < m; o++) {
			printf("%d ", s[i][o]);
		}
		printf("\n");
	}


	return 0;
}
