#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int H[100];
int n = 1;

void buildHeap();
void downHeap(int i);
void printHeap();

int main(void) {
    scanf("%d",&n);
    n++;
    for (int i = 1; i < n; i++) {
        scanf(" %d",&H[i]);
    }

    buildHeap();
    printHeap();
    return (0);
}

void buildHeap() {
    for (int i = n / 2; i > 0; i--) {
        downHeap(i);
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

void printHeap() {
    if (n <= 1) return ;
    for (int i = 1; i < n; i++) {
        printf(" %d",H[i]);
    }
    printf("\n");
}
// 8↦ 키 개수
// 5 15 10 20 30 25 31 29