#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int get_len(string a, string b) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		if (a[i] != b[i]) cnt++;
	}
	return cnt;
}

int find(vector<string>& v) {
	int min_len = 100;
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			for (int k = j + 1; k < v.size(); k++) {
				int len = get_len(v[i], v[j]) + get_len(v[i], v[k]) + get_len(v[k], v[j]);
				min_len = min(min_len, len);
			}
		}
	}
	return min_len;
}

int main() {
	int t, n;
	cin >> t;

	for (int i = 0; i < t; i++) {
		string str;
		vector<string> v;
		cin >> n;
		if (n >= 33) {
			for (int j = 0; j < n; j++) cin >> str;
			cout << 0 << endl;
		}
		else {
			for (int j = 0; j < n; j++) {
				cin >> str;
				v.push_back(str);
			}
			cout << find(v) << endl;
		}
	}
	return 0;
}
