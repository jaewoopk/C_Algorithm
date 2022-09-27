#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int H[100];
int n = 1;

void insertItem(int key);
int removeMax();
void upHeap(int i);
void downHeap(int i);
void printHeap();

int main(void) {
    int k;
    while (1) {
        char ch;
        scanf("%c",&ch);
        getchar();
        switch (ch)
        {
        case 'i' :
            scanf("%d",&k);
            getchar();
            insertItem(k);
            break;
        
        case 'd' :
            printf("%d\n",removeMax());
            break;

        case 'p' :
            printHeap();
            break ;
        case 'q' :
            exit(0);
        }
    }
    return (0);
}

void insertItem(int key) {
    H[n] = key;
    upHeap(n);
    n++;
    printf("0\n");
}

int removeMax() {
    int tmp = H[1];
    H[1] = H[n - 1];
    H[n - 1] = 0;
    downHeap(1);
    n--;
    return (tmp);
}

void upHeap(int i) {
    if (i <= 1) return ;
    else if (H[i] > H[i / 2]) {
        int tmp = H[i];
        H[i] = H[i / 2];
        H[i / 2] = tmp;
        upHeap(i / 2);
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