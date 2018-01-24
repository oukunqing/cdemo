#include "stdio.h"

int getArrayLen(int* numbers);

int main(int argc, char* argv[])
{
    int numbers[] = {12, 23, 5, 10, 96, 18, 54, 72, 99};
    int i, j, c;
    c = sizeof(numbers) / sizeof(numbers[0]);
    //c = getArrayLen(numbers);
    printf("numbers length: %d\n", c);
    for(i=0; i<c; i++)
    {
        for(j=c-1; j>=i; j--)
	{
            if(numbers[j] > numbers[j+1])
	    {
                int tmp = numbers[j];
		numbers[j] = numbers[j+1];
		numbers[j+1] = tmp;
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
/*
int getArrayLen(int* numbers)
{
    return sizeof(numbers);
    //return 9;
    //return (sizeof(numbers) / sizeof(numbers[0]));
}
*/
