/*
 * 3.54
 * A function with prototype
 * int decode2(int x, int y, int z);
 * is compiled into IA32 assembly code. The body of the code is as follows:
 * x at %ebp+8, y at %ebp+12, z at %ebp+16
 * 1 movl 12(%ebp), %edx
 * 2 subl 16(%ebp), %edx
 * 3 movl %edx, %eax
 * 4 sall $31, %eax
 * 5 sarl $31, %eax
 * 6 imull 8(%ebp), %edx
 * 7 xorl %edx, %eax
 * Parameters x, y, and z are stored at memory locations with offsets 8, 12, and 16relative to the address in register %ebp. The code stores the return value in register%eax.
 * Write C code for decode2 that will have an effect equivalent to our assemblycode.
 */

int decode2(int x, int y, int z){
    int diff = y - z;
    int mask = (diff << 31) >> 31;
    int prod = diff * x;
    return mask ^ prod;
}

int main(int argc, char *argv[]){
    return 0;
}