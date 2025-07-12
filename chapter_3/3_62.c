/*
The following code transposes the elements of an M × M array, where M is aconstant deﬁned by #define:

void transpose(Marray_t A) {
    int i, j;
    for(i=0;i<M; i++)
        for(j=0;j<i; j++) {
            int t = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = t;
            }
        }

When compiled with optimization level -O2, gcc generates the following code for the inner loop of the function:

i in %esi, j in %ecx

1 .L3:
2 movl (%ebx), %eax             %eax = A[i][j]
3 movl (%esi,%ecx,4), %edx      %edx = A[j][i]
4 movl %eax, (%esi,%ecx,4)      A[j][i] = A[i][j](%eax)      
5 addl $1, %ecx                 j++
6 movl %edx, (%ebx)             A[i][j]((%ebx)) = A[j][i](%edx)
7 addl $52, %ebx                
8 cmpl %edi, %ecx               compare i and j
9 jl .L3

A. What is the value of M?
    13
B. What registers hold program values i and j?
    i in %edi, j in % ecx, A[i][j] in % ebx, A[j][0] in %esi
C. Write a C code version of transpose that makes use of the optimizationsthat occur in this loop. Use the parameter M in your code rather than numericconstants.
*/