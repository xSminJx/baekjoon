#include <iostream>
#include <queue>
using namespace std;

int isfound = 0;
vector<int> sec(100001); // 방문까지 걸린 시간
vector<int> visit(100001); // 방문한 횟수
queue<int> qu;

void checknpush(int a, int b, int k) {
	if ((0 <= b && b <= 100000 && (visit[b] == 0 || sec[b] - 1 == sec[a]))) { // 이미 b에 방문한 적이 있어도 새롭게 방문한 시간이 기존 시간과 같을 때
		if (b == k) {
			sec[b] = sec[a] + 1;
			visit[b]++;
			isfound = 1;
		}
		else {
			sec[b] = sec[a] + 1, visit[b]++;
			if (isfound == 0) qu.push(b); // k에 방문했었으면 큐에 그만 넣는다
		}
	}
}

int main() {
	int n, k;
	cin >> n >> k;

	qu.push(n);
	sec[n] = 0;
	visit[n] = 1;

	while (!qu.empty()) {
		int a = qu.front();
		qu.pop();

		checknpush(a, a - 1, k);
		checknpush(a, a + 1, k);
		checknpush(a, a * 2, k);
	}

	cout << sec[k] << '\n' << visit[k];
	return 0;
}
