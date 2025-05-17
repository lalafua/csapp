/*
 * 2.65
 * Write code to implement the following function:
 *
 * // Return 1 when any odd bit of x equals 1; 0 otherwise.
 * // Assume w=32.
 *
 * int any_odd_one(unsigned x);
 *
 * Your function should follow the bit-level integer coding rules(page 120), except
 * that you may assume that data type `int` has `w` = 32 bits.
 * Your code should contain a total of at most 12 arithmetic, bit-wise, and logical operations.
 */

int odd_ones(unsigned x) {
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    x &= 1;
    return x;
}

int main(int argc, char **argv){
    return 0;
}
