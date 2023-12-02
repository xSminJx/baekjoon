#include <stdio.h>

int main() {
    int x, a = 64, sum = 64, n = 1;
    scanf("%d", &x);
    while (sum > x) {
        a /= 2;
        n++;
        if (sum - a >= x) {
            sum -= a;
            n--;
        }
    }
    printf("%d", n);
    return 0;
}
