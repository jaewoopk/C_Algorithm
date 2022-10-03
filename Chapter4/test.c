#include <stdio.h>
#include <stdlib.h>

int H[99];// 힙
int n;// 키 개수(힙의 크기)
int s;// 힙의 원래 크기 저장할 변수

void downHeap(int i) {
	int left = i * 2;//왼쪽 자식
	int right = i * 2 + 1;//오른쪽 자식
	int big, tmp;
	if (n < left && n < right)
		return;

	big = left;
	if (n >= right) {
		if (H[big] < H[right]) {
			big = right;
		}
	}

	if (H[big] <= H[i])
		return;

	tmp = H[i];
	H[i] = H[big];
	H[big] = tmp;

	downHeap(big);
}

void rBuildHeap(int i) { // 상향식 힙 생성 함수
	if (i > n)
		return;
	rBuildHeap(i * 2);
	rBuildHeap(i * 2 + 1);
	downHeap(i);

	return;
}

void inPlaceHeapSort() { // 제자리 힙 정렬 함수
	int tmp;
	s = n;

	for (int i = n; i >= 2; i--) {
		tmp = H[1];
		H[1] = H[i];
		H[i] = tmp;
		n--;

		downHeap(1);
	}
}

void printArray() {
	for (int i = 1; i <= s; i++) {
		printf(" %d", H[i]);
	}
	printf("\n");
}


int main() {
	
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &H[i]);
		getchar();
	}

	rBuildHeap(1);
    s = n;
    printArray();
	inPlaceHeapSort();
	printArray();
	
	return 0;
}