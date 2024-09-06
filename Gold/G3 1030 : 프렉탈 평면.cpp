#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cout.tie(0)
int s, n, k, r1, r2, c1, c2;

// a, b가 프랙탈의 중심(1인 부분) 에 있는지 검사
bool incenter(int a, int b) {
	return (n - k) / 2 <= a && a < (n + k) / 2 && (n - k) / 2 <= b && b < (n + k) / 2;
}

bool getint(int i, int j, int time) {
	if (time == 0) return 0; // 시간이 0이면 흰 정사각형이니 0 반환
	int nlen = pow(n, time - 1); // 시간이 t일 때, 작은 정사각형의 한 변의 길이(큰 변을 n으로 나눈 값)
	int a = i / nlen, b = j / nlen; // i, j가 정사각형의 어느 작은 정사각형에 있는지

	if (time == 1) return incenter(a, b); // 시간이 1초일 때, 당연히 a, b가 센터면 1이고 아니면 0이다.
	else if (incenter(a, b)) return 1; // 당연히 검은색이니 1 반환
	else return getint(i % nlen, j % nlen, time - 1); // a, b가 센터에 위치 하지 않았으면 그 작은 정사각형에 대해 다시 검사. 
}

int main() {
	fastio;

	cin >> s >> n >> k >> r1 >> r2 >> c1 >> c2;

	for (int i = r1; i <= r2; i++) {
		for (int j = c1; j <= c2; j++) {
			cout << getint(i, j, s);
		}
		cout << '\n';
	}
	return 0;
}
