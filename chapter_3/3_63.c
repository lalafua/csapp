/*
3.63

Consider the following source code, where E1 and E2 are macro expressions de-clared with #define that compute the dimensions of array A in terms of parametern. This code computes the sum of the elements of column j of the array.

1 int sum_col(int n, int A[E1(n)][E2(n)], int j) {
2     int i;
3     int result = 0;
4     for (i = 0; i < E1(n); i++) 
5         result += A[i][j];
6     return result;
7     }

In compiling this program, gcc generates the following assembly code:
n at %ebp+8, A at %ebp+12, j at %ebp+16
1 movl 8(%ebp), %eax            %eax = n
2 leal (%eax,%eax), %edx        %edx = 2n
3 leal (%edx,%eax), %ecx        %ecx = 3n
4 movl %edx, %ebx               %ebx = 2n
5 leal 1(%edx), %eax            %eax = 2n+1
6 movl $0, %edx                 %edx = 0
7 testl %eax, %eax              
8 jle .L3                       if 2n+1 <= 0, go to .L3
9 leal 0(,%ecx,4), %esi         %esi = 12n
10 movl 16(%ebp), %edx          %edx = j
11 movl 12(%ebp), %ecx          %ecx = A
12 leal (%ecx,%edx,4), %eax     %eax = A+4j
13 movl $0, %edx                %edx = 0
14 movl $1, %ecx                %ecx = 1
15 addl $2, %ebx                %ebx = 2n+2
16 .L4:
17 addl (%eax), %edx            result += A[i][j]
18 addl $1, %ecx                i++
19 addl %esi, %eax              %eax += 12n
20 cmpl %ebx, %ecx              
21 jne .L4                      if i != 2n+2, go to .L4
22 .L3:                     
23 movl %edx, %eax              %eax = result

Use your reverse engineering skills to determine the definitions of E1 and E2.

E1(n)=2n+1 E2(n)=3n
*/