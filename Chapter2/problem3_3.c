#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)

void select(int *arr, int idx);
void insertion(int *arr, int idx);

int main(void) {
	int n;
	int *A,*B;

	srand(time(NULL));
	scanf("%d",&n);

	A = (int *)malloc(sizeof(int) * n);
	B = (int *)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		A[i] = n - i;
		B[i] = n - i;
	}
	clock_t start, end;
    double result;
 
    start = clock();
 
    for (int i = 0 ; i < n; i++) {
		select(A, n - i - 1);
	}

    end = clock();
    result = (double)(end - start);
    printf("%.9lfms\n", result / CLOCKS_PER_SEC); //결과 출력

    start = clock();

	for (int i = 0; i < n - 1; i++) {
		insertion(B, i  + 1);
	}

    end = clock();

    result = (double)(end - start);
    printf("%.9lfms\n", result / CLOCKS_PER_SEC); //결과 출력

	free(A);
	free(B);
	return 0;
}

void select(int *arr, int idx) {
	int max = arr[0], id = 0, tmp;
	for (int i = 0; i <= idx; i++) {
		if (arr[i] > max) {
			max = arr[i];
			id = i;
		}
	}
	tmp = arr[idx];
	arr[idx] = arr[id];
	arr[id] = tmp;
}

void insertion(int *arr, int idx) {
	int save = arr[idx];
    int i;
	for (i = idx - 1; i >= 0 && arr[i] > save; i--) {
		arr[i + 1] = arr[i];
	}
    arr[i + 1] = save;
}