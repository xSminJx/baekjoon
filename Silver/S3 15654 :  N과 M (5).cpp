#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void fun(int n, int m, vector<int> v, string str) {
	if (m == 0) cout << str << '\n';
	else for (int i = 0; i < v.size(); i++) {
		vector<int> a = v;
		a.erase(a.begin() + i);
		fun(n, m - 1, a, str + to_string(v[i]) + " ");
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	fun(n, m, v, "");
	return 0;
}
