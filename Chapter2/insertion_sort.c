#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void before_idx_sort(int *arr, int start, int end) {
    for (int i = end; i > start; i--) {
        arr[i] = arr[i - 1];
    }
}

void insertion(int* arr, int idx) {
    int save = arr[idx];
    for (int i = 0; i < idx; i++) {
        if (arr[idx] > arr[i]) continue;
        else {
            before_idx_sort(arr, i, idx);
            arr[i] = save;
            break ;
        }
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        insertion(arr, i + 1);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }
    free(arr);
    return (0);
}

//7
//3 73 48 31 8 11 20