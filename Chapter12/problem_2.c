#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INFINITE 99999

typedef struct s_node {
    int start;
    int end;
    int weight;
} t_node;

int n, m;
int count = 0;
int total = 0;


void printUF();
int unionFind[101];
t_node *G;
void kruskal();

int main() {
    scanf("%d %d",&n, &m);
    G = (t_node *)malloc(sizeof(t_node) * n);
    for (int i = 1; i < n + 1; i++) {
        unionFind[i] = i;
    }

    for (int i = 1; i < m + 1; i++) {
        int vertex1, vertex2, weight;
        scanf(" %d %d %d", &vertex1, &vertex2, &weight);
        G[i].start = vertex1;
        G[i].end = vertex2;
        G[i].weight = weight;
    }
    for (int idx = 1; idx < m + 1; idx++) {
        t_node tmp = G[idx];
        int save = G[idx].weight;
        int i = idx - 1;

        while (G[i].weight > save && i >= 0) {
            G[i + 1] = G[i];
            i--;
        }
        G[i + 1] = tmp;
    }

    for (int i = 1; i < m + 1; i ++){
        printf(" %d ",G[i].weight);
    }
    printf("\n");

    kruskal();
    printf("\n");
    printf("%d\n",total);
    
    exit(0);
    return 0;
}

void kruskal() {
    for (int i = 1; i < m + 1; i++) {
        printUF();
        if (unionFind[G[i].start] != unionFind[G[i].end]) {
            unionFind[G[i].end] = unionFind[G[i].start];
            total += G[i].weight;
            count++;
            printf(" %d\n",G[i].weight);
        }
        if (count == m - 1) {
            return ;
        }
    }
}

void printUF() {
    printf("-----------\n");
    for (int i = 1; i < n + 1; i++) {
        printf(" %d",unionFind[i]);
    }
    printf("\n-----------\n");
}