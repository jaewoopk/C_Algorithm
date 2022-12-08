#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INFINITE 210000000

typedef struct s_node {
    struct s_node *next;
    char ch;
    int index;
    int vertex;
    int weight;
    bool visit;
} t_node;

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear; 
    int count; 
} Queue;

Queue Q;

void    initQueue();
int     isEmpty();
void    enqueue(int data);
int     dequeue();
void    insertNode(t_node *node, int v, int w);
void    insertAllNode(t_node **list);

int main(void) {
    initQueue();
    t_node *list[7];
    for (int i = 0; i < 7; i++) {
        list[i] = (t_node *)malloc(sizeof(t_node));
        if (i > 0) {
            list[i]->ch = 'A' + i - 1;
            list[i]->index = i;
        }
    }
    insertAllNode(list);
    exit(0);
    return (0);
}


void initQueue() {
    Q.front = Q.rear = NULL; 
    Q.count = 0;
}
 
int isEmpty() {
    return (Q.count == 0);
}

void enqueue(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
 
    if (isEmpty())
        Q.front = newNode;
    else
        Q.rear->next = newNode;
    Q.rear = newNode;
    Q.count++;
}
 
int dequeue() {
    int data;
    Node *p;
    if (isEmpty())
        return (0);
    p = Q.front;
    data = p->data;
    Q.front = p->next;
    Q.count--;
    free(p);
    
    return (data);
}

void insertNode(t_node *node, int v, int w) {
    t_node *newNode = (t_node *)malloc(sizeof(t_node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    node->next = newNode;
}

void insertAllNode(t_node **list) {

    insertNode(list[1], 2, 8);
    insertNode(list[1]->next, 3, 1);
    insertNode(list[1]->next->next, 4, 4);

    insertNode(list[2], 1, 8);
    insertNode(list[2]->next, 3, 7);
    insertNode(list[2]->next->next, 5, 4);

    insertNode(list[3], 1, 1);
    insertNode(list[3]->next, 2, 7);
    insertNode(list[3]->next->next, 4, 5);
    insertNode(list[3]->next->next->next, 5, 3);
    insertNode(list[3]->next->next->next->next, 6, 9);

    insertNode(list[4], 1, 4);
    insertNode(list[4]->next, 3, 5);
    insertNode(list[4]->next->next, 6, 4);

    insertNode(list[5], 2, 4);
    insertNode(list[5]->next, 3, 3);

    insertNode(list[6], 3, 9);
    insertNode(list[6]->next, 4, 4);

}

// void topologicalSort() {
//     for (int i = 0; i < n; i++) {
//         if (list[i].inDegree == 0 && !list[i].visit) {
//             enqueue(i);
//             list[i].visit = true;
//         }
//     }
//     while (!isEmpty()) {
//         int u = dequeue();
//         T[tIndex++] = list[u].ch;
//         for (int j = 0; j < list[u].index; j++) {
//             list[list[u].vertex[j]].inDegree--;
//             if (list[list[u].vertex[j]].inDegree == 0 && !list[list[u].vertex[j]].visit)
//                 enqueue(list[u].vertex[j]);
//                 list[u].visit = true;
//         }
//     }
//     return ;
// }
