#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int OD(int num) {
	return 2 * num % 10000;
}
int OS(int num) {
	if (num == 0) return 9999;
	return num - 1;
}
int OL(int num) {
	int d[4];
	for (int i = 3; i >= 0; i--) {
		d[i] = num % 10;
		num /= 10;
	}
	return d[1] * 1000 + d[2] * 100 + d[3] * 10 + d[0];
}
int OR(int num) {
	int d[4];
	for (int i = 3; i >= 0; i--) {
		d[i] = num % 10;
		num /= 10;
	}
	return d[3] * 1000 + d[0] * 100 + d[1] * 10 + d[2];
}

bool bfs(int num1, int num2, queue<int>& qu, vector<int>& v, vector<string>& vs) {
	if (num1 == num2) return 1;
	int o[4] = { OD(num1),OS(num1),OL(num1),OR(num1) };
	string s[4] = { "D","S","L","R" };
	for (int i = 0; i < 4; i++) {
		if (v[o[i]] == 0) {
			qu.push(o[i]);
			v[o[i]] = 1;
			vs[o[i]] = vs[num1] + s[i];
		}
	}
	return 0;
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num1, num2;
		cin >> num1 >> num2;

		queue<int> qu;
		vector<int> v(10000, 0);
		vector<string> vs(10000);
		qu.push(num1);
		v[num1] = 1;
		int qs = 1;
		while (qs != 0) {
			qs = qu.size();
			for (int j = 0; j < qs; j++) {
				if (bfs(qu.front(), num2, qu, v, vs)) {
					cout << vs[qu.front()] << endl;
					qs = 0;
					break;
				}
				qu.pop();
			}
		}
	}
	return 0;
}
