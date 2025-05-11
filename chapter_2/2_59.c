/*
 * 2.59
 * Write a Cexpression that will tield a word consisting of the least significant
 * byte of x, and the remaining bytes of y. For operands x= 0x89ABCDEF and y = 
 * 0x76543210, this would give 0x765432EF
 * */


int yield_word(unsigned x, unsigned y){
    return x & 0xff | y & ~0U << 8;
}

int main(int argc, char *argv[]){
    return 0;
}
