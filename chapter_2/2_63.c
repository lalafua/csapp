/*
 * 2.63
 * Fill in code for the following C functoins. Function `srl` performs a logical right
 * shift using an arithmetic right shift (given by vaalue `xsra`), followed by other oper-
 * ations not including right shift or division. Function `sra` performs an arithmetic
 * right shift using a logical right shift (given by value `xsrl`), followed by other 
 * operations not including right shifts or division. You may use the computation 
 * `8*sizeof(int)` to determine `w`, the number of bits in data type int. The shift
 * amount `k` can range from `0` wo `w-1`.
 *
 * ```c
 * unsigned srl (unsigned x, int k) {
 *     unsigned xsra = (int) x >> k;
 *     .
 *     .
 *     .
 * }
 *
 * int sra (int x, int k) {
 *     int xsrl = (unsigned) x >> k;
 *     .
 *     .
 *     .
 * }
 * ```
 */

unsigned srl(unsigned x, int k) {
    unsigned xsra = (int) x >> k;
    int mask = 0 >> k;
    return (xsra ^ mask);
}

int sra(int x, int k){
    int xsrl = (unsigned) x >> k;
    unsigned mask = 0 >> k;
    return (xsrl )
}










