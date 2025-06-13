#include <stdio.h>

int main() {
    int find = 10;
    int collection[] = {3, 10, 4, 6, 7};
    int i;

    // Check every element in the collection for the occurrence of 10
    for (i = 0; i < 5; i++) {
        if (collection[i] == find)
            break;
    }

    if (i < 5)
        printf("Found\n");
    else
        printf("Not found\n");

    return 0;
}
