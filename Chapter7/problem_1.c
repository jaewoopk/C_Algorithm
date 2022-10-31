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
	t_node *root = (t_node *)malloc(sizeof(t_node));
    bool isRoot = true;
    char c;
    int k;
    bool quit = true;

    while (quit) {
        scanf(" %c", &c);
        switch (c)
        {
        case 'i' :
            scanf(" %d", &k);
            if (isRoot) {
                root->key = k;
                isRoot = false;
            }
            printf("%p",&root);
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
    exit(0);
    return (0);
}

// int findElement(int k) {
//     t_node *w = treeSearch(root, k);
// }

// t_node *treeSearch(t_node *node, int k) {
//     if (isExternal(node)) {
//         return node;
//     }
//     if (k == node->key) {
//         return node;
//     }
//     else if (k < node->key) {
//         return treeSearch(node->lChild, k);
//     }
//     else if (k > node->key) {
//         return treeSearch(node->rChild, k);
//     }
// }

void insertItem(t_node *node, int k) {
    if (!node) {
        return ;
    }
    if (node->key < k) {
        insertItem(node->rChild, k);
        node->rChild->parent = node;
    }
    else if (node->key > k){
        insertItem(node->lChild, k);
        node->lChild->parent = node;
    }
    else {
        return ;
    }
}

void printTree(t_node *node) {
    if (!node) {
        printf("nothing\n");
        return ;
    }
    else {
        printf(" %d",node->key);
        printTree(node->lChild);
        printTree(node->rChild);
    }
}