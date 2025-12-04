#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, target;
        scanf("%d", &n);
        scanf("%d", &target);

        int a[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        int mn = INT_MAX;
        for (int i = 0; i < n; i++) {
            int j = i + 1, k = n - 1;
            // Applied 2 Sum
            int sum = -1;
            while (j < k) {
                sum = a[i] + a[j] + a[k];
                if (target > sum) {
                    j++;
                } else if (target < sum) {
                    k--;
                }
                mn = mn > abs(target - sum) ? abs(target - sum) : mn;
            }
            if (target == sum) {
                printf("0\n");
                break;
            }
        }
        printf("%d\n", mn==INT_MAX ? -1 : mn);
    }
    return 0;
}
