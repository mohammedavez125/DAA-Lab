#include<stdio.h>
#include<math.h>

void nqueens(int n, int x[], int k) {
    if (k == n + 1) {
        for (int i = 1; i <= n; i++, printf("\n"))
            for (int j = 1; j <= n; j++)
                printf("%c ", (x[i] == j) ? 'Q' : 'X');
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++) {
        int valid = 1;
        for (int j = 1; j < k; j++)
            if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
                valid = 0;
                break;
            }
        if (valid) {
            x[k] = i;
            nqueens(n, x, k + 1);
        }
    }
}

int main() {
    int n, x[10] = {0};
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    nqueens(n, x, 1);
    return 0;
}
