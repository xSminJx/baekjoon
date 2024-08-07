#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int maxdp[3], mindp[3], buffer1[3], buffer2[3];

	cin >> buffer1[0] >> buffer1[1] >> buffer1[2];
	for (int i = 0; i < 3; i++) buffer2[i] = buffer1[i];

	for (int i = 1; i < n; i++) {
		cin >> maxdp[0] >> maxdp[1] >> maxdp[2];
		for (int i = 0; i < 3; i++) mindp[i] = maxdp[i];
		
		maxdp[0] += max(buffer1[0], buffer1[1]);
		maxdp[1] += max({ buffer1[0], buffer1[1],buffer1[2] });
		maxdp[2] += max(buffer1[1], buffer1[2]);

		mindp[0] += min(buffer2[0], buffer2[1]);
		mindp[1] += min({ buffer2[0], buffer2[1],buffer2[2] });
		mindp[2] += min(buffer2[1], buffer2[2]);

		for (int j = 0; j < 3; j++) {
			buffer1[j] = maxdp[j];
			buffer2[j] = mindp[j];
		}
	}

	cout << max({ buffer1[0],buffer1[1],buffer1[2] }) << " " << min({ buffer2[0],buffer2[1],buffer2[2] });
	return 0;
}
