#define bool int
#define true 1
#define false 0

struct ConfigKey
{
	char key[16];
	char val[64];
};

int add(int i, int j);

bool equals(char s[], char s1[]);

void clear_array(char s[], int len);

void parse_config(char s[], char keys[][16], int keys_len, struct ConfigKey kvs[]);

bool exists(char s[], char keys[][16], int keys_len);