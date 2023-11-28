#include<stdio.h>

int s[50][50];
int main(void) {
    int n, m, i, j,mx=0;
    scanf("%d %d", &n,&m);
    getchar();
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            s[i][j] = getchar();
        }
        getchar();
    }
    
    for (;;) {
        static int a=0, b=0;
        int stcw = 0, stcb = 0,imx;
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                if ((i + j) % 2 == 0) {
                    if (s[a + i][b + j] == 'W') stcw++;
                    else if (s[a + i][b + j] == 'B') stcb++;
                }
                else {
                    if (s[a + i][b + j] == 'B') stcw++;
                    else if (s[a + i][b + j] == 'W') stcb++;
                }
            }
        }
        imx = (stcw > stcb) ? stcw : stcb;
        mx = (mx > imx) ? mx : imx;
        b++;
        if (a==n-7) {
            break;
        }
        else if (b == m - 7) {
            a++;
            b = 0;
        }
    }
    printf("%d", 64-mx);
    return 0;
}
