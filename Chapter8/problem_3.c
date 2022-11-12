#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_node {
    int key;
    int value;
    struct s_node *next;
}   t_node;

typedef struct s_bucket {
    int count;
    struct s_node *head;
}   t_bucket;

int M, n, q;
int diffCount;
int firstHashValue;
t_bucket *ht = NULL;

int insertNode(int value, int k);
int  hashFunction(int value);
int  hashQFunction(int value);
void printHash();
void searchHash(int value);
//int deleteHash(int value);

int main(void) {
    bool quit = true;
    scanf(" %d %d %d", &M, &n, &q);
    ht = (t_bucket *)malloc(sizeof(t_bucket) * M);
    for (int i = 0; i < M; i++) {
        ht[i].count = 0;
    }
    while (quit) {
        char c;
        int k;
        scanf(" %c", &c);
        switch (c)
        {
        case 'i' :
            scanf(" %d", &k);
            firstHashValue = hashFunction(k);
            printf("%d\n", insertNode(k, firstHashValue));
            break ;
        // case 'd' :
        //     scanf(" %d", &k);
        //     printf("%d\n",deleteHash(k));
        //     break ;
        case 's' :
            scanf(" %d", &k);
            searchHash(k);
            break ;
        case 'p' :
            printHash();
            break ;
        case 'e' :
            printHash();
            quit = false;
            break ;
        default:
            break;
        }
    }
    free(ht);
    exit(0);
    return (0);
}

int insertNode(int value, int k) {
    t_node *newNode = (t_node *)malloc(sizeof(t_node));
    newNode->key = k;
    newNode->value = value;
    newNode->next = NULL;
    if (ht[k].count == 0) {
        ht[k].head = (t_node *)malloc(sizeof(t_node));
        ht[k].head->next = newNode;
        ht[k].count++;
    }
    else {
        printf("C");
        int diff = hashQFunction(value);
        diffCount++;
        k = insertNode(value, (firstHashValue + (diffCount * diff)) % M);
    }
    diffCount = 0;
    return (k);
}

int hashFunction(int value) {
    return (value % M);
}

int hashQFunction(int value) {
    return (q - (value % q));
}

void printHash() {
    for (int i = 0; i < M; i++) {
        if (ht[i].count > 0) {
            t_node *tmp = ht[i].head->next;
            while (tmp) {
                printf(" %d",tmp->value);
                tmp = tmp->next;
            }
        }
        else {
            printf(" 0");
        }
    }
    printf("\n");
}

void searchHash(int value) {
    int finding = 0;
    for (int i = 0; i < M; i++) {
        if (ht[i].count > 0) {
            t_node *tmp = ht[i].head->next;
            int counting = 0;
            while (tmp) {
                counting++;
                if (value == tmp->value) {
                    finding = counting;
                    printf("%d %d\n", i, tmp->value);
                    break ; 
                }
                tmp = tmp->next;
            }
        }
    }
    if (finding == 0) {
        printf("-1\n");
    }
}

// int deleteHash(int value) {
//     int deleting = 0;
//     for (int i = 0; i < M; i++) {
//         if (ht[i].count > 0) {
//             t_node *tmp = ht[i].head->next;
//             t_node *before_tmp = ht[i].head;
//             int counting = 0;
//             while (tmp) {
//                 counting++;
//                 if (value == tmp->value) {
//                     before_tmp->next = tmp->next;
//                     tmp->next = NULL;
//                     free(tmp);
//                     deleting = counting;
//                     break ; 
//                 }
//                 before_tmp = tmp;
//                 tmp = tmp->next;
//             }
//         }
//     }
//     return (deleting);
// }