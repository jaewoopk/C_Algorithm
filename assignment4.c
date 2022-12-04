#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int arr[3][2] = {{0, 4}, {2, 5}, {2, 4}};
int MAX = 30;

LARGE_INTEGER ticksPerSec;
LARGE_INTEGER start,end, diff;

int airtelDC(int n, int s, int d, int A[], int H[]);
int rAirtelDC(int n, int s, int d, int A[], int H[]);
int airtelDP(int n, int s, int d, int A[], int H[]);
void printCPUTimeCheckerStart();
void printCPUTimeCheckerEnd();

int main(void) {
	int A[MAX], H[MAX];
	int n,s,d, mincost;
	A[0] = 0; A[1] = 1;
	for (int i = 2; i < MAX; i++) {
		A[i] = A[i - 1] + (A[i - 1] % 5 + 3);
	}
	H[0] = 0; H[1] = 5;
	for (int i = 2; i < MAX; i++) {
		H[i] = (H[i - 1] + i) % 9 + 1;
	}
	printf("n	s	d	mincost	  version	cputime\n");

	n = 6;
	for (int i = 0; i < 3; i++) {
		printCPUTimeCheckerStart();
		mincost = airtelDC(n, arr[i][0], arr[i][1], A, H); // mincost에 airtelDC의 반환값을 넣어준다.
		printf("%d	%d	%d	%d	  DC	",n,arr[i][0], arr[i][1], mincost);
		printCPUTimeCheckerEnd();

		printCPUTimeCheckerStart();
		mincost = airtelDP(n, arr[i][0], arr[i][1], A, H);
		printf("%d	%d	%d	%d	  DP	",n,arr[i][0], arr[i][1], mincost);
		printCPUTimeCheckerEnd();
	}
	n = 30;
	s = 1; d = n - 2;

	printCPUTimeCheckerStart();
	mincost = airtelDC(n, s, d, A, H);
	printf("%d	%d	%d	%d	  DC	",n,s,d, mincost);
	printCPUTimeCheckerEnd();

	printCPUTimeCheckerStart();
	mincost = airtelDP(n, s, d, A, H);
	printf("%d	%d	%d	%d	  DP	",n,s,d, mincost);
	printCPUTimeCheckerEnd();


	return (0);
}

int airtelDP(int n, int s, int d, int A[], int H[]) { // Dynamic Programming
	int m[d + 1];
	int cost;

	m[0] = 0;
	for (int i = 1; i < d + 1; i++) {
		m[i] = INT_MAX;
		for (int j = 0; j < i; j++) { // 2중 for문을 사용하여 점화식을 통해 i는 0부터 d + 1, j는 0부터 i까지
			cost = m[j] + H[j] + A[i - j]; // m[j] + H[j] + A[i - j]라는 점화식을 통해 cost를 구하고
			if (cost < m[i]) m[i] = cost; // min 비교를 통해 m[i]에 최소값을 갱신한다.
		}
	}
	// 2중 for문을 사용하기 때문에 총 O(n^2)이라는 시간이 걸린다.
	return m[d]; // m[d]를 리턴한다.
}

int rAirtelDC(int n, int s, int d, int A[], int H[]) {
	int mincost, cost;
	if (d == 0) // d가 0일 때, 0을 리턴
		return 0;
	mincost = INT_MAX;
	for (int i = 0; i < d; i++) {
		cost = rAirtelDC(n, s, i, A, H) + H[i] + A[d - i];
		// cost에 s 부터 i까지 최소비용을 구하고, H[i]를 숙박한다음, A[d-i]를 통해 비행거리를 더한다
		// 이렇게 하면 0부터 d - 1번까지 돌며 각 i값에 대해 최소비용을 계산할 수 있다.
		if (cost < mincost) mincost = cost;
	}
		// for문 속에 rAirtelDC라는 재귀함수를 돌리기때문에 총 O(2^n)이라는 시간이 걸린다.
	return mincost;
}

int airtelDC(int n, int s, int d, int A[], int H[]) {
	return (rAirtelDC(n - 1, s, d, A, H)); // rAirtelDC에 n-1값을 넣은 반환값을 리턴한다.
}

void printCPUTimeCheckerStart() {
	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);

}

void printCPUTimeCheckerEnd() {
	QueryPerformanceCounter(&end);

	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("	%.8f\n", ((double)diff.QuadPart) / (double)(ticksPerSec.QuadPart) * 1000);
}