
#include<stdio.h>
#include<stdlib.h>
#include"cJSON.h"


 
int main(int argc, const char *argv[])
{
	cJSON *root;
	
	char *temp_json_buf;

     root = cJSON_CreateObject();
    
         cJSON * js_body ;
 
         const char *const body = "body";
         cJSON_AddItemToObject(root, body, js_body=cJSON_CreateObject());
				cJSON_AddNumberToObject(js_body,"value",125.78);
			cJSON_AddStringToObject(js_body,"name","xiaohui");
   
		temp_json_buf = cJSON_PrintUnformatted(root);
		printf("interlace: %s\n", temp_json_buf);
        cJSON_Delete(root);


	getchar();

	return 0;
}