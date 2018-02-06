#include "stdio.h"
#include "string.h"

#define RegisterCN 9021
#define CN "9021"

#define bool int
#define true 1
#define false 0

bool equals(char s[], char s1[])
{
	int len = strlen(s);
	int len1 = strlen(s1);
	if(len != len1)
	{
		return false;
	}
	for(int i=len-1; i>=0; i--)
	{
		if(s[i] != s1[i])
		{
			return false;
		}
	}
	return true;
}


int main(int argc, char *argv[])
{
	int num = 9021;
	if(num == RegisterCN)
	{
		printf("数字相等\n");
	}
	char cn[] = {"90210"};
	printf("%s\n", cn);
	
	if(0 == strcmp(cn,CN))
	{
		printf("字符串相等\n");
	}
	
	bool result = equals(cn, CN);

	printf("equals result: %d\n", result);

	printf("请输入两个字符串：\n");
	char s[100], s1[100];
	scanf("%s%s", &s, &s1);

	printf("%s %s\n", s, s1);
	printf("是否相等: %d\n", equals(s, s1));

	getchar();
	return 0;
}