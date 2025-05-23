/*
 * 2.75
 * Suppose we want to compute the complete 2w-bit representation of x*y, where
 * both x and y are unsigned, on a machine for which data type `unsigned` is `w` bits.
 * The low-order `w` bits of the product can be computed with the expression x*y, so
 * we only require a procedure with prototype.
 *
 * unsigned int unsigned_high_prod(unsigned x, unsigned y);
 *
 * that computes the high_ordor w bits of x*y for unsigned variables.
 *
 * We have access to library function with prototype
 *
 * int signed_high_prod(int x, int y);
 *
 * that computes the high-order w bits of x*y for the case where x and y are int two's-
 * complement form. Write code calling this procedure to implement the function
 * for unsigned arguments. Justify the correctness of your solution.
 *
 * Hint: Look at the relationship between the signed product x*y and the
 * unsigned product x'*y' int the derication of Equation 2.18.
 */

int signed_high_prod(int x, int y) {
    int64_t mul = (int_64_t) x * y;
    return mul >> 32;
}

unsigned unsigned_high_prod(unsigned x, unsigned y) {
    int sig_x = x >> 31;
    int sig_y = y >> 31;
    int signed_prod = signed_high_prod(x, y);

    return signed_prod + x*sig_y + y*sig_x;
}

int main(int argc, char **argv){
    return 0;
}
