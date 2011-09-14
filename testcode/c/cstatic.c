#include<stdio.h>
#include"string.h"
void getresp(char **resp)
{
    static char hello[] = "hello\r\n";
    *resp = hello;
}
int main()
{
    char *resp = NULL;
    printf("s is :%s\n",resp);
    getresp(&resp);
    resp[2] = 'W';
    printf("%s\n", resp);
    printf("strlen is %s %d \n",resp, strlen(resp));
}

