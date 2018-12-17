//
// Created by Matheus Nerone on 2018-12-07.
//
#include <iostream>
#include "dynamic_bitset.h"

using namespace std;

#define N_BITS 128

int main(){

    DynamicBitSet bitset = DynamicBitSet(N_BITS);

    bitset.print();

    for(size_t i = 0; i < N_BITS; i++)
    {
        bitset.setBitToOne(i);
    }

    bitset.print();

    return 1;
}

