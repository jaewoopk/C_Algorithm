#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct s_node {
    struct s_node *lChild;
    struct s_node *rChild;
    struct s_node *parent;
    int key;
} t_node;

int findElement(int key);
void insertItem(int key);
t_node *treeSearch(int key);
int removeElement(int key);
bool isExternal(t_node *w);
bool isInternal(t_node *w);
t_node *inOrderSucc(t_node *w);

int main(void) {
	t_node *root = (t_node *)malloc(sizeof(t_node));

    return (0);
}