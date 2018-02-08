#include "stdio.h"
#include "string.h"
#include "hello.h"
#include "common.h"

int main(int argc, char *argv[])
{
	char s[100], s1[100];
	printf("Please input tow char:\n");
	scanf("%s%s", &s, &s1);
	printf("Your input is %s and %s \n", s, s1);
	bool result = equals(s, s1);
	printf("equals result: %d\n", result);
	
	hello("Tom");
	int i = 2, j = 3;
	printf("%d + %d = %d\n", i, j, add(i, j));

	char config[1024] = "CP=&&VER=19700101000000&[{\"SysVer\":\"ZY-720\",\"SysDate\":\"19700101000000\",\"SysKv\":\"0.001283\",\"SysBv\":\"-0.003107\",\"SysKi\":\"0.005082\",\"SysBi\":\"0.023885\",\"SysRs485BR\":\"9600\",\"SysRs485XYJG\":\"5\",\"SysRs485WM\":\"1\",\"SysRs232BR\":\"9600\",\"SysRs232JY\":\"0\",\"SysRs232SB\":\"1\",\"SysRs232WM\":\"1\",\"SysRs232DT\":\"0\",\"SysNET\":\"111\",\"SysZF\":\"0\",\"SysGsmApn\":\"cmnet\",\"SysGsmUN\":\"\",\"SysGsmPW\":\"\",\"SysGsmIp\":\"112.54.97.178\",\"SysGsmP\":\"23473\",\"SysGsmID\":\"yd720\",\"Sys3GApn\":\"ctnet\",\"Sys3GUN\":\"card\",\"Sys3GPW\":\"card\",\"Sys3GIp\":\"112.54.97.178\",\"Sys3GP\":\"23473\",\"Sys3GID\":\"dx720\",\"SysDhcp\":\"1\",\"SysLIp\":\"192.168.1.64\",\"SysSM\":\"255.255.255.0\",\"SysGW\":\"192.168.1.1\",\"SysDNS\":\"192.168.1.1\",\"SysLanIp\":\"112.54.97.178\",\"SysLanP\":\"23473\",\"SysLanID\":\"lan720\",\"SysDevWM\":\"1\",\"SysYuRe\":\"1\",\"SysDevJGMode\":\"15\",\"SysAlarmIn\":\"1\"},{\"SysDevJG\":\"\"},{\"SysAlarmOut3\":\"\"}]&&";
	
	char keys[][16] = {"SysDate", "SysKv", "SysBv", "SysGsmIp"};

	int keys_len = sizeof(keys) / sizeof(keys[0]);

	printf("keys len: %d\n", keys_len);
	
	struct ConfigKey kvs[keys_len];

	parse_config(config, keys, keys_len, kvs);

	for(int i=0; i<keys_len; i++)
	{
		printf("Data %d: %s = %s\n", i, kvs[i].key, kvs[i].val);
	}

	getchar();
	return 0;
}
