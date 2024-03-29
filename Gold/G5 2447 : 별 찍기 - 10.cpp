#include <iostream>
#include <vector>
#include <string>
using namespace std;

int tkatodl(int a) {
	int b = 0;
	while (a > 1) {
		b++;
		a /= 3;
	}
	return 1 << b;
}

int dltoint(int a) {
	int b = 0;
	while (a > 1) {
		a /= 2;
		b++;
	}
	return b;
}

int pow3(int a) {
	if (a == 0) return 1;
	return 3 * pow3(a - 1);
}

string star(string s, int i, int n) {
	int k = tkatodl(n);
	while (i > 0) {
		if (i >= k) {
			i -= k;
			int stc = -1, k2 = pow3(dltoint(k));
			for (int a = 0; a < n; a++) {
				if (a % k2 == 0) stc++;
				if (stc == 3) stc = 0;
				if (stc == 1) s[a] = ' ';
			}
		}
		else k /= 2;
	}
	return s;
}

vector<int> output(vector<int> v, int n) {
	vector<int> outv;
	for (auto i : v) {
		outv.push_back(i * 2);
		outv.push_back(i * 2 + 1);
		outv.push_back(i * 2);
	}
	n /= 3;
	if (n == 1) return outv;
	else return output(outv, n);
}

int main() {
	int n;
	cin >> n;
	vector<string> v(tkatodl(n));
	vector<int> order(n), input{ 0 };
	v[0].append(n, '*');

	for (int i = 1; i < v.size(); i++) v[i] = star(v[0], i, n);

	order = output(input, n);
	
	for (int i = 0; i < n; i++) cout << v[order[i]] << endl;
	return 0;
}
