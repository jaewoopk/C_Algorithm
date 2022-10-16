#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#pragma warning(disable:4996)

int n = 100000;
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
void arrayCopy(int *dest, int *src);

int main(void) {
    clock_t start, end;
    int *arr = createArray();
    srand(time(NULL));
    printf("Limit\t결정적1\t\t결정적3\t\t무작위1\t\t무작위3\n");
    for (int i = 0; i < 4; i++) {
        int *test_arr = (int *)malloc(sizeof(int) * n); // test_arr을 통해 quickSort 진행
        printf("%d\t",Limits[i]);
        for (int j = 0; j < 4; j++) {
            arrayCopy(test_arr, arr);
            start = clock();
            quickSort(test_arr, i, j);
            end = clock();
            printf("%.8lf\t",((double)end - (double)start) / CLOCKS_PER_SEC); // 시간 재기
        }
        printf("\n");
        free(test_arr);
    }
    free(arr);
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
    rQuickSort(array, 0, n - 1, i, m); // i는 Limits의 index를, m은 mode의 index를 나타낸다.
    if (Limits[i] > 1) { // Limits가 1일 때는 Quicksort만, 1이 아닐 때는 선택정렬과 혼합한다.
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
    if (mode[m] == 'a') // 결정적 1
        return (r);
    if (mode[m] == 'c') // 무작위 1
        return ((rand() % (r - l) + l));
    if (r - l == 1)
        return (l);
    
    int a, b, c;

    switch (mode[m]) {
    case 'b': // 결정적 3
        a = l;
        b = (l + r) / 2;
        c = r;
        break;
    
    case 'd': // 무작위 3
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
    if (r - l >= Limits[i]) { // r - l 이 Limits[i]보다 크거나 같을 경우만 작동하여
        if (l >= r)           // 어느 정도 정렬이 이루어진 상태에서 선택정렬을 혼합한다.
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

void insertionSort(int *array, int idx) { // 선택정렬
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

void arrayCopy(int *dest, int *src) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}