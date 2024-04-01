#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int o = 0; o < t; o++) {
		int n, stc = 1;
		cin >> n;
		vector<string> v;
		vector<int> cnt;
		string a, str;

		for (int i = 0; i < n; i++) {
			cin >> a >> str;
			for (int j = 0; j < v.size(); j++) {
				if (v[j] == str) {
					cnt[j]++;
					break;
				}
				else if (j == v.size() - 1) {
					v.push_back(str);
					cnt.push_back(1);
					break;
				}
			}
			if (v.size() == 0) {
				v.push_back(str);
				cnt.push_back(1);
			}
		}
		for (auto i : cnt) stc *= i + 1;
		cout << stc - 1 << endl;
	}
	return 0;
}
