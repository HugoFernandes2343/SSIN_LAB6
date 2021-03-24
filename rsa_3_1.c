/* bn_sample.c */
#include <stdio.h>
#include <openssl/bn.h>
#define NBITS 256

void printBN(char *msg, BIGNUM * a)
{
    /* Use BN_bn2hex(a) for hex string
    * Use BN_bn2dec(a) for decimal string */
    char * number_str = BN_bn2hex(a);
    printf("%s %s\n", msg, number_str);
    OPENSSL_free(number_str);
}

int main ()
{
    BN_CTX *ctx = BN_CTX_new();
    BIGNUM *p = BN_new();
    BIGNUM *q = BN_new();
    BIGNUM *e = BN_new();

    // Initialize p, q, e
    //BN_generate_prime_ex(p, NBITS, 1, NULL, NULL, NULL);
    //BN_dec2bn(&q, "273489463796838501848592769467194369268");
    // BN_rand(e, NBITS, 0, 0);

    BN_hex2bn(&p, "F7E75FDC469067FFDC4E847C51F452DF");
    BN_hex2bn(&q, "E85CED54AF57E53E092113E62F436F4F");
    BN_hex2bn(&e, "0D88C3");

    BIGNUM *n = BN_new();
    // n = p*q
    BN_mul(n, p, q, ctx);
    printBN("p * q = ", n);

    BIGNUM *res = BN_new();
    // res = pˆq mod e
    BN_mod_exp(res, p, q, e, ctx);
    printBN("pˆq mod e = ", res);

    return 0;
}