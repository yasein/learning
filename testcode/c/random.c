#include<time.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
static int rand_between(int low, int high)
{
    if(low >= high) return low;
        return low + (rand()%(high-low));
}

char *gen_sn()
{
    static char sn[10] = {0};
    static char range[3][2] = {{'0','9'}, {'a','z'}, {'A','Z'}};

    int i = 0, j = 0;
    for(i = 0; i < 9; i++)
    {
        j = rand_between(0, 2);
        sn[i] = (char)rand_between((int)range[j][0], (int)range[j][1]);
    }
    sn[9] = '0';
    printf("%s \n",sn);
    return sn;
}
int main()
{
    int i = 0;
    srand(time(NULL));
    for(i = 0; i< 10; i++)
    {
        //srand(time(NULL));
        gen_sn();
        //usleep(123000*i);
    }    
    return 0;
}
