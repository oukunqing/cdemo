
#include<stdio.h>
#include<stdlib.h>
#include"cJSON.h"
 

char json_data_buf[1000];
	char *json_buf;
double  test_json_j=3.1415926;
void zhu_json_data(void)
{

	cJSON *root;
	
	char *temp_json_buf;
	///temp_json_buf= json_data_buf;
      /*create json string root*/
     root = cJSON_CreateObject();
    
         cJSON * js_body ;
 
         const char *const body = "body";
         cJSON_AddItemToObject(root, body, js_body=cJSON_CreateObject());
				cJSON_AddNumberToObject(js_body,"value",125.78);
         cJSON_AddStringToObject(js_body,"name","xiaohui");
         
         test_json_j++;
	
		//		json_buf=CoKmalloc(500);
		//	if(json_buf!=0)
		//	{
	//			json_buf = cJSON_PrintUnformatted(root);
		//			strcpy(json_data_buf,json_buf);
		//		CoKfree(json_buf);
	//		}
						temp_json_buf = cJSON_PrintUnformatted(root);
      //  if(s){
          //  DEBUG("create js string is %s\n",s);
//            // free(s);
if(temp_json_buf)
{
				strcpy(json_data_buf,temp_json_buf);
	CoKfree(temp_json_buf);
}
       /// 	}
       // json_buf = cJSON_PrintUnformatted(root);
       
         cJSON_Delete(root);


}



int main(int argc, const char *argv[])
{

zhu_json_data();

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