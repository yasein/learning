#include<time.h>
#include<stdio.h>

int main()
{
    struct timespec now;
    clock_gettime(CLOCK_MONOTONIC, &now);
    unsigned long long lnow = now.tv_sec*1000000000LL + now.tv_nsec;
    printf("tick time %u\n", lnow);
    return 0;
}
