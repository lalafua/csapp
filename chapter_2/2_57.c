/*
 * 2.57
 * Write procedures `show_short`,`show_long`,and `show_double` that print the byte
 * representations of C objects of types `short int`,`long int`,and `double`, respec-
 * tively. Try these out on the several mechines.
 * */

#include <stdio.h>

typedef unsigned char byte;

void show_bytes(byte *start, size_t len){
    for(size_t i=0; i<len; i++){
        printf("%.2x%c", start[i], i+1 != len ? ' ': '\n');    
    }
}

void show_short(short x){
    show_bytes((byte *)&x, sizeof(short));
}

void show_long(long x){
    show_bytes((byte *)&x, sizeof(long));
}

void show_double(double x){
    show_bytes((byte *)&x, sizeof(double));
}

void show_void(void *x){
    show_bytes((byte *)&x, sizeof(void *));
}

int main(int argc, char *argv[]){
    return 0;
}

