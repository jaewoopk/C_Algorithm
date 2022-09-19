#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)

void select(int *arr, int idx);
void insertion(int *arr, int idx);
void before_idx_sort(int *arr, int start, int end);

int main(void) {
	int n;
	int *A,*B;

	srand(time(NULL));
	scanf("%d",&n);

	A = (int *)malloc(sizeof(int) * n);
	B = (int *)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		A[i] = i;
		B[i] = i;
	}
	clock_t start, end;
    double result;
 
    start = clock();
 
    for (int i = 0 ; i < n; i++) {
		select(A, n - i - 1);
	}

    end = clock();
    result = (double)(end - start);
    printf("select sort == > %6lf\n", result / CLOCKS_PER_SEC); //결과 출력

    start = clock();

	for (int i = 0; i < n - 1; i++) {
		insertion(B, i  + 1);
	}

    end = clock();

    result = (double)(end - start);
    printf("insertion sort == > %6lf", result / CLOCKS_PER_SEC); //결과 출력

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
	for (int i = 0; i < idx; i++) {
		if (arr[idx] > arr[i]) continue;
		else {
			before_idx_sort(arr, i, idx);
			arr[i] = save;
			break ;
		}
	}
}

void before_idx_sort(int *arr, int start, int end) {
	for (int i = end; i > start; i--) {
		arr[i] = arr[i - 1];
	}
}