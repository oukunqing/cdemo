#include "stdio.h"
#include "string.h"
#include "stdlib.h"
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

void parse_message(char s[], struct Message *msg)
{
	char con[1024] = {0};
	split_message(s, con);

	printf("parse_message: %s\n", con);
	char key[16] = {0};
	char val[960] = {0};
	bool isVal = false;
	int i = 0, m = 0;
	int len = strlen(con) + 1;
	bool isCP = false;
	bool success = false;
	printf("con len: %d\n", len);

	for(m = 0; m < len; m++)
	{
		char _con = con[m];

		if('=' == _con && !isCP)
		{
			isVal = true;
			if(equals(key, "CP"))
			{
				isCP = true;
			}
			i = 0;
		}
		else if(!isVal)
		{
			key[i] = _con;
			i++;
		}
		else
		{
			if((!isCP && ';' == _con) || m >= len - 1)
			{
				printf("key: %s, val: %s\n", key, val);
				i = 0;
				
				push_message(val, key, msg, &success);
				if(!success)
				{
					printf("%s parse failed.\n", key);
				}

				clear_array(key, 16);
				clear_array(val, 960);
				isVal = false;
			}
			else
			{
				val[i] = _con;
				i++;
			}
		}
	}

	//printf("msg: QN=%s, MN=%s, CN=%s, Flag=%s, PW=%s, CP=%s\n", (*msg).QN, (*msg).MN, (*msg).CN, (*msg).Flag, (*msg).PW, (*msg).CP);

}

void push_message(char val[], char key[], struct Message *msg, bool *success)
{
	*success = true;

	if(equals(key, "QN"))
	{
		strcpy((*msg).QN, val);
	}
	else if(equals(key, "MN"))
	{
		strcpy((*msg).MN, val);
	}
	else if(equals(key, "CN"))
	{
		strcpy((*msg).CN, val);
	}
	else if(equals(key, "PW")) 
	{
		strcpy((*msg).PW, val);
	}
	else if(equals(key, "Flag")) 
	{
		strcpy((*msg).Flag, val);
	}
	else if(equals(key, "CP")) 
	{
		char con[960] = {0};
		parse_content(val, con, success);
		if(success)
		{
			strcpy((*msg).CP, con);
		}
	}
}

void parse_content(char s[], char con[], bool *success)
{
	int i = 0, m = 0;
	int len = strlen(s);
	*success = true;
	while(*s)
	{
		char c = *s;
		if(i >= 2 && i < len - 2)
		{
			con[m] = c;
			m++;
		}
		else if(i < len - 1)
		{
			if(c != '&')
			{
				*success = false;
				break;
			}
		}
		i++;
		++s;
	}
}

void split_message (char s[], char con[])
{
	printf("parse_message: %s\n", s);
	int len = 0;
	int idx = 0;
	int pos = 0;
	int i = 0;
	int HEAD_CHAR_LENGTH = 2;
	int LENGTH_NUMBER = 4;

	char num[5] = {0};
	char crc[5] = {0};

	while(*s)
	{
		if(pos < 2)
		{
			if('#' != *s)
			{
				printf("not have message head\n");
				break;
			}
		}
		else if(pos >= HEAD_CHAR_LENGTH && pos < (HEAD_CHAR_LENGTH + LENGTH_NUMBER))
		{
			num[pos-HEAD_CHAR_LENGTH] = *s;

			if(pos == HEAD_CHAR_LENGTH + LENGTH_NUMBER - 1)
			{
				len = atoi(num);
			}
		}
		else
		{
			if(idx < len)
			{
				con[idx] = *s;
				idx++;
			}
			else
			{
				if(i < 4)
				{
					crc[i] = *s;
					i++;
				}
				else
				{
					break;
				}
			}
		}
		pos++;
		++s;
	}
	printf("num: %d\n", len);
	printf("num: %s\n", num);
	printf("con: %s\n", con);	
	printf("crc: %s\n", crc);
}

void build_key_value(char con[], char key[], char prefix[], char val[])
{
	strncat(con, key, strlen(key));
	char symbol[4] = {0}, endSymbol[3] = {0};
	if(!equals(key, "CP"))
	{
		strcpy(symbol, "=");
		strcpy(endSymbol, ";");
	}
	else
	{
		strcpy(symbol, "=&&");
		strcpy(endSymbol, "&&");
	}
	strncat(con, symbol, strlen(symbol));
	strncat(con, prefix, strlen(prefix));
	strncat(con, val, strlen(val));
	strncat(con, endSymbol, strlen(endSymbol));
}

void build_message(struct Message msg, char con[1024], bool response)
{
	/*
	//char data[][64] = { "##", "QN=", msg.QN, ";", "MN=", msg.MN, ";"};
	struct ContentKey cons[] = {
		{"QN", &msg.QN}
	};

	char data[][64] = { "##", "QN=", "MN=", ";"};
	int len = sizeof(data) / sizeof(data[0]);
	int i;
	for(i = 0; i < len; i++)
	{
		strncat(con, data[i], strlen(data[i]));
	}*/

	char QN[22] = {0};
	build_key_value(QN, "QN", "", msg.QN);

	if(!response)
	{
		strncat(con, QN, strlen(QN));
	}
	build_key_value(con, "MN", "", msg.MN);
	build_key_value(con, "CN", "", msg.CN);
	build_key_value(con, "PW", "", msg.PW);
	build_key_value(con, "Flag", "", msg.Flag);
	build_key_value(con, "CP", response ? QN : "", msg.CP);
}