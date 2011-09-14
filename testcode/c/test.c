#include<stdio.h>
#include<string.h>
int main()
{
    unsigned char sn[10] = {0};
    unsigned short chk = 15;
    sprintf(sn, "%02x", chk);
    printf(sn);
    const char sn2[] = "0f";
    unsigned int chk2 = 0;
    sscanf(sn2, "%x", &chk2);
    printf("\n%d\n", chk2);
    return 0;
}
