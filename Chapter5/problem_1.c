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
void mergeSort(t_list *list);
void merge(t_list *list1, t_list *list2);
void partition(t_list *list,int k);

int main(void) {
    int n;
    t_list *list = (t_list *)malloc(sizeof(t_list));
    list->head = (t_node *)malloc(sizeof(t_node));
    t_node *tmp;

    scanf(" %d", &n);
    
    for (int i = 0; i < n; i++) {
        int data;
        scanf(" %d",&data);
        insertItems(list, data);
    }
    tmp = list->head;
    while (tmp->next) {
        printf(" %d",tmp->next->data);
        tmp = tmp->next;
    }
    exit(0);
    return (0);
}

void insertItems(t_list *list, int data) {
    t_node *tmp = list->head;
    t_node *new_node = (t_node *)malloc(sizeof(t_node));
    new_node->data = data;
    new_node->next = NULL;

    while(tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = new_node;
}

void mergeSort(t_list *list) {

}

void merge(t_list *list1, t_list *list2) {

}

void partition(t_list *list, int k) {

}