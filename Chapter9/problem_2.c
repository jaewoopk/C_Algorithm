#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int arr[7][7] = {
    {0,0,0,0,0,0,0},
    {0,0,1,1,1,0,2},
    {0,1,0,1,0,0,0},
    {0,1,1,0,0,4,0},
    {0,1,0,0,0,0,0},
    {0,0,0,4,0,4,3},
    {0,2,0,0,0,3,0}
};

int main(void) {
    bool quit = true;

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
            for (int i = 1; i <= 6; i++) {
                if (arr[k][i] != 0) {
                    printf(" %d %d",i,arr[k][i]);
                }
            }
            printf("\n");
            break ;
        case 'm' :
            scanf(" %d %d %d", &a, &b, &w);
            if ((a < 1 || a > 6) || (b < 1 || b > 6)) {
                printf("-1\n");
                break ;
            } 
            arr[a][b] = w;
            arr[b][a] = w;
            break ;
        case 'q' :
            quit = false;
            break ;
        }
    }
    exit(0);
    return (0);
}