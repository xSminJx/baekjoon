#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> v(106, 0);  // 방문
vector<int> vs(106, 0); // 주사위 횟수

bool bfs(int num1, int num2, queue<int>& qu, vector<int>& in, vector<int>& out) {
	if (num1 == num2) return 1; // num1 = 현재 지점, num2 = 목표 지점
	int o[6] = { 1,2,3,4,5,6 }; // 가능한 주사위 눈금(필요없긴함)

	for (int i = 0; i < 6; i++) {
		if (num1 + o[i] > num2) break; // 배열 범위 검사
		if (v[num1 + o[i]] == 0) {
			auto it = find(in.begin(), in.end(), num1 + o[i]); // num1+o[i]가 뱀이나 사다리의 시작점인지 확인(아니면 it = in.end())
			int k;

			if (it != in.end()) { // num1+o[i]가 뱀, 사다리의 시작점일 때
				v[num1 + o[i]] = 1;
				k = out[it - in.begin()]; // k = 뱀, 사다리를 타고 도착한 지점
				if (v[k] == 1) continue;
			}
			else k = num1 + o[i]; // num1+o[i]가 뱀, 사다리의 시작점이 아닐 때

			qu.push(k);
			v[k] = 1;
			vs[k] = vs[num1] + 1; // 주사위 횟수 기록
		}
	}
	return 0;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> in(n + m); // 뱀, 사다리의 출발점
	vector<int> out(n + m); // 뱀, 사다리의 도착점

	for (int i = 0; i < n + m; i++) {
		cin >> in[i] >> out[i];
	}

	queue<int> qu;

	qu.push(1);
	v[1] = 1;
	int qs = 1;
	while (qs != 0) {
		qs = qu.size();
		for (int j = 0; j < qs; j++) {
			if (bfs(qu.front(), 100, qu, in, out)) { // qu.front()가 100일 때 = v[100]에 값이 들어있을 때 실행됨
				cout << vs[100] << endl;
				return 0;
			}
			qu.pop();
		}
	}

	return 0;
}
