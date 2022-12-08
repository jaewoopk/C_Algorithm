#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INFINITE 9999999
#define VERTEXES 6

typedef struct s_node {
    struct s_node *next;
    char ch;
    int index;
    int vertex;
    int weight;
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
t_node *list[VERTEXES + 1];
int distance[VERTEXES + 1];

int s, t;

void    initQueue();
int     isEmpty();
void    enqueue(int data);
int     dequeue();
void    insertNode(t_node *node, int v, int w);
void    insertAllNode(t_node **list);

void    initDistance();
void    Dijkstra(int s);

int main(void) {
    initQueue();
    initDistance();
    for (int i = 0; i < VERTEXES + 1; i++) {
        list[i] = (t_node *)malloc(sizeof(t_node));
        if (i > 0) {
            list[i]->ch = 'A' + i - 1;
            list[i]->index = i;
        }
    }
    insertAllNode(list);

    char startC, targetC;
    scanf(" %c %c",&startC, &targetC);

    for (int i = 1; i < VERTEXES + 1; i++) {
        if (list[i]->ch == startC) {
            s = i;
        }
        else if (list[i]->ch == targetC) {
            t = i;
        }
    }
    Dijkstra(s);
    printf("%c, %c : 최단거리 = %d, 최단경로 수 = ",startC, targetC, distance[t]);
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

void initDistance() {
    for (int i = 1; i < VERTEXES + 1; i++) {
        distance[i] = INFINITE;
    }
}

void Dijkstra(int s) {
    int min = INFINITE;
    distance[s] = 0;
    t_node *tmp = list[s];
    while (!tmp) {
        if (min > tmp->weight) min = tmp->weight;
        distance[tmp->vertex] = tmp->weight;
        enqueue(tmp->vertex);
        tmp = tmp->next;
    }

    while(!isEmpty()) {
        int d = dequeue();
        tmp = list[d];
        if (min < tmp->weight) {
            enqueue(d);
            continue;
        }
        int dWeight = tmp->weight;
        while(!tmp) {
            if (tmp->vertex == s || tmp->vertex == d) tmp = tmp->next;
            if (distance[tmp->vertex] > tmp->weight + dWeight) {
                distance[tmp->vertex] = tmp->weight + dWeight;
                enqueue(tmp->vertex);
            }
        }

    }
}