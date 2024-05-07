#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	unordered_map<string, string> map;
	string str1, str2;
	for (int i = 0; i < n; i++) {
		cin >> str1 >> str2;
		map[str1] = str2;
	}

	for (int i = 0; i < m; i++) {
		cin >> str1;
		cout << map[str1] << "\n";
	}
	return 0;
}
