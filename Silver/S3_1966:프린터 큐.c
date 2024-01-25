#include <stdio.h>

typedef struct {
	int x;
	int y;
}nums;

void Move(int N, nums* ss) {
	for (int i = 0; i < N; i++) {
		*(ss + i) = *(ss + i + 1);
	}
}

int main(void) {
	int t, n, m;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		nums s[101] = { 0,0 };
		int stc = 0, top_num = 0;
		scanf("%d %d", &n, &m);

		for (int j = 0; j < n; j++) {
			scanf("%d", &s[j].x);
			s[j].y = 0;
		}
		s[m].y = 1;

		for (int i = 0; i < n; i++) {
			top_num = (top_num > s[i].x) ? top_num : s[i].x;
		}

		while (1) {
			if (s[0].x >= top_num) {
				stc++;
				if (s[0].y) {
					printf("%d\n", stc);
					break;
				}
				s[0].x = 0;
				n--;
				Move(n, s);	

				top_num = 0;
				for (int i = 0; i < n; i++) {
					top_num = (top_num > s[i].x) ? top_num : s[i].x;
				}
			}
			else {
				s[n] = s[0];
				Move(n, s);
				s[n].x = 0, s[n].y = 0;
			}
		}
	}
	return 0;
}
