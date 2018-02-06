#include "stdio.h"
#include "string.h"
#include "common.h"

int add(int i, int j)
{
	return i + j;
}

bool equals(char s[], char s1[])
{
	int len = strlen(s);
	int len1 = strlen(s1);
	int i;
	if(len != len1)
	{
		return false;
	}
	for(i = len - 1; i>=0; i--)
	{
		if(s[i] != s1[i])
		{
			return false;
		}
	}
	return true;
}

void clear_array(char s[], int len)
{
	for(int i=0; i<len; i++)
	{
		s[i] = 0;
	}
}

void parse_config(char s[], char keys[][16], int keys_len, struct ConfigKey kvs[])
{
	printf("parse_config:\n%s\n", s);

	int key_len = 16, value_len = 64;
	char key[16] = {0}, value[64] = {0};
	int n = 0, i = 0, k = 0;

	while(*s)
	{
		if('"' == *s)
		{
			n++;
			i = 0;
		}
		else
		{
			if(1 == n)
			{
				key[i] = *s;
				i++;
			}
			else if(3 == n)
			{
				value[i] = *s;
				i++;
			}
		}
		if(4 == n)
		{
			printf("key: %s, value: %s\n", key, value);
			if(exists(key, keys, keys_len))
			{
				printf("==> %s = %s \n", key, value);
				//ConfigKey kv = {key, value};
				strcpy(kvs[k].key, key);
				strcpy(kvs[k].val, value);
				k++;
			}
			n = 0;
			clear_array(key, key_len);
			clear_array(value, value_len);
		}
		++s;
	}
}

bool exists(char s[], char keys[][16], int keys_len)
{
	for(int i=0; i<keys_len; i++)
	{
		if(equals(s, keys[i]))
		{
			return true;
		}
	}
	return false;
}