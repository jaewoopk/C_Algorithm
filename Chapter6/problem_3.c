#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void rFindElement(int t, int l, int r, char *c);

int main(void) {
    int a, b, num;

    scanf(" %d %d %d",&a,&b,&num);
    char *str = (char *)malloc(sizeof(char) * num);

    scanf(" %s",str);
    rFindElement(b, a, b, str);
    
    return (0);
}

void rFindElement(int t, int l, int r, char *c) {
    printf("%d\n", t);
    if (l > r) {
        return ;
    }
    int mid = (l + r) / 2;

    if (t == mid) {
        printf("%d",t);
        return ;
    }
    else if (*c == 'N') {
        c++;
        rFindElement(t, mid + 1, r, c);
    }
    else if (*c == 'Y') {
        c++;
        rFindElement(t, l, mid - 1, c);
    }
}