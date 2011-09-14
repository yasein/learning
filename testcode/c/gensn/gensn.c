#include<stdio.h>
#include<string.h>
#include<time.h>

// polynomial value for ccitt
#define P_CCITT         0x1021

// ccitt_byte_crc_value -- Calculate byte CRC
static unsigned short ccitt_byte_crc_value(int byte)
{
    int i;
    unsigned short crc, c;

    crc = 0;
    c = ((unsigned short) byte) << 8;

    for (i = 0; i < 8; i++) {
        if ((crc ^ c) & 0x8000)
            crc = (crc << 1) ^ P_CCITT;
        else
            crc = crc << 1;
        c = c << 1;
    }
   return crc;
}

// update_crc_ccitt -- Calculate a new CRC-CCITT value based on the previous
//                     value of the CRC and the next byte of the data to be
//                     checked
unsigned short update_crc_ccitt(unsigned short crc, char c)
{
    unsigned short tmp, short_c;
    short_c = 0x00ff & (unsigned short) c;

    tmp = (crc >> 8) ^ short_c;
    crc = (crc << 8) ^ ccitt_byte_crc_value(tmp);
    return crc;
}

// crc_ccitt_lib -- Calculate a new CRC-CCITT value based on the previous
//                  value of the CRC and the next string to be checked
unsigned short crc_ccitt_lib(unsigned short crc, unsigned char const *data, int len)
{
    while (len--)
        crc = update_crc_ccitt(crc, *data++);
    return crc;
}

int rand_between(int low, int high)
{
    if(low >= high) return low;
        return low + (rand()%(high-low));
}

#define FTK_SN_SZ 16
#define FTM_SN_PREFIX "FTM"

char* ftm_generate_sn()
{
    unsigned short checksum;
    static char sn[FTK_SN_SZ + 1] = {0};
    memset(sn, 0, sizeof(sn));
    strcat(sn, FTM_SN_PREFIX);
    strcat(sn, "200");
    {
        int i, idx = strlen(FTM_SN_PREFIX) + 3;
        for(i = idx; i < FTK_SN_SZ -2; i++)
        {
            sn[i] = (char)rand_between('0','9');
        }
    }
    checksum = (crc_ccitt_lib(0, (const unsigned char*)sn, FTK_SN_SZ - 2)>>8);
    sprintf(&sn[FTK_SN_SZ-2], "%02x", checksum);
    return sn;
}

int main(int argc, char* argv[])
{
    int i = 0;
    int cnt = 10;
    if(argc > 1)
        cnt = atoi(argv[1]);
    
    srand(time(NULL));
    for(i = 0; i < cnt; i++)
        printf("%s\n", ftm_generate_sn());
    return 0;
}

