#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct s_node {
    char ch;
    char next[1000];
    
}

int n, m;
int *in;
int *visit;
int *G;
char *str;
char **information;


int main(void) {
    scanf(" %d",&n);
    str = (char *)malloc(sizeof(char) * n);
    in = (int *)malloc(sizeof(int) * n);
    visit = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        scanf(" %c",str + i);
        in[i] = 0;
        visit[i] = 0;
    }
    scanf(" %d",&m);
    for (int i = 0; i < m; i++) {
        char start, end;
        scanf(" %c %c",&start, &end);
        for (int j = 0; j < n; j++) {
            if (str[j] == end) {
                in[j] += 1;
                break ;
            }
        }
    }
    exit(0);
    return (0);
}