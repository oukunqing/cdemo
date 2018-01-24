#include "stdio.h"

int main(int argc, char* argv[])
{
    int num;
    long long total;
    printf("Please input a number:\n");
    while(scanf("%d", &num) != EOF)
    {
	total = 0;

        for(int i=1; i<=num; i++)
	{
            total += i; 
	}

	printf("%d jiecheng = %ld\n", num, total);
	printf("Please input a number:\n");
    }
    getchar();
    return 0;
}
