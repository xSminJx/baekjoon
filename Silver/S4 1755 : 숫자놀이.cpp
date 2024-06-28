#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class str {
public:
	int num;
	string nstr;
};

bool compare(const str& a, const str& b) {
	return a.nstr < b.nstr;
}

int main() {
	int n, m, cnt = 0;
	vector<str> v;
	vector<string> numtoword{ "zero ","one ","two ","three ","four ","five ","six ","seven ","eight ","nine " };
	cin >> n >> m;

	for (int i = n; i <= m; i++) {
		string s;
		if (i >= 10) {
			s = numtoword[i / 10];
			s += numtoword[i % 10];
		}
		else s = numtoword[i];
		v.push_back({ i,s });
	}

	sort(v.begin(), v.end(), compare);
	for (auto i : v) {
		cnt++;
		cout << i.num << " ";
		if (cnt == 10) {
			cout << endl;
			cnt = 0;
		}
	}

	return 0;
}
