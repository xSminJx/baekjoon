#include <stdio.h>
#include <math.h>

int main(void) {
    int t, n, x1, x2, y1, y2, x, y, r;
    double st, ed;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int sum = 0;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            scanf("%d %d %d",&x,&y,&r);
            st = sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
            ed = sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
            if (st < r) {
                if (ed > r) sum++;
            }
            else if (st > r) {
                if (ed < r) sum++;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
