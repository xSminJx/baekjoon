#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	for (int j = 0; j < t; j++) {
		cin >> n;
		vector<long long> v(max(n, 3));
		v[0] = v[1] = v[2] = 1;
		for (int i = 3; i < n; i++) {
			v[i] = v[i - 2] + v[i - 3];
		}
		cout << v[n - 1] << endl;
	}
	return 0;
}
