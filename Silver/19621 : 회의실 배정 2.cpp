#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class hh {
public:
	vector<int> hs;
	hh() {
		hs = vector<int>(3);
	}
};

bool compare(const hh& a, const hh& b) {
	return a.hs[0] < b.hs[0];
}

int main() {
	int n;
	cin >> n;
	vector<hh> v(n);

	for (auto it = v.begin(); it != v.end();it++) {
		cin >> it->hs[0] >> it->hs[1] >> it->hs[2];
	}
	sort(v.begin(), v.end(), compare);

	int mmx = 0;
	for (int i = 0; i < n; i++) {
		int mx = 0;
		for (int j = 0; j < n; j++) {
			if (v[j].hs[1] <= v[i].hs[0]) mx = max(mx, v[j].hs[2]);
		}
		v[i].hs[2] += mx;
		mmx = max(v[i].hs[2], mmx);
	}

	cout << mmx;
	return 0;
}
