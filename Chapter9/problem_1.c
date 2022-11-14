#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_node {
    struct s_node *next;
    int vertex;
    int weight;
} t_node;

void insertNode(t_node *node, int v, int w);
void insertAllNode(t_node **list);
void printGraph(t_node **node, int k);
void changeWeight(t_node **node, int a, int b, int w);
void eraseWeight(t_node **node, int a, int b);

int main(void) {
    t_node *list[7];
    for (int i = 0; i < 7; i++) {
        list[i] = (t_node *)malloc(sizeof(t_node));
    }
    bool quit = true;
    insertAllNode(list);
    while (quit) {
        char c;
        int k, a, b, w;
        scanf(" %c", &c);
        switch (c)
        {
        case 'a' :
            scanf(" %d", &k);
            if (k < 1 || k > 6) {
                printf("-1\n");
                break ;
            }
            printGraph(list, k);
            printf("\n");
            break ;
        case 'm' :
            scanf(" %d %d %d", &a, &b, &w);
            if ((a < 1 || a > 6) || (b < 1 || b > 6)) {
                printf("-1\n");
                break ;
            }
            if (w == 0) {
                eraseWeight(list, a, b);
            }
            else {
                changeWeight(list, a, b, w);
            }
            break ;
        case 'q' :
            quit = false;
            break ;
        }
    }
    exit(0);
    return (0);
}

void insertNode(t_node *node, int v, int w) {
    t_node *newNode = (t_node *)malloc(sizeof(t_node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    node->next = newNode;
}

void insertAllNode(t_node **list) {

    insertNode(list[1], 2, 1);
    insertNode(list[1]->next, 3, 1);
    insertNode(list[1]->next->next, 4, 1);
    insertNode(list[1]->next->next->next, 6, 2);

    insertNode(list[2], 1, 1);
    insertNode(list[2]->next, 3, 1);

    insertNode(list[3], 1, 1);
    insertNode(list[3]->next, 2, 1);
    insertNode(list[3]->next->next, 5, 4);

    insertNode(list[4], 1, 1);

    insertNode(list[5], 3, 4);
    insertNode(list[5]->next, 5, 4);
    insertNode(list[5]->next->next, 6, 3);

    insertNode(list[6], 1, 2);
    insertNode(list[6]->next, 5, 3);

}

void printGraph(t_node **node, int k) {
    t_node *tmp = node[k]->next;
    if (!tmp) {
        printf("-1");
        return ;
    }
    while (tmp) {
        printf(" %d %d",tmp->vertex, tmp->weight);
        tmp = tmp->next;
    }
    
}

void changeWeight(t_node **node, int a, int b, int w) {
    t_node *tmp1 = node[a]->next;
    t_node *tmp2 = node[b]->next;

    t_node *before_tmp1 = node[a];
    t_node *before_tmp2 = node[b];

    while (tmp1) {
        if (tmp1->vertex >= b)
            break ;
        before_tmp1 = tmp1;
        tmp1 = tmp1->next;
    }

    while (tmp2) {
        if (tmp2->vertex >= a)
            break ;
        before_tmp2 = tmp2;
        tmp2 = tmp2->next;
    }
    if (!tmp1 || !tmp2) {
        if (!tmp1 && tmp2) {
            tmp2->weight = w;
            insertNode(before_tmp1, b, w);
        }
        else if (!tmp2 && tmp1) {
            tmp1->weight = w;
            insertNode(before_tmp2, a, w);
        }
        else if (!tmp1 && !tmp2){
            insertNode(before_tmp1, b, w);
            insertNode(before_tmp2, a, w);
        }
        return ;
    }
    else {
        tmp1->weight = w;
        tmp2->weight = w;
    }

    // t_node *newNode1 = (t_node *)malloc(sizeof(t_node));
    // t_node *newNode2 = (t_node *)malloc(sizeof(t_node));

    // newNode1->vertex = b;
    // newNode1->weight = w;
    // newNode1->next = tmp1;

    // newNode2->vertex = a;
    // newNode2->weight = w;
    // newNode2->next = tmp2;

    // before_tmp1->next = newNode1;
    // before_tmp2->next = newNode2;

}

void eraseWeight(t_node **node, int a, int b) {
    t_node *tmp1 = node[a]->next;
    t_node *tmp2 = node[b]->next;
    
    if (!tmp1 || !tmp2) {
        printf("-1\n");
        return ;
    }
    t_node *before_tmp1 = node[a];
    t_node *before_tmp2 = node[b];

    if (a == b) {
        while (tmp1) {
            if (tmp1->vertex == b)
                break ;
            before_tmp1 = tmp1;
            tmp1 = tmp1->next;
        }
        if (!tmp1)
            return ;
        
        before_tmp1->next = tmp1->next;
        tmp1->next = NULL;
        free(tmp1);
        return ;
    }

    while (tmp1) {
        if (tmp1->vertex == b)
            break ;
        before_tmp1 = tmp1;
        tmp1 = tmp1->next;
    }
    while (tmp2) {
        if (tmp2->vertex == a)
            break ;
        before_tmp2 = tmp2;
        tmp2 = tmp2->next;
    }
    if (!tmp1 || !tmp2)
        return ;
    
    before_tmp1->next = tmp1->next;
    before_tmp2->next = tmp2->next;
    tmp1->next = NULL;
    tmp2->next = NULL;
    free(tmp1);
    free(tmp2);
}