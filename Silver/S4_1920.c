#include <stdio.h>
#include <stdlib.h>

int compare(const int* a, const int* b) {
    if (*(int*)a > *(int*)b)
        return 1;
    if (*(int*)a == *(int*)b)
        return 0;
    return -1;
}
int N[100000], M[100000];
int main() {
    int n, m, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &N[i]);
    scanf("%d", &m);
    for (i = 0; i < m; i++) scanf("%d", &M[i]);
    qsort(N, n, sizeof(int), compare);
    for (int j = 0; j < m; j++) {
        int l = 0, r = n - 1;
        for (i = 0; i < 32; i++) {
            int mid = (l + r) / 2;
            if (M[j] == N[0] || M[j] == N[n - 1]) {
                printf("%d\n", 1);
                break;
            }
            else if (M[j] > N[n - 1] || M[j] < N[0]) {
                printf("%d\n", 0);
                break;
            }
            if (M[j] == N[mid]) {
                printf("%d\n", 1);
                break;
            }
            else if (M[j] > N[mid]) l = mid + 1;
            else r = mid - 1;
        }
        if (i == 32) printf("%d\n", 0);
    }
    return 0;
}
