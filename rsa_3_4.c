/* bn_sample.c */
#include <stdio.h>
#include <openssl/bn.h>
#define NBITS 256

void printBN(char *msg, BIGNUM *a)
{
    /* Use BN_bn2hex(a) for hex string
    * Use BN_bn2dec(a) for decimal string */
    char *number_str = BN_bn2hex(a);
    printf("%s %s\n", msg, number_str);
    OPENSSL_free(number_str);
}

int main()
{
    BN_CTX *ctx = BN_CTX_new();
    BIGNUM *n = BN_new();
    BIGNUM *d = BN_new();
    BIGNUM *m1 = BN_new();
    BIGNUM *m2 = BN_new();

    BN_hex2bn(&n, "AE1CD4DC432798D933779FBD46C6E1247F0CF1233595113AA51B450F18116115");
    BN_hex2bn(&d, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");
    BN_hex2bn(&m1, "49206F776520796F752024323030302E");
    BN_hex2bn(&m2, "49206F776520796F752024333030302E");

    // res= C = m^e  mod n
    BIGNUM *res1 = BN_new();
    BIGNUM *res2 = BN_new();
    BN_mod_exp(res1, m1, d, n, ctx);
    BN_mod_exp(res2, m2, d, n, ctx);
    printBN("Signature 1 = ", res1);
    printBN("Signature 2 = ", res2);

    return 0;
}