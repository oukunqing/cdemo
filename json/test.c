#include <string.h>
#include <stdio.h>
#include "cJSON.h"

void printntab(int iCnt)
{
    int i = 0;
    for(i = 0; i < iCnt; i++)
    {
        printf("\t");
    }
}

int parseJson(cJSON * pJson, int iCnt)
{
    if(NULL == pJson)
    {
        return -1;
    }
    switch(pJson->type)
    {
        case cJSON_False :
            {
                printf("%s : %d\n", pJson->string, pJson->valueint);
            }
            break;
        case cJSON_True :
            {
                printf("%s : %d\n", pJson->string, pJson->valueint);
            }
            break;
        case cJSON_NULL :
            {
                printf("%s : NULL\n", pJson->string);
            }
            break;
        case cJSON_Number :
            {
                printf("%s : %d | %lf\n", pJson->string, pJson->valueint, pJson->valuedouble);
            }
            break;
        case cJSON_String :
            {
                printf("%s : %s\n", pJson->string, pJson->valuestring);
            }
            break;
        case cJSON_Array  :
        case cJSON_Object :
            {
                int iSize = cJSON_GetArraySize(pJson);
                int i = 0;
                iCnt++;
                printf("%s : {\n", NULL == pJson->string ? "" : pJson->string);
                for(i = 0; i < iSize; i++)
                {
                    printntab(iCnt);
                    cJSON * pSub = cJSON_GetArrayItem(pJson, i);
                    parseJson(pSub, iCnt);
                }
                printntab(iCnt);
                printf("}\n");
            }
            break;
        default :
            return -1;
            break;
    }
}

int main(int argc, char *argv[])
{
    char * xjson =
        "{\
            \"aStr\": \"aaaaaaa\", \
            \"subobject_1\": \
            { \
                \"bStr\": \"bbbbbbb\", \
                \"subobject_2\": \
                {\
                    \"cStr\": \"ccccccc\"\
                } \
            }, \
            \"xStr\": \"xxxxxxx\" \
        }";
    cJSON * pJson = cJSON_Parse(xjson);
    if(NULL == pJson)
    {
        return -1;
    }
    parseJson(pJson, 0);

	getchar();

	return 0;
}