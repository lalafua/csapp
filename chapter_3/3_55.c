/* 
 * 3.55
 * The following code computes the product of x and y and stores the result in memory. Data type ll_t is deﬁned to be equivalent to long long.
 * typedef long long ll_t;
 * void store_prod(ll_t *dest, int x, ll_t y) {
 * dest = x*y;
 * }
 * GCC generates the following assembly code implementing the computation:
 * dest at %ebp+8,x at %ebp+12, y at %ebp+16
 * 1 movl 16(%ebp), %esi        y_l to %esi (low 4 bytes)
 * 2 movl 12(%ebp), %eax        x to %eax 
 * 3 movl %eax, %edx            x to %edx 
 * 4 sarl $31, %edx             x >> 31 to %edx (0 or -1)
 * 5 movl 20(%ebp), %ecx        y_h to %ecx (high 4 bytes)
 * 6 imull %eax, %ecx           x * y_h to %ecx
 * 7 movl %edx, %ebx            x(sig) to %ebx
 * 8 imull %esi, %ebx           y_l * x to %ebx
 * 9 addl %ebx, %ecx            (x*y_h) + (x*y_l) to %ecx
 * 10 mull %esi                 x * y_l to %esi
 * 11 leal (%ecx,%edx), %edx    x * y_h + x to %edx
 * 12 movl 8(%ebp), %ecx        dest to %eck
 * 13 movl %eax, (%ecx)         low 4 bytes(x * y_l) to *dest
 * 14 movl %edx, 4(%ecx)        high 4 bytes(x * y_h) to *dest+4
 * This code uses three multiplications to implement the multiprecision arith-metic required to implement 64-bit arithmetic on a 32-bit machine. Describe thealgorithm used to compute the product, and annotate the assembly code to showhow it realizes your algorithm. Hint: See Problem 3.12 and its solution.
 */

typedef long long ll_t;

void store_prod(ll_t *dest, int x, ll_t y) {
    *dest = x*y;
}

int main(int argc, char *argv[]){
    return 0;
}