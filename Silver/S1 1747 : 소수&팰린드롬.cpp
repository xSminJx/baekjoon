#include <iostream>
#include <string>
using namespace std;

bool fal(int a) {
	string str = to_string(a);
	for (int i = 0; i < str.size()/2; i++) {
		if (str[i] != str[str.size() - 1 - i]) return 0;
	}
	return 1;
}

bool prime(int a) {
	for (int i = 2; i * i <= a; i++) {
		if (a % i == 0) return 0;
	}
	return 1;
}

int main() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << 2;
		return 0;
	}

	for (int i = n;; i++) {
		if (fal(i)&&prime(i)){
			cout << i;
			break;
		}
	}
	return 0;
}
