/*
3.60

Consider the following source code, where R, S, and T are constants declared with

#define:

int A[R][S][T];
int store_ele(int i, int j, int k, int *dest)
{
    *dest = A[i][j][k];
    return sizeof(A);
}

In compiling this program, gcc generates the following assembly code:

i at %ebp+8, j at %ebp+12, k at %ebp+16, dest at %ebp+20
 
1 movl 12(%ebp), %edx           %edx = j
2 leal (%edx,%edx,4), %eax      %eax = 5*(%edx) = 5j
3 leal (%edx,%eax,2), %eax      %eax = j + 2*5*j = 11j
4 imull $99, 8(%ebp), %edx      %edx = 99i
5 addl %edx, %eax               %eax = 11j + 99i
6 addl 16(%ebp), %eax           %eax = 99i + 11j + k
7 movl A(,%eax,4), %edx         %edx = A + 4(99i + 11j + k)
8 movl 20(%ebp), %eax           %eax = &dest
9 movl %edx, (%eax)             (%eax) = *dest = A + 4(99i + 11j + k)       
10 movl $1980, %eax             sizeof(A) = 0x1980             

A. Extend Equation 3.1 from two dimensions to three to provide a formula forthe location of array element A[i][j][k].
    A[i][j][k] = A + (i × S × T + j × T + k) × sizeof(int)
    
    For this specific case: A[i][j][k] = A + (99i + 11j + k) × 4
    
B. Use your reverse engineering skills to determine the values of R, S, and T based on the assembly code.
    R = 5    (从 sizeof(A) = 1980 和 S×T = 99 计算得出)
    S = 9    (从 i的系数99 = S×T，T = 11 计算得出)
    T = 11   (从 j的系数11直接得出)
    
    验证：R×S×T×4 = 5×9×11×4 = 1980 ✓  
*/