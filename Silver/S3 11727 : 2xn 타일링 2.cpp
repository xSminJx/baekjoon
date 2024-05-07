#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(3);
	v[1] = 1, v[2] = 3;
	for (int i = 3; i <= n; i++) v.push_back((v[i - 1] + v[i - 2] * 2) % 10007);
	cout << v[n];	
	return 0;
}
