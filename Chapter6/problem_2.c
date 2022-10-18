#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int n, k, ans;

void FindFirst(int *array);

int main(void) {
    int mid, l, r;
    scanf(" %d %d",&n, &k);
    ans = n;

    int *arr = (int *)malloc(sizeof(n));
    for (int i = 0; i < n; i++) {
        scanf(" %d",arr + i);
    }
    l = 0;
    r = n;
    while (1) {
        if (l > r) {
            break ;
        }
        mid = (l + r) / 2;
        if (arr[mid] == k) {
            ans = mid;
            break ;
        }
        else if (arr[mid] < k) {
            l = mid + 1;
        }
        else if (arr[mid] > k) {
            r = mid - 1;
        }
    }
    if (l > n) ans = n;
    else ans = l;
    FindFirst(arr);
    printf(" %d",ans);
    free(arr);
    return (0);
}

void FindFirst(int *array) {
    if (k <= array[0])
        ans = 0;
}

// 8 44
// -92 -31 -7 4 14 20 29 44