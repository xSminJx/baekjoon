#include <stdio.h>

typedef struct {
	int z, o;
}twin;
twin s[41];

void fib(int N) {
	if (s[N].z == 0 && s[N].o == 0) {
		if (s[N - 1].z == 0 && s[N - 1].o == 0) {
			fib(N - 1);
		}
		s[N].z = s[N - 1].z + s[N - 2].z;
		s[N].o = s[N - 1].o + s[N - 2].o;
	}
}

int main(void) {
	int t, n;
	scanf("%d", &t);

	s[0].z = 1, s[0].o = 0;
	s[1].z = 0, s[1].o = 1;

	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		fib(n);
		printf("%d %d\n", s[n].z, s[n].o);
	}

	return 0;
}
