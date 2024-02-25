#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int a;
	char b[21];
}ssn;
ssn Sn[100000];

char si[100000][21];

int compare(const void* a, const void* b) {
	ssn* str1 = (ssn*)a;
	ssn* str2 = (ssn*)b;
	return strcmp(str1->b, str2->b);
}

int main(void) {
	int n, m;
	char input[21];
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%s", Sn[i].b);
		strcpy(si[i], Sn[i].b);
		Sn[i].a = i;
	}
	qsort(Sn, n, sizeof(ssn), compare);

	for (int i = 0; i < m; i++) {
		scanf("%s", input);
		if (input[0] < 65) {
			int num = atoi(input);
			printf("%s\n", si[num - 1]);
		}
		else {
			int l = 0, r = n, mid;
			while (l <= r) {
				mid = (l + r) / 2;
				if (strcmp(Sn[mid].b, input) == 0) {
					printf("%d\n", Sn[mid].a + 1);
					break;
				}
				else if (strcmp(Sn[mid].b, input) > 0) {
					r = mid;
				}
				else l = mid;
			}
		}
	}
	return 0;
}
