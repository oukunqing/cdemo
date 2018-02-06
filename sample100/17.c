#include "stdio.h"

int main(int argc, char* argv[])
{
    char c;
    int letters = 0, space = 0, digit = 0, other = 0;
    printf("please input some characters:\n");
    while((c=getchar()) != '\n')
    {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            letters++;
        }
        else if(c == ' ')
        {
			space++;
        }
		else if(c >= '0' && c <= '9')
        {
			digit++;
		}
		else
		{
			other++;
		}
    }

    printf("all in all: char=%d, space=%d, digit=%d, other=%d\n", letters, space, digit, other);
    getchar();
    return 0;
}
