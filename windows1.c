#include "stdio.h"
#include "windows.h"

int main(int argc, char *argv[])
{

    MessageBox(NULL, "我的第一个窗口程序", "hello world", MB_OK);

    getchar();
    return 0;
}