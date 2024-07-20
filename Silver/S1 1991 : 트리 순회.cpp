#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class node {
public:
	char name, l = '.', r = '.';
};

void a(int k, vector<node>& v) {
	cout << v[k].name;
	if (v[k].l != '.') a(v[k].l - 65, v);
	if (v[k].r != '.') a(v[k].r - 65, v);
}

void b(int k, vector<node>& v) {
	if (v[k].l != '.') b(v[k].l - 65, v);
	cout << v[k].name;
	if (v[k].r != '.') b(v[k].r - 65, v);
}

void c(int k, vector<node>& v) {
	if (v[k].l != '.') c(v[k].l - 65, v);
	if (v[k].r != '.') c(v[k].r - 65, v);
	cout << v[k].name;
}

int main() {
	int n;
	cin >> n;
	vector<node> v(27);
	for (int i = 0; i < n; i++) {
		char root, left, right;
		cin >> root >> left >> right;
		int k = root - 65;
		v[k].name = root;
		v[k].l = left;
		v[k].r = right;

	}
	a(0, v);
	cout << endl;
	b(0, v);
	cout << endl;
	c(0, v);
	return 0;
}
