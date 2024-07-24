#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string str1, str2;
	cin >> str1 >> str2;
	int s1 = str1.size(), s2 = str2.size();
	vector<vector<int>> v(s1 + 1, vector<int>(s2 + 1));

	for (int i = 0; i < s1; i++) v[i][0] = 0;
	for (int i = 0; i < s2; i++) v[0][i] = 0;

	for (int i = 1; i <= s1; i++) {
		for (int j = 1; j <= s2; j++) {
			if (str1[i - 1] == str2[j - 1]) v[i][j] = v[i - 1][j - 1] + 1;
			else v[i][j] = max(v[i - 1][j], v[i][j - 1]);
		}
	}
	cout << v[s1][s2];
	return 0;
}
