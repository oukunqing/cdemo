#include <mysql/mysql.h>

#include <stdio.h>

#include <stdlib.h>

#define HOST "localhost"

#define USERNAME "sa"

#define PASSWORD "123qweQWE456"

#define DATABASE "wechat"

int main(void)

{

    MYSQL mysql;

    MYSQL_ROW row;

    MYSQL_RES *result;

    unsigned int num_fields;

    unsigned int i;

    mysql_init(&mysql);

    if (!mysql_real_connect(&mysql, HOST, USERNAME, PASSWORD, DATABASE, 0, NULL, 0))

    {

        printf("Connection failed,%s\n", mysql_error(&mysql));
    }

    mysql_query(&mysql, "set names utf8");

    if (!mysql_query(&mysql, "SELECT * FROM account"))

    {

        result = mysql_store_result(&mysql);

        if (!result)

        {

            perror("result error.");

            exit(1);
        }

        num_fields = mysql_num_fields(result);

        while (row = mysql_fetch_row(result))

        {

            for (i = 0; i < num_fields; i++)

            {

                printf("%s\t", row[i]);
            }

            printf("\n");
        }

        mysql_free_result(result);
    }

    mysql_close(&mysql);

    return 0;
}