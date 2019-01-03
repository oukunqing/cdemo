
#include<stdio.h>
#include<stdlib.h>
#include"cJSON.h"


 
int main(int argc, const char *argv[])
{
	cJSON *root, *fmt, *json, *format;
	char *out;
	int i;

	//创建JSON字符串
	root = cJSON_CreateObject();

	cJSON_AddItemToObject(root, "name", cJSON_CreateString("Jack"));
	cJSON_AddItemToObject(root, "format", fmt = cJSON_CreateObject());
	cJSON_AddStringToObject(fmt, "type", "rect");
	cJSON_AddNumberToObject(fmt, "width", 1000);
	cJSON_AddNumberToObject(fmt, "height", 125.78);
	cJSON_AddFalseToObject(fmt, "interlace");
	cJSON_AddNumberToObject(fmt, "frame rate", 24);
	cJSON_AddItemToObject(root, "code", cJSON_CreateString("dev01"));

	out = cJSON_Print(root);	//out中保存的是JSON格式的字符串
	cJSON_Delete(root);			//删除cJSON

	printf("%s\n", out);		//终端打印输出
 
	json = cJSON_Parse(out);	//解析JSON格式的字符串
	free(out);					//释放字符串空间

	if(!json)
	{
		printf("Error before:[%s]\n", cJSON_GetErrorPtr());
	}
	else
	{
		//提取出各个数据并打印输出
		char *name = cJSON_GetObjectItem(json, "name") -> valuestring;
		printf("name: %s\n", name);

		format = cJSON_GetObjectItem(json, "format");
		char *type = cJSON_GetObjectItem(format, "type") -> valuestring;
		printf("type: %s\n", type);

		int width = cJSON_GetObjectItem(format, "width") -> valueint;
		printf("width: %d\n", width);

		double height = cJSON_GetObjectItem(format, "height") -> valuedouble;
		printf("height: %f\n", height);

		int framerate = cJSON_GetObjectItem(format, "frame rate") -> valueint;
		printf("framerate: %d\n", framerate);
		
		int interlace = cJSON_GetObjectItem(format, "interlace") -> valueint;
		printf("interlace: %d\n", interlace);
		
	}

	getchar();

	return 0;
}