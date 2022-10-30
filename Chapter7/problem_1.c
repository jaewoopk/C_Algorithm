#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning(disable:4996)

typedef struct s_node {
    struct s_node *lChild;
    struct s_node *rChild;
    struct s_node *parent;
    int key;
} t_node;

int findElement(int k);
void insertItem(t_node *node, int k);
t_node *treeSearch(int k);
void printTree(t_node *node);
int removeElement(int k);
bool isExternal(t_node *w);
bool isInternal(t_node *w);
t_node *inOrderSucc(t_node *w);

int main(void) {
	t_node *root;
    char c;
    int k;
    bool quit = true;

    while (quit) {
        scanf(" %c %d", &c, &k);
        switch (c)
        {
        case 'i' :
            insertItem(root, k);
            break ;
        
        case 'p' :
            printTree(root);
            break ;
        case 'q' :
            quit = false;
            break ;
        default:
            break;
        }
    }
    return (0);
}

// int findElement(int k) {

// }

void insertItem(t_node *node, int k) {
    if (!node) {
        t_node *newNode = (t_node *)malloc(sizeof(t_node));
        newNode->key = k;
        node = newNode;
        return ;
    }
    if (node->key < k) {
        insertItem(node->rChild, k);
        node->rChild->parent = node;
    }
    else {
        insertItem(node->lChild, k);
        node->lChild->parent = node;
    }
}

void printTree(t_node *node) {
    if (!node) {
        return ;
    }
    else {
        printf(" %d",node->key);
        printTree(node->lChild);
        printTree(node->rChild);
    }
}