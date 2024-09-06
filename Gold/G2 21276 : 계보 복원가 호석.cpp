#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)

class node {
public:
	string name;
	int cnt = 0;
	vector<int> next;
	vector<int> wktlr;
};

bool compare(node& a, node& b) {
	return a.name < b.name;
}

//이름 넣으면 인덱스 반환해줌
int search(string target, vector<node>& v) {
	int l = 0, r = v.size() - 1, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (v[mid].name < target) l = mid + 1;
		else if (v[mid].name > target) r = mid - 1;
		else return mid;
	}
}

int main() {
	fastio;
	int n, m;
	cin >> n;
	vector<node> v(n);
	vector<int> rkans;
	queue<int> qu;

	for (int i = 0; i < n; i++) cin >> v[i].name;
	sort(v.begin(), v.end(), compare);

	//조상의 next랑 후손의 cnt
	cin >> m;
	while (m--) {
		string a, b;
		cin >> a >> b;
		int aidx = search(a, v), bidx = search(b, v);
		v[bidx].next.push_back(aidx);
		v[aidx].cnt++;
	}

	//조상이 없으면 큐랑 가문에 넣음
	for (int i = 0; i < n; i++) {
		if (v[i].cnt == 0) qu.push(i), rkans.push_back(i);
	}

	//위상 정렬을 통해 자식을 찾는다(어떤 사람의 바로 앞의 사람이 부모이기 때문)
	while (!qu.empty()) {
		int cur = qu.front();
		qu.pop();

		for (auto i : v[cur].next) {
			v[i].cnt--;
			if (v[i].cnt == 0) {
				v[cur].wktlr.push_back(i);
				qu.push(i);
			}
		}
	}

	cout << rkans.size() << endl;
	for (auto i : rkans) cout << v[i].name << " ";
	cout << endl;
	for (auto i : v) {
		cout << i.name << " " << i.wktlr.size() << " ";
		sort(i.wktlr.begin(), i.wktlr.end());
		for (auto j : i.wktlr) cout << v[j].name << " ";
		cout << endl;
	}
	return 0;
}
