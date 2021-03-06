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
    BN_hex2bn(&s, "a4d83a0b54859b41f232142ac6b1677d0dd16d092dcda6969ce961c5e12c94932060b8f333c321a9c8ce3cc4487b0a4de2a38884e60a33f1b1f938d9b35923719937354a7c5eb675f9ae41ec6ca238189fcec83a509643c1d2381a113d3176f054528965db96f2e4eb3171f118c0479a0796836a8454eece1874aafb1857f587352d259e3b982412749fa2771c9f9ab1f555f6707c12d8c4188cf2314bcc5ac6829575db8fd91c2b3bf1bd13c22b9f7cb38781c53e3d7dfbfa2db0b0081131df68dd298d84f9ed5dd3249a5f4be051a3fa84054064815d7aa93c779372d7f358f53efdad875e9535e05d20eb91b387f997be3bfcd47674f477839ff83bc07f20");
    BN_hex2bn(&e, "10001");
    BN_hex2bn(&m, "0001ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff003031300d060960864801650304020105000420d151c37125d9be7cde130ea3f0cc7f008f3f97b13b6aa438c87578e02ca957d5");

    // res= C = m^e  mod n
    BIGNUM *res = BN_new();
    BN_mod_exp(res, s, e, n, ctx);
    printBN("m??e mod n = ", res);
    printBN("M = ", m);

    if (BN_ucmp(res, m) == 0)
        printf("Signature is valid.\n");
    else
        printf("Signature is not valid.\n");
    return 0;
}