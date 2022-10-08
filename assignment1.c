#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning(disable:4996)

int length;

int findKthSmallest(int *list, int n, int k);
int *buildList(int n, int min, int max);
void downHeap(int *list, int n, int i);
void inPlaceHeapSort(int *list, int n, int k);
void upHeap(int *list, int i);

int main(void) {
    srand(time(NULL));
    int *list;
    list = buildList(10, 1, 100);
    
    for (int i = 1; i < length + 1; i++) {
        printf(" %d",list[i]);
    }

    for (int i = 1; i <= 3; i++) {
        int *test_list = (int *)malloc(sizeof(int) * (length + 1));
        memmove(test_list, list, sizeof(int) * (length + 1));
        printf("\n %d \n",findKthSmallest(test_list, 10, i));
        free(test_list);
    }
    printf("\n");
    for (int i = 1; i < length + 1; i++) {
        printf(" %d",list[i]);
    }
    //findKthSmallest(list, 10, 2);
    //findKthSmallest(list, 10, 3);

    free(list);
    //list = buildList(100000, 1, 1000000);

    //free(list);
    return (0);
}

int findKthSmallest(int *list, int n, int k) {
    inPlaceHeapSort(list, n, k);
    return list[n - k + 1];
}

int *buildList(int n, int min, int max) {
    int *arr = (int *)malloc(sizeof(int) * n + 1);
    length = 0;
    for (int i = 1; i < n + 1; i++) {
        arr[i] = (rand() % (max - min)) + min;
        upHeap(arr, i);
        length++;
    }
    return (arr);
}

void inPlaceHeapSort(int *list, int n, int k) {
	int tmp;
    int T = n;

	for (int i = n; i >= T - k + 1; i--) {
		tmp = list[1];
		list[1] = list[i];
		list[i] = tmp;
        n--;  
		downHeap(list, n, 1);
	}
    if (T == k && list[1] < list[2]) {
        tmp = list[1];
        list[1] = list[2];
        list[2] = tmp;
    }
}

void downHeap(int *list, int n, int i) {
    if (i * 2 >= n) return ;
    if (list[i * 2] < list[(i * 2) + 1]) {
        if (list[i] > list[i * 2]) {
            int tmp = list[i];
            list[i] = list[i * 2];
            list[i * 2] = tmp;
            downHeap(list, n, i * 2);
        }
    }
    else {
        if (list[i] > list[(i * 2) + 1]) {
            int tmp = list[i];
            list[i] = list[(i * 2) + 1];
            list[(i * 2) + 1] = tmp;
            downHeap(list, n, (i * 2) + 1);
        }
    }
}

void upHeap(int *list, int i) {
    if (i <= 1) return ;
    else if (list[i] < list[i / 2]) {
        int tmp = list[i];
        list[i] = list[i / 2];
        list[i / 2] = tmp;
        upHeap(list, i / 2);
    }
}