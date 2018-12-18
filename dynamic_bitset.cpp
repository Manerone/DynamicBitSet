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

void DynamicBitSet::setBitToOne(uint64_t bit) {
    bitset[bit / min_element_size_bits()] |= (1 << (bit % min_element_size_bits()));
}

void DynamicBitSet::setBitToZero(uint64_t bit) {
    bitset[bit / min_element_size_bits()] &= ~(1 << (bit % min_element_size_bits()));
}

bool DynamicBitSet::readBit(uint64_t bit) {
    min_element_size value = bitset[bit / min_element_size_bits()];
    return (min_element_size) 1 & (value >> (bit % min_element_size_bits()));
}

DynamicBitSet DynamicBitSet::intersection(DynamicBitSet b2){
    DynamicBitSet result = DynamicBitSet(n_of_bits);

    for(size_t i = 0; i < bitset_size; ++i){
        result.bitset[i] = this->bitset[i] & b2.bitset[i];
    }

    return result;
}

void DynamicBitSet::intersection_on_self(DynamicBitSet b2){
    for(size_t i = 0; i < bitset_size; ++i){
        this->bitset[i] = this->bitset[i] & b2.bitset[i];
    }
}

void DynamicBitSet::print(){

    for(size_t i = 0; i < bitset_size * min_element_size_bits(); i++)
    {
        if(i % min_element_size_bits() == 0)
            printf("|");
        printf("%d", readBit(i));
    }
    printf("\n");

}

inline uint64_t DynamicBitSet::min_element_size_bits(){
    return sizeof(min_element_size)*8;
}