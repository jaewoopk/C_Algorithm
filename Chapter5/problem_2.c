#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)

int n;

void printArr();
void inPlaceQuickSort(int *array, int l, int r);
int inPlacePartion(int *array, int l, int r, int k);
int findPivot(int *array, int l, int r);

int main(void) {
    srand(time(NULL));
    scanf(" %d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf(" %d", arr + i);
    }
    inPlaceQuickSort(arr, 0, n - 1);
    printArr(arr);
    exit(0);
    return (0);
}

void printArr(int *array) {
    for (int i = 0; i < n; i++) {
        printf(" %d",array[i]);
    }
}

void inPlaceQuickSort(int *array, int l, int r) {
    if (l >= r)
        return ;
    int k, a, tmp;

    k = findPivot(array, l, r);
    a = inPlacePartion(array, l, r, array[k]);
    tmp = array[k];
    array[k] = array[a];
    array[a] = tmp;
    inPlaceQuickSort(array, l, a - 1);
    inPlaceQuickSort(array, a + 1, r);
}

int findPivot(int *array, int l, int r) {
    return (rand() % (r - l) + l);
}

int inPlacePartion(int *array, int l, int r, int k) {
    int tmp;
    if (l >= r) {
        return r;
    }

    if (array[l] <= k && array[r] <= k) {
        l++;
    }
    else if (array[l] <= k && array[r] > k) {
        l++;
        r--;
    }
    else if (array[l] > k && array[r] <= k) {
        tmp = array[l];
        array[l] = array[r];
        array[r] = tmp;
        l++;
        r--;
    }
    else if (array[l] > k && array[r] > k) {
        r--;
    }
    return inPlacePartion(array, l, r, k);
}