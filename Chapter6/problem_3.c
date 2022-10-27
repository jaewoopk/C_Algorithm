#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int rFindElement(int l, int r, char *c, int index);

int main(void) {
	// binary search about number
	int a, b, num, ans;

    scanf(" %d %d %d",&a,&b,&num);
    char *str = (char *)malloc(sizeof(char) * num);

    scanf(" %s",str);
    ans = rFindElement(a, b, str, 0);
    printf("%d\n",ans);
    return (0);
}

int rFindElement(int l, int r, char *str, int index) {
    if (l >= r) {
        return (l + r) / 2;
    }
    int mid = (l + r) / 2;
    int ans = mid;
    if (str[index] == 'Y') {
        ans = rFindElement(mid + 1, r, str, index + 1);
    }
    else if (str[index] == 'N') {
        ans = rFindElement(l, mid, str, index + 1);
    }
    return ans;
}
