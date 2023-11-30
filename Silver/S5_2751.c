#include <stdio.h>
#include <stdlib.h>

int compare(const int* a, const int* b) {
    return(*a - *b);
}
int s[1000000] = { 0 };
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        s[i] = a;
    }
    qsort(s, n, sizeof(int), compare);
    for (int i = 0; i < n; i++) {
        printf("%d\n", s[i]);
    }
    return 0;
}
