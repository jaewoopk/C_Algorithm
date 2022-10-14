#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//합병정렬

typedef struct ListNode {
	int elem;
	struct ListNode* next;
}node;

void addList(node** L, int elem) {// 리스트에 원소 추가
	node* q = (node*)malloc(sizeof(node));
	q->elem = elem;
	q -> next = NULL;

	node* p = *L;
	if (*L == NULL) {
		*L = q;
	}
	else {
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = q;
	}
}

void partition(node* L, node** L1, node** L2, int size) {
	node* p = L;

	*L1 = L;
	for (int i = 0; i < (size / 2) - 1; i++) {
		p = p->next;
	}
	*L2 = p->next;
	p->next = NULL;
}

node* merge(node* L1, node* L2) {
	node* p = NULL;

	if (L1 == NULL)
		return L2;
	else if (L2 == NULL)
		return L1;

	if (L1->elem < L2->elem) {
		p = L1;
		p->next = merge(L1->next, L2);
	}
	else {
		p = L2;
		p->next = merge(L1, L2->next);
	}

	return p;
}

void mergeSort(node** L, int size) {
	node* L1, * L2, * p = *L;

	if (size <= 1)
		return;

	partition(p, &L1, &L2, size);
	if (size % 2 == 0) {
		mergeSort(&L1, size / 2);
		mergeSort(&L2, size / 2);
	}
	else {
		mergeSort(&L1, size / 2);
		mergeSort(&L2, (size / 2) + 1);
	}

	*L = merge(L1, L2);
}

void printList(node* L) {
	node* p = L;

	while (p != NULL) {
		printf(" %d", p->elem);
		p = p->next;
	}
}

void freeList(node* L) {
	node* p = L;

	while (p != NULL) {
		L = L->next;
		free(p);
		p = L;
	}
}

int main() {
    srand(time(NULL));
	int n, e;

	node* L = NULL;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
        e = rand() % 2000;
		//scanf(" %d", &e);
		addList(&L, e);
	}

	mergeSort(&L, n);
	printList(L);

	freeList(L);// 노드 free

	return n;
}