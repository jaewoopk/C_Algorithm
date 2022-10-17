#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int n, k, ans = -1;

void rFindElement(int *array, int l, int r);
void FindLast(int *array);

int main(void) {
    scanf(" %d %d",&n, &k);
    
    int *arr = (int *)malloc(sizeof(n));
    for (int i = 0; i < n; i++) {
        scanf(" %d",arr + i);
    }
    rFindElement(arr, 0, n);
    FindLast(arr);
    printf(" %d",ans);
    free(arr);
    return (0);
}

void rFindElement(int *array, int l, int r) {
    if (l > r) {
        return ;
    }
    int mid = (l + r) / 2;

    if (array[mid] <= k && k < array[mid + 1]) {
        ans = mid;
        return ;
    }
    else if (array[mid] < k) {
        rFindElement(array, mid + 1, r);
    }
    else if (array[mid] > k) {
        rFindElement(array, l, mid - 1);
    }
}

void FindLast(int *array) {
    if (k >= array[n - 1])
        ans = n - 1;
}

// 8 55
// -92 -31 -7 4 14 20 29 44