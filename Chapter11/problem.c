#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;
 
 
typedef struct Queue {
    Node *front;
    Node *rear; 
    int count; 
}Queue;

typedef struct s_node {
    char ch;
    char *next;
    int index;
    int inDegree;
    bool visit;
} t_node;

t_node *list;
Queue q;
int n, m;
char *T;
int tIndex;

void initGraph();
void buildGraph();
void topologicalSort();
void initQueue(Queue *q);
int isEmpty(Queue *q);
void enqueue(Queue *q, int data);
int dequeue(Queue *q);

int main(void) {
    int i;
 
    initQueue(&q);
    scanf(" %d",&n);
    list = (t_node *)malloc(sizeof(t_node) * n);
    T = (char *)malloc(sizeof(char) * n);
    initGraph();

    scanf(" %d",&m);
    buildGraph();

    topologicalSort();
    for (int i = 0; i < n; i++) {
        printf("%c ",list[i].ch);
        printf("--> %s \n",list[i].next);
    }
    printf("\n");

    if (tIndex != n) {
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
        list[i].next = (char *)malloc(sizeof(char) * 10);
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
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (list[i].inDegree == 0 && !list[i].visit) {
            enqueue(&q, list[i].ch);
            //T[tIndex++] = list[i].ch;
            list[i].visit = true;
            for (int j = 0; j < list[i].index; j++) {
                list[(list[i].next)[j] - 'A'].inDegree--;
            }
        }
        else
            count++;
    }
    printf(" %d\n",dequeue(&q));
    if (count == n) {
        return;
    }
}

void initQueue(Queue *q) {
    q->front = q->rear = NULL; 
    q->count = 0;
}
 
int isEmpty(Queue *q) {
    return (q->count == 0);
}

void enqueue(Queue *q, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
 
    if (isEmpty(q))
        q->front = newNode;
    else
        q->rear->next = newNode;
    q->rear = newNode;
    q->count++;
}
 
int dequeue(Queue *q) {
    int data;
    Node *p;
    if (isEmpty(q))
        return (0);
    p = q->front;
    data = p->data;
    q->front = p->next;
    q->count--;
    free(p);
    
    return (data);
}
