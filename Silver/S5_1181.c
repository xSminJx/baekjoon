#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char c[50];
	int len;
}string;

int compare(const void* a, const void* b) {
	const string* str1 = (const string*)a;
	const string* str2 = (const string*)b;
	if (str1->len != str2->len) return str1->len - str2->len;
	return strcmp(str1->c, str2->c);
}

int main(void) {
	int N;
	scanf("%d", &N);
	string* s = (string*)malloc(sizeof(string) * N);
	
	for (int i = 0; i < N; i++) {
		scanf("%s", s[i].c);
		s[i].len = strlen(s[i].c);
	}
	qsort(s, N, sizeof(string), compare);

	for (int i = 0; i < N-1; i++) {
		if (strcmp(s[i].c, s[i + 1].c) == 0) s[i].c[0] = '\0';
	}

	for (int i = 0; i < N; i++) {
		if (s[i].c[0] != '\0') printf("%s\n", s[i].c);
	}

	free(s);
	return 0;
}
