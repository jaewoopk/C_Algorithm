#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear; 
    int count; 
} Queue;

typedef struct s_node {
    char ch;
    char *next;
    int index;
    int inDegree;
    bool visit;
} t_node;

t_node *list;
Queue Q;
int n, m;
char *T;
int tIndex;

void    initGraph();
void    buildGraph();
void    topologicalSort();
void    initQueue();
int     isEmpty();
void    enqueue(int data);
int     dequeue();

int main(void) {
    int i;
 
    initQueue();
    scanf(" %d",&n);
    list = (t_node *)malloc(sizeof(t_node) * n);
    T = (char *)malloc(sizeof(char) * n);
    initGraph();

    scanf(" %d",&m);
    buildGraph();

    topologicalSort();
    // for (int i = 0; i < n; i++) {
    //     printf("%c ",list[i].ch);
    //     printf("--> %s \n",list[i].next);
    // }
    // printf("\n");

    if (tIndex < n) {
        printf("0\n");
        exit(0);
    }
    for (int i = 0; i < n; i++) {
        printf("%c ",T[i]);
    }
    printf("\n");
    exit(0);
    return (0);
}

void initGraph() {
    for (int i = 0; i < n; i++) {
        scanf(" %c",&(list[i].ch));
        list[i].next = (char *)malloc(sizeof(char) * 100);
        list[i].index = 0;
        list[i].inDegree = 0;
        list[i].visit = false;
    }
}

void buildGraph() {
    for (int i = 0; i < m; i++) {
        char start, end;
        scanf(" %c %c",&start, &end);
        for (int j = 0; j < n; j++) {
            if (list[j].ch == start) {
                for (int k = list[j].index; k > 0; k--) {
                    list[j].next[k] = list[j].next[k - 1];
                }
                list[j].next[0] = end;
                (list[j].index)++;
            }
            else if (list[j].ch == end) {
                (list[j].inDegree)++;
            }
        }
    }
}

void topologicalSort() {
    for (int i = 0; i < n; i++) {
        if (list[i].inDegree == 0 && !list[i].visit) {
            enqueue(i);
            list[i].visit = true;
        }
    }
    while (!isEmpty()) {
        int u = dequeue();
        T[tIndex++] = list[u].ch;
        for (int j = 0; j < list[u].index; j++) {
            list[list[u].next[j]].inDegree--;
            if (list[list[u].next[j]].inDegree == 0 && !list[(list[u].next)[j]].visit)
                enqueue(list[u].next[j]);
                list[u].visit = true;
        }
    }
    return ;
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
