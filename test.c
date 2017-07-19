//
// Created by waroy on 17-7-17.
//
#include <stdlib.h>
#include <printf.h>
#include <geohash.h>
#include <stdio.h>
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

void testgeohash() {
    char *geoalphabet= "0123456789bcdefghjkmnpqrstuvwxyz";
    double xy[2]={121,31};
    /* Re-encode */
    GeoHashRange r[2];
    GeoHashBits hash;
    r[0].min = -180;
    r[0].max = 180;
    r[1].min = -90;
    r[1].max = 90;
    geohashEncode(&r[0],&r[1],xy[0],xy[1],26,&hash);
    char buf[12];
    int i;
    for (i = 0; i < 11; i++) {
        int idx = (hash.bits >> (52-((i+1)*5))) & 0x1f;
        buf[i] = geoalphabet[idx];
    }
    buf[11] = '\0';

    printf("geohash: %s",buf);
}

int main(int argc, char **argv) {
//    testpqsort();
    testgeohash();
}