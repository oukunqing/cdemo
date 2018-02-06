#include "stdio.h"

int main(int argc, char* argv[])
{
    printf("Fibonacci sequence\n");
    printf("Please input a number:");
    int c = 0;
    while(scanf("%d", &c) == 1)
    {
        if(c <= 0)
        {
            break;
        }
        long n1 = 1, n2 = 1;
        for(int i=1; i<=c; i++)
        {
            printf("%12ld %12ld", n1, n2);
            if(i % 2 == 0)
            {
                printf("\n");
            }
            n1 = n1 + n2;
            n2 = n1 + n2;
        }

        printf("\nPlease input a number:");
    }

    getchar();

    return 0;
}

