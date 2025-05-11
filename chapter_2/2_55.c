/* 
 * 2.55
 * Compile and run the sample code that uses show_bytes (ﬁle show-bytes.c) on
 * different machines to which you have access. Determine the byte orderings used
 * by these machines.
 * */


#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len){
    int i;
    for(i=0; i<len; i++){
    	printf(" %.2x", start[i]);
    }
    printf("\n");
}

void show_int(int x){
    show_bytes((byte_pointer)&x, sizeof(int));
}

void show_float(float x){
    show_bytes((byte_pointer)&x, sizeof(float));
}

void show_void(void *x){
    show_bytes((byte_pointer)&x, sizeof(void));
}


