#include "stdio.h"

int main(int argc, char* argv[])
{
    int x, y;
    double m1, m2;
    for(x=1; x<=150; x++)
    {
	y = x - 150;
	if(x * x * 24.5 == y * y * 32)
	{
	    printf("x = %d, y = %d\n", x, y);
	}
    }
    	
    getchar();
    return 0;
}
