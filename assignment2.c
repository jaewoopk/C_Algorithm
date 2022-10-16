#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#pragma warning(disable:4996)

int n = 10;
int Limits[] = {1, 100, 500, 1000};
char mode[] = {'a', 'b', 'c', 'd'};

int *createArray();
void printArr();
void quickSort(int *array, int i, int m);
void rQuickSort(int *array, int l, int r, int i, int m);
void insertionSort(int *array, int idx);
int inPlacePartion(int *array, int l, int r, int k);
int findPivot(int *array, int l, int r, int m);
int findIndexOfMedianOfThree(int a, int b, int c);
void swap(int *array, int i, int j);

int main(void) {
    clock_t start, end;
    int e;
    double t;
    int *arr = createArray();
    srand(time(NULL));

    for (int i = 0; i < 4; i++) {
        int *test_arr;
        for (int j = 0; j < 4; j++) {
            memcpy(test_arr, arr, sizeof(int) * (n + 1));
            start = clock();
            quickSort(test_arr, i, j);
            end = clock();

            t = (double)(end - start);
            printf(" [clock is %d, t is %.6f] ", e, (t / CLOCKS_PER_SEC)); // write 4 elements in 1 line
            
        }
    }
    exit(0);
    return (0);
}

int *createArray() {
    int *newArray = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        newArray[i] = rand() % (n * 30 - 1) + 1;
    }
    return newArray;
}

void quickSort(int *array, int i, int m) {
    rQuickSort(array, 0, n - 1, i, m);
    if (Limits[i] > 1) {
        for (int j = 0; j < n - 1; j++) {
            insertionSort(array, j + 1);
        }
    }
}

void printArr(int *array) {
    for (int i = 0; i < n; i++) {
        printf(" %d",array[i]);
    }
}

int findPivot(int *array, int l, int r, int m) {
    if (mode[m] == 'a')
        return (r);
    if (mode[m] == 'c')
        return ((rand() % (r - l) + l));
    if (r - l == 1)
        return (l);
    
    int a, b, c;

    switch (mode[m]) {
    case 'b':
        a = l;
        b = (l + r) / 2;
        c = r;
        break;
    
    case 'd':
        a = rand() % (r - l) + l;
        b = rand() % (r - l) + l;
        c = rand() % (r - l) + l;
        break;
    }
    return (findIndexOfMedianOfThree(a, b, c));
}

int inPlacePartion(int *array, int l, int r, int pivot) {
    int tmp;
    if (l > r) {
        return r;
    }

    if (array[l] <= pivot && array[r] <= pivot) {
        l++;
    }
    else if (array[l] <= pivot && array[r] > pivot) {
        l++;
        r--;
    }
    else if (array[l] > pivot && array[r] <= pivot) {
        tmp = array[l];
        array[l] = array[r];
        array[r] = tmp;
        l++;
        r--;
    }
    else if (array[l] > pivot && array[r] > pivot) {
        r--;
    }
    return inPlacePartion(array, l, r, pivot);
}

void rQuickSort(int *array, int l, int r, int i, int m) {
    if (r - l >= Limits[i]) {
        if (l >= r)
            return ;
        int k, a, b;
        
        k = findPivot(array, l, r, m);
        swap(array, l, k);
        a = b = inPlacePartion(array, l, r, array[l]);
        swap(array, l, a);
        rQuickSort(array, l, a - 1, i, m);
        rQuickSort(array, b + 1, r, i, m);
    }
}

void insertionSort(int *array, int idx) {
	int save = array[idx];
    int i;
	for (i = idx - 1; i >= 0 && array[i] > save; i--) {
		array[i + 1] = array[i];
	}
    array[i + 1] = save;
}

int findIndexOfMedianOfThree(int a, int b, int c) {
    return (a + b + c) / 3;
}

void swap(int *array, int i, int j) {
    int tmp;

    tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}