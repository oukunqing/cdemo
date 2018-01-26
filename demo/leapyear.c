#include "stdio.h"
#define bool _Bool

bool isLeapYear(int year);

int main(int argc, char *argv[])
{
    int year;
    while(scanf("%d*c", &year) == 1)
    {
	if(year <= 0)
	{
	    break;
	}
	if(isLeapYear(year))
	{
 	    printf("%d year is leap year.\n", year);
	}
	else
	{
	    printf("%d year is normal year.\n", year);
	}
    }
    getchar();
    return 0;

}

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}
