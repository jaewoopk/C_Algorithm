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
void insertItem(t_node **node, int k);
t_node *treeSearch(t_node *node, int k);
void printTree(t_node *node);
int removeElement(t_node *node, int k);
bool isExternal(t_node *w);
// bool isInternal(t_node *w);
t_node *inOrderSucc(t_node *w);

int main(void) {
	t_node *root = NULL;
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
            insertItem(&root, k);
            break ;
        case 'd' :
            scanf(" %d", &k);
            int tmps = removeElement(root, k);
            if (tmps == -1) {
                printf("X\n");
            }
            else {
                printf("%d\n",tmps);
            }
            break ;
        case 's' :
            scanf(" %d", &k);
            t_node *tmp = treeSearch(root, k);
            if (isExternal(tmp)) {
                printf("X\n");
            }
            else {
                printf("%d\n",tmp->key);
            }
            break ;
        case 'p' :
            printTree(root);
            printf("\n");
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

bool isExternal(t_node *w) {
    if (!w) {
        return true;
    }
    return false;
}

t_node *treeSearch(t_node *node, int k) {
    if (isExternal(node)) {
        return node;
    }
    if (k == node->key) {
        return node;
    }
    else if (k < node->key) {
        return treeSearch(node->lChild, k);
    }
    else if (k > node->key) {
        return treeSearch(node->rChild, k);
    }
    return node;
}

void insertItem(t_node **node, int k) {
    if (!(*node)) {
        t_node *newNode = (t_node *)malloc(sizeof(t_node));
        newNode->key = k;
        *node = newNode;
        return ;
    }
    if ((*node)->key < k) {
        insertItem(&((*node)->rChild), k);
        (*node)->rChild->parent = *node;
    }
    else if ((*node)->key > k){
        insertItem(&((*node)->lChild), k);
        (*node)->lChild->parent = *node;
    }
    else {
        return ;
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

int removeElement(t_node *node, int k) {
    t_node *w = treeSearch(node, k);
    t_node *tmp_w;
    if (isExternal(w)) {
        return -1;
    }
    tmp_w = w->lChild;
    if (!isExternal(tmp_w)) {
        tmp_w = w->rChild;
    }
    else {
        if (isExternal(w->rChild)) {
            if (w->parent->lChild) {
                if (w->parent->lChild->key == k)
                    w->parent->lChild = NULL;
            }
            else if (w->parent->rChild) {
                if (w->parent->rChild->key == k)
                    w->parent->rChild = NULL;
            }
            return k;
        }
    }
    if (isExternal(tmp_w)) {
        if (tmp_w == w->rChild) {
            w->key = w->lChild->key;
            w->lChild = NULL;
            return k;
        }
        else {
            w->key = w->rChild->key;
            w->rChild = NULL;
            return k;
        }
    }
    else {
        t_node *y = inOrderSucc(w);
        w->key = y->key;
        removeElement(y, y->key);
    }
    return k;
}

t_node* inOrderSucc(t_node* w) {
	t_node* tmp = w->rChild;

	if (isExternal(tmp))
		return tmp;
	while (tmp->lChild) {
        tmp = tmp->lChild;
    }
	return tmp;
}