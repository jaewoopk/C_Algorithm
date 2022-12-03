#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int MAX = 30;

void printCPUTime();

int main(void) {
	int A[30], H[30];
	A[0] = 0; A[1] = 1;
	for (int i = 2; i < MAX; i++) {
		A[i] = A[i - 1] + (A[i - 1] % 5 + 3);
	}
	H[0] = 0; H[1] = 5;
	for (int i = 2; i < MAX; i++) {
		H[i] = (H[i - 1] + i) % 9 + 1;
	}
	printf("n    s    d    mincost    version    cputime\n");
	return (0);
}

void printCPUTime() {
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;

	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);


	QueryPerformanceCounter(&end);

	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("time : %.12f sec\n\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
}