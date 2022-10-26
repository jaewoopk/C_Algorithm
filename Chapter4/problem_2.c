#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int H[100];
int n;
int T;

void buildHeap();
void inPlaceHeapSort();
void downHeap(int i);
void printArray();

int main(void) {
    scanf("%d",&n);
    n++;
    for (int i = 1; i < n; i++) {
        scanf(" %d",&H[i]);
    }

    buildHeap();
    inPlaceHeapSort();
    printArray();
    return (0);
}

void buildHeap() {
    for (int i = n / 2; i > 0; i--) {
        downHeap(i);
    }
}

void inPlaceHeapSort() {
	int tmp;
    n--;
    T = n;

	for (int i = n; i > 1; i--) {
		tmp = H[1];
		H[1] = H[i];
		H[i] = tmp;
        n--;  
		downHeap(1);
	}
    if (H[1] > H[2]) {
        tmp = H[1];
        H[1] = H[2];
        H[2] = tmp;
    }
}

void downHeap(int i) {
    if (i * 2 >= n) return ;
    if (H[i * 2] > H[(i * 2) + 1]) {
        if (H[i] < H[i * 2]) {
            int tmp = H[i];
            H[i] = H[i * 2];
            H[i * 2] = tmp;
            downHeap(i * 2);
        }
    }
    else {
        if (H[i] < H[(i * 2) + 1]) {
            int tmp = H[i];
            H[i] = H[(i * 2) + 1];
            H[(i * 2) + 1] = tmp;
            downHeap((i * 2) + 1);
        }
    }
}

void printArray() {
    if (T <= 1) return ;
    for (int i = 1; i <= T; i++) {
        printf(" %d",H[i]);
    }
    printf("\n");
}


// 8↦ 키 개수
// 31 10 10 20 31 31 31 10