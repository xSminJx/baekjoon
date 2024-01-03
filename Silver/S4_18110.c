#include<stdio.h>
#include<stdlib.h>

int roundnum(double a) {
    a += 0.5;
    a = (int)a / 1;
    return a;
}
int compare(const int* a, const int* b) {
    return (*a - *b);
}
int s[300000];
int main(void) {
    int n, i,j;
    scanf("%d", &n);
    if (n == 0) {
        printf("%d", 0);
        return 0;
    }
    double nn = n * 0.15, sum = 0;
    for (i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        s[i] = a;
    }
    qsort(s, n, sizeof(int),compare);
    for (i = roundnum(nn); i < n - roundnum(nn); i++) {
        sum += s[i];
    }
    sum /= (n - 2 * roundnum(nn));
    printf("%d", roundnum(sum));
    return 0;
}
