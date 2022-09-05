#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct s_node {
    struct s_node *left;
    struct s_node *right;
    int data;
} t_node;

typedef struct s_tree {
    struct s_node *root;
} t_tree;

void init(t_tree *tree);
void addNode(t_tree *tree, int data, int l, int r);
t_node *findNode(t_node *node, int r);
void getTreeData(t_tree *tree);

int main(void) {
    int n;
    scanf(" %d", &n);

    t_tree *tree = (t_tree *)malloc(sizeof(t_tree));
    init(tree);
    for (int i = 0; i < n; i++) {
        int data, l, r;
        scanf(" %d %d %d",&data,&l,&r);
        addNode(tree, data, l, r);
        getTreeData(tree);
    }
    return 0;
}

void init(t_tree *tree) {
    tree->root = (t_node *)malloc(sizeof(t_node));
}

void addNode(t_tree *tree, int data, int l, int r) {
    t_node *whereNode = findNode(tree->root, data);
    if (!whereNode) {
        whereNode = tree->root;
    }
    if (l) {
        t_node *newNode_left = (t_node *)malloc(sizeof(t_node));
        newNode_left->data = l;
        whereNode->left = newNode_left;
    }
    if (r) {
        t_node *newNode_right = (t_node *)malloc(sizeof(t_node));
        newNode_right->data = r;
        whereNode->right = newNode_right;
    }
    whereNode->data = data;
}

t_node *findNode(t_node *node, int r) {
    if (!node) {
        return NULL;
    }
    if (node->data == r) {
        return node;
    }
    else if (node->left) {
        findNode(node->left, r);
    }
    else if (node->right){
        findNode(node->right, r);
    }
}
void getTreeData(t_tree *tree) {
    t_node *tmp;

    tmp = tree->root;
    while (tmp) {
        printf(" node data => %d\n", tmp->data);
        tmp = tmp->left;
    }
    tmp = tree->root;
    while (tmp) {
        printf(" node data => %d\n", tmp->data);
        tmp = tmp->right;
    }
}