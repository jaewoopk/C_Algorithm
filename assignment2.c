#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#pragma warning(disable:4996)

int n = 100000;
int Limits[] = {1, 100, 500, 1000};
char *mode[] = {"deterministic1", "deterministic3",
                "randomized1", "randomized3"};

int *createArray();
void printArr();
void printCPUtime();
void quickSort(int *array);
void rQuickSort(int *array, int l, int r);
void inPlaceQuickSort(int *array, int l, int r);
int inPlacePartion(int *array, int l, int r, int k);
int findPivot(int *array, int l, int r);
int findIndexOfMedianOfThree(int a, int b, int c);
void swap(int *array, int i, int j);

int main(void) {
    srand(time(NULL));
    int *arr = createArray();

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int *test_arr;
            memmove(test_arr, arr, sizeof(int) * (n + 1));
            quickSort(test_arr);
            printCPUtime();
            mode++;
        }
        Limits++;
        mode -= 4;
    }
    exit(0);
    return (0);
}

int *createArray() {
    int *newArray = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        newArray[i] = rand() % (n - 1) + 1;
    }
    return newArray;
}

void printArr(int *array) {
    for (int i = 0; i < n; i++) {
        printf(" %d",array[i]);
    }
}

void inPlaceQuickSort(int *array, int l, int r) {
    if (l >= r)
        return ;
    
    int k, a, b, tmp;

    k = findPivot(array, l, r);
    a = b = inPlacePartion(array, l, r, array[k]);
    tmp = array[k];
    array[k] = array[a];
    array[a] = tmp;
    inPlaceQuickSort(array, l, a - 1);
    inPlaceQuickSort(array, b + 1, r);
}

int findPivot(int *array, int l, int r) {
    if (*mode == "deterministic1")
        return (r);
    if (*mode == "randomized1")
        return ((rand() % (r - l) + l));
    if (r - l == 1)
        return (l);
    
    int a, b, c;

    switch (*mode) {
    case "deterministic3":
        a = l;
        b = (l + r) / 2;
        c = r;
        break;
    
    case "randomized3":
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

void quickSort(int *array) {
    rQuickSort(array, 0, n - 1);
    if (*Limits > 1) {
        for (int i = 0; i < *Limits - 1; i++) {
            insertionSort(array, i + 1);
        }
    }
    return ;
}

void rQuickSort(int *array, int l, int r) {
    if (r - l >= *Limits) {
        int k, a, b, tmp;

        k = findPivot(array, l, r);
        a = b = inPlacePartion(array, l, r, array[k]);
        tmp = array[k];
        array[k] = array[a];
        array[a] = tmp;
        inPlaceQuickSort(array, l, a - 1);
        inPlaceQuickSort(array, b + 1, r);
    }
}

void printCPUtime() {

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
    return a;
}

void swap(int *array, int i, int j) {
    int tmp;

    tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}