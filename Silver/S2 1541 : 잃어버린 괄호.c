#include <iostream>
using namespace std;

int main() {
	int sum = 0, n = 0, plus_stc = 1;
	char s[52];
	cin >> s;

	for (int i = 0;; i++) {
		if (s[i] == '\0') {
			s[i] = '+';
			s[i + 1] = '\0';
			break;
		}
	}

	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] >= '0') {
			n *= 10;
			n += s[i] - 48;
		}
		else if (s[i] == '+' || s[i] == '-') {
			if (plus_stc) sum += n;
			else sum -= n;

			if (s[i] == '-') if (plus_stc) plus_stc = 0;
			n = 0;
		}
	}

	cout << sum << endl;
	return 0;
}
