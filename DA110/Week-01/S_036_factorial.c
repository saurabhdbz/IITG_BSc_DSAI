#include <stdio.h>

int main() {
    int n = 6, fac = 1;

    while (n >= 1) {
        fac = fac * n;
        n = n - 1;
    }

    printf("The factorial is %d\n", fac);

    return 0;
}

