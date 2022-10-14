#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct s_node {
    int data;
    struct s_node *next;
} t_node;

typedef struct s_list {
    struct s_node *head;
} t_list;

void insertItems(t_list *list, int data);
void printList(t_list *list);
t_list *mergeSort(t_list *list, int k);
t_list *merge(t_list *list1, t_list *list2);
t_list *partition(t_list *list,int k);

int n;

int main(void) {
    t_list *list = (t_list *)malloc(sizeof(t_list));
    list->head = (t_node *)malloc(sizeof(t_node));
    t_node *tmp;

    scanf(" %d", &n);
    
    for (int i = 0; i < n; i++) {
        int data;
        scanf(" %d",&data);
        insertItems(list, data);
    }

    t_list *answer = mergeSort(list, n / 2);
    printList(answer);
    exit(0);
    return (0);
}

void insertItems(t_list *list, int data) {
    t_node *tmp = list->head;
    t_node *newNode = (t_node *)malloc(sizeof(t_node));
    newNode->data = data;
    newNode->next = NULL;

    while(tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

t_list *mergeSort(t_list *list, int k) {
    if (k < 1)
        return list;
    t_list *list2, *tmp1, *tmp2;
    t_list *answerList;
    
    list2 = partition(list, k);
    //if (k % 2 == 0) {
    tmp1 = mergeSort(list, k / 2);
    tmp2 = mergeSort(list2, k / 2);
    //}
    //else {
    //    tmp1 = mergeSort(list, k / 2);
    //    tmp2 = mergeSort(list2, k / 2 + 1);
    //}
    answerList = merge(tmp1, tmp2);
    return answerList;
}

t_list *merge(t_list *list1, t_list *list2) {
    t_node *tmp1 = list1->head->next;
    t_node *tmp2 = list2->head->next;
    t_node *newTmpNode;
    t_list *newList = (t_list *)malloc(sizeof(t_list));
    newList->head = (t_node *)malloc(sizeof(t_node));
    newTmpNode = newList->head;

    while (tmp1 || tmp2) {
        if (tmp1 == NULL) {
            newTmpNode->next = tmp2;
            tmp2 = tmp2->next;
            newTmpNode = newTmpNode->next;
            continue ;
        }
        else if (tmp2 == NULL) {
            newTmpNode->next = tmp1;
            tmp1 = tmp1->next;
            newTmpNode = newTmpNode->next;
            continue ;
        }
        if (tmp1->data < tmp2->data) {
            newTmpNode->next = tmp1;
            tmp1 = tmp1->next;
        }
        else if (tmp1->data >= tmp2->data) {
            newTmpNode->next = tmp2;
            tmp2 = tmp2->next;
        }
        newTmpNode = newTmpNode->next;
    }
    return newList;
}

t_list *partition(t_list *list, int k) {
    t_list *newList = (t_list *)malloc(sizeof(t_list));
    t_node *tmp = list->head->next;
    newList->head = (t_node *)malloc(sizeof(t_node));

    for (int i = 0; i < k - 1; i++) {
        tmp = tmp->next;
    }
    newList->head->next = tmp->next;
    tmp->next = NULL;
    return newList;
}

void printList(t_list *list) {
    t_node *tmp = list->head->next;
    while (tmp) {
        printf(" %d",tmp->data);
        tmp = tmp->next;
    }
}