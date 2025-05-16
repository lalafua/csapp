/*
 * 2.64
 * Write code to implement the following function:
 * 
 * // Return 1 when any odd bit of x equals 1; 0 otherwise.
 * // Assume w=32.
 * int any_odd_one (unsigned x);
 *
 * Your function shoule follow the bit-level integer coding rules (page 120), except
 * that you may assume that data type `int` has `w` = 32 bits/
 */


int any_odd_one(unsigned x) {
    return !!(0xAAAAAAAA & x);
}

int main(int argc, char **argv) {
    return 0;
}
