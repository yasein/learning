#include<openssl/aes.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int encrypt_seed(unsigned char*, unsigned char*, unsigned char **);
int decrypt_seed(unsigned char*, unsigned char*, unsigned char **);


int main()
{
    printf("hello ssl\n");
    unsigned char seed[] = "encrypt seed000000000";
    unsigned char udid[] = "FTM00101010";
    unsigned char *encrypt = NULL, *decrypt = NULL;
    
    encrypt_seed(seed, udid, &encrypt);
    
    decrypt_seed(encrypt, udid, &decrypt);

    printf("\n%s\n", decrypt);
 
}

const unsigned char secret_iv[] = "fortitokenmobile";
#define SEED_SIZE 40
#define IV_SIZE 16
int encrypt_seed(unsigned char *seed, unsigned char *udid, unsigned char** encrypt)
{
    static unsigned char enc[SEED_SIZE] = {0};
    static unsigned char iv[IV_SIZE] = {0}; 
    
    if(seed == NULL || udid == NULL || encrypt == NULL)
        return -1;
    memset(enc, 0, SEED_SIZE);
    memset(iv, 0, IV_SIZE);
    memcpy(iv, secret_iv, IV_SIZE);

    AES_KEY ekey;
    AES_set_encrypt_key(udid, 128, &ekey);
    
    AES_cbc_encrypt(seed, enc, SEED_SIZE, &ekey, iv, AES_ENCRYPT);

    *encrypt = enc;

    return 0;
}

int decrypt_seed(unsigned char *encrypt, unsigned char *udid, unsigned char **seed)
{
    static unsigned char dec[SEED_SIZE] = {0};
    static unsigned char iv[IV_SIZE] = {0};

    if(encrypt == NULL || udid == NULL || seed == NULL)
        return -1;

    memset(dec, 0, SEED_SIZE);
    memset(iv, 0, IV_SIZE);
    memcpy(iv, secret_iv, IV_SIZE);

    AES_KEY dkey;
    AES_set_decrypt_key(udid, 128, &dkey);
    
    AES_cbc_encrypt(encrypt, dec, SEED_SIZE, &dkey, iv, AES_DECRYPT);
    
    *seed = dec;
    
    return 0;
}




    
