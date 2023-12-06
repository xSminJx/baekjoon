#include <stdio.h>

int HT(void) {
    char text[6];
    int hash=0;  // 448 335 443 559 339
    for (int i = 0; i < 6; i++) {
        char c;
        c = getchar();
        if (c != ' ' && c != '\n') {
            hash += c;
        }
        else break;
    }
    return hash;
}
int main() {
    int n, i, s[10001],stc=0;
    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++) {
        int a = HT();
        switch (a) {
        case 448:
            scanf("%d", &s[stc]);
            stc++;
            getchar();
            break;
        case 335:
            if (stc > 0) {
                printf("%d\n", s[stc - 1]);
                s[stc] = 0;
                stc--;
            }
            else printf("%d\n", -1);
            break;
        case 443:
            printf("%d\n", stc);
            break;
        case 559:
            if (stc == 0) printf("%d\n",1);
            else printf("%d\n",0);
            break;
        case 339:
            if (stc > 0)printf("%d\n", s[stc-1]);
            else printf("%d\n",-1);
            break;
        default:
            printf("뭔가 이상함!!\n");
        }
    }
    return 0;
}
