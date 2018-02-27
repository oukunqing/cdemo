#define __STDC_VERSION__199901L
#define bool int
#define true 1
#define false 0

struct ConfigKey
{
	char key[16];
	char val[64];
};

struct Message
{
	char QN[20];
	char MN[32];
	char CN[4];
	char PW[6];
	char Crc[4];
	char Flag[1];
	char CP[960];
};

int add(int i, int j);

bool equals(char s[], char s1[]);

void clear_array(char s[], int len);

void parse_config(char s[], char keys[][16], int keys_len, struct ConfigKey kvs[]);

bool exists(char s[], char keys[][16], int keys_len);

void parse_message(char s[], struct Message *msg);

void push_message(char val[], char key[], struct Message *msg);

void split_message (char s[], char con[]);
