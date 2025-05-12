/*
 * 2.62
 * Write a function `int_shifts_are_arithmetic()` that yields 1 when run on a
 * machine that uses arithmetic right shifts for `int`'s, and 0 otherwise. Your code
 * should work on a machine with any word size. Test your code on several machines.
 * */

int int_shifts_are_arithmetic () {
    const static int x = -1;
    return ((x >> 1) == -1);
}

int main (int argc, char *argv[]) {
    return 0;
}
