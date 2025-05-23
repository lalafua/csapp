/*
 * Write code for function with the following prototype:
 * 
 * // Addition that saturates to TMin ot TMax 
 * int saturating_add(int x, int y);
 *
 * Instead of overflowing the way normal two's-complement addition does, sat-
 * urating addition returns `TMax` when there would be positive overflow, and TMin
 * when there would be negative overflow. Saturating arithmetic is commanly used 
 * in programs that perform digital signal processing.
 * 
 * Your function should follow the bit--level integer coding rules (page 120).
 */


int saturating_add(int x, int y){
    int mask = 0x80000000;
    int sum = x + y;
    
    int pos_over = !(x & mask) && !(y & mask) && (sum & mask);
    int neg_over = (x & mask) && (y & mask) && !(sum & mask);

    (pos_over && (sum = 0x7FFFFFFF) || neg_over && (sum = 0x80000000));

    return sum;
}


int main(int argc, char **argv){
    return 0;
}
