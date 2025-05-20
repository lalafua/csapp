#include <stdio.h>
#include <limits.h>

void find_max () {
    int x = 1;
    int n = 1;
    for(; n <= INT_MAX && n > 0; x++) {
        n *= x;
    }
    printf("%X, %d", n, x);
}

int main(int argc, char **argv) {
    find_max();
    return 0;
}
