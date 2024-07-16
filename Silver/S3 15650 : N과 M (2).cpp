#include <iostream>
#include <string>
using namespace std;

void fun(int n, int m, int k, int c, string str) {
	for (int i = c + 1; i <= n; i++) {
		string str2 = str + to_string(i) + " ";
		if (k == m) cout << str2 << endl;
		else fun(n, m, k + 1, i, str2);
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	fun(n, m, 1, 0, "");
	return 0;
}
