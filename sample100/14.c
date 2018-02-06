#include "stdio.h"

int main(int argc, char* argv[])
{
    int n,i;
    printf("please input a number:\n");

    while(scanf("%d", &n) == 1)
    {
		if(n <= 0)
		{
			break;
		}
	    printf("%d = ",n);
	    for(i = 2; i <= n; i++)
	    {
			while(n != i)
			{
		     	if(n % i == 0)
		     	{
					printf("%d * ", i);
					n = n / i;
		     	}
		     	else
		     	{
		        	break; 
		     	} 
			}
	    } 
	    printf("%d\n", n);

        printf("please input a number:\n");
    }
    getchar();
    return 0;
}