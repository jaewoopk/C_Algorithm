#include <stdio.h>
#include <stdlib.h>

typedef struct s_node {
    struct s_node *next;
    struct s_node *prev;
    char data;
} t_node;

typedef struct s_list {
    struct s_node *head;
    struct s_node *tail;
} t_list;

void init(t_list *list);
void add(t_list *list, int r, char e);
void delete(t_list *list, int r);
void get(t_list *list, int r);
void print(t_list *list);

int main(void) {
    int n;
    scanf(" %d", &n);

    t_list *list = (t_list*)malloc(sizeof(t_list*));
    init(list);
    for (int i = 0; i < n; i++) {
        char k;
        scanf(" %c",&k);
        if (k == 'A') {
            int r;
            char e;
            scanf(" %d %c",&r,&e);
            add(list,r,e);
        }
        else if (k == 'D') {
            int r;
            scanf(" %d",&r);
            delete(list,r);
        }
        else if (k == 'G') {
            int r;
            scanf(" %d",&r);
            get(list,r);
        }
        else if (k == 'P') {
            print(list);
        }
    }
    exit(0);
    return 0;
}

void init(t_list *list) {
    t_node *head = (t_node *)malloc(sizeof(t_node *));
    t_node *tail = (t_node *)malloc(sizeof(t_node *));
    list->head = head;
    list->tail = tail;

    list->head->next = list->tail;
    list->tail->prev = list->head;
}

void add(t_list *list, int r, char e) {
    t_node *tmp = list->head;
    t_node *newNode = (t_node*)malloc(sizeof(t_node));

    for (int i = 0; i < r; i++) {
        tmp = tmp->next;
        if (tmp == NULL || (tmp->next == NULL && tmp != list->tail)) {
            printf("invalid position\n");
            return ;
        }
    }
    if (tmp == NULL) {
        printf("invalid position\n");
        return ;
    }
    newNode->data = e;
    newNode->next = tmp;
    newNode->prev = tmp->prev;
    tmp->prev->next = newNode;
    tmp->prev = newNode;
}

void delete(t_list *list, int r) {
    t_node *tmp = list->head;

    for (int i = 0; i < r; i++) {
        tmp = tmp->next;
        if (tmp == NULL || (tmp->next == NULL && tmp != list->tail)) {
            printf("invalid position\n");
            return ;
        }
    }
    if (tmp == NULL || tmp == list->tail) {
        printf("invalid position\n");
        return ;
    }
    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
    free(tmp);
}

void get(t_list *list, int r) {
    t_node *tmp = list->head;

    for (int i = 0; i < r; i++) {
        tmp = tmp->next;
        if (tmp == NULL || (tmp->next == NULL && tmp != list->tail)) {
            printf("invalid position\n");
            return ;
        }
    }
    if (tmp == NULL || tmp == list->tail) {
        printf("invalid position\n");
        return ;
    }
    printf("%c\n", tmp->data);
}

void print(t_list *list) {
    t_node *tmp = list->head->next;

    while (tmp != list->tail) {
        printf("%c",tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

