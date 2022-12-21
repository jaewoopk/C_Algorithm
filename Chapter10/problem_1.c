#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 그래프순회 dfs, bfs

typedef struct s_node {
    struct s_node *next;
    int vertex;
    int length;
} t_node;

void insertNode(t_node *node1, t_node *node2, int a, int b);
// void printGraph(t_node **node, int k);
void DFS(t_node **list, int k);

int n, m, s;
int arr[101];

int main(void) {
    for (int i = 0; i < 101; i++) {
        arr[i] = 0;
    }
    scanf(" %d %d %d", &n, &m, &s);
    t_node *list[n + 1];
    for (int i = 0; i < n + 1; i++) {
        list[i] = (t_node *)malloc(sizeof(t_node));
        list[i]->length = 0;
    }
    bool quit = true;

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf(" %d %d",&a, &b);
        insertNode(list[a],list[b], a, b);
        list[a]->length += 1;
        list[b]->length += 1;
    }
    // for (int i = 1; i < n + 1; i++) {
    //     printGraph(list, i);
    // }
    DFS(list, s);
    exit(0);
    return (0);
}

void insertNode(t_node *node1, t_node *node2, int a, int b) {
    while (node1->next) {
        if (node1->next->vertex > b) {
            break ;
        }
        node1 = node1->next;
    }
    while (node2->next) {
        if (node2->next->vertex > a) {
            break ;
        }
        node2 = node2->next;
    }

    t_node *newNode1 = (t_node *)malloc(sizeof(t_node));
    t_node *newNode2 = (t_node *)malloc(sizeof(t_node));
    newNode1->vertex = b;
    newNode2->vertex = a;

    if (node1->next == NULL) {
        newNode1->next = NULL;
        node1->next = newNode1;
    }
    else {
        newNode1->next = node1->next;
        node1->next = newNode1;
    }
    if (node2->next == NULL) {
        newNode2->next = NULL;
        node2->next = newNode2;
    }
    else {
        newNode2->next = node2->next;
        node2->next = newNode2;
    }
    
}

// void printGraph(t_node **node, int k) {
//     t_node *tmp = node[k]->next;
//     if (!tmp) {
//         printf("-1");
//         return ;
//     }
//     while (tmp) {
//         printf(" %d",tmp->vertex);
//         tmp = tmp->next;
//     }
//     printf("\n");
    
// }

void DFS(t_node **list, int k) {
    t_node *node = list[k];
    if (arr[k] == 1) {
        return ;
    }
    printf("%d\n", k);
    arr[k] = 1;
    for (int i = 0; i < list[k]->length; i++) {
        DFS(list, node->next->vertex);
        node = node->next;
    }
}