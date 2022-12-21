#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//

#define INFINITE 99999

typedef struct s_node {
    struct s_node* next;
    int data;
} t_node;

t_node *T;
t_node *notT;

int n, m;
int number = 1;
int G[101][101];
int total = 0;

void insertNode(t_node *node, int data);
void deleteNode(t_node *node, int data);
void primJarnik(int s);

int main() {
    T = (t_node *)malloc(sizeof(t_node));
    notT = (t_node *)malloc(sizeof(t_node));
    t_node *tmp = notT;
    scanf("%d %d",&n, &m);
    for (int i = 1; i < n + 1; i++) {
        insertNode(tmp,i);
        tmp = tmp->next;
        for (int j = 1; j < n + 1; j++) {
            if (i == j) G[i][j] = 0;
            else G[i][j] = INFINITE;
        }
    }
    for (int i = 1; i < m + 1; i++) {
        int vertex1, vertex2, weight;
        scanf(" %d %d %d", &vertex1, &vertex2, &weight);
        G[vertex1][vertex2] = weight;
        G[vertex2][vertex1] = weight;
    }
    // for (int i = 1; i < n + 1; i ++){
    //     for (int j = 1; j < n + 1; j++) {
    //         printf(" %d ",G[i][j]);
    //     }
    //     printf("\n");
    // }
    deleteNode(notT, number);
    insertNode(T, number);
    primJarnik(number);
    T = T->next;
    while (T) {
        printf(" %d",T->data);
        T = T->next;
    }
    printf("\n%d\n",total);
    exit(0);
    return 0;
}

void insertNode(t_node *node, int data) {
    t_node *newNode = (t_node *)malloc(sizeof(t_node));
    newNode->data = data;
    newNode->next = NULL;
    node->next = newNode;
}

void deleteNode(t_node *node, int data) {
    t_node *before_tmp = node;
    t_node *tmp = node->next;
    while (tmp) {
        if (tmp->data == data) {
            before_tmp->next = tmp->next;
            free(tmp);
            return ;
        }
        before_tmp = tmp;
        tmp = tmp->next;
    }
}

void primJarnik(int s) {
    int min = INFINITE;
    int j;
    t_node *tmp = T->next;
    t_node *tmpNot = notT->next;
    if (!tmpNot) {
        return ;
    }

    while(tmp) {
        tmpNot = notT->next;
        while(tmpNot) {
            if (G[tmp->data][tmpNot->data] < min) {
                min = G[tmp->data][tmpNot->data];
                number = tmpNot->data;
            }
            tmpNot = tmpNot->next;
        }
        tmp = tmp->next;
    }
    total += min;
    deleteNode(notT, number);
    tmp = T;
    while (tmp->next) {
        tmp = tmp->next;
    }
    insertNode(tmp, number);
    primJarnik(number);
}