#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

int main()
{
    Tree t;
    CreateTree(&t);
    Insert(&t, 5);
    Insert(&t, 1);
    Insert(&t, 2);
    Insert(&t, 3);
    Insert(&t, 4);
    Insert(&t, 6);
    Insert(&t, 7);
    printf("\nTree size is %d", TreeSize(t));
    printf("\nTree height is %d\n", TreeHeight(t));
    ///**********************************************************///
    Delete(&t, 7);
    printf("\nTree size is %d", TreeSize(t));
    printf("\nTree height is %d\n", TreeHeight(t));
    Delete(&t, 6);
    printf("\nTree size is %d", TreeSize(t));
    printf("\nTree height is %d\n", TreeHeight(t));
    Delete(&t, 5);
    printf("\nTree size is %d", TreeSize(t));
    printf("\nTree height is %d\n", TreeHeight(t));
    Delete(&t, 4);
    printf("\nTree size is %d", TreeSize(t));
    printf("\nTree height is %d\n", TreeHeight(t));
    Delete(&t, 3);
    printf("\nTree size is %d", TreeSize(t));
    printf("\nTree height is %d\n", TreeHeight(t));
    Delete(&t, 2);
    printf("\nTree size is %d", TreeSize(t));
    printf("\nTree height is %d\n", TreeHeight(t));
    Delete(&t, 1);
    printf("\nTree size is %d", TreeSize(t));
    printf("\nTree height is %d\n", TreeHeight(t));
}
