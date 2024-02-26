#include <stdio.h>
#include <stdlib.h>

int compare(const char* a, const char* b) {
	return strcmp(a, b);
}

char a[500000][21], b[500000][21], c[500000][21];
int main(void) {
	int n, m, impmid = 0, cindex = 0, cnt = 0;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) scanf("%s", &a[i]);
	for (int i = 0; i < m; i++) scanf("%s", &b[i]);
	qsort(a, n, sizeof(a[0]), compare);
	qsort(b, m, sizeof(b[0]), compare);

	for (int i = 0; i < m; i++) {
		int l = impmid, r = m, mid;
		while (l <= r) {
			mid = (l + r) / 2;
			if (strcmp(a[i], b[mid]) == 0) {
				impmid = mid;
				strcpy(c[cindex], b[mid]);
				cindex++;
				cnt++;
				break;
			}
			else if (strcmp(a[i], b[mid]) > 0) l = mid + 1;
			else if (strcmp(a[i], b[mid]) < 0) r = mid - 1;
		}
	}

	printf("%d\n", cnt);
	for (int i = 0; i < cindex; i++) printf("%s\n", c[i]);

	return 0;
}
