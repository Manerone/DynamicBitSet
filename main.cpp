//
// Created by Matheus Nerone on 2018-12-07.
//
#include <iostream>
#include "dynamic_bitset.h"

using namespace std;

#define N_BITS 4294967296

int main(){

    DynamicBitSet bitset = DynamicBitSet(N_BITS);
    DynamicBitSet bitset2 = DynamicBitSet(N_BITS);

    for(size_t i = 0; i < N_BITS; i += 3)
    {
        bitset.setBitToOne(i);
    }

    for(size_t i = 0; i < N_BITS; i += 2)
    {
        bitset2.setBitToOne(i);
    }


    // bitset.print();
    // bitset2.print();
    bitset.intersection_on_self(bitset2);
    // bitset.print();

    return 1;
}

