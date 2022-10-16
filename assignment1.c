#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning(disable:4996)

int length;

int findKthSmallest(int *list, int n, int k);
int *buildList(int n, int min, int max);
void writeList(int *list);
void downHeap(int *list, int n, int i);
void inPlaceHeapSort(int *list, int n, int k);
void upHeap(int *list, int i);
/*
int main(void) {
    clock_t start, end;
    int *list; // buildList로 만들어지는 1D배열인 int형 포인터 list
    int *test_list; // findKthSmallest 함수를 사용할 때, list원형을 쓰기 위해 list로부터 memmove를 통해 복사받는 test_list
    int output[4];
    int karray[4] = {1, 100, 99900, 99999};
    int e;
    double t;
    srand(time(NULL));

    list = buildList(10, 1, 100); // build a list size 10
    writeList(list); // write 10 elements in 1 lines

    for (int k = 1; k <= 3; k++) { // mini test runs
        test_list = (int *)malloc(sizeof(int) * (length + 1));
        memmove(test_list, list, sizeof(int) * (length + 1)); // 최근의 buildList를 통해 만들어진 배열을 쓰기 위해 memmove를 통해 배열 복사
        output[k] = findKthSmallest(test_list, 10, k);
        printf(" [k is %d, answer is %d] ", k, output[k]); // write 3 elements in 1 line
        free(test_list);
    }
    printf("\n");

    free(list);
    list = buildList(100000, 1, 1000000); // build a list of size 100,000

    for (int k = 0; k <= 3; k++) { // mini test runs
        test_list = (int *)malloc(sizeof(int) * (length + 1));
        memmove(test_list, list, sizeof(int) * (length + 1)); // 최근의 buildList를 통해 만들어진 배열을 쓰기 위해 memmove를 통해 배열 복사
        start = clock();
        e = findKthSmallest(test_list, 100000, karray[k]);
        end = clock();
        t = (double)(end - start);
        printf(" [e[%d] is %d, t is %.6f] ", k, e, (t / CLOCKS_PER_SEC)); // write 4 elements in 1 line
        free(test_list);
        printf("\n");
    }
    free(list);
    return (0);
}

int findKthSmallest(int *list, int n, int k) {
    inPlaceHeapSort(list, n, k); // inPlaceHeapSort를 통해 list[n - k + 1]의 k번째 smallest 값을 도출한다.
    return list[n - k + 1];
}

int *buildList(int n, int min, int max) { // buildList에서 upHeap을 통해 오름차순 무순위배열을 만든다.
    int *arr = (int *)malloc(sizeof(int) * n + 1);
    length = 0; // 전역변수 length를 통해 초기 배열의 길이를 알아낸다.
    for (int i = 1; i < n + 1; i++) {
        arr[i] = (rand() % (max - min)) + min;
        upHeap(arr, i);
        length++;
    }
    return (arr);
}

void writeList(int *list) { // List의 요소들을 출력한다.
    for (int i = 1; i < length + 1; i++) {
        printf(" %d",list[i]);
    }
    printf("\n");
}

void inPlaceHeapSort(int *list, int n, int k) {
	int tmp;
    int T = n; // 변수 T에 기존 n의 값을 저장하여

	for (int i = n; i >= T - k + 1; i--) { // T - k + 1까지 list의 첫 값을 가장 뒤로 보내고 오름차순 정렬을 시행한다.
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

void downHeap(int *list, int n, int i) { // 기존의 downHeap 함수를 오름차순으로 바꾸었다.
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

void upHeap(int *list, int i) { // 기존의 upHeap함수를 오름차순으로 바꾸었다.
    if (i <= 1) return ;
    else if (list[i] < list[i / 2]) {
        int tmp = list[i];
        list[i] = list[i / 2];
        list[i / 2] = tmp;
        upHeap(list, i / 2);
    }
}*/