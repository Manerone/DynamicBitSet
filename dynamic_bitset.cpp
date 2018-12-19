#include "dynamic_bitset.h"
#include "inttypes.h"
#include "stdio.h"
#include "string.h"
#include <math.h>

DynamicBitSet::DynamicBitSet(uint64_t number_of_bits) {
    bitset_size = ceil(number_of_bits / (double)min_element_size_bits);
    n_of_bits = number_of_bits;
    bitset = new min_element_size[bitset_size];
    memset(bitset, 0, bitset_size * min_element_size_bits/8);
}

void DynamicBitSet::setBitToOne(uint64_t bit) {
    // bitset[bit / min_element_size_bits] |= (one << (bit % min_element_size_bits));
    bitset[bit >> log_of_min_element] |= (one << (bit & (min_element_size_bits - 1)));
}

void DynamicBitSet::setBitToZero(uint64_t bit) {
    // bitset[bit / min_element_size_bits] &= ~(one << (bit % min_element_size_bits));
    bitset[bit >> log_of_min_element] &= ~(one << (bit & (min_element_size_bits - 1)));
}

bool DynamicBitSet::readBit(uint64_t bit) {
    min_element_size value = bitset[bit / min_element_size_bits];
    // return one & (value >> (bit % min_element_size_bits));
    return one & (value >> (bit & (min_element_size_bits - 1)));
}

DynamicBitSet DynamicBitSet::intersection(DynamicBitSet b2){
    DynamicBitSet result = DynamicBitSet(n_of_bits);

    for(uint64_t i = 0; i < bitset_size; ++i){
        result.bitset[i] = this->bitset[i] & b2.bitset[i];
    }

    return result;
}

void DynamicBitSet::intersection_on_self(DynamicBitSet b2){
    for(uint64_t i = 0; i < bitset_size; ++i){
        this->bitset[i] = this->bitset[i] & b2.bitset[i];
    }
}

void DynamicBitSet::print(){

    for(uint64_t i = 0; i < bitset_size * min_element_size_bits; i++)
    {
        if(i % min_element_size_bits == 0)
            printf("|");
        printf("%d", readBit(i));
    }
    printf("\n");

}