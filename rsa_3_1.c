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
    BIGNUM *one = BN_new();
    BN_hex2bn(&one, "1");

    BIGNUM *p = BN_new();
    BIGNUM *q = BN_new();
    BIGNUM *e = BN_new();

    // Initialize p, q, e
    BN_hex2bn(&p, "F7E75FDC469067FFDC4E847C51F452DF");
    BN_hex2bn(&q, "E85CED54AF57E53E092113E62F436F4F");
    BN_hex2bn(&e, "0D88C3");

    // n = p*q
    BIGNUM *n = BN_new();
    BN_mul(n, p, q, ctx);
    printBN("p * q = ", n);

    // res = pˆq mod e
    BIGNUM *res = BN_new();
    BN_mod_exp(res, p, q, e, ctx);
    printBN("pˆq mod e = ", res);

    // d -> private key
    BIGNUM *d = BN_new();
    BIGNUM *Q = BN_new();
    BIGNUM *Q_temp = BN_new();
    BN_sub(Q, p, one);
    BN_sub(Q_temp, q, one);
    BN_mul(Q, Q, Q_temp, ctx);
    BN_mod_inverse(d, e, Q, ctx);
    printBN("d = ", d);
    
    BIGNUM *M = BN_new();
    BN_hex2bn(&M, "4120746f702073656372657421");
    printBN("M = ", M);

    BIGNUM *C = BN_new();
    BN_mod_exp(C, M, e, n, ctx);
    printBN("C = ", C);

    BIGNUM *D = BN_new();
    BN_mod_exp(D, C, d, n, ctx);
    printBN("D = ", D);

    return 0;
}
