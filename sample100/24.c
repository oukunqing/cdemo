#include "stdio.h"

int main(int argc, char *argv[])
{
    int n, t, number = 20;
    float a = 2, b = 1, s = 0;
    for(n = 1; n <= number; n++)
    {
        s = s + a / b;
        t = a;
        a = a + b;
        b = t;
    }

    printf("sum is %9.8f\n", s);
    getchar();
    return 0;
}