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
void findAndAddNode(t_tree *tree, t_node *node, int data, int l, int r);
void getTreeData(t_node *node);

int main(void) {
    int n, s;
    scanf(" %d", &n);

    t_tree *tree = (t_tree *)malloc(sizeof(t_tree));
    init(tree);
    for (int i = 0; i < n; i++) {
        int data, l, r;
        scanf(" %d %d %d",&data,&l,&r);
        findAndAddNode(tree, tree->root, data, l , r);
        //getTreeData(tree->root);
    }
    scanf(" %d", &s);
    for (int i = 0; i < s; i++) {
        t_node *tmp = tree->root;
        int j = 0;
        char arr[101];
        scanf(" %s", arr);
        printf(" %d", tmp->data);

        while (arr[j]) {
            if (arr[j] == 'L') {
                tmp = tmp->left;
            }
            else if (arr[j] == 'R') {
                tmp = tmp->right;
            }
            printf(" %d", tmp->data);
            j++;
        }
        printf("\n");
    }
    return 0;
}

void init(t_tree *tree) {
    tree->root = (t_node *)malloc(sizeof(t_node));
}

void findAndAddNode(t_tree *tree, t_node *node, int data, int l, int r) {
    t_node *whereNode = node;
    if (whereNode->left) {
        findAndAddNode(tree, node->left, data, l, r);
    }
    if (whereNode->right) {
        findAndAddNode(tree, node->right, data, l, r);
    }
    if (whereNode->data == data) {
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
        return ;
    }
    if (!whereNode->left && !whereNode->right && whereNode->data != data && whereNode == tree->root) {
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
        return ;
    }
}

void getTreeData(t_node *node) {
    t_node *tmp = node;

    if (tmp->left) {
        getTreeData(node->left);
    }
    printf("node data => %d\n",node->data);
    if (tmp->right) {
        getTreeData(node->right);
    }
}