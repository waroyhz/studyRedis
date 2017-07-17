//
// Created by waroy on 17-7-17.
//
#include <stdlib.h>
#include <printf.h>
#include "src/pqsort.h"

int cmp(const void * a , const void * b){
    if (*((u_int8_t*)a)==*((u_int8_t*)b)){
        return 0;
    }else if (*((u_int8_t*)a)>*((u_int8_t*)b)){
        return 1;
    }else {
        return -1;
    }
}


void testpqsort() {
    printf("pqsort test\n");
    u_int8_t a[10];
    for (int i=0;i<sizeof(a);i++){
        a[i]=rand();
        printf("%d=%d\n",i,a[i]);
    }
    pqsort(a, 10, sizeof(u_int8_t), cmp, 0, 10);
    printf("pqsort\n");
    for (int i=0;i<sizeof(a);i++){
        printf("%d=%d\n",i,a[i]);
    }
}

int main(int argc, char **argv) {
    testpqsort();
}