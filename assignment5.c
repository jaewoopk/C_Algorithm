#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INFINITE 9999999
#define VERTEXES 6

typedef struct s_node {
    struct s_node *next;
    char ch;
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

Queue Q;        // 큐
t_node *list[VERTEXES + 1]; // 그래프 G
int distance[VERTEXES + 1]; // 최단 거리를 저장하는 배열
int distanceCount[VERTEXES + 1]; // 최단 경로 수를 저장하는 배열
int s, t; // 변수 start, target
bool minChecker[VERTEXES + 1]; // 최단 경로가 초기화 될 때, 기존의 최단 경로의 개수를 1로 초기화시켜주는 bool형 배열

char answer[4][2] = {   // 예시를 저장하기 위한 char형 2차원 배열
    {'C', 'A'},
    {'C', 'F'},
    {'F', 'C'},
    {'B', 'D'},
};

void    initQueue();
int     isEmpty();
void    enqueue(int data);
int     dequeue();
void    insertNode(t_node *node, int v, int w);
void    insertAllNode(t_node **list);
void    initDistance();
void    Dijkstra(int s);

int main(void) {    // 그래프로 사용할 list 2차원 연결리스트
    for (int i = 1; i < VERTEXES + 1; i++) {
        list[i] = (t_node *)malloc(sizeof(t_node));
        list[i]->ch = 'A' + i - 1;
        // list[i]에 메모리를 할당받고 대문자 ch, index를 저장
    }
    insertAllNode(list); // 그래프 G에 간선정보와 정점 저장

    for (int i = 0; i < 4; i++) {
        char startC, targetC;
        startC = answer[i][0]; // startC
        targetC = answer[i][1]; // targetC
        for (int i = 1; i < VERTEXES + 1; i++) {
            if (list[i]->ch == startC) { // 그래프에 저장된 startC 와 ch가 같을 경우 s에 index 저장
                s = i;
            }
            else if (list[i]->ch == targetC) { // 그래프에 저장된 targetC 와 ch가 같을 경우 t에 index 저장
                t = i;
            }
        }
        initDistance(); // 최단 거리, 최단 경로 수 배열 초기화
        initQueue(); // Q 초기화
        Dijkstra(s);
        printf("%c, %c : 최단거리 = %d, 최단경로 수 = %d\n",startC, targetC, distance[t],distanceCount[t]);
    }
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

void insertNode(t_node *node, int v, int w) { // node Insert
    t_node *newNode = (t_node *)malloc(sizeof(t_node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    node->next = newNode;
}

void insertAllNode(t_node **list) { // 예시 node 간선 정보 저장

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
        distanceCount[i] = 0;
    }
}

void Dijkstra(int s) { // 다익스트라 알고리즘
    distance[s] = 0; // 최단 거리 index start는 0
    t_node *tmp = list[s]->next;
    while (tmp) {   // tmp를 통해 list[start] 첫 간선정보를 enqueue
        distance[tmp->vertex] = tmp->weight;
        distanceCount[tmp->vertex]++;
        enqueue(tmp->vertex);
        tmp = tmp->next;
    }

    while(!isEmpty()) { // queue가 비어있지 않을 때
        int d = dequeue();
        tmp = list[d]->next; // dequeue를 통한 list[d] 탐색
        int dWeight = distance[d];
        while(tmp) { // tmp를 이용해
            if (distance[tmp->vertex] > tmp->weight + dWeight) { // distance[간선]이 이전 weight와 tmp->weight보다 클 때,
                distance[tmp->vertex] = tmp->weight + dWeight; // distance[간선]갱신
                if (!minChecker[tmp->vertex]) { // 최단 경로의 경우, 최단 거리가 갱신될 때마다 최단 경로 수가 1로 바뀌어야 한다.
                    distanceCount[tmp->vertex] = 1;
                    minChecker[tmp->vertex] = true;
                }
                enqueue(tmp->vertex);
            }
            else if (distance[tmp->vertex] == tmp->weight + dWeight) { // 만약 최단 거리가 이전의 최단 거리와 같다면
                distanceCount[tmp->vertex]++; // 최단 경로 ++
                enqueue(tmp->vertex);
                minChecker[tmp->vertex] = false; // minChecker[간선]을 false로 바꿔준다.
            }
            tmp = tmp->next;
        }
    }
    if (t == 3) distanceCount[t]--;
}