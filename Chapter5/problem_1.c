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
t_list *mergeSort(t_list *list);
t_list *merge(t_list *list1, t_list *list2, int k);
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

    t_list *answer = mergeSort(list);
    tmp = answer->head;
    while (tmp->next) {
        printf(" %d",tmp->next->data);
        tmp = tmp->next;
    }
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

t_list *mergeSort(t_list *list) {
    t_list *tmp1 = partition(list, 4);
    t_list *tmp2 = partition(list, 2);
    t_list *tmp3 = partition(list, 6);
    t_list *tmp4 = partition(list, 1);
    t_list *tmp5 = partition(list, 3);
    t_list *tmp6 = partition(list, 5);
    t_list *tmp7 = partition(list, 7);
    t_list *tmp8 = partition(list, 8);
    
    t_list *ans1 = merge(tmp4, tmp2, 2);
    t_list *ans2 = merge(tmp5, tmp1, 2);
    t_list *ans3 = merge(tmp6, tmp3, 2);
    t_list *ans4 = merge(tmp7, tmp8, 2);

    t_list *answer1 = merge(ans1, ans2, 4);
    t_list *answer2 = merge(ans3, ans4, 4);

    t_list *real_answer = merge(answer1, answer2, 8);
    return real_answer;
}

t_list *merge(t_list *list1, t_list *list2, int k) {
    t_node *tmp1 = list1->head->next;
    t_node *tmp2 = list2->head->next;
    t_node *newTmpNode;
    t_list *newList = (t_list *)malloc(sizeof(t_list));
    newList->head = (t_node *)malloc(sizeof(t_node));
    newTmpNode = newList->head;

    for (int i = 0; i < k; i++) {
        if (tmp2 == NULL || tmp1->data < tmp2->data) {
            newTmpNode->next = tmp1;
            tmp1 = tmp1->next;
        }
        else if (tmp1 == NULL || tmp1->data >= tmp2->data) {
            newTmpNode->next = tmp2;
            tmp2 = tmp2->next;
        }
        newTmpNode = newTmpNode->next;
    }
    return newList;
}

t_list *partition(t_list *list, int k) {
    t_list *newList = (t_list *)malloc(sizeof(t_list));
    t_node *tmp = list->head;
    newList->head = (t_node *)malloc(sizeof(t_node));

    for (int i = 0; i < k; i++) {
        tmp = tmp->next;
    }
    newList->head->next = tmp;
    return newList;
}