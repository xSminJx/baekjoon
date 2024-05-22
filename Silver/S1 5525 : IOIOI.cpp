#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m, cnt = 0, stc = 0;
	cin >> n >> m;

	char first, c;
	int firidx = -1;
	for (int i = 0; i < m; i++) {
		cin >> c;
		if (stc == 0 && c == 'I') first = c, firidx = i, stc++;
		else if (stc) {
			if (firidx % 2 == i % 2 && c == 'I') stc++;
			else if (firidx % 2 != i % 2 && c == 'O') stc++;
			else if (c == 'I') stc = 1, firidx = i;
			else stc = 0;
		}
		if (stc == 2 * n + 1) cnt++, firidx += 2, stc -= 2;
	}

	cout << cnt;
	return 0;
}
