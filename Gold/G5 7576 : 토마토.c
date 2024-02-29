#include <stdio.h>

int s[1000][1000], queue[1000000][2], n, m, cnt, day, left, right;

void bfs(int a, int b) {
	int abs[8] = { a,a,a - 1,a + 1,b - 1,b + 1,b,b };
	for (int i = 0; i < 4; i++) {
		int x = abs[i], y = abs[i + 4]; //x, y는 체크해야 하는 좌표
		if (x < n && x >= 0 && y < m && y >= 0) {
			if (s[x][y] == 0) {
				s[x][y] = 1;
				queue[right][0] = x, queue[right][1] = y;
				right++;
				cnt--;
			}
		}
	}
}

void act() {
	int stc = right;
	for (int i = left; i < stc; i++) {
		bfs(queue[i][0], queue[i][1]);
		queue[i][0] = queue[i][1] = 0;
		left++;
	}

	if (right - stc == 0 && cnt > 0) {
		day = -1;
		return;
	}
	if (right - stc > 0) {
		day++;
		act(left, right);
	}
	else return;
}

int main(void) {
	scanf("%d %d", &m, &n);
	cnt = n * m;
	for (int i = 0; i < n; i++) {
		for (int o = 0; o < m; o++) {
			scanf("%d", &s[i][o]);
			if (s[i][o] == 1) {
				queue[right][0] = i, queue[right][1] = o;
				right++;
				cnt--;
			}
			else if (s[i][o] == -1) cnt--;
		}
	}

	act();
	printf("%d", day);

	return 0;
}
