#include <stdio.h>
// Use this tool to visualize the stack: 
// https://pythontutor.com/render.html#mode=edit
// Function prototype
int factorial(int);

int main() {
    int n = 6;
    int fac;

    fac = factorial(n);

    printf("The factorial of %d is %d\n", n, fac);

    return 0;
}

// Recursive factorial function
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;  // Base case
    } else {
        return n * factorial(n - 1);  // Recursive case
    }
}
