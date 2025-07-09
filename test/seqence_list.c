#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <assert.h>

#define MAXSIZE 50

typedef int ele_t ;

typedef struct{
    ele_t data[MAXSIZE];
    unsigned int length;
} seq_list;

void init_list(seq_list *list, ele_t *data, unsigned int length){
    if (data != NULL){
        memcpy((*list).data, data, length*sizeof(ele_t));
    }
    (*list).length = length;
}

void print_list(seq_list *list){
    printf("length: %d \n", (*list).length);
    for (int i=0; i<(*list).length; i++){
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

void del_same(seq_list *list){
    unsigned int k = 0;
    for (int i=1; i<=list->length-1; i++){
        if (list->data[i-1] == list->data[i]){
            k++;
        }
        else{
            list->data[i-k] = list->data[i];
        }
    }
    list->length -= k;
}

int main(int argc, char **argv){
    seq_list ls;
    ele_t data[] = {0, 1, 2, 2, 3, 3, 4, 5, 6, 6, 7, 7};
    unsigned int length = sizeof(data) / sizeof(ele_t);

    init_list(&ls, data, length);
    print_list(&ls);

    del_same(&ls);
    print_list(&ls);

    return 0;
}
