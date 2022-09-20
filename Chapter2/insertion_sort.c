#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void insertion(int *arr, int idx) {
	int save = arr[idx];
    int i;
	for (i = idx - 1; i >= 0 && arr[i] > save; i--) {
		arr[i + 1] = arr[i];
	}
    arr[i + 1] = save;
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