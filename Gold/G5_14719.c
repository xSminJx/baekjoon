#include <stdio.h>

int main() {
    int h, w, sum = 0;
    scanf("%d %d", &h, &w);
    int W[501] = { 0 };
    for (int i = 0; i < w; i++) {       // 배열에 블록 높이 입력
        int a = 0;
        scanf("%d", &a);
        W[i] = a;
    }
    for (int i = 0; i < h; i++) {       // 빗물 계산
        int n = 0,tmp=0;
        for (int j = 0; j < w; j++) {
            if (n==0) {
                if (W[j] > i) n = 1;
            }
            else if (n == 1) {
                if (W[j] <= i) {
                    n = 2;
                    tmp++;
                }
            }
            else if (n == 2) {
                if (W[j] <= i) {
                    n = 2;
                    tmp++;
                }
                else if (W[j] > i) {
                    n = 1;
                    sum += tmp;
                    tmp = 0;
                }
            }
        }
    }
    printf("%d", sum);
    return 0;
}