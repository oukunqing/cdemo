#include "stdio.h"

int main(int argc, char* argv[])
{
    int day, x1, x2;
    day = 9;
    x2 = 1;

    while(day > 0)
    {
        x1 = (x2 + 1) * 2;
		x2 = x1;
		day--;
    }
	printf("The total is %d.\n", x1);

	getchar();
    return 0;
}