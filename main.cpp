//
// Created by Matheus Nerone on 2018-12-07.
//
#include <iostream>
#include "dynamic_bitset.h"

using namespace std;

int main(){

    DynamicBitSet bitset = DynamicBitSet(10);

    cout << bitset.readBit(65) << '\n';

    bitset.setBitToOne(65);

    cout << bitset.readBit(65) << '\n';

    bitset.setBitToOne(66);

    cout << bitset.readBit(66) << '\n';
    cout << bitset.readBit(65) << '\n';

    return 1;
}

