#include <iostream>
using namespace std;

int main() {
	int n;
	long long ans[3] = { 1,1,1 };
	cin >> n;

	for (int i = 2; i <= n; i++) {
		long long v = ans[0] + ans[1] + ans[2];
		ans[0] = v % 9901;
		ans[1] = (v - ans[1]) % 9901;
		ans[2] = (v - ans[2]) % 9901;
	}

	cout << (ans[0] + ans[1] + ans[2]) % 9901;
	return 0;
}
