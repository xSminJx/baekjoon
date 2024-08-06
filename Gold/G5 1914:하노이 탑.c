#include <stdio.h>

// 하노이 탑 이동순서 출력 함수
void FloorN(int a, int b, int c) { // a = 현재 원판의 층 수, b = 시작 지점, c = 옮겨야 할 지점
	if (a > 1) FloorN(a - 1, b, 6 - (b + c)); // 일단 머리위에 있는 작은 원판을 다른데로 옮김 (6 - (b + c) = 다른데)
	printf("%d %d\n", b, c); // b에서 c로 옮겼다고 출력
	if (a > 1) FloorN(a - 1, 6 - (b + c), c); // 아까 옮겨둔 작은판을 다시 머리위에 올림
}

int intlen(int a) {
	int len = 0;
	while (a) {
		a /= 10;
		len++;
	}
	return len;
}

int main(void) {
	int n, s[5] = { 1 };
	scanf("%d", &n);

    // 이동횟수 k를 표현하기 위한 각고의 노력 (2^100은 ㅈㄴ크니깐)
	for (int i = 0; i < n; i++) {
		for (int o = 0; o < 5; o++) s[o] *= 2;
		for (int o = 0; o < 5; o++) {
			if (s[o] >= 1000000000) {
				s[o] -= 1000000000;
				s[o + 1]++;
			}
		}
	}
	s[0]--;

    // 이동횟수 k를 출력하기 위한 각고의 노력 (족같다 시발 파이썬이었으면 개날먹이었는데)
	for (int o = 3; o >= 0; o--) {
		if (s[o] == 0) continue;
		if (intlen(s[o]) == 9) printf("%d", s[o]);
		else {
			if (s[o + 1] == 0) printf("%d", s[o]);
			else {
				for (int i = 0; i < 9 - intlen(s[o]); i++) printf("0");
				printf("%d", s[o]);
			}
		}
	}

	if (n < 21) {
		printf("\n");
		FloorN(n, 1, 3);
	}
	return 0;
}
