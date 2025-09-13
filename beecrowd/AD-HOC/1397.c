#include <stdio.h>

int main() {
    int n = 0;
    while (scanf("%d", &n) != EOF && n != 0) {
        int ptsa = 0, ptsb = 0;
        for (int i = 0; i < n; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            if (a > b) {
                ptsa++;
            } else if (b > a) {
                ptsb++;
            }
        }
        printf("%d %d\n", ptsa, ptsb);
    }
    return 0;
}
