/*
 * 3.57
 * In Section 3.6.6, we examined the following code as a candidate for the use ofconditional data transfer:
 * int cread(int *xp) {
 *     return (xp ? *xp : 0);
 * }
 * We showed a trial implementation using a conditional move instruction but arguedthat it was not valid, since it could attempt to read from a null address.
 * Write a C function cread_alt that has the same behavior as cread, exceptthat it can be compiled to use conditional data transfer. When compiled with thecommand-line option ‘-march=i686’, the generated code should use a conditionalmove instruction rather than one of the jump instructions.
 */

int cread(int *xp) {
    return (xp ? *xp : 0);
}

int cread_alt(int *xp) {
    int z = 0;
    return *(xp ? xp : &z);
}

int main(int argc, char **argv){
    return 0;
}