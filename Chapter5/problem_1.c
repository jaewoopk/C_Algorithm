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
t_list *twoSort(t_list *list);

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
    t_list *answer;
    answer = mergeSort(list, n);
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
        return twoSort(list);
    t_list *list2, *tmp1, *tmp2;
    t_list *answerList;
    
    list2 = partition(list, k / 2);
    if (k % 2 == 1){
        tmp1 = mergeSort(list, k / 2);
        if (k == 1) {
            tmp2 = mergeSort(list2, k / 2);    
        }
        else {
            tmp2 = mergeSort(list2, k / 2 + 1);
        }
    }
    else {
        tmp1 = mergeSort(list, k / 2);
        tmp2 = mergeSort(list2, k / 2);
    }
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
        }
        else if (tmp2 == NULL) {
            newTmpNode->next = tmp1;
            tmp1 = tmp1->next;
        }
        else if (tmp1->data < tmp2->data) {
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
    t_node *tmp = list->head->next;
    if (!tmp) return list;
    t_list *newList = (t_list *)malloc(sizeof(t_list));
    newList->head = (t_node *)malloc(sizeof(t_node));

    for (int i = 0; i < k- 1; i++) {
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

t_list *twoSort(t_list *list) {
    t_node *tmp1 = list->head->next;
    if (tmp1 == NULL)
        return list;
    t_node *tmp2 = list->head->next->next;
    if (tmp2 == NULL)
        return list;
    if (tmp1->data > tmp2->data) {
        tmp1->next = NULL;
        list->head->next = tmp2;
        tmp2->next = tmp1;
    }
    return list;
}