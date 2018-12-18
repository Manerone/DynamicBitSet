#include "dynamic_bitset.h"
#include "inttypes.h"
#include "stdio.h"
#include "string.h"
#include <math.h>

DynamicBitSet::DynamicBitSet(uint64_t n_of_bits) {
    bitset_size = ceil(n_of_bits / (double)min_element_size_bits());
    n_of_bits = n_of_bits;
    bitset = new min_element_size[bitset_size];
    memset(bitset, 0, bitset_size * min_element_size_bits()/8);
}

void DynamicBitSet::setBitToOne(DynamicBitSet bitset, uint64_t bit) {
    bitset.bitset[bit / bitset.min_element_size_bits()] |= (1 << (bit % bitset.min_element_size_bits()));
}

void DynamicBitSet::setBitToZero(DynamicBitSet bitset, uint64_t bit) {
    bitset.bitset[bit / bitset.min_element_size_bits()] &= ~(1 << (bit % bitset.min_element_size_bits()));
}

bool DynamicBitSet::readBit(DynamicBitSet bitset, uint64_t bit) {
    min_element_size value = bitset.bitset[bit / bitset.min_element_size_bits()];
    return (min_element_size) 1 & (value >> (bit % bitset.min_element_size_bits()));
}

DynamicBitSet DynamicBitSet::intersection(DynamicBitSet bitset, DynamicBitSet b2){
    DynamicBitSet result = DynamicBitSet(bitset.n_of_bits);

    for(size_t i = 0; i < bitset.bitset_size; ++i){
        result.bitset[i] = bitset.bitset[i] & b2.bitset[i];
    }

    return result;
}

void DynamicBitSet::intersection_on_self(DynamicBitSet bitset, DynamicBitSet b2){
    for(size_t i = 0; i < bitset.bitset_size; ++i){
        bitset.bitset[i] = bitset.bitset[i] & b2.bitset[i];
    }
}

void DynamicBitSet::print(DynamicBitSet bitset){

    for(size_t i = 0; i < bitset.bitset_size * bitset.min_element_size_bits(); i++)
    {
        if(i % bitset.min_element_size_bits() == 0)
            printf("|");
        printf("%d", DynamicBitSet::readBit(bitset, i));
    }
    printf("\n");

}

inline uint64_t DynamicBitSet::min_element_size_bits(){
    return sizeof(min_element_size)*8;
}