#include <iostream>
#include <queue>
using namespace std;

int main() {
	long long a, b, stc = 1, maxint = 1000000000;
	cin >> a >> b;

	queue<long long> qu;
	qu.push(a);
	int qs = qu.size();

	while (qs) {
		while (qs--) {
			long long qf = qu.front();
			if (qf == b) {
				cout << stc;
				return 0;
			}
			if (qf * 2 <= maxint) qu.push(qf * 2);
			if (qf * 10 + 1 <= maxint) qu.push(qf * 10 + 1);
			qu.pop();
		}
		stc++;
		qs = qu.size();
	}

	cout << -1;
	return 0;
}
