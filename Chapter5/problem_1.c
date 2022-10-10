#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct s_node {
    int data;
    struct s_node *head;
    struct s_node *next;
} t_node;

void insertItems(t_node *list, int data);

int main(void) {
    int n;
    t_node *list = (t_node *)malloc(sizeof(t_node));
    t_node *tmp;

    n = scanf(" %d",&n);
    printf("n = %d\n",n);

    for (int i = 0; i < n; i++) {
        int data;
        data = scanf(" %d",&data);
        printf("data = %d\n",data);
        //insertItems(list, data);
    }
    /*tmp = list->head;
    while (tmp->next) {
        printf(" %d",tmp->next->data);
    }*/
    exit(0);
    return (0);
}

void insertItems(t_node *list, int data) {
    t_node *tmp = list->head;
    t_node *new_node = (t_node *)malloc(sizeof(t_node));
    new_node->data = data;
    new_node->next = NULL;

    while(tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = new_node;
}