#include <iostream>
#include <vector>
#include <string>
using namespace std;

string makefal(vector<int> v) {
	string outstr;
	int rec = -1;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] % 2 == 0) v[i] = (v[i] + 1) / 2;
		else {
			v[i] /= 2;
			rec = i;
		}
		outstr.append(v[i], i + 65);
	}
	if (rec > -1) outstr.append(1, rec + 65);
	for (int i = 25; i >= 0; i--) outstr.append(v[i], i + 65);
	return outstr;
}

int main() {
	int oddcnt = 0;
	string s;
	cin >> s;
	vector<int> v(26);

	for (auto c : s) v[c - 65]++;
	for (auto i : v) {
		if (i % 2) oddcnt++;
	}

	if (s.size() % 2 && oddcnt == 1 || s.size() % 2 == 0 && oddcnt == 0) cout << makefal(v);
	else cout << "I'm Sorry Hansoo";

	return 0;
}
