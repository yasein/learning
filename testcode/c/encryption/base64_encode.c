#include<openssl/bio.h>
#include<openssl/evp.h>
#include<string.h>

int b64encode_seed()
{
    BIO *bio, *b64;
    char message[] = "hello world\n";

    b64 = BIO_new(BIO_f_base64());
    bio = BIO_new_fp(stdout, BIO_NOCLOSE);
    bio = BIO_push(b64, bio);
    BIO_write(bio, message, strlen(message));
    BIO_flush(bio);
    BIO_free_all(bio);
    return 0;
}
int b64decode_seed()
{
    BIO *bio, *b64, *bio_out;
    char inbuf[512];
    int inlen;
    b64 = BIO_new(BIO_f_base64());
    bio = BIO_new_fp(stdin, BIO_NOCLOSE);
    bio_out = BIO_new_fp(stdout, BIO_NOCLOSE);
    bio = BIO_push(b64, bio);
    while((inlen = BIO_read(bio, inbuf, 512)) > 0)
        BIO_write(bio_out, inbuf, inlen);
    BIO_free_all(bio);
    return 0;
}

int b64encode(unsigned char *input, unsigned char ** output)
{
    BIO *bio, *b64;
    if(input == NULL || out == NULL)
        return -1;
    
    b64 = BIO_new(BIO_f_base64());
    
    return 0;
}
int b64decode()
{
}
int main()
{
    b64encode();
    b64decode();
    return 0;
}
