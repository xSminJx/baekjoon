#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)

bool compare(int& a, int& b) {
	return a > b; // 음수들 내림차순 정렬
}

int main() {
	fastio;
	int n;
	cin >> n;
	vector<int> a; // 양수 값
	vector<int> b; // 음수 값

	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp < 0) b.push_back(temp);
		else a.push_back(temp);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), compare);

	//투 포인터 씀
	int aidx = 0, bidx = 0, mn = INT_MAX, mna = 0, mnb = 0;
	while (aidx != a.size() && bidx != b.size()) {
		if (mn > abs(a[aidx] + b[bidx])) {
			mn = abs(a[aidx] + b[bidx]);
			mna = a[aidx], mnb = b[bidx];
		}
		if (a[aidx] > abs(b[bidx])) bidx++;
		else if (a[aidx] < abs(b[bidx])) aidx++;
		else aidx++, bidx++;
	}

	// 한 종류만 들어왔을 경우
	if (a.size() == 0) mna = b[0], mnb = b[1];
	else if (b.size() == 0) mna = a[0], mnb = a[1];

	// 한 종류만 쓰는 게 더 나은 경우
	else {
		if (mn > abs(a[0] + a[1])) {
			mn = abs(a[0] + a[1]);
			mna = a[0], mnb = a[1];
		}
		if (mn > abs(b[0] + b[1])) mna = b[0], mnb = b[1];
	}

	cout << min(mna, mnb) << " " << max(mna, mnb);
	return 0;
}
