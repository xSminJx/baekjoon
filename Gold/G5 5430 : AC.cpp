#include <iostream>
using namespace std;

char com[100001];
int s[100000];

int main() {
	int t, n;
	cin >> t;

	for (int k = 0; k < t; k++) {
		cin >> com >> n;
		int l = 0, r = n - 1, sidx = 0, s_reverse = 0, a = 0; //s_reverse가 0이면 정순, 1이면 역순

		for (int i = 0;; i++) {
			char c;
			cin >> c;
			if (c == ']') {
				if (a) s[sidx++] = a;
				break;
			}
			if (48 <= c && c <= 57) {
				a *= 10;
				a += c - 48;
			}
			else {
				if (a) s[sidx++] = a;
				a = 0;
			}
		}

		for (int i = 0; com[i] != '\0'; i++) {
			if (com[i] == 'R') s_reverse ^= 1;
			else if (com[i] == 'D') {
				if (!s_reverse) l++;
				else r--;
			}
		}

		if (r + 1 == l) {
			cout << "[]" << endl;
			continue;
		}
		else if (l > r) {
			cout << "error" << endl;
			continue;
		}

		cout << "[";
		if (s_reverse) {
			for (int i = r; i >= l; i--) {
				if (i == l) cout << s[i];
				else printf("%d,", s[i]);
			}
		}
		else {
			for (int i = l; i <= r; i++) {
				if (i == r) cout << s[i];
				else printf("%d,", s[i]);
			}
		}
		cout << "]" << endl;
	}

	return 0;
}
