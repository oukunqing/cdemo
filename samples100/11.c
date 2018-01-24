#include "stdio.h"

int main(int argc, char* argv[])
{
    int c = 0;
    while(scanf("%d", &c) != -1)
    {
        long i = 1, j = 1;

        for(int m = 1; m <= c; m++)
        {
	    printf("%12ld %12ld \n", i, j);
            i = i + j;
	    j = i + j;
        }
    }
    getchar();
    return 0;
}
