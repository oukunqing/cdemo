#include <stdio.h>
    /* 字符串操作 */
    #include <string.h>
    
    int main(int argc, char *argv[]) {
        char str[] = "hello\0 world";
        /* str 在这里是一个指针，是字符串数组的第一个元素的地址 */
        printf("%d\n", &str[0] == str);
        /* 那么为什么printf打印一个地址的时候，会将整个字符串打印出来呢？*/
        /* 因为在存储字符串的时候，会将自动在字符串的最后添加一个\0，printf打印到\0截止 */
        printf("%s\n", str);
        /* 如果这样定义字符串数组，需要后面添加\0 */
        /* 只有字符串数组可以一直寻址到\0 */
        char arr[] = {'a','b','c','\0'};
        printf("%c\n", arr[0]);
        printf("%s\n", arr);
        /* 字符串数组的长度，不包含\0 */
        printf("%lu\n", strlen(arr));
    }