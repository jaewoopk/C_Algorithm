#include <stdio.h>
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
t_node *findNode(t_tree *tree, int r);

int main(void) {
    int n;
    scanf(" %d", &n);

    t_tree *tree = (t_tree *)malloc(sizeof(t_tree));
    init(tree);
    for (int i = 0; i < n; i++) {
        int data, l, r;
        scanf(" %d %d %d",&data,&l,&r);
        addNode(tree, data, l, r);
    }
    printf("root data = %d\n",tree->root->data);
    printf("root->left data = %d\n",tree->root->left->data);
    printf("root->right data = %d\n",tree->root->right->data);
    return 0;
}

void init(t_tree *tree) {
    tree->root = (t_node *)malloc(sizeof(t_node));
}

void addNode(t_tree *tree, int data, int l, int r) {
    t_node *whereNode = findNode(tree, data);
    t_node *newNode_left = (t_node *)malloc(sizeof(t_node));
    t_node *newNode_right = (t_node *)malloc(sizeof(t_node));
    newNode_left->data = l;
    newNode_right->data = r;
    whereNode->data = data;
    whereNode->left = newNode_left;
    whereNode->right = newNode_right;
}

t_node *findNode(t_tree *tree, int r) {
    return tree->root;
}