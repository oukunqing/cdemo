#include "stdio.h"

void swap(int numbers[], int i, int j);

int main(int argc, char* argv[])
{
    int numbers[] = {12, 23, 5, 10, 96, 18, 54, 72, 99};
    int i, j, c;
    c = sizeof(numbers) / sizeof(numbers[0]);
    printf("numbers length: %d\n", c);

    int flag = 1; 

    for(i=0; i<c && flag == 1; i++)
    {
	flag = 0;
        for(j=c-1; j>=i; j--)
	{
            if(numbers[j] > numbers[j+1])
	    {
                int tmp = numbers[j];
		numbers[j] = numbers[j+1];
		numbers[j+1] = tmp;
		flag = 1;
	    }
	}
    }

    for(i=0; i<c; i++)
    {
    	printf("%d ", numbers[i]);
    }

    getchar();
    return 0;
}
