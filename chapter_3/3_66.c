/*
3.66

You are charged with maintaining a large C program, and you come across thefollowing code:

1 typedef struct {
2     int left;
3     a_struct a[CNT];
4     int right;
5 } b_struct;
6
7 void test(int i, b_struct *bp)
8 {
9     int n = bp->left + bp->right;
10    a_struct *ap = &bp->a[i];
11    ap->x[ap->idx] = n;
12 }

1 00000000 <test>:
2 0: 55                     push %ebp
3 1: 89 e5                  mov %esp,%ebp
4 3: 8b 45 08               mov 0x8(%ebp),%eax          i
5 6: 8b 4d 0c               mov 0xc(%ebp),%ecx          bp
6 9: 8d 04 80               lea (%eax,%eax,4),%eax      5i
7 c: 03 44 81 04            add 0x4(%ecx,%eax,4),%eax   5i + bp->a[i].idx
8 10: 8b 91 b8 00 00 00     mov 0xb8(%ecx),%edx         bp->right
9 16: 03 11                 add (%ecx),%edx             bp->left + bp->right
10 18: 89 54 81 08          mov %edx,0x8(%ecx,%eax,4)   bp->a[i].x[ap->idx] = n
11 1c: 5d pop %ebp
12 1d: c3 ret

The declarations of the compile-time constant CNT and the structure a_structare in a file for which you do not have the necessary access privilege. Fortunately, you have a copy of the ‘.o’ version of code, which you are able to disassemble with the objdump program, yielding the disassembly shown in Figure 3.45.

Using your reverse engineering skills, deduce the following.

A. The value of CNT.
CNT = 9 

B. A complete declaration of structure a_struct. Assume that the only fields in this structure are idx and x.
typedef struct{
    int x[4];
    int idx;
} a_struct

*/