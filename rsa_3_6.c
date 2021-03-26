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
    BIGNUM *m = BN_new();
    BIGNUM *e = BN_new();
    BIGNUM *s = BN_new();

    BN_hex2bn(&n, "D018CF45D48BCDD39CE440EF7EB4DD69211BC9CF3C8E4C75B90F3119843D9E3C29EF500D10936F0580809F2AA0BD124B02E13D9F581624FE309F0B747755931D4BF74DE1928210F651AC0CC3B222940F346B981049E70B9D8339DD20C61C2DEFD1186165E7238320A82312FFD2247FD42FE7446A5B4DD75066B0AF9E426305FBE01CC46361AF9F6A33FF6297BD48D9D37C1467DC75DC2E69E8F86D7869D0B71005B8F131C23B24FD1A3374F823E0EC6B198A16C6E3CDA4CD0BDBB3A4596038883BAD1DB9C68CA7531BFCBCD9A4ABBCDD3C61D7931598EE81BD8FE264472040064ED7AC97E8B9C05912A1492523E4ED70342CA5B4637CF9A33D83D1CD6D24AC07");
    BN_hex2bn(&s, "1a803e3679fbf32ea946377d5e541635aec74e0899febdd13469265266073d0aba49cb62f4f11a8efc114f68964c742bd367deb2a3aa058d844d4c20650fa596da0d16f86c3bdb6f0423886b3a6cc160bd689f718eee2d583407f0d554e98659fd7b5e0d2194f58cc9a8f8d8f2adcc0f1af39aa7a90427f9a3c9b0ff02786b61bac7352be856fa4fc31c0cedb63cb44beaedcce13cecdc0d8cd63e9bca42588bcc16211740bca2d666efdac4155bcd89aa9b0926e732d20d6e6720025b10b090099c0c1f9eadd83beaa1fc6ce8105c085219512a71bbac7ab5dd15ed2bc9082a2c8ab4a621ab63ffd7524950d089b7adf2affb50ae2fe1950df346ad9d9cf5ca");
    BN_hex2bn(&e, "10001");
    BN_hex2bn(&m, "12efcf61ed50eb71f3503341a25a6671ab4cee10df87c6855ab1bf3a3c00fb42");

    // res= C = m^e  mod n
    BIGNUM *res = BN_new();
    BN_mod_exp(res, s, e, n, ctx);
    printBN("mˆe mod n = ", res);
    printBN("M = ", m);

    if (BN_cmp(res, m) == 0)
        printf("Signature is valid.\n");
    else
        printf("Signature is not valid.\n");
    return 0;
}