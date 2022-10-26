#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void select(int* arr, int idx) {
    int max = arr[0], id = 0, tmp;
    for (int i = 0; i <= idx; i++) {
        if (arr[i] > max) {
            max = arr[i];
            id = i;
        }
    }
    tmp = arr[idx];
    arr[idx] = arr[id];
    arr[id] = tmp;
}

int main(void) {
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    for (int i = 0; i < n; i++) {
        select(arr, n - i - 1);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }
    free(arr);
    return (0);
}

// 8
// 8 31 48 73 3 65 20 29
