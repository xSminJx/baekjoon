#include <iostream>
#include <string>
using namespace std;

void fun(int n, int m, int k, string str) {
	if (m == 0) cout << str << '\n';
	else for (int i = k; i <= n; i++) {
		fun(n, m - 1, i, str + to_string(i) + " ");
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	fun(n, m, 1, "");
	return 0;
}
