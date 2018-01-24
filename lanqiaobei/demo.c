#include "stdio.h"

int main(int argc, char* argv[])
{

    int m, n, total;
    printf("Please input two number:\n");

    scanf("%d%d", &m, &n);
    printf("m=%d, n=%d\n", m, n);

    total = m + n;
    printf("%d\n", total);

    getchar();
    return 0;
}
