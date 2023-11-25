#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void main() {
    int n, x;
    int a = 0, b = 1;
    int sum = 0;
    int i=0;

    printf("Enter n and x: ");
    scanf("%d %d", &n, &x);

    printf("Nth element is: %d\n", fibonacci(n));
    int j=n;
    printf("The Fibonacci Series\n");
    while(i<x)
    {
        printf("%d\t",fibonacci(j++));
        i++;
    }
}