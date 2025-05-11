/*
 * 2.61
 * Write C expressions thar evaluate to 1 when the following conditions are ture, and
 * to 0 when they are false. Assume x is of type int.
 * 
 * A. Any bit of x equals 1.
 * B. Any bit of x equals 0.
 * C. Any bit in the least significant of x equals 1.
 * D. Any bit in the most significant of x euqals 0.
 *
 * Your code shoule follow the bit-level integer rules (page 120), with the 
 * additional restriction that you may not use equality (==) or inequality(!=) tests.
 * */

int exp_A (int x){
    return !~x;
}

int exp_B (int x){
    return ~x;
}

int exp_C (int x){
    int mask = 0xFF << 3;
    return !(x & mask);
}

int exp_D (int x){
        
}
