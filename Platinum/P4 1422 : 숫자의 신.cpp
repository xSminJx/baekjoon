#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(string& a, string& b) {
	return a + b > b + a;
}

int main() {
	int k, n;
	cin >> k >> n;
	vector<string> v(k);
	for (int i = 0; i < k; i++) cin >> v[i];
	sort(v.begin(), v.end(), compare);

	auto a = max_element(v.begin(), v.end(),
		[](const std::string& a, const std::string& b) {
			if (a.size() == b.size()) {
				return a < b;
			}
			return a.size() < b.size();
		});

	for (int i = 0; i < k; i++) {
		cout << v[i];
		if (v[i] == *a && (i == k - 1 || (i != k - 1 && v[i] != v[i + 1]))) {
			for (int j = 0; j < n - k; j++) cout << v[i];
		}
	}

	return 0;
}
