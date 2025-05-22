#include <stdio.h>

int main() {
    int N, K;

    while (1) {
        scanf("%d %d", &N, &K);
        if (N == 0 && K == 0) break;

        int freq[101] = {0}; // P varia de 1 a 100
        for (int i = 0; i < N; i++) {
            int p;
            scanf("%d", &p);
            freq[p]++;
        }

        int frequentes = 0;
        for (int i = 1; i <= 100; i++) {
            if (freq[i] >= K) {
                frequentes++;
            }
        }

        printf("%d\n", frequentes);
    }

    return 0;
}
